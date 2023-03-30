#include "NormalShadow.hh"

vec3 NormalShadow::shading(shared_ptr<Scene> scene, HitInfo& info, vec3 lookFrom, vector<shared_ptr<Light>> lights, vec3 globalLight) {
    //I = kaIa (ambient) + kdId cos( ⃗ L , ⃗ N ) (difosa) + ksIs cos( ⃗ N , ⃗ H)β (especular)
    vec3 N = normalize(info.normal);
    vec3 color = 0.5f * (N + vec3(1.0));
    vec3 total = vec3(0,0,0);
    vec3 diffuse, ambient;
    vec3 ka = info.mat_ptr->Ka; /* Component ambient */
    vec3 kd = info.mat_ptr->Kd; /* Component difusa */
    vec3 ia = vec3(0, 0, 0);

    /* Suma de la iluminació ambiental global */
    vec3 ambientGl = globalLight * ka;
    total += ambientGl;

    /* Càlcul de la iluminaci de cada font de llum */
    for (int i = 0; i < (int)lights.size(); i++) {
        vec3 L = normalize(lights[i]->vectorL(info.p)); /* Vector del punt de la superfície a la llum */
        vec3 H = normalize((L + normalize(lookFrom - info.p)) / 2.0f); /* Vector del punt de la superfície al mig entre L i V */
        ia = lights[i]->getIa(); /* Intensitat ambient de la llum */
        vec3 id = lights[i]->getId(); /* Intensitat difosa de la llum */
        vec3 is = lights[i]->getIs(); /* Intensitat especular de la llum */

        /* Càlcul del factor d'ombra */
        float shadowFactor = computeShadow(scene, lights[i], info.p);

        /* Càlcul de la iluminació difosa i especular */
        diffuse = id * kd * glm::max(dot(L, info.normal), 0.0f);
        vec3 specular = is * info.mat_ptr->Ks * pow(glm::max(dot(info.normal, H), 0.0f), info.mat_ptr->shininess);

        /* Aplicació del factor d'ombra */
        color *= shadowFactor;

        /* Acumulació de la iluminació */
        total += color;
    }

    return total;
 }

float NormalShadow::computeShadow(shared_ptr<Scene> scene, shared_ptr<Light> light, vec3 point) {
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


