#ifndef GL_VIEW_H
#define GL_VIEW_H
#include "facade_interface.h"
#include "normalization_parameters.h"
#include <QOpenGLFunctions>
#include <QWidget>
#include <QGLWidget>

class MainWindow;

class GLView: public QGLWidget {
    Q_OBJECT
public:
    GLView(MainWindow * = 0, FacadeInterface* = 0);

    void initializeGL();
    void resizeGL(int, int);
    void paintGL();

    void updateData(const std::vector<std::vector<std::string>>&);
public slots:
    void changeXang(int);
    void changeYang(int);
    void changeZang(int);
    void changeMinX(double);
    void changeMaxX(double);
    void changeMinY(double);
    void changeMaxY(double);
    void changeMinZ(double);
    void changeMaxZ(double);
    void changeMinNormal(double);
    void changeMaxNormal(double);
private:
    int xang;
    int yang;
    int zang;

    double minNormal;
    double maxNormal;

    NormalizationParameters normalizationParameters;

    std::vector<std::vector<double>> data3d;

    FacadeInterface* facade;
};

#endif
