#include "PhongShading.hh"

vec3 PhongShading::shading(shared_ptr<Scene> scene, HitInfo& info, vec3 lookFrom, vector<shared_ptr<Light>> lights, vec3 globalLight) {
    //I = kaIa (ambient) + kdId cos( ⃗ L , ⃗ N ) (difosa) + ksIs cos( ⃗V, ⃗R)α (especular)

    vec3 total = vec3(0,0,0);
    vec3 diffuse, specular, R, L, V, ia, id, is, ka, kd, ks, N, ambient;
    float alpha, factor, dist;
    vec3 ambientGl = globalLight * info.mat_ptr->Ka;

    ka = info.mat_ptr->Ka; /* Component ambient */
    kd = info.mat_ptr->Kd; /* Component difusa */
    ks = info.mat_ptr->Ks; /* Component especualr */

    V = normalize(lookFrom-info.p); /* Vector del punt de la superfície a l'observador */
    alpha = info.mat_ptr->shininess; /* Exponent de reflexió especular */
    N = normalize(info.normal); /* Vector de la normal al punt */

    for (int i = 0; i < (int)lights.size(); i++) {
        L = normalize(lights[i]->vectorL(info.p)); /* Vector del punt de la superfície a la llum */
        R = reflect(-L, N); /* R = 2 * N * (dot(N, L)) - L; */
        ia = lights[i]->getIa(); /* Intensitat ambient de la llum */
        id = lights[i]->getId(); /* Intensitat difosa de la llum */
        is = lights[i]->getIs(); /* Intensitat especular de la llum */

        diffuse = id * info.mat_ptr->getDiffuse(info.uv) * glm::max(dot(L,N), 0.0f);
        specular = is * ks * pow(glm::max(dot(R, V), 0.0f), alpha);
        ambient = ia * ka;

        total += ((diffuse+specular) * lights[i]->attenuation(info.p)) + ambient;
    }

    return total + ambientGl;
}
