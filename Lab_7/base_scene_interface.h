#ifndef BASE_SCENE_INTERFACE_H
#define BASE_SCENE_INTERFACE_H

#include <vector>
#include "facet.h"
#include "normalization_parameters.h"

class BaseScene {
public:
    virtual ~BaseScene() {}
    virtual std::vector<Facet> GetFigures(const NormalizationParameters&) = 0;
};

#endif // BASE_SCENE_INTERFACE_H
