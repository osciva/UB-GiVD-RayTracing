#ifndef MATERIALTEXTURA_HH
#define MATERIALTEXTURA_HH

#include "Texture.hh"
#include "Material.hh"

class MaterialTextura: public Material {
public:
    MaterialTextura();
    MaterialTextura(vec3 a, vec3 d, vec3 s, float o, int sh);
    virtual ~MaterialTextura();

    virtual bool scatter(const Ray& r_in, const HitInfo& rec, vec3& color, Ray & r_out) const override;
    vec3 getDiffuse(vec2 point) const override;

    virtual void read (const QJsonObject &json);
    Texture *image;
};

#endif // MATERIALTEXTURA_HH
