#include "ColorShadow.hh"

vec3 ColorShadow::shading(shared_ptr<Scene> scene, HitInfo& info, vec3 lookFrom, vector<shared_ptr<Light>> lights, vec3 globalLight) {
    //I = kaIa (ambient) + kdId cos( ⃗ L , ⃗ N ) (difosa) + ksIs cos( ⃗ N , ⃗ H)β (especular)
    vec3 color = info.mat_ptr->Kd;
    vec3 total = vec3(0,0,0);
    vec3 diffuse, ambient;
    vec3 ka = info.mat_ptr->Ka; /* Component ambient */
    vec3 kd = info.mat_ptr->Kd; /* Component difusa */
    vec3 ia = vec3(0, 0, 0);

    // Suma de la iluminación ambiental global
    vec3 ambientGl = globalLight * ka;
    total += ambientGl;

    // Cálculo de la iluminación de cada fuente de luz
    for (int i = 0; i < (int)lights.size(); i++) {
        vec3 L = normalize(lights[i]->vectorL(info.p)); /* Vector del punt de la superfície a la llum */
        vec3 H = normalize((L + normalize(lookFrom - info.p)) / 2.0f); /* Vector del punt de la superfície al mig entre L i V */
        ia = lights[i]->getIa(); /* Intensitat ambient de la llum */
        vec3 id = lights[i]->getId(); /* Intensitat difosa de la llum */
        vec3 is = lights[i]->getIs(); /* Intensitat especular de la llum */

        // Cálculo del factor de sombra
        float shadowFactor = computeShadow(scene, lights[i], info.p);

        // Cálculo de la iluminación difusa y especular
        diffuse = id * kd * glm::max(dot(L, info.normal), 0.0f);
        vec3 specular = is * info.mat_ptr->Ks * pow(glm::max(dot(info.normal, H), 0.0f), info.mat_ptr->shininess);

        // Aplicación del factor de sombra
        color *= shadowFactor;

        // Acumulación de la iluminación
        total += color;
    }

    return total;
 }

float ColorShadow::computeShadow(shared_ptr<Scene> scene, shared_ptr<Light> light, vec3 point) {
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

