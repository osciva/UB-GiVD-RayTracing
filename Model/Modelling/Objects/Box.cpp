#include "Box.hh"
#include <glm/glm.hpp>

const float EPSILON = 0.0001f;

Box::Box() {
    punt_min = vec3(-1,-1,-1);
    punt_max = vec3(1,1,1);

    boxCenter = (punt_min+punt_max) / 2.f;
}

Box::Box(vec3 min, vec3 max, float data) :Object(data) {
    punt_min=min;
    punt_max=max;
    boxCenter = (min+max) / 2.f;
}

Box::Box(float data) :Object(data) {
    punt_min = vec3(-1,-1,-1);
    punt_max = vec3(1,1,1);
}

bool Box::hit(Ray& ray, float t_min, float t_max, HitInfo& info) const {
    /* Algoritme extret de: https://is.gd/LKGNN9 */
    float tmin, tmax;
    tmin = (punt_min.x - ray.getOrigin().x) / ray.getDirection().x;
    tmax = (punt_max.x - ray.getOrigin().x) / ray.getDirection().x;

    if(tmin > tmax) swap(tmin, tmax);

    float tymin = (punt_min.y - ray.getOrigin().y) / ray.getDirection().y;
    float tymax = (punt_max.y - ray.getOrigin().y) / ray.getDirection().y;

    if(tymin > tymax) swap(tymin, tymax);

    if ((tmin > tymax) || (tymin > tmax))
        return false;

    if (tymin > tmin)
        tmin = tymin;

    if (tymax < tmax)
        tmax = tymax;

    float tzmin = (punt_min.z - ray.getOrigin().z) / ray.getDirection().z;
    float tzmax = (punt_max.z - ray.getOrigin().z) / ray.getDirection().z;

    if (tzmin > tzmax) swap(tzmin, tzmax);

    if ((tmin > tzmax) || (tzmin > tmax))
        return false;

    if (tzmin > tmin)
        tmin = tzmin;

    if (tzmax < tmax)
        tmax = tzmax;

    if(tmin > t_min && tmax < t_max){
        info.t = tmin;
        info.p = ray.getOrigin() + (ray.getDirection() * tmin);
        info.mat_ptr = material.get();

        vec3 closest_normal;
        float min_dist = numeric_limits<float>::max();

        /* Check the intersection with each face of the box */
        if(equals(info.p.x, punt_max.x, DBL_EPSILON)){
            vec3 normal(1, 0, 0);
            float dist = length(info.p - vec3(punt_max.x, (punt_min.y + punt_max.y) / 2.0f, (punt_min.z + punt_max.z) / 2.0f));
            if(dist < min_dist){
                closest_normal = normal;
                min_dist = dist;
            }
        }

        if(equals(info.p.y, punt_max.y, DBL_EPSILON)){
            vec3 normal(0, 1, 0);
            float dist = length(info.p - vec3((punt_min.x + punt_max.x) / 2.0f, punt_max.y, (punt_min.z + punt_max.z) / 2.0f));
            if(dist < min_dist){
                closest_normal = normal;
                min_dist = dist;
            }
        }

        if(equals(info.p.z, punt_max.z, DBL_EPSILON)){
            vec3 normal(0, 0, 1);
            float dist = length(info.p - vec3((punt_min.x + punt_max.x) / 2.0f, (punt_min.y + punt_max.y) / 2.0f, punt_max.z));
            if(dist < min_dist){
                closest_normal = normal;
                min_dist = dist;
            }
        }

        if(equals(info.p.x, punt_min.x, DBL_EPSILON)){
            vec3 normal(-1, 0, 0);
            float dist = length(info.p - vec3(punt_min.x, (punt_min.y + punt_max.y) / 2.0f, (punt_min.z + punt_max.z) / 2.0f));
            if(dist < min_dist){
                closest_normal = normal;
                min_dist = dist;
            }
        }

        if(equals(info.p.y, punt_min.y, DBL_EPSILON)){
            vec3 normal(0, -1, 0);
            float dist = length(info.p - vec3((punt_min.x + punt_max.x) / 2.0f, punt_min.y, (punt_min.z + punt_max.z) / 2.0f));
            if(dist < min_dist){
                closest_normal = normal;
                min_dist = dist;
            }
        }

        if(equals(info.p.z, punt_min.z, DBL_EPSILON)){
            vec3 normal(0, 0, -1);
            float dist = length(info.p - vec3((punt_min.x + punt_max.x) / 2.0f, (punt_min.y + punt_max.y) / 2.0f, punt_min.z));
            if(dist < min_dist){
                closest_normal = normal;
                min_dist = dist;
            }
        }

        info.normal = closest_normal;

        return true;
    }

    return false;
}


// Calculate normal at intersection point
vec3 Box::getNormal(const vec3& point) const {
    // Find which face the intersection point is on
    if (abs(point.x - punt_min.x) < EPSILON) {
        return vec3(-1, 0, 0);
    }
    if (abs(point.x - punt_max.x) < EPSILON) {
        return vec3(1, 0, 0);
    }
    if (abs(point.y - punt_min.y) < EPSILON) {
        return vec3(0, -1, 0);
    }
    if (abs(point.y - punt_max.y) < EPSILON) {
        return vec3(0, 1, 0);
    }
    if (abs(point.z - punt_min.z) < EPSILON) {
        return vec3(0, 0, -1);
    }
    return vec3(0, 0, 1);
}



void Box::aplicaTG(shared_ptr<TG> t) {
    if (dynamic_pointer_cast<TranslateTG>(t)) {
        // Per ara només es fan les translacions
        vec4 c(boxCenter, 1.0);
        c = t->getTG() * c;
        boxCenter.x = c.x; boxCenter.y = c.y; boxCenter.z = c.z;
    }

    if (dynamic_pointer_cast<ScaleTG>(t)) {
        vec3 scale = dynamic_pointer_cast<ScaleTG>(t)->scalation;
        punt_min = (punt_min - boxCenter) * scale + boxCenter;
        punt_max = (punt_max - boxCenter) * scale + boxCenter;
    }

}

void Box::read (const QJsonObject &json)
{
    Object::read(json);

    if (json.contains("punt_min") && json["punt_min"].isArray()) {
        QJsonArray auxVec = json["punt_min"].toArray();
        punt_min[0] = auxVec[0].toDouble();
        punt_min[1] = auxVec[1].toDouble();
        punt_min[2] = auxVec[2].toDouble();
    }

    if (json.contains("punt_max") && json["punt_max"].isArray()) {
        QJsonArray auxVec = json["punt_max"].toArray();
        punt_max[0] = auxVec[0].toDouble();
        punt_max[1] = auxVec[1].toDouble();
        punt_max[2] = auxVec[2].toDouble();
    }
}


//! [1]
void Box::write(QJsonObject &json) const
{
    Object::write(json);

    QJsonArray auxArray;
    auxArray.append(punt_min[0]);auxArray.append(punt_min[1]);auxArray.append(punt_min[2]);
    json["punt_min"] = auxArray;

    auxArray.append(punt_max[0]);auxArray.append(punt_max[1]);auxArray.append(punt_max[2]);
    json["punt_max"] = auxArray;
}
//! [1]

void Box::print(int indentation) const
{
    Object::print(indentation);

    const QString indent(indentation * 2, ' ');

    QTextStream(stdout) << indent << "punt min:\t" << punt_min[0] << ", "<< punt_min[1] << ", "<< punt_min[2] << "\n";
    QTextStream(stdout) << indent << "punt max:\t" << punt_max[0] << ", "<< punt_max[1] << ", "<< punt_max[2] << "\n";
}

