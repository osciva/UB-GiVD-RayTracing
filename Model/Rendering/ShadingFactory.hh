#pragma once

#include "ShadingFactory.hh"
#include "ColorShading.hh"
#include "NormalShading.hh"
#include "DepthShading.hh"
#include "ColorShadow.hh"
#include "BlinnPhongShading.hh"
#include "PhongShading.hh"
#include "CellShading.hh"

class ShadingFactory
{
public:
    ShadingFactory() {};
    typedef enum  SHADING_TYPES{
        NOSHADING,
        COLOR,
        COLORSHADOW,
        NORMAL,
        DEPTH,
        PHONG,
        BLINNPHONG,
        CELL
    } SHADING_TYPES;

    static ShadingFactory& getInstance() {
        static ShadingFactory instance;
        return instance;
    }

    shared_ptr<ShadingStrategy>   createShading(SHADING_TYPES t);
    SHADING_TYPES                 getShadingType(QString s);
    QString                       getNameType(SHADING_TYPES t);
    ShadingFactory::SHADING_TYPES getIndexType(shared_ptr<ShadingStrategy> m);
    shared_ptr<ShadingStrategy>   switchShading(shared_ptr<ShadingStrategy> m, bool shadow);
};

