#ifndef FILE_READER_IMPLEMENTATION_H
#define FILE_READER_IMPLEMENTATION_H

#include "file_reader_interface.h"
#include "base_scene_interface.h"

#include <fstream>

class FileReaderImplementation: public BaseFileReader {
public:
    BaseScene* ReadScene(const std::string& filename);
};

#endif // FILE_READER_IMPLEMENTATION_H
