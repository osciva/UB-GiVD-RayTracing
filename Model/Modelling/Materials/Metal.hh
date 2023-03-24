#pragma once

#include "Material.hh"

class Metal : public Material
{
public:
    Metal(){}
    Metal(const vec3& color);
    Metal(const vec3 &Ka, const vec3 &Kd, const vec3 &Ks, int shininess);
    virtual ~Metal();
    virtual bool scatter(const Ray& r_in, const HitInfo& rec, vec3& color, Ray & r_out) const;
};
