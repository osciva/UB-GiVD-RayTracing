#include "Cylinder.hh"

Cylinder::Cylinder() {
    this->radi = 0.0;
    this->center = vec3(0,0,0);
    this->height = 0.0;
}

Cylinder::Cylinder(float data) : Object(data){
    this->radi = 1.0;
    this->center = vec3(0,0,0);
    this->height = 1.0;
    this->n1 = vec3(0.0,1.0,0.0);
    this->n2 = vec3(0.0,-1.0,0.0);
    this->top1 = new Circle(n1,this->center.y+vec3(0,height,0), 1);
    this->top2 = new Circle(n2,this->center,1);
}

Cylinder::Cylinder(vec3 center, float radi, float height, float data) : Object(data){
    this->center = center;
    this->radi = radi;
    this->height = height;
    this->n1 = vec3(0.0,1.0,0.0);
    this->n2 = vec3(0.0,-1.0,0.0);
    this->top1 = new Circle(n1,this->center.y+vec3(0,height,0), 1);
    this->top2 = new Circle(n2,this->center,1);
}

Cylinder::~Cylinder(){

}

bool Cylinder::cylinderHit(Ray& r, float t_min, float t_max, HitInfo& info) const {
    /* Comprovem si hit amb el cos principal del cilindre */
    /* Instruccions i procediment de: https://is.gd/nLCSkZ */
    /* Calculem x² + z² = 1, on x = p0x + vx*t z = x = p0z + vz*t components del raig */
    /* Resolent per t podem obtenir una equacio de 2n grau format at² + bt + c = 0 on:
     * a = vx² + vz² */
    float a = (r.getDirection().x * r.getDirection().x) + (r.getDirection().z * r.getDirection().z);

    /* No té solució real -> no hi ha intersecció */
    if(a < DBL_EPSILON){
        return false;
    }

    /* b = 2*(vx*(p0x - cx) + (vz*(p0z - cz)) */
    float b = 2*(r.getDirection().x * (r.getOrigin().x - center.x) +
                 r.getDirection().z * (r.getOrigin().z - center.z));

    /*c = (pox - cx)² + (poz - cz)² - 1 */
    float c = ((r.getOrigin().x - center.x)*(r.getOrigin().x - center.x)) +
            ((r.getOrigin().z - center.z)*(r.getOrigin().z - center.z)) - 1;

    /* Comprovant el resultat de l'arrel ja podem treure conclusions i estalviar calculs */

    float discrim = (b * b) - (4 * a * c);

    /* Estudiarem els dos possibles valors de t que segueixen : (-b +- SQRT(b² – 4 * a * c) ) / (2 * a) */
    float t1,t2;

    /* No té solució real -> no hi ha intersecció */
    if(discrim < DBL_EPSILON){//no té solució real no hi ha intersecció
        return false;
    }

    /* Raig tangent al cilindre -> 1 únic t */
    else if (discrim > 0-DBL_EPSILON && discrim < 0+DBL_EPSILON){
        t1 = t2 = -b / (2 * a);//no tenim arrel
    }

    /* Tenim 2 interseccions i hem d'agafar la t més petita */
    else{
        t1 = (-b + sqrtf(discrim))/(2 * a);
        t2 = (-b - sqrtf(discrim))/(2 * a);
    }

    /* Ens quedem la t més petita */
    if(t2 < t1 && t2 >= 0){
        t1 = t2;
    }

    if(t1 < 0){
        return false;
    }

    if(t1 < t_max+DBL_EPSILON && t1 > t_min-DBL_EPSILON){
        /* Calculem les coordenades del punt d'intersecció */
        vec3 t = r.pointAtParameter(t1);

        /* Si la intersecció és més petita que l'alçada, es troba dins
         * del nostre cilindre */
        if(t.y < center.y+height+DBL_EPSILON && t.y > center.y-DBL_EPSILON){
            /* Omplim info */
            info.t = t1;
            info.p = r.pointAtParameter(info.t);
            info.normal = (info.p - center)/radi;
            info.mat_ptr = material.get();
            return true;
        }
    }

    return false;
}

bool Cylinder::hit(Ray& r, float t_min, float t_max, HitInfo& info) const {
    bool hasHit = false;
    float t_cilindre(std::numeric_limits<float>::infinity());
    float t_top1(std::numeric_limits<float>::infinity());
    float t_top2(std::numeric_limits<float>::infinity());

    /* Càlcul de la intersecció amb el cilindre */
    if(cylinderHit(r,t_min,t_max,info)){
        t_top1 = info.t;
        hasHit = true;
    }

    /* Càlcul de la intersecció amb top1 */
    if(top1->hit(r,t_min,t_max,info)){
        t_top1 = info.t;
        hasHit = true;
    }

    /* Càlcul de la intersecció amb top2 */
    if(top2->hit(r,t_min,t_max,info)){
        t_top2 = info.t;
        hasHit = true;
    }

    /* Si hi ha hagut hit */
    if(hasHit){
        float temp(std::numeric_limits<float>::infinity());
        /* Trobem quina és la intersecció mínima */
        if(t_cilindre < temp){
            temp = t_cilindre;
        }
        if(t_top1 < temp){
            temp = t_top1;
        }
        if(t_top2 < temp){
            temp = t_top2;
        }
        /* Omplim la informació */
        info.t = temp;
        info.p = r.pointAtParameter(info.t);
        info.normal = vec3(info.p.x,0,info.p.z);
        info.mat_ptr = material.get();
    }
    return hasHit;
}

void Cylinder::read(const QJsonObject &json){
    Object::read(json);

    if(json.contains("radious") && json["radious"].isDouble()){
        this->radi = json["radious"].toDouble();
    }

    if(json.contains("h") && json["h"].isDouble()){
        this->height = json["h"].toDouble();
    }

    if (json.contains("center") && json["center"].isArray()) {
        QJsonArray auxVec = json["center"].toArray();
        this->center[0] = auxVec[0].toDouble();
        this->center[1] = auxVec[1].toDouble();
        this->center[2] = auxVec[2].toDouble();
    }

    /* Calcular dos punts que pertanyin al pla del cercle */
    vec3 point1(center.x + radi, center.y, center.z + height/2.0f);
    vec3 point2(center.x - radi, center.y, center.z + height/2.0f);

    /* Calcular dos vectors que pertanyin al pla del cercle */
    vec3 vector1 = point1 - center;
    vec3 vector2 = point2 - center;

    /* Calcular la normal com el producte vectorial dels dos vectors */
    vec3 normal = cross(vector1, vector2);

    /* Crear els dos cercles del cilindre */
    this->top1 = new Circle(normal,this->center.y+vec3(0,height,0), 1);
    this->top2 = new Circle(-normal,this->center,1);
 }

 void Cylinder::write(QJsonObject &json) const {
     Object::write(json);
 }

 void Cylinder::print(int indentation) const {
    Object::print(indentation);

    const QString indent(indentation * 2, ' ');

    QTextStream(stdout) << indent << "radius:\t" << radi << "\n";
    QTextStream(stdout) << indent << "height:\t" << height << "\n";
    QTextStream(stdout) << indent << "center:\t" << center[0] << ", "<< center[1] << ", "<< center[2] << "\n";
}

 void Cylinder::aplicaTG(shared_ptr<TG> tg) {
     vec4 c(center, 1.0);

     /* Desplacem el centre */
     if (dynamic_pointer_cast<TranslateTG>(tg)) {
         vec4 c(center, 1.0);
         c = tg->getTG() * c;
         center.x = c.x; center.y = c.y; center.z = c.z;
     }

     /* Augmentem l'altura */
     if (dynamic_pointer_cast<TranslateTG>(tg)){
         vec4 c(1.0,1.0,1.0,1.0);
         c = tg->getTG() * c;
         this->height = c.x*height;
     }
 }
