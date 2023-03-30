#pragma once

#include "Material.hh"

class Transparent : public Material
{
public:
    Transparent() {}
    Transparent(const vec3& color);
    Transparent(const vec3 &Ka, const vec3 &Kd, const vec3 &Ks, float k);
    Transparent(const vec3 &Ka, const vec3 &Kd, const vec3 &Ks, float k, float o);
    virtual ~Transparent();

    virtual bool scatter(const Ray& r_in, const HitInfo& rec, vec3& color, Ray & r_out) const;

};
