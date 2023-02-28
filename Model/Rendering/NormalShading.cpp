#include "NormalShading.hh"

vec3 NormalShading::shading(shared_ptr<Scene> scene, HitInfo& info, vec3 lookFrom) {
    vec3 N = normalize(info.normal);
    vec3 color = 0.5f * (N + vec3(1.0));
    return color;
}
