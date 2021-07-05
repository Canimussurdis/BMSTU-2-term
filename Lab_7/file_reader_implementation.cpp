#include "file_reader_implementation.h"
#include "facade_operation_result.h"
#include <scene_implementation.h>
#include <fstream>
#include <sstream>

BaseScene* FileReaderImplementation::ReadScene(const std::string &filename
                                        ) {
    std::ifstream source(filename);
    std::string currentLine;

    std::vector<std::vector<std::string>> data;

    while (std::getline(source, currentLine)) {
        std::stringstream oneLineStream(currentLine);
        std::vector<std::string> record;
        std::string oneValue;
        while (std::getline(oneLineStream, oneValue, ',')) {
           record.push_back(oneValue);
        }
        data.push_back(record);
    }
//    SceneImplementation* sceneImplementation = new SceneImplementation;
    return new SceneImplementation(data);
}
