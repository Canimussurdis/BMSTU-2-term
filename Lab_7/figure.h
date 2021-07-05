#ifndef FIGURE_H
#define FIGURE_H

#include <vector>
#include "vertex.h"
#include "facet.h"

class Figure {
public:
    std::vector<Vertex> vertices;
    std::vector<Facet> facets;

};

#endif // FIGURE_H
