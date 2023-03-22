#include "Transp.hh"



Transp::Transp(const vec3& color): Material()
{
    Ks = color;
}

Transp::Transp(const vec3 &Ka, const vec3 &Kd, const vec3 &Ks, float refractionIndex, float shininess){//components i shininess
    this->Ka = Ka;
    this->Kd = Kd;
    this->Ks = Ks;
    vec3 vector_unitari = vec3(1);
    kt = vector_unitari - this->Ks;
    this->shininess = shininess;
    this->refractionIndex = refractionIndex;
}


Transp::~Transp(){
}


bool Transp::scatter(const Ray& r_in, const HitInfo& rec, vec3& color, Ray& r_out) const  {
    vec3 N = normalize(rec.normal);//Normal a la intersecció
    vec3 V = normalize(r_in.getOrigin());//Vector del raig incident
    float cos = dot(N,V);//Cos de la Normal i el raig incident
    float snell = 1.0003f/refractionIndex;// medi2 / medi1
    vec3 p0 = rec.p;//punt d'intersecció

    if(cos > DBL_EPSILON){//Contrari
        N = -N;
        snell = 1.f/snell;
    }
    vec3 v_refract = refract(V,N,snell);// vector refractat normalitzat
    r_out = Ray(p0,v_refract);//raig refractat
    color = kt;

    if(dot(v_refract,v_refract) < DBL_EPSILON){//No hi ha refracció sinó reflexió
        vec3 v_reflect = reflect(normalize(p0 - V), N);//vector reflexat
        p0 = rec.p + vec3(DBL_EPSILON)*v_reflect;//evitem acné
        r_out = Ray(p0,v_reflect);//raig reflectit
        color = Ks;

    }

    return true;

}

vec3 Transp::scatterTransp(const Ray& r_in, const HitInfo& rec, vec3& color, Ray& r_out) const{
    vec3 N = normalize(rec.normal);//Normal a la intersecció
    vec3 V = normalize(r_in.getOrigin());//Vector del raig incident
    float cos = dot(N,V);//Cos de la Normal i el raig incident
    float snell = 1.0003f/refractionIndex;// medi2 / medi1
    vec3 p0 = rec.p;//punt d'intersecció

    if(cos > DBL_EPSILON){//Contrari
        N = -N;
        snell = 1.f/snell;
    }
    vec3 v_refract = refract(V,N,snell);// vector refractat normalitzat
    r_out = Ray(p0,v_refract);//raig refractat
    color = kt;

    if(dot(v_refract,v_refract) < DBL_EPSILON){//No hi ha refracció sinó reflexió
        vec3 v_reflect = reflect(normalize(p0 - V), N);//vector reflexat
        p0 = rec.p + vec3(DBL_EPSILON)*v_reflect;//evitem acné
        r_out = Ray(p0,v_reflect);//raig reflectit
        color = Ks;

    }

    return color;

}
