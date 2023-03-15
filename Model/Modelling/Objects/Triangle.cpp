#include "Triangle.hh"

Triangle::Triangle() {
    this->A = vec3(1,0,0);
    this->B = vec3(0,1,0);
    this->C = vec3(0,0,1);

    vertexs = vector<vec3>();
    vertexs.push_back(A);
    vertexs.push_back(B);
    vertexs.push_back(C);

    //setPlane();
}

/* Crear un triangle a partir de 3 punts */
Triangle::Triangle(vec3 A, vec3 B, vec3 C, float data) : Object(data){
    vertexs = vector<vec3>();
    vertexs.push_back(A);
    vertexs.push_back(B);
    vertexs.push_back(C);
    normal = normalize(cross(B - A, C - A));

    setPlane();
}

/* Crear un triangle unitari */
Triangle::Triangle(float data) : Object(data){
    this->A = vec3(1,0,0);
    this->B = vec3(0,1,0);
    this->C = vec3(0,0,1);

    vertexs = vector<vec3>();
    vertexs.push_back(A);
    vertexs.push_back(B);
    vertexs.push_back(C);

    normal = normalize(cross(B - A, C - A));

    setPlane();

    //this->aplicaTG(new TranslateTG(cord));
}

bool Triangle::hit(Ray &r, float t_min, float t_max, HitInfo &info) const {

    float prod = dot(r.getDirection(), normal);

    /* Comprovem si el raig intersecta amb el pla que conté el triangle */
    if(plane.hit(r, t_min, t_max, info)){
        if(fabs(prod) < DBL_EPSILON){
            return false;
        }

        /* Per fer els càlculs seguirem la fòrmula i explicació de: https://is.gd/G9FyQn */
        /* Calculem la D, és a dir, la distància desde l'origen de coordenades fins el pla */
        float d = -dot(normal, vertexs[0]);

        /* t és la distància des de l'origen del raig fins al punt d'intersecció */
        float t_dist = -((d + dot(normal, r.getOrigin()))/prod);
        vec3 intersection = r.pointAtParameter(t_dist);

        /* Creem les arestes del triangle */
        float v1 = dot(cross((vertexs[1] - vertexs[0]), intersection - vertexs[0]), normal);
        float v2 = dot(cross((vertexs[2] - vertexs[1]), intersection - vertexs[1]), normal);
        float v3 = dot(cross((vertexs[0] - vertexs[2]), intersection - vertexs[2]), normal);

        /* Mirem si les arestes tenen el mateix signe per saber si la intersecció està dins del triangle */
        if((v1 < 0 && v2 < 0 && v3 < 0) || (v1 > 0 && v2 > 0 && v3 > 0)){
            /* Si la distància t calculada estpa dins del rang del raig -> actualitzem la info */
            if(t_min < t_dist && t_dist < t_max){
                info.t = t_dist;
                info.p = intersection;

                /* Si el raig incideix a la cara anterior */
                if(prod < 0){
                    info.normal = normal;
                }
                /* Si el raig incideix a la cara posterior */
                else {
                    info.normal = -normal;
                }

                info.mat_ptr = material.get();
                return true;
            }
            return false;
        } else {
            return false;
        }
    }
    return false;
}


void Triangle::aplicaTG(shared_ptr<TG> tg){
    vec4 v1(vertexs[0], 1.0);
    vec4 v2(vertexs[1], 1.0);
    vec4 v3(vertexs[2], 1.0);

    /* Desplacem vertexs */
    if (dynamic_pointer_cast<TranslateTG>(tg)) {
        v1 = tg->getTG() * v1;
        v2 = tg->getTG() * v2;
        v3 = tg->getTG() * v3;

        vertexs[0].x = v1.x; vertexs[0].y = v1.y; vertexs[0].z = v1.z;
        vertexs[1].x = v2.x; vertexs[1].y = v2.y; vertexs[1].z = v2.z;
        vertexs[2].x = v3.x; vertexs[2].y = v3.y; vertexs[2].z = v3.z;
    }

    /* Escalem els vertexs */
    if (dynamic_pointer_cast<ScaleTG>(tg)){
        v1 = tg->getTG() * v1;
        v2 = tg->getTG() * v2;
        v3 = tg->getTG() * v3;

        float factorA = vertexs[0].x/v1.x;
        float factorB = vertexs[1].x/v2.x;
        float factorC = vertexs[2].x/v3.x;

        vertexs[0] *= factorA; vertexs[0].y *= factorA; vertexs[0].z *= factorA;
        vertexs[1].x *= factorB; vertexs[1].y *= factorB; vertexs[1].z *= factorB;
        vertexs[2].x *= factorC; vertexs[2].y *= factorC; vertexs[2].z *= factorC;
    }
}

void Triangle::read(const QJsonObject &json){
    Object::read(json);

    if(json.contains("p1") && json["p1"].isArray()){
        QJsonArray auxVec = json["p1"].toArray();
        this->vertexs[0].x = auxVec[0].toDouble();
        this->vertexs[0].y = auxVec[1].toDouble();
        this->vertexs[0].z = auxVec[2].toDouble();
    }

    if(json.contains("p2") && json["p2"].isArray()){
        QJsonArray auxVec = json["p2"].toArray();
        this->vertexs[1].x = auxVec[0].toDouble();
        this->vertexs[1].y = auxVec[1].toDouble();
        this->vertexs[1].z = auxVec[2].toDouble();
    }

    if(json.contains("p3") && json["p3"].isArray()){
        QJsonArray auxVec = json["p3"].toArray();
        this->vertexs[2].x = auxVec[0].toDouble();
        this->vertexs[2].y = auxVec[1].toDouble();
        this->vertexs[2].z = auxVec[2].toDouble();
    }

    this->normal = normalize(cross(vertexs[1] - vertexs[0], vertexs[2] - vertexs[0]));
    setPlane();
}

void Triangle::write(QJsonObject &json) const {
    Object::write(json);
}

void Triangle::print(int indentation) const {
    Object::print(indentation);

    const QString indent(indentation * 2, ' ');

    QTextStream(stdout) << indent << "p1:\t" << vertexs[0].x << ", "<< vertexs[0].y << ", "<< vertexs[0].z << "\n";
    QTextStream(stdout) << indent << "p2:\t" << vertexs[1].x << ", "<< vertexs[1].y << ", "<< vertexs[1].z << "\n";
    QTextStream(stdout) << indent << "p3:\t" << vertexs[2].x << ", "<< vertexs[2].y << ", "<< vertexs[2].z << "\n";
}

void Triangle::setPlane() {
    this->plane = Plane(normal, this->A, 1.0);
}
