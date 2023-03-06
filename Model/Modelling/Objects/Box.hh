/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#pragma once

#include "Object.hh"
#include "Model/Modelling/Animation.hh"
#include "Model/Modelling/TG/TranslateTG.hh"

class Box: public Object  {
public:
    Box();

    Box(vec3 min, vec3 max, float data);
    //Crea un box unitari amb min al punt (0,0,0) i max al punt (1,1,1)
    Box(float data);
    virtual ~Box() {}
    virtual bool hit(Ray& r, float tmin, float tmax, HitInfo& info) const override;
    vec3 getNormal(const vec3& point) const;
    virtual void aplicaTG(shared_ptr<TG> tg) override;

    virtual void read (const QJsonObject &json) override;
    virtual void write(QJsonObject &json) const override;
    virtual void print(int indentation) const override;


    vec3  getMin() { return punt_min;};
    vec3 getMax() { return punt_max;}

private:
    // Vèrtex mínim del box
    vec3 punt_min;
    // Vèrtex màxim del box
    vec3 punt_max;
};





