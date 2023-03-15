#include <QVector>
#include <QVector3D>

#include "Mesh.hh"
#include "Triangle.hh"
#include "Object.hh"


Mesh::Mesh(const QString &fileName): Object()
{
    nom = fileName;
    load(fileName);
    makeTriangles();
}

Mesh::Mesh(const QString &fileName, float data): Object(data)
{
    nom = fileName;
    load(nom);
    makeTriangles();
}

Mesh::~Mesh() {
}

void Mesh::makeTriangles() {

    vec3 minX, maxX;
    vec3 minY, maxY;
    vec3 minZ, maxZ;

    /* Llegim totes les cares i creem els triangles de la mesh */
    for (auto&& face : cares) {
        /* Vertexs que formen la cara (triangle) */
        int id0 = face.idxVertices[0];
        int id1 = face.idxVertices[1];
        int id2 = face.idxVertices[2];

        /* Obtenim màxims i mínims */
        minX = min(vec3(vertexs[id0]),minX);
        maxX = max(vec3(vertexs[id0]),maxX);
        minY = min(vec3(vertexs[id1]),minY);
        maxY = max(vec3(vertexs[id1]),maxY);
        minZ = min(vec3(vertexs[id2]),minZ);
        maxZ = max(vec3(vertexs[id2]),maxZ);

        Triangle newTriangle = Triangle(vec3(vertexs[id0]), vec3(vertexs[id1]), vec3(vertexs[id2]),data);
        newTriangle.setMaterial(make_shared<Lambertian>(vec3(0.5, 0.2, 0.7)));

        /* Afegim la cara */
        triangles.push_back(newTriangle);
    }

    box = new Box(minX, maxX, data);

    makeBoundingSphere();
}

void Mesh::makeBoundingSphere() {
    // Calculate center of bounding sphere
    vec3 center(0.0f);
    for (auto&& vertex : vertexs) {
        center += vec3(vertex);
    }
    center /= vertexs.size();

    // Calculate radius of bounding sphere
    float radius = 0.0f;
    for (auto&& vertex : vertexs) {
        float distance = length(vec3(vertex) - center);
        if (distance > radius) {
            radius = distance;
        }
    }

    // Create bounding sphere
    sphere = new Sphere(center, radius, data);
}

bool Mesh::hit(Ray &r, float t_min, float t_max, HitInfo &info) const {
    bool hit_anything = false;
    float closest_so_far(numeric_limits<float>::infinity());

    if(box->hit(r, t_min, t_max, info)) {
        if(sphere->hit(r, t_min, t_max, info)) {
            for (auto&& t : triangles) {
                if (t.hit(r, t_min, t_max, info)) {

                    if(info.t < closest_so_far){
                        closest_so_far = info.t;
                    }
                    hit_anything = true;
                }
            }
        }
    }

    /* Actualitzem la informació */
    info.t = closest_so_far;
    info.p = r.pointAtParameter(info.t);
    info.normal = vec3(info.p.x, 0, info.p.z);
    info.mat_ptr = material.get();

    return hit_anything;
}

void Mesh::aplicaTG(shared_ptr<TG> tg) {
    for (auto&& t : triangles) {
        t.aplicaTG(tg);
    }
}

void Mesh::load (QString fileName) {
    QFile file(fileName);
    if(file.exists()) {
        if(file.open(QFile::ReadOnly | QFile::Text)) {
            while(!file.atEnd()) {
                QString line = file.readLine().trimmed();
                QStringList lineParts = line.split(QRegularExpression("\\s+"));
                if(lineParts.count() > 0) {
                    // if it’s a comment
                    if(lineParts.at(0).compare("#", Qt::CaseInsensitive) == 0)
                    {
                        // qDebug() << line.remove(0, 1).trimmed();
                    }

                    // if it’s a vertex position (v)
                    else if(lineParts.at(0).compare("v", Qt::CaseInsensitive) == 0)
                    {
                        vertexs.push_back(vec4(lineParts.at(1).toFloat(),
                                               lineParts.at(2).toFloat(),
                                               lineParts.at(3).toFloat(),1.0f));
                    }

                    // if it’s a normal (vn)
                    else if(lineParts.at(0).compare("vn", Qt::CaseInsensitive) == 0)
                    {

                    }
                    // if it’s a texture (vt)
                    else if(lineParts.at(0).compare("vt", Qt::CaseInsensitive) == 0)
                    {

                    }

                    // if it’s face data (f)
                    // there’s an assumption here that faces are all triangles
                    else if(lineParts.at(0).compare("f", Qt::CaseInsensitive) == 0)
                    {
                        Face *face = new Face();

                        // get points from v array
                        face->idxVertices.push_back(lineParts.at(1).split("/").at(0).toInt() - 1);
                        face->idxVertices.push_back(lineParts.at(2).split("/").at(0).toInt() - 1);
                        face->idxVertices.push_back(lineParts.at(3).split("/").at(0).toInt() - 1);

                        cares.push_back(*face);
                    }
                }
            }
            file.close();
        } else {
            qWarning("Boundary object file can not be opened.");
        }
    } else  qWarning("Boundary object file not found.");
}

void Mesh::read (const QJsonObject &json)
{
    Object::read(json);
    if (json.contains("objFileName") && json["objFileName"].isString()) {
        nom = json["objFileName"].toString();
        load(nom);
        makeTriangles();
    }
}


//! [1]
void Mesh::write(QJsonObject &json) const
{
    Object::write(json);
    json["objFileName"] = nom;
}
//! [1]

void Mesh::print(int indentation) const
{
    Object::print(indentation);
    const QString indent(indentation * 2, ' ');
    QTextStream(stdout) << indent << "objFileName:\t" << nom << "\n";
}



