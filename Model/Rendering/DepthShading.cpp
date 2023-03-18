#include "DepthShading.hh"
#include <stdio.h>

vec3 DepthShading::shading(shared_ptr<Scene> scene, HitInfo& info, vec3 lookFrom, vector<shared_ptr<Light>> lights, vec3 globalLight) {
    float distance = length(lookFrom - info.p); // calcula la distancia desde el centro de la esfera hasta el punto de intersección
    float maxDistance = length(lookFrom - vec3(0,0,0)); // obtiene la distancia máxima de renderización
    float normalizedDistance = distance / maxDistance; // normaliza la distancia en función de la distancia máxima
    vec3 color = vec3(normalizedDistance); // crea un vector RGB con los mismos valores de gris
    return color;
}

