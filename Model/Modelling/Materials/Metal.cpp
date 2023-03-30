#include "Metal.hh"

Metal::Metal(const vec3& color) : Material()
{
    Ks = color;
}

Metal::Metal(const vec3 &Ka, const vec3 &Kd, const vec3 &Ks, int shininess){//components i shininess
    this->Ka = Ka;
    this->Kd = Kd;
    this->Ks = Ks;
    kt = vec3(1) - this->Ks;
    this->shininess = shininess;
}

Metal::~Metal()
{
}

bool Metal::scatter(const Ray& r_in, const HitInfo& rec, vec3& color, Ray & r_out) const  {
    vec3 v = reflect(normalize(rec.p - r_in.getOrigin()), rec.normal); /* Vector reflexat */
    vec3 p0 = rec.p + vec3(DBL_EPSILON)*v; /* Evitem acné */
    r_out =  Ray(p0,v); /* Raig reflectit */
    color = Ks; /* Només especular */
    return true;
}
