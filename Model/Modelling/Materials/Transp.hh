#pragma once

#include "Material.hh"

class Transp : public Material
{
public:
    Transp() {};
    Transp(const vec3& color);
    Transp(const vec3 &Ka, const vec3 &Kd, const vec3 &Ks, float refractionIndex, float shininess);
    virtual ~Transp();
    virtual bool scatter(const Ray& r_in, const HitInfo& rec, vec3& color, Ray & r_out) const;
    vec3 scatterTransp(const Ray& r_in, const HitInfo& rec, vec3& color, Ray & r_out) const;
    float refractionIndex;




};
