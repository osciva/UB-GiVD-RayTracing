#include "Transparent.hh"

Transparent::Transparent(const vec3& color): Material()
{
    Kd = color;
}

Transparent::Transparent(const vec3 &Ka, const vec3 &Kd, const vec3 &Ks, float k) : Material(Ka, Kd, Ks, k){
}

Transparent::Transparent(const vec3 &Ka, const vec3 &Kd, const vec3 &Ks, float k, float o) : Material(Ka, Kd, Ks, k, o){
}


Transparent::~Transparent(){
}

bool Transparent::scatter(const Ray& r_in, const HitInfo& rec, vec3& color, Ray& r_out) const  {
    /* Determine if the incident ray is inside the object or not by calculating the dot product
    * of the incident ray's direction and the surface normal */
    bool inside_or_not = dot (r_in.getDirection(), rec.normal) < 0;

    /* If the ray is inside the object, use the surface normal; otherwise, use the opposite of the surface normal */
    vec3 normal= inside_or_not ? rec. normal : -rec.normal;

    /* Calculate the ratio of the refractive indices based on whether the ray is inside or outside the object */
    double ratio = inside_or_not ? (1.0003f/nut) : nut;

    /* Set the color based on whether the ray is inside or outside the object */
    color = inside_or_not ? this->kt : this->Ks;

    /* Calculate the cosine of the angle between the negative incident ray direction and the surface normal */
    double cos_theta = fmin(dot(-normalize(r_in.getDirection()), normal), 1.0);

    /* Calculate the sine of the angle using the cosine value */
    double sin_theta = sqrt(1.0 - cos_theta*cos_theta);

    /* Determine if total internal reflection occurs */
    bool cannot_refract = ratio * sin_theta> 1.0;

    /* Declare the direction vector for the refracted or reflected ray */
    vec3 direction;

    /* If total internal reflection occurs, calculate the reflected ray direction; otherwise, calculate the refracted ray direction */
    if (cannot_refract) {
        direction = reflect(normalize(r_in.getDirection()), normal);
    } else {
        direction = refract(normalize(r_in.getDirection()), normal, ratio);
    }

    vec3 p_0;
    p_0 = rec.p + vec3(DBL_EPSILON) * direction; /* Try to solve acné */
    r_out = Ray(p_0, direction);
    return true;
}
