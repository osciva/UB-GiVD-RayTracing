#include "Builder.hh"


void Builder::newSphere()
{
    vec3 position(0.0, 0.0, 0.0);
    float radius = 0.5;
    QMessageBox msgBox;
    if (Controller::getInstance()->createScene(position, radius))
            msgBox.setText("One Sphere is created.");
    else msgBox.setText("Not enough memory. Error.");
    msgBox.exec();
}

void Builder::newTriangle(){
    vec3 A = vec3(1,0,0);
    vec3 B = vec3(0,1,0);
    vec3 C = vec3(0,0,1);

    QMessageBox msgBox;
    if (Controller::getInstance()->createScene(A, B, C))
            msgBox.setText("One Triangle is created.");
    else msgBox.setText("Not enough memory. Error.");
    msgBox.exec();
}

void Builder::newSimulatedScene()
{
   QMessageBox msgBox;
   if (Controller::getInstance()->createScene())
           msgBox.setText("A simulated Scene is created.");
   else msgBox.setText("Not enough memory. Error.");
   msgBox.exec();
}


void Builder::newVirtualScene()
{
    QString fileName = QFileDialog::getOpenFileName();
    if (!fileName.isNull()) {
        QMessageBox msgBox;
        if(Controller::getInstance()->createScene(SceneFactory::SCENE_TYPES::VIRTUALWORLD, fileName))
            msgBox.setText("Virtual Scene well loaded.");
        else msgBox.setText("Scene NOT loaded. Error reading data.");
        msgBox.exec();
    }
}


void Builder::newDataScene()
{
    QString fileName = QFileDialog::getOpenFileName();
    if (!fileName.isNull()) {
        QMessageBox msgBox;
        if (Controller::getInstance()->createScene(SceneFactory::SCENE_TYPES::REALDATA, fileName)) {
                msgBox.setText("Data Scene well loaded.");
        } else msgBox.setText("Scene NOT loaded. Error reading data.");
        msgBox.exec();
    }
}

void Builder::loadSettings() {
    QString fileName = QFileDialog::getOpenFileName();
    if (!fileName.isNull()) {
        QMessageBox msgBox;
        if (Controller::getInstance()->createSettings(fileName)) {
                msgBox.setText("Visual Settings well loaded.");

        } else msgBox.setText("Settings NOT loaded. Error reading data.");
        msgBox.exec();
        emit settingsChanged();
    }
}

void Builder::activaColorShading() {
    QMessageBox msgBox;
    if (Controller::getInstance()->createShading(ShadingFactory::SHADING_TYPES::COLOR)) {
        msgBox.setText("Color Shading created.");
    } else msgBox.setText("Error creating shading");
    msgBox.exec();
}

void Builder::activaNormalShading() {
    QMessageBox msgBox;
    if (Controller::getInstance()->createShading(ShadingFactory::SHADING_TYPES::NORMAL)) {
        msgBox.setText("Normal Shading created.");
    } else msgBox.setText("Error creating shading");
    msgBox.exec();
}

void Builder::activaDepthShading() {
    QMessageBox msgBox;
    if (Controller::getInstance()->createShading(ShadingFactory::SHADING_TYPES::DEPTH)) {
        msgBox.setText("Depth Shading created.");
    } else msgBox.setText("Error creating shading");
    msgBox.exec();
}
