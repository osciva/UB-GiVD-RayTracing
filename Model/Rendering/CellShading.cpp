#include "CellShading.hh"

vec3 CellShading::shading(shared_ptr<Scene> scene, HitInfo& info, vec3 lookFrom, vector<shared_ptr<Light>> lights, vec3 globalLight) {
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
    }
    return intensity;
}
