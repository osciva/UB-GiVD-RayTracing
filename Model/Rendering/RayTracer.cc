#include "RayTracer.hh"

RayTracer::RayTracer(QImage *i):
    image(i) {

    setup = Controller::getInstance()->getSetUp();
    scene = Controller::getInstance()->getScene();
}

void RayTracer::run() {

    init();
    auto camera = setup->getCamera();
    int  width = camera->viewportX;
    int  height = camera->viewportY;

    for (int y = height-1; y >= 0; y--) {
        std::cerr << "\rScanlines remaining: " << y << ' ' << std::flush;  // Progrés del càlcul
        for (int x = 0; x < width; x++) {

            //TODO FASE 2: mostrejar més rajos per pixel segons el valor de "samples"
            vec3 color(0, 0, 0);

            float u = (float(x)) / float(width);
            float v = (float(height -y)) / float(height);

            float i = (float(x+1)) / float(width);
            float o = (float((height-y)-1)) / float(height);

            float final_x;
            float final_y;

            Ray r;

            for (int k = 0; k < setup->getSamples(); k++) {
                final_x = r.random(u, i);
                final_y = r.random(o, v);
                r = camera->getRay(final_x, final_y);
                color += this->RayPixel(r, 0);
            }

            // TODO FASE 2: Gamma correction
            color = vec3(sqrt(color.x/setup->getSamples()), sqrt(color.y/setup->getSamples()), sqrt(color.z/setup->getSamples()));
            color *= 255;
            setPixel(x, y, color);
        }
    }
    std::cerr << "\nFinished.\n";
}

void RayTracer::setPixel(int x, int y, vec3 color) {

    if (color.r < 0) color.r = 0;
    if (color.g < 0) color.g = 0;
    if (color.b < 0) color.b = 0;

    if (color.r > 255) color.r = 255;
    if (color.g > 255) color.g = 255;
    if (color.b > 255) color.b  = 255;

    image->setPixelColor(x, y, QColor(color.r, color.g, color.b));

}

/* Mètode RayPixel
** TODO: Cal modificar la funcio RayPixel es la funcio recursiva del RayTracing. Cal retocar-lo per:
** FASE 0 per a fer el degradat del fons
** FASES 0 i 1 per a cridar a la intersecció amb l'escena i posar el color de l'objecte (via color, depth o normal)
** FASE 2 per incloure els shading més realistes (Blinn-Phong  i ombres)
** FASE 2 per a tractar reflexions i transparències
**
*/

// Funcio recursiva que calcula el color.
vec3 RayTracer::RayPixel(Ray &ray, int depth) {
    vec3 color;
    vec3 recursiveRay = normalize(ray.getDirection());
    HitInfo info;
    auto s = setup->getShadingStrategy();

    if (scene->hit(ray, 0.000001f, numeric_limits<float>::infinity(), info)) { // el raig intersecta amb un objecte
        color = s->shading(scene, info, ray.getOrigin(), setup->getLights(), setup->getGlobalLight()) * (vec3(1.f)-info.mat_ptr->kt);

        Ray scatteredRay;
        vec3 c = vec3(0.0f);

        if(depth < setup->getMAXDEPTH()) {
            if(info.mat_ptr->scatter(ray, info, c, scatteredRay)) {
                color += RayPixel(scatteredRay,depth+1) * c;
            }
        } else {
            color += setup->getGlobalLight() * info.mat_ptr->Ka;
        }
    }else{
        float t = 0.5f * (recursiveRay.y+1);
        color = vec3((1-t) * setup->getDownBackground()+ t * setup->getTopBackground());
    }
    return color;
}

void RayTracer::init() {
    auto s = setup->getShadingStrategy();
    auto s_out = ShadingFactory::getInstance().switchShading(s, setup->getShadows());
    if (s_out!=nullptr) setup->setShadingStrategy(s_out);
}
