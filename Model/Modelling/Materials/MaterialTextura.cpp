#include "MaterialTextura.hh"

MaterialTextura::MaterialTextura() : Material(){
    this->Kd = vec3(0.5,0.5,0.5);
    this->Ks = vec3(0.0,0.0,0.0);
    this->Ka = vec3(0.1,0.1,0.1);
    this->opacity = 1.0;
    this->shininess = 1.0;
}

MaterialTextura::~MaterialTextura()
{}

bool MaterialTextura::scatter(const Ray& r_in, const HitInfo& rec, vec3& color, Ray & r_out) const {
    return false;
}

MaterialTextura::MaterialTextura(vec3 a, vec3 d, vec3 s, float o, int sh) : Material(a,d,s,o,sh){
    this->Kd = d;
    this->Ks = s;
    this->Ka = a;
    if(o > 1.0+DBL_EPSILON){o = 1.0;}
    this->opacity = o;
    if(sh > 500+DBL_EPSILON){sh = 500;}
    this->shininess = sh;
}

vec3 MaterialTextura::getDiffuse(vec2 point) const {
  float dd = point.x;
  float ee = point.y;
  return this->image->getColorPixel(point);
}

void MaterialTextura::read(const QJsonObject &json) {
    Material::read(json);

    if (json.contains("textureFile") && json["textureFile"].isString()){
        QString path = json["textureFile"].toString();
        this->image = new Texture(path);
    }
}
