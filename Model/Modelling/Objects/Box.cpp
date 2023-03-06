#include "Box.hh"
#include <glm/glm.hpp>

const float EPSILON = 0.0001f;

Box::Box() {
    punt_min = vec3(-2,-2,2);
    punt_max = vec3(-5,-1,5);
}

Box::Box(vec3 min, vec3 max, float data) :Object(data) {
    punt_min=min;
    punt_max=max;
}

Box::Box(float data) :Object(data) {
    punt_min = vec3(-2,-2,2);
    punt_max = vec3(-5,-1,5);
}

bool Box::hit(Ray& ray, float tmin, float tmax, HitInfo& info) const {
    // Calculate inverse direction of the ray to avoid division by zero
    vec3 invDir = 1.0f / ray.getDirection();

    vec3 tMin = (punt_min - ray.getOrigin()) * invDir;
    vec3 tMax = (punt_max - ray.getOrigin()) * invDir;

    vec3 t1 = glm::min(tMin, tMax);
    vec3 t2 = glm::max(tMin, tMax);

    float tNear = glm::max(glm::max(t1.x, t1.y), t1.z);
    float tFar = glm::min(glm::min(t2.x, t2.y), t2.z);

    if (tNear > tFar || tFar < tmin || tNear > tmax) {
        return false;
    }

    // Calculate intersection point and normal
    info.t = tNear;
    info.normal = getNormal(ray.pointAtParameter(info.t));
    info.mat_ptr = material.get();
    info.p = ray.pointAtParameter(info.t);

    return true;
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
    /*if (dynamic_pointer_cast<TranslateTG>(t)) {
        // Per ara només es fan les translacions
        vec4 c(center, 1.0);
        c = t->getTG() * c;
        center.x = c.x; center.y = c.y; center.z = c.z;
    }
    //TODO: Cal ampliar-lo per a acceptar Escalats
    */
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

