#include "scene_implementation.h"
#include <cmath>
#include "normalization_parameters.h"
SceneImplementation::~SceneImplementation() {}

std::vector<Facet>
SceneImplementation::GetFigures(const NormalizationParameters& np) {

    std::vector<Facet> facets;
    int h = data.size();
    if(h) {
        int w = data[0].size();


        double minzv, maxzv;
        bool first = true;
        for (int p = 0; p < h - 1; p++) {
            for (int q = 0; q < w - 1; q++) {
                if (first || np.minZ > data[p][q]) {
                    minzv = data[p][q];
                }
                if (first || np.maxZ < data[p][q]) {
                    maxzv = data[p][q];
                }
                first = false;
            }
        }

        for (int p = 0; p < h - 1; p++) {
            for (int q = 0; q < w - 1; q++) {
                {
                    //                    double x1 = mx * q, y1 = my * p, z1 = (data[p][q] - np.minZ) / (np.maxZ - np.minZ);
                    double x1 = np.minX + (np.maxX - np.minX) * (q / (w - 1.0)),
                            y1 = np.minY + (np.maxY - np.minY) * (p / (h - 1.0)),
                            z1 = np.minZ + (np.maxZ - np.minZ) * (data[p][q] - minzv) / (maxzv - minzv);
                    //                    double x2 = mx * (q+1), y2 = my * p, z2 =(m*data[p][q+1] - np.minZ) / (np.maxZ - np.minZ);
                    double x2 = np.minX + (np.maxX - np.minX) * (q+1.0) / (w - 1.0),
                            y2 = np.minY + (np.maxY - np.minY) * p / (h - 1.0),
                            z2 = np.minZ + (np.maxZ - np.minZ) * (data[p][q+1] - minzv) / (maxzv - minzv);
                    //                    double x3 = mx* 1, y3 = my * (p + 1), z3 = (m*data[p+1][q] - np.minZ) / (np.maxZ - np.minZ);
                    double x3 = np.minX + (np.maxX - np.minX) * q / (w - 1.0),
                            y3 = np.minY + (np.maxY - np.minY) * (p + 1.0) / (h - 1.0),
                            z3 = np.minZ + (np.maxZ - np.minZ) * (data[p+1][q] - minzv) / (maxzv - minzv);

                    double dx1 = x2 - x1, dy1 = y2 - y1, dz1 = z2 - z1;
                    double dx2 = x3 - x1, dy2 = y3 - y1, dz2 = z3 - z1;
                    double nx = dy1 * dz2 - dy2 * dz1;
                    double ny = dz1 * dx2 - dz2 * dx1;
                    double nz = dx1 * dy2 - dy1 * dx2;
                    double r = std::sqrt(nx * nx + ny * ny + nz * nz);
                    nx /= r; ny /= r; nz /= r;
                    facets.push_back(Facet(Point3D(nx, ny, nz),
                                           Point3D(x1, y1, z1),
                                           Point3D(x2, y2, z2),
                                           Point3D(x3, y3, z3)));
                }
                {
                    //                    double x1 = mx * (q + 1), y1 = my * p, z1 = (data[p][q+1] - np.minZ) / (np.maxZ - np.minZ);
                    double x1 = np.minX + (np.maxX - np.minX) * ((q + 1.0) / (w - 1.0)),
                            y1 = np.minY + (np.maxY - np.minY) * (p / (h - 1.0)),
                            z1 = np.minZ + (np.maxZ - np.minZ) * (data[p][q+1] - minzv) / (maxzv - minzv);
                    //                    double x2 = mx * (q+1), y2 = my * (p+1), z2 = (data[p+1][q+1] - np.minZ) / (np.maxZ - np.minZ);
                    double x2 = np.minX + (np.maxX - np.minX) * (q+1.0) / (w - 1.0),
                            y2 = np.minY + (np.maxY - np.minY) * (p+1.0) / (h - 1.0),
                            z2 = np.minZ + (np.maxZ - np.minZ) * (data[p+1][q+1] - minzv) / (maxzv - minzv);
                    //                    double x3 = mx * q, y3 = my * (p+1), z3 = (data[p+1][q] - np.minZ) / (np.maxZ - np.minZ);
                    double x3 = np.minX + (np.maxX - np.minX) * q / (w - 1.0),
                            y3 = np.minY + (np.maxY - np.minY) * (p + 1.0) / (h - 1.0),
                            z3 = np.minZ + (np.maxZ - np.minZ) * (data[p+1][q] - minzv) / (maxzv - minzv);

                    double dx1 = x2 - x1, dy1 = y2 - y1, dz1 = z2 - z1;
                    double dx2 = x3 - x1, dy2 = y3 - y1, dz2 = z3 - z1;
                    double nx = dy1 * dz2 - dy2 * dz1;
                    double ny = dz1 * dx2 - dz2 * dx1;
                    double nz = dx1 * dy2 - dy1 * dx2;
                    double r = std::sqrt(nx * nx + ny * ny + nz * nz);
                    nx /= r; ny /= r; nz /= r;

                    facets.push_back(Facet(Point3D(nx, ny, nz),
                                           Point3D(x1, y1, z1),
                                           Point3D(x2, y2, z2),
                                           Point3D(x3, y3, z3)));
                }
            }
        }
    }
    return facets;
}

std::vector<std::vector<double>> SceneImplementation::from_string_array(
        const std::vector<std::vector<std::string>> &string_data
        ) {
    std::vector<std::vector<double>> data;

    for (const auto& string_row: string_data) {
        std::vector<double> row;
        for (const auto& element: string_row) {
            row.push_back(std::atof(element.c_str()));
        }
        data.push_back(row);
    }
    return data;
}
