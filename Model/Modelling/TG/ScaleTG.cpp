#include "ScaleTG.hh"

ScaleTG::ScaleTG(vec3 scale) : scalation(scale)
{
    matTG = glm::scale(glm::mat4(1.0f), scale);
}

ScaleTG::ScaleTG(float esc) {
    escala = esc;
    matTG = glm::scale(glm::mat4(1.0f), vec3(esc, esc, esc));
}

ScaleTG::~ScaleTG()
{

}
