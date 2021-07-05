#ifndef VERTEX_H
#define VERTEX_H

#include "point3d.h"
#include "transform_information.h"

class Vertex {
public:
    Point3D GetPosition();
    void Transform(const TransformInformation&);
private:
    Point3D position;
};

#endif // VERTEX_H
