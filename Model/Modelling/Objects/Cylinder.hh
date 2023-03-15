#ifndef CYLINDER_HH
#define CYLINDER_HH

#include "math.h"
#include "Object.hh"
#include "Circle.hh"
#include "Model/Modelling/Animation.hh"
#include "Model/Modelling/TG/TranslateTG.hh"
#include "Model/Modelling/TG/TG.hh"

class Cylinder: public Object {
public:
    Cylinder();
    Cylinder(vec3 center, float radi, float height, float data);

    /* Crea un cilindre unitari */
    Cylinder(float data);
    virtual ~Cylinder();
    virtual bool hit(Ray& r, float tmin, float tmax, HitInfo& info) const override;
    bool cylinderHit(Ray& r, float tmin, float tmax, HitInfo& info) const;
    virtual void aplicaTG(shared_ptr<TG> tg) override;

    virtual void read (const QJsonObject &json) override;
    virtual void write(QJsonObject &json) const override;
    virtual void print(int indentation) const override;

private:
    /* Centre de la base del cilindre */
    vec3 center;

    /* Radi del cilindre */
    float radi;

    /* Alçada del cilindre */
    float height;

    /* Tapa de d'alt del cilindre */
    Circle *top1;

    /* Tapa d'abaix del cilindre */
    Circle *top2;

    /* Vector normal tapa de d'alt */
    vec3 n1;

    /* Vector normal tapa d'abaix */
    vec3 n2;
};

#endif // CYLINDER_HH
