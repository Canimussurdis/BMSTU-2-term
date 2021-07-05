#include "facade_implementation.h"
#include <iostream>
#include <QGLWidget>

FacadeImplementation::FacadeImplementation(BaseFileReader *_fileReader,
                     BaseSceneDrawer *_sceneDrawer,
                     BaseScene *_scene):
    _fileReader(_fileReader),
    _sceneDrawer(_sceneDrawer),
    _scene(_scene) {}

FacadeImplementation::~FacadeImplementation() {
    delete _fileReader;
    delete _sceneDrawer;
    delete _scene;
}

FacadeOperationResult FacadeImplementation::DrawScene(const NormalizationParameters& np) {

    std::vector<Facet> facets = _scene ->GetFigures(np);

    glBegin(GL_TRIANGLES); {

        for (const Facet& currentFacet: facets) {
            glNormal3d(currentFacet.n.x, currentFacet.n.y, currentFacet.n.z);
            glVertex3d(currentFacet.p1.x, currentFacet.p1.y, currentFacet.p1.z);
            glVertex3d(currentFacet.p2.x, currentFacet.p2.y, currentFacet.p2.z);
            glVertex3d(currentFacet.p3.x, currentFacet.p3.y, currentFacet.p3.z);
        }

    }glEnd();
    glPopAttrib();

    return FacadeOperationResult();
}

FacadeOperationResult FacadeImplementation::LoadScene(const std::string & filename) {
    if (_scene) {
        delete _scene;
        _scene = nullptr;
    }
//    std::cout << "loadScene" << std::endl;
    _scene = _fileReader->ReadScene(filename);

    return FacadeOperationResult();
}

FacadeOperationResult FacadeImplementation::MoveScene(double dx, double dy, double dz) {
    return FacadeOperationResult();
}

FacadeOperationResult FacadeImplementation::RotateScene(double angle_x, double angle_y, double angle_z) {
    return FacadeOperationResult();
}

FacadeOperationResult FacadeImplementation::ScaleScene(double sc_x, double sc_y, double sc_z) {
    return FacadeOperationResult();
}
