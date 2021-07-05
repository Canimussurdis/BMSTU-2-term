#ifndef EDGE_H
#define EDGE_H

#include "point3d.h"
// edge
class Facet {
public:
    Facet(const Point3D& n, const Point3D& p1,
          const Point3D& p2, const Point3D& p3):
    n(n), p1(p1), p2(p2), p3(p3) {}
    Point3D n, p1, p2, p3;
};

#endif // EDGE_H
