#include "CellShadow.hh"


vec3 CellShadow::shading(shared_ptr<Scene> scene, HitInfo& info, vec3 lookFrom, vector<shared_ptr<Light>> lights, vec3 globalLight) {
    vec3 intensity = vec3(0,0,0);
    vec3 L, N, V, H;
    float dotNL;

    N = normalize(info.normal); /* Vector de la normal al punt */
    V = normalize(lookFrom - info.p); /* Vector del punt de la superfície a l'observador */
    H = normalize(L+V); /* Vector mig entre la View i la llum */

    for (int i = 0; i < (int)lights.size(); i++) {
        L = normalize(lights[i]->vectorL(info.p)); /* Vector del punt de la superfície a la llum */
        dotNL = glm::dot(N,L); /* Intensitat */

        /* Les diferents intensitats estipulades a les diapositives */
        if (dotNL > 0.95) {
            intensity += vec3(1.0, 0.5, 0.5) * lights[i]->getId();
        } else if (dotNL > 0.5) {
            intensity += vec3(0.6, 0.3, 0.3) * lights[i]->getId();
        } else if (dotNL > 0.25) {
            intensity += vec3(0.4, 0.2, 0.2) * lights[i]->getId();
        } else {
            intensity += vec3(0.2, 0.1, 0.1) * lights[i]->getId();
        }
        /* Càlcul del factor d'ombra */
        float shadowFactor = computeShadow(scene, lights[i], info.p);

        intensity *= shadowFactor;
    }
    return intensity;
}

float CellShadow::computeShadow(shared_ptr<Scene> scene, shared_ptr<Light> light, vec3 point) {
    vec3 l;
    l = normalize(light->vectorL(point));
    point = point + (vec3(DBL_EPSILON,DBL_EPSILON,DBL_EPSILON)*l);
    Ray p_llum(point, l);
    HitInfo info;
    if(scene->hit(p_llum, 0.001, numeric_limits<float>::infinity(), info)){
        return 0;
    }
    return 1;
}

