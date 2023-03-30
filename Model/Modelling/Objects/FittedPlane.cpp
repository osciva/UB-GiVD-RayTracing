#include "FittedPlane.hh"

FittedPlane::FittedPlane(vec3 normal, vec3 pass_point, vec2 pass_min, vec2 pass_max, float d) : Plane(normal, pass_point, d) {
    this->minpoint = pass_min;
    this->maxpoint = pass_max;
}

bool FittedPlane::hit(Ray &r, float t_min, float t_max, HitInfo &info) const {
    if (Plane::hit(r, t_min, t_max, info)){
        float u = (info.p.x - this->minpoint.x) / (this->maxpoint.x - this->minpoint.x);
        float v = (info.p.z - this->minpoint.y) / (this->maxpoint.y - this->minpoint.y);
        vec2 uv = glm::clamp(vec2(u, v), vec2(0.0f), vec2(1.0f));
        if (uv.x <= 0 || uv.x >= 1 || uv.y <= 0 || uv.y >= 1) {
            return false;
        }
        info.uv = uv;
        return true;
    }
    return false;
}




void FittedPlane::aplicaTG(shared_ptr<TG> tg) {
    if (dynamic_pointer_cast<TranslateTG>(tg)) {
        /* Movem el punt de pas del pla */
        vec4 c(point, 1.0);
        c = tg->getTG() * c;
        point.x = c.x;
        point.y = c.y;
        point.z = c.z;
    }

    if(dynamic_pointer_cast<ScaleTG>(tg)) {
        /* Considerem la y del minpoint i maxpoint com la component z, i usem
        *  un vec2 per definir la x min/max i la z min/max.
        */
        vec4 cmin(minpoint.x, 1.0, minpoint.y, 1.0);
        vec4 cmax(maxpoint.x, 1.0, maxpoint.y, 1.0);

        cmin = tg->getTG() * cmin;
        cmax = tg->getTG() * cmax;

        minpoint.x *= cmin.x;
        minpoint.y *= cmin.z;

        maxpoint.x *= cmax.x;
        maxpoint.y *= cmax.z;
    }
}

void FittedPlane::read (const QJsonObject &json)
{
    Plane::read(json);

    if (json.contains("pmin") && json["pmin"].isArray()) {
        QJsonArray auxVec = json["pmin"].toArray();
        minpoint.x = auxVec[0].toDouble();
        minpoint.y = auxVec[1].toDouble();
    }
    if (json.contains("pmax") && json["pmax"].isArray()) {
        QJsonArray auxVec = json["pmax"].toArray();
        maxpoint.x = auxVec[0].toDouble();
        maxpoint.y = auxVec[1].toDouble();
    }
}

void FittedPlane::write(QJsonObject &json) const
{
    Plane::write(json);

    QJsonArray min, max;
    min.append(this->minpoint[0]); min.append(this->minpoint[1]);
    max.append(this->maxpoint[0]); max.append(this->maxpoint[1]);

    json["pmin"] = min;
    json["pmax"] = max;
}


void FittedPlane::print(int indentation) const
{
    Plane::print(indentation);
}
