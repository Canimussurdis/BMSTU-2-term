#ifndef FACADE_IMPLEMENTATION_H
#define FACADE_IMPLEMENTATION_H

#include "facade_interface.h"
#include "normalization_parameters.h"

class FacadeImplementation: public FacadeInterface {
public:
    FacadeImplementation(BaseFileReader *_fileReader,
                         BaseSceneDrawer *_sceneDrawer,
                         BaseScene *_scene);
    virtual ~FacadeImplementation();
    virtual FacadeOperationResult DrawScene(const NormalizationParameters&);
    virtual FacadeOperationResult LoadScene(const std::string &);
    virtual FacadeOperationResult MoveScene(double x, double y, double z);
    virtual FacadeOperationResult RotateScene(double angle_x,
                                              double angle_y,
                                              double angle_z);
    virtual FacadeOperationResult ScaleScene(double scale_x,
                                             double scale_y,
                                             double scale_z);
private:
    BaseFileReader *_fileReader;
    BaseSceneDrawer *_sceneDrawer;
    BaseScene *_scene;
};

#endif // FACADE_IMPLEMENTATION_H
