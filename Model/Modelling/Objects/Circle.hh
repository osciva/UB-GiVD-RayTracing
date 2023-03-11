#ifndef CIRCLE_HH
#define CIRCLE_HH

#include "math.h"
#include "Plane.hh"
#include "Model/Modelling/Animation.hh"
#include "Model/Modelling/TG/TranslateTG.hh"

class Circle: public Plane {
public:
    Circle(vec3 normal, vec3 pass_point, float radius);

    virtual ~Circle() {}

    virtual bool hit(Ray& r, float t_min, float t_max, HitInfo& info) const override;
    virtual void aplicaTG(shared_ptr<TG> tg) override;
    float getCenterY();
    void setCenterY(float centery);

private:
    vec3 normal;
    vec3 center;
    float radius;
};

#endif // CIRCLE_HH
