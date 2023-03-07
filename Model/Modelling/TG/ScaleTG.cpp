#include "ScaleTG.hh"

ScaleTG::ScaleTG(glm::vec3 s) : scale(s)
{
    matTG = glm::scale(glm::mat4(1.0f), scale);
}

ScaleTG::~ScaleTG()
{

}
