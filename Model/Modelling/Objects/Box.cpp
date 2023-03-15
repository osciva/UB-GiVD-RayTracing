#include "Box.hh"
#include <glm/glm.hpp>

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
    boxCenter = (punt_min+punt_max) / 2.f;
}

bool Box::hit(Ray& ray, float t_min, float t_max, HitInfo& info) const {
    // Calculate the inverse direction of the ray
    glm::vec3 inv_dir = 1.0f / ray.getDirection();

    // Calculate the sign of the inverse direction
    glm::ivec3 sign = glm::ivec3(inv_dir.x < 0, inv_dir.y < 0, inv_dir.z < 0);

    // Calculate the minimum and maximum values of t for each face of the box
    glm::vec3 t_min_box = (punt_min - ray.getOrigin()) * inv_dir;
    glm::vec3 t_max_box = (punt_max - ray.getOrigin()) * inv_dir;

    // Calculate the minimum and maximum values of t for the box
    float t_enter = glm::max(glm::max(glm::min(t_min_box.x, t_max_box.x), glm::min(t_min_box.y, t_max_box.y)), glm::min(t_min_box.z, t_max_box.z));
    float t_exit = glm::min(glm::min(glm::max(t_min_box.x, t_max_box.x), glm::max(t_min_box.y, t_max_box.y)), glm::max(t_min_box.z, t_max_box.z));

    // Check if the ray hits the box
    if (t_enter <= t_exit && t_exit >= t_min && t_enter <= t_max) {
        // Calculate the hit point and normal
        glm::vec3 hit_point = ray.getOrigin() + t_enter * ray.getDirection();
        glm::vec3 normal;
        if (hit_point.x <= punt_min.x + DBL_EPSILON) normal = -glm::vec3(1, 0, 0);
        else if (hit_point.x >= punt_max.x - DBL_EPSILON) normal = glm::vec3(1, 0, 0);
        else if (hit_point.y <= punt_min.y + DBL_EPSILON) normal = -glm::vec3(0, 1, 0);
        else if (hit_point.y >= punt_max.y - DBL_EPSILON) normal = glm::vec3(0, 1, 0);
        else if (hit_point.z <= punt_min.z + DBL_EPSILON) normal = -glm::vec3(0, 0, 1);
        else if (hit_point.z >= punt_max.z - DBL_EPSILON) normal = glm::vec3(0, 0, 1);

        // Set the hit info
        info.t = t_enter;
        info.p = hit_point;
        info.normal = normal;
        info.mat_ptr = material.get();

        return true;
    }
    return false;
}

void Box::aplicaTG(shared_ptr<TG> t) {
    if (dynamic_pointer_cast<TranslateTG>(t)) {
        // Per ara només es fan les translacions
        vec4 c(boxCenter, 1.0);
        c = t->getTG() * c;
        vec3 translation = dynamic_pointer_cast<TranslateTG>(t)->traslation;
        punt_min += translation;
        punt_max += translation;
        boxCenter = (punt_min+punt_max) / 2.f;
    }

    if (dynamic_pointer_cast<ScaleTG>(t)) {
        vec3 scale = dynamic_pointer_cast<ScaleTG>(t)->scalation;
        vec3 center = (punt_min+punt_max) / 2.0f;
        vec3 half_size = (punt_min-punt_max) / 2.0f;
        vec3 scaled_half_size = vec3(half_size.x*scale.x, half_size.y*scale.y, half_size.z*scale.z);
        punt_min = center-scaled_half_size;
        punt_max = center+scaled_half_size;
        boxCenter = (punt_min+punt_max) / 2.f;
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