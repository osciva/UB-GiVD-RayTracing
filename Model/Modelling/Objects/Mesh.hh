#pragma once

#include <vector>
#include <string>
#include <limits>

#include <QString>
#include <QFile>
#include <QRegularExpression>


#include <iostream>
#include <stdlib.h>
#include <cstring>

#include "Object.hh"
#include "Face.hh"
#include "Triangle.hh"
#include "Box.hh"
#include "Sphere.hh"

using namespace std;
using namespace glm;

class Mesh : public Object
{
public:
    Mesh() {}
    Mesh(const QString &fileName);
    Mesh(const QString &fileName, float data);
    virtual bool hit( Ray& r, float tmin, float tmax, HitInfo& info) const override;


    virtual void aplicaTG(shared_ptr<TG> tg) override;

    virtual void read (const QJsonObject &json) override;
    virtual void write(QJsonObject &json) const override;
    virtual void print(int indentation) const override;

    virtual ~Mesh();
private:

    QString nom;
    vec3 centre;
    vector<Face> cares; /* Faces de l'objecte */
    vector<vec4> vertexs; /* Vertexs de l'objecte sense repetits */
    vector<Triangle> triangles;

    void load(QString filename);
    void makeTriangles();
    void makeBoundingSphere();
    Box* box;
    Sphere* sphere;
};

