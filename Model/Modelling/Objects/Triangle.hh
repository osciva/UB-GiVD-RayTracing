#ifndef TRIANGLE_HH
#define TRIANGLE_HH

#include <iostream>
#include <vector>
#include "Plane.hh"
#include "Object.hh"
#include "Model/Modelling/Animation.hh"
#include "Model/Modelling/TG/TranslateTG.hh"
#include "Model/Modelling/TG/ScaleTG.hh"

using namespace std;

class Triangle: public Object {
public:
    Triangle();

    Triangle(vec3 A, vec3 B, vec3 C, float data);

    /* Crea un triangle unitari */
    Triangle(float data);

    virtual ~Triangle() {}
    virtual bool hit(Ray& r, float tmin, float tmax, HitInfo& info) const override;
    virtual void aplicaTG(shared_ptr<TG> tg) override;

    void setPlane();

    virtual void read (const QJsonObject &json) override;
    virtual void write(QJsonObject &json) const override;
    virtual void print(int indentation) const override;

    //vec3 getA() {return A;}
    //vec3 getB() {return B;}
    //vec3 getC() {return C;}
    //vector<vec3> getVertexs() {return vertexs;}

private:
    /* Vector de vertexs del triangle */
    vector<vec3> vertexs;

    /* Punts dels vertexs del triangle */
    vec3 A, B, C;

    /* Normal del pla del triangle */
    vec3 normal;

    /* Pla del triangle */
    Plane plane;
};

#endif // TRIANGLE_HH
