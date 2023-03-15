#include "Circle.hh"

Circle::Circle(vec3 normal, vec3 pass_point, float radius) : Plane(normal, pass_point,radius){
    this->normal = normalize(normal);
    this->center = pass_point;
    this->radius = radius;
}
bool Circle::hit(Ray& r, float t_min, float t_max, HitInfo& rec) const {
    if(Plane::hit(r,t_min,t_max,rec)){//si fa hit hem de comprovar si el punt pertany a la superficie del cercle.
        float x2 = (rec.p.x - center.x)*(rec.p.x - center.x);
        float z2 = (rec.p.z - center.z)*(rec.p.z - center.z);
        if((x2 + z2)-radius <= DBL_EPSILON && (x2 + z2) >= DBL_EPSILON){//Comprova que el punt de intersecció es trobi dins del cercle.
            //(x - cx)²+ (z - cz)² = r
            return true;
        }
    }
    return false;
}

void Circle::setCenterY(float centery){
    this->center.y=centery;
}
float Circle::getCenterY(){
    return this->center.y;
}

void Circle::aplicaTG(shared_ptr<TG> tg){
    if (dynamic_pointer_cast<TranslateTG>(tg)) {//movem el centre
        vec4 c(center, 1.0);
        c = tg->getTG() * c;
        center.x = c.x; center.y = c.y; center.z = c.z;
    }
    if (dynamic_pointer_cast<TranslateTG>(tg)){//canviem el radi
        //radius *= t->getTG();
    }
}
