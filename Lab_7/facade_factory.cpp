#include "facade_implementation.h"

#include "file_reader_implementation.h"
#include "scene_drawer_implementation.h"
#include "scene_implementation.h"

FacadeInterface* FacadeFactory() {
    return new FacadeImplementation(
                new FileReaderImplementation,
                new SceneDrawerImplementation,
                new SceneImplementation);
}

