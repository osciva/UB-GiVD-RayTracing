#include "BlinnPhongShadowShading.hh"

vec3 BlinnPhongShadowShading::shading(shared_ptr<Scene> scene, HitInfo& info, vec3 lookFrom, vector<shared_ptr<Light>> lights, vec3 globalLight) {
    //I = kaIa (ambient) + kdId cos( ⃗ L , ⃗ N ) (difosa) + ksIs cos( ⃗ N , ⃗ H)β (especular)

    vec3 total = vec3(0,0,0);
    vec3 diffuse, specular, H, L, V, ia, id, is, ka, kd, ks, N, ambient;
    float beta, factor, dist, factorOmbra;;
    vec3 ambientGl = globalLight * info.mat_ptr->Ka;

    ka = info.mat_ptr->Ka; /* Component ambient */
    kd = info.mat_ptr->Kd; /* Component difusa */
    ks = info.mat_ptr->Ks; /* Component especualr */

    V = normalize(lookFrom-info.p); /* Vector del punt de la superfície a l'observador */
    beta = info.mat_ptr->shininess;
    N = normalize(info.normal); /* Vector de la normal al punt */

    for (int i = 0; i < (int)lights.size(); i++) {
        L = normalize(lights[i]->vectorL(info.p)); /* Vector del punt de la superfície a la llum */
        H = normalize((L+V)/normalize(L+V)); /* Vector mig normalitzat entre L i V (L i V normalitzats) */
        ia = lights[i]->getIa(); /* Intensitat ambient de la llum */
        id = lights[i]->getId(); /* Intensitat difosa de la llum */
        is = lights[i]->getIs(); /* Intensitat especular de la llum */

        dist = lights[i]->distanceToLight(info.p); /* Distància de la superfície al focus de llum */
        factor = 0.5 + 0.01 * pow(dist, 2); /* Coeficient d'atenuació */

        diffuse = id * info.mat_ptr->getDiffuse(info.uv) * glm::max(dot(L,N), 0.0f);
        specular = is * ks * pow(glm::max(dot(N, H), 0.0f), beta);
        ambient = ia * ka;
        factorOmbra = this->computeShadow(scene, lights[i], info.p);
        total += (factorOmbra*((diffuse+specular)/factor)) + ambient;
    }

    return total + ambientGl;
}

float BlinnPhongShadowShading::computeShadow(shared_ptr<Scene> scene, shared_ptr<Light> light, vec3 point) {
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

