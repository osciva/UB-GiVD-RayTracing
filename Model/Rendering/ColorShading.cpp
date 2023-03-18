#include "ColorShading.hh"

vec3 ColorShading::shading(shared_ptr<Scene> scene, HitInfo& info, vec3 lookFrom, vector<shared_ptr<Light>> lights, vec3 globalLight) {
    return info.mat_ptr->Kd;
}
