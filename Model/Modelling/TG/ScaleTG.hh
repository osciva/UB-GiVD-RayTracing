#ifndef SCALETG_H
#define SCALETG_H

#include "TG.hh"

class ScaleTG : public TG
{
public:
    glm::vec3 scale;
    ScaleTG(glm::vec3 s);
    virtual ~ScaleTG();
};

#endif // SCALETG_H
