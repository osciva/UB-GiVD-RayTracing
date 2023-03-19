#pragma once

#include <QtWidgets>
#include "Controller.hh"

class Builder : public QObject {
    Q_OBJECT

public:
    Builder(){};

public slots:
    void newSphere();
    void newBox();
    void newCylinder();
    void newTriangle();
    void newSimulatedScene();
    void newVirtualScene();
    void newDataScene();
    void loadSettings();
    void activaColorShading();
    void activaNormalShading();
    void activaDepthShading();
    void activaBlinn_Phong();
    void activaPhongShader();
    void activaCell_Shading();

signals:
     void settingsChanged();
};

