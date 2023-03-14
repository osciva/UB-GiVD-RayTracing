#ifndef FITTEDPLANE_HH
#define FITTEDPLANE_HH

#include "Plane.hh"
#include "Model/Modelling/Animation.hh"
#include "Model/Modelling/TG/TranslateTG.hh"
#include "Model/Modelling/TG/ScaleTG.hh"

class FittedPlane: public Plane {
public:
    FittedPlane() {}
    FittedPlane(vec3 normal, vec3 pass_point, vec2 pass_min, vec2 pass_max, float d);
    virtual ~FittedPlane(){}
    virtual bool hit(Ray &r, float t_min, float t_max, HitInfo &info) const;
    virtual void aplicaTG(shared_ptr<TG> tg);

    virtual void read (const QJsonObject &json) override;
    virtual void write(QJsonObject &json) const override;
    virtual void print(int indentation) const override;

    vec3 point;
private:
    vec3 normal;

    vec2 minpoint;
    vec2 maxpoint;
};

#endif // FITTEDPLANE_HH
