#include "FittedPlane.hh"

FittedPlane::FittedPlane(vec3 normal, vec3 pass_point, vec2 pass_min, vec2 pass_max, float d) : Plane(normal, pass_point, d) {
    this->minpoint = pass_min;
    this->maxpoint = pass_max;
}

bool FittedPlane::hit(Ray &r, float t_min, float t_max, HitInfo &info) const {
    if(Plane::hit(r, t_min, t_max, info)) {
        if(info.p.x <= maxpoint.x && info.p.x >= minpoint.x && info.p.z <= maxpoint.y && info.p.z >= minpoint.y) {
            return true;
        }
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
