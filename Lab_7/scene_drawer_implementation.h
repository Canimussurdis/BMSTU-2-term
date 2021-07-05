#ifndef SCENE_DRAWER_IMPLEMENTATION_H
#define SCENE_DRAWER_IMPLEMENTATION_H

#include "base_scene_interface.h"
#include "scene_drawer_interface.h"

class SceneDrawerImplementation: public BaseSceneDrawer {
public:
    virtual void DrawScene(BaseScene* scene);
};

#endif // SCENE_DRAWER_IMPLEMENTATION_H
