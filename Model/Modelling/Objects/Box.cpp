#include "Box.hh"

Box::Box() {
    punt_min=vec3(0.0,0.0,0.0);
    punt_max=vec3(0.0,0.0,0.0);
}

Box::Box(vec3 min, vec3 max, float data) :Object(data) {
    punt_min=min;
    punt_max=max;
}

Box::Box(float data) :Object(data) {
    punt_min = vec3(0,0,0);
    punt_max = vec3(1,1,1);
}

bool Box::hit(Ray &raig, float tmin, float tmax, HitInfo& info) const {
    vec3 oc = raig.getOrigin() - center;
    float a = dot(raig.getDirection(), raig.getDirection());
    float b = dot(oc, raig.getDirection());
    float c = dot(oc, oc) - radius*radius;
    float discriminant = b*b - a*c;
    if (discriminant > 0) {
        float temp = (-b - sqrt(discriminant))/a;
        if (temp < tmax && temp > tmin) {
            info.t = temp;
            info.p = raig.pointAtParameter(info.t);
            info.normal = (info.p - center) / radius;
            info.mat_ptr = material.get();
            // TODO Fase 3: Cal calcular les coordenades de textura

            return true;
        }
        temp = (-b + sqrt(discriminant)) / a;
        if (temp < tmax && temp > tmin) {
            info.t = temp;
            info.p = raig.pointAtParameter(info.t);
            info.normal = (info.p - center) / radius;
            info.mat_ptr = material.get();
            // TODO Fase 3: Cal calcular les coordenades de textura

            return true;
        }
    }
    return false;
}


void Box::aplicaTG(shared_ptr<TG> t) {
    if (dynamic_pointer_cast<TranslateTG>(t)) {
        // Per ara només es fan les translacions
        vec4 c(center, 1.0);
        c = t->getTG() * c;
        center.x = c.x; center.y = c.y; center.z = c.z;
    }
    //TODO: Cal ampliar-lo per a acceptar Escalats

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

