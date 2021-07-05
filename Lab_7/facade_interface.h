#ifndef FACADE_H
#define FACADE_H

#include "facade_operation_result.h"
#include "file_reader_interface.h"
#include "scene_drawer_interface.h"
#include "base_scene_interface.h"

class NormalizationParameters;

class FacadeInterface {
public:
    virtual ~FacadeInterface() {}
    virtual FacadeOperationResult DrawScene(const NormalizationParameters&) = 0;
    virtual FacadeOperationResult LoadScene(const std::string &) = 0;
    virtual FacadeOperationResult MoveScene(double x,
                                            double y,
                                            double z) = 0;
    virtual FacadeOperationResult RotateScene(double angle_x,
                                              double angle_y,
                                              double angle_z) = 0;
    virtual FacadeOperationResult ScaleScene(double scale_x,
                                             double scale_y,
                                             double scale_z) = 0;
};

#endif // FACADE_H
