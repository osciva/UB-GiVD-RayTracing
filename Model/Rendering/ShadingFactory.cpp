#include "ShadingFactory.hh"

shared_ptr<ShadingStrategy> ShadingFactory::createShading(SHADING_TYPES t) {
    shared_ptr<ShadingStrategy> s;
    switch(t) {
    case COLOR:
        s= make_shared<ColorShading>();
        break;
    case NORMAL:
        s= make_shared<NormalShading>();
        break;
    case DEPTH:
        s= make_shared<DepthShading>();
        break;
    case COLORSHADOW:
        s = make_shared<ColorShadow>();
        break;
    case BLINNPHONG:
        s = make_shared<BlinnPhongShading>();
        break;
    case BLINNPHONGSHADOW:
        s = make_shared<BlinnPhongShadowShading>();
        break;
    case PHONG:
        s = make_shared<PhongShading>();
        break;
    default:
        s = nullptr;
    }
    return s;
}

ShadingFactory::SHADING_TYPES ShadingFactory::getShadingType(QString name) {
    if (name=="COLOR") return SHADING_TYPES::COLOR;
    else if (name == "COLORSHADOW") return SHADING_TYPES::COLORSHADOW;
    else if (name == "NORMAL") return SHADING_TYPES::NORMAL;
    else if (name =="DEPTH") return SHADING_TYPES::DEPTH;
    else if (name =="BLINNPHONG") return SHADING_TYPES::BLINNPHONG;
    else if (name =="BLINNPHONGSHADOW") return SHADING_TYPES::BLINNPHONGSHADOW;
    else if (name == "PHONG") return SHADING_TYPES::PHONG;
}

QString ShadingFactory::getNameType(SHADING_TYPES t) {
    switch (t) {
    case COLOR:
        return (QString("COLOR"));
        break;
    case COLORSHADOW:
        return (QString("COLORSHADOW"));
        break;
    case NORMAL:
        return (QString("NORMAL"));
        break;
    case DEPTH:
        return (QString("DEPTH"));
        break;
    case BLINNPHONG:
        return (QString("BLINNPHONG"));
        break;
    case BLINNPHONGSHADOW:
        return (QString("BLINNPHONGSHADOW"));
        break;
    case PHONG:
        return (QString("PHONG"));
        break;
    default:
        return(QString(""));
    }
}
ShadingFactory::SHADING_TYPES ShadingFactory::getIndexType(shared_ptr<ShadingStrategy> m) {
    if (dynamic_pointer_cast<ColorShading>(m) != nullptr) {
        return SHADING_TYPES::COLOR;
    } else if (dynamic_pointer_cast<ColorShadow>(m) != nullptr) {
        return SHADING_TYPES::COLORSHADOW;
    } else if (dynamic_pointer_cast<NormalShading>(m) != nullptr){
        return SHADING_TYPES::NORMAL;
    } else if (dynamic_pointer_cast<DepthShading>(m) != nullptr){
        return SHADING_TYPES::DEPTH;
    } else if (dynamic_pointer_cast<BlinnPhongShading>(m) != nullptr){
        return SHADING_TYPES::BLINNPHONG;
    }else if (dynamic_pointer_cast<BlinnPhongShadowShading>(m) != nullptr){
        return SHADING_TYPES::BLINNPHONGSHADOW;
    } else if (dynamic_pointer_cast<PhongShading>(m) != nullptr) {
        return SHADING_TYPES::PHONG;
    } else
        return SHADING_TYPES::NOSHADING;
}

shared_ptr<ShadingStrategy> ShadingFactory::switchShading(shared_ptr<ShadingStrategy> m, bool shadow) {
    shared_ptr<ShadingStrategy> m_out = nullptr;
    m.get();
    if (shadow) {
        if (dynamic_pointer_cast<ColorShadow>(m) != nullptr) {
             m_out = createShading(COLORSHADOW);
        }else if (dynamic_pointer_cast<BlinnPhongShading>(m) != nullptr) {
            m_out = createShading(BLINNPHONGSHADOW);
       }
    } else {
        if (dynamic_pointer_cast<ColorShading>(m) != nullptr) {
             m_out = createShading(COLOR);
        } else if (dynamic_pointer_cast<NormalShading>(m) != nullptr) {
            m_out = createShading(NORMAL);
        } else if (dynamic_pointer_cast<DepthShading>(m) != nullptr) {
            m_out = createShading(DEPTH);
        } else if (dynamic_pointer_cast<BlinnPhongShading>(m) != nullptr) {
            m_out = createShading(BLINNPHONG);
        } else if (dynamic_pointer_cast<BlinnPhongShadowShading>(m) != nullptr) {
            m_out = createShading(BLINNPHONGSHADOW);
        } else if (dynamic_pointer_cast<PhongShading>(m) != nullptr) {
            m_out = createShading(PHONG);
        }
    }
    return m_out;
}
