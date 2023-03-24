#include "Transparent.hh"

Transparent::Transparent(const vec3& color): Material()
{
    Kd = color;
}

Transparent::Transparent(const vec3 &Ka, const vec3 &Kd, const vec3 &Ks, float k) : Material(Ka, Kd, Ks, k){
}

Transparent::Transparent(const vec3 &Ka, const vec3 &Kd, const vec3 &Ks, float k, float o) : Material(Ka, Kd, Ks, k, o){
}


Transparent::~Transparent(){
}

bool Transparent::scatter(const Ray& r_in, const HitInfo& rec, vec3& color, Ray& r_out) const  {
    vec3 N = normalize(rec.normal); /* Normal a la intersecció */
    vec3 V = normalize(r_in.getDirection()); /* Vector del raig incident */

    float cos = dot(N, V); /* Cosinus de la Normal i el raig incident */
    float snell = 1/rec.mat_ptr->nut; /* medi2 / medi1 */

    vec3 p0 = rec.p; /* punt d'intersecció */

    /* Fem el contrari */
    if(cos > DBL_EPSILON){
        N = -N;
        snell = 1/snell;
    }

    vec3 v_refract = glm::refract(V, N, snell); /* Vector refractat normalitzat */


    if(dot(v_refract,v_refract) < DBL_EPSILON){ /* No hi ha refracció sinó reflexió interna */
        vec3 reflect = glm::reflect(V, N); /* Vector reflexat */
        p0 = rec.p + vec3(DBL_EPSILON)*reflect; /* Evitem acné */
        r_out = Ray(p0,reflect); /* Raig reflectit */
        color = Ks;
    } else {
        p0 = rec.p + vec3(DBL_EPSILON)*v_refract; /* Evitem acné */
        r_out = Ray(p0,v_refract); /* Raig refactat */
        color = kt;
    }

    return true;
}
