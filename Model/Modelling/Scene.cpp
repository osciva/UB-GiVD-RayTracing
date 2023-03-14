#include "Scene.hh"

Scene::Scene()
{
    pmin.x = -0.5f;  pmin.y = -0.5f; pmin.z = -0.5f;
    pmax.x = 0.5f;  pmax.y = 0.5f; pmax.z = 0.5f;
}


bool Scene::hit(Ray &raig, float tmin, float tmax, HitInfo& info) const {
    // TODO FASE 0 i FASE 1:
    // Heu de codificar la vostra solucio per aquest metode substituint el 'return true'
    // Una possible solucio es cridar el mètode "hit" per a tots els objectes i quedar-se amb la interseccio
    // mes propera a l'observador, en el cas que n'hi hagi més d'una.
    // Si un objecte es intersecat pel raig, el parametre  de tipus HitInfo conte
    // la informació sobre la interseccio.
    // Cada vegada que s'intersecta un objecte s'ha d'actualitzar el HitInfo del raig.

    bool hit_sth = false;
    float closest_so_far = tmax;
    HitInfo temp_info;

    /* Hit del pla base o el "terra" */
    if(basePlane && basePlane->hit(raig, tmin, tmax, temp_info)) {
        hit_sth = true;

        if(temp_info.t < closest_so_far) {
            closest_so_far = temp_info.t;
            info = temp_info;
        }
    }

    for(const auto& object: objects){

        /* Crida al mètode hit de cada objecte. Si hi ha hit entre els valors de tmin y tmax, i
           està més a prop que cap altre hit trobat, l'informació de HitInfo s'actualitza. */
        if(object->hit(raig, tmin, closest_so_far, temp_info)) {
            hit_sth = true;

            if(temp_info.t < closest_so_far) {
                closest_so_far = temp_info.t;
                info = temp_info;
            }
        }
    }

    /* True si al menys un objecte en l'escena es tocat per un raig, sinó retorna false. */
    return hit_sth;
}


void Scene::update(int nframe) {
    for (unsigned int i = 0; i< objects.size(); i++) {
        objects[i]->update(nframe);
    }
}

void Scene::setDimensions(vec3 p1, vec3 p2) {
    pmin = p1;
    pmax = p2;
}

