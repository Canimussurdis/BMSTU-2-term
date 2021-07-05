#ifndef SCENE_IMPLEMENTATION_H
#define SCENE_IMPLEMENTATION_H

#include "base_scene_interface.h"
#include "normalization_parameters.h"

#include <vector>
#include <string>
#include <iostream>
class SceneImplementation: public BaseScene {
public:
    virtual ~SceneImplementation();
    virtual std::vector<Facet> GetFigures(const NormalizationParameters&);

    SceneImplementation() {}
    SceneImplementation(const std::vector<std::vector<std::string>> &data):
        data(SceneImplementation::from_string_array(data)) {

//        std::cout << "we are here! " << data.size() << " " << data[0].size() << std::endl;
    }
    static std::vector<std::vector<double>> from_string_array(const std::vector<std::vector<std::string>> &string_data);
private:
    std::vector<std::vector<double>> data;
};

#endif // SCENE_IMPLEMENTATION_H
