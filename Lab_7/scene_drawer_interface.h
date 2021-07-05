#ifndef SCENE_DRAWER_INTERFACE_H
#define SCENE_DRAWER_INTERFACE_H

#include "base_scene_interface.h"

class BaseSceneDrawer {
public:
    virtual ~BaseSceneDrawer() {}
    virtual void DrawScene(BaseScene* scene) = 0;

};

#endif // SCENE_DRAWER_INTERFACE_H
