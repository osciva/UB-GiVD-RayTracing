#include "BlinnPhongShading.hh"

vec3 BlinnPhongShading::shading(shared_ptr<Scene> scene, HitInfo& info, vec3 lookFrom) {
    //I = kaIa + kdId cos( ⃗ L , ⃗ N ) + ksIs cos( ⃗ N , ⃗ H)β ⃗
    vec3 ka = info.mat_ptr->Ka;
    vec3 kd = info.mat_ptr->Kd;
    vec3 ks = info.mat_ptr->Ks;

    return vec3(0.0,0.0,0.0);
}
