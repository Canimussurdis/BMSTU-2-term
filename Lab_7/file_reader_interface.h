#ifndef FILE_READER_INTERFACE_H
#define FILE_READER_INTERFACE_H

#include <string>

#include "base_scene_interface.h"

class BaseFileReader {
public:
    virtual ~BaseFileReader() {}
    virtual BaseScene* ReadScene(const std::string &filename) = 0;
};

#endif // FILE_READER_INTERFACE_H
