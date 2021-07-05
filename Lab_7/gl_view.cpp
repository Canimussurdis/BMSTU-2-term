#include "gl_view.h"
#include "mainwindow.h"
#include <cmath>
#include <QOpenGLFunctions>
#include <QGLWidget>

GLView::GLView(MainWindow* parent, FacadeInterface* facade):
    QGLWidget(parent), facade(facade) {
}

void
GLView::initializeGL() {
    glEnable(GL_DEPTH_TEST);
//     glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);

    glEnable(GL_SMOOTH);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    //    glClearColor(100, 0, 0, 1);
    //    glClear(GL_COLOR_BUFFER_BIT);

    GLfloat specularMat[] = {0.3, 0.7, 0.1, 1.0};
    GLfloat emissionMat[] = {0.0, 0.0, 0.0, 1.0};

    glMaterialfv(GL_FRONT, GL_SPECULAR, specularMat);
    glMaterialfv(GL_FRONT, GL_EMISSION, emissionMat);
    {
        glEnable(GL_LIGHT0); //координаты фонариков

        float vposx = 0.0, vposy = 0.0, vposz = -30.0;
        float m = -1.0;
        float vdirx = vposx * m, vdiry = vposy * m, vdirz = vposz * m;
        float r = std::sqrt(vdirx*vdirx + vdiry*vdiry + vdirz*vdirz);
        vdirx /= r; vdiry /= r; vdirz /=r;

        GLfloat ambientLight[] = {0.0, 0.0, 0.0, 1.0};
        GLfloat diffuseReflection[] = {0.6, 0.6, 0.9, 1.0}; //blue
        GLfloat specularLight[] = {0.2, 0.2, 0.2, 1.0};
        GLfloat pos[] = {GLfloat(vposx),  GLfloat(vposy), GLfloat(vposz), 1};
        GLfloat dir[] = {GLfloat(vdirx),  GLfloat(vdiry), GLfloat(vdirz)};

        glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseReflection);
        glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
        glLightfv(GL_LIGHT0, GL_POSITION, pos);
        glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, dir);
    }

    {
        glEnable(GL_LIGHT1);

        // (-30,   0,   0) - right
        // (  0, -30,   0) - up
        // (  0,   0, -30) - front
        float vposx = -30.0, vposy = -20.0, vposz = 30.0;
        float m = -1.0;
        float vdirx = vposx * m, vdiry = vposy * m, vdirz = vposz * m;
        float r = std::sqrt(vdirx*vdirx + vdiry*vdiry + vdirz*vdirz);
        vdirx /= r; vdiry /= r; vdirz /=r;

        GLfloat ambientLight[] = {0.0, 0.0, 0.0, 1.0};
        GLfloat diffuseReflection[] = {0.9, 0.6, 0.6, 1.0};
        GLfloat specularLight[] = {0.2, 0.2, 0.2, 1.0};
        GLfloat pos[] = {GLfloat(vposx),  GLfloat(vposy), GLfloat(vposz), 1};
        GLfloat dir[] = {GLfloat(vdirx),  GLfloat(vdiry), GLfloat(vdirz)};

        glLightfv(GL_LIGHT1, GL_AMBIENT, ambientLight);
        glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuseReflection);
        glLightfv(GL_LIGHT1, GL_SPECULAR, specularLight);
        glLightfv(GL_LIGHT1, GL_POSITION, pos);
        glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, dir);
    }


    {
        glEnable(GL_LIGHT2);

        //         (-30,   0,   0) - right
        //         (  0, -30,   0) - up
        //         (  0,   0, -30) - front
        float vposx =30.0, vposy = -20.0, vposz = 30.0;
        float m;
        float vdirx = vposx * m, vdiry = vposy * m, vdirz = vposz * m;
        float r = std::sqrt(vdirx*vdirx + vdiry*vdiry + vdirz*vdirz);
        vdirx /= r; vdiry /= r; vdirz /=r;

        GLfloat ambientLight[] = {0.0, 0.0, 0.0, 1.0};
        GLfloat diffuseReflection[] = {0.6, 0.6, 0.9, 1.0};
        GLfloat specularLight[] = {0.2, 0.2, 0.2, 1.0};
        GLfloat pos[] = {GLfloat(vposx),  GLfloat(vposy), GLfloat(vposz), 1};
        GLfloat dir[] = {GLfloat(vdirx),  GLfloat(vdiry), GLfloat(vdirz)};

        glLightfv(GL_LIGHT2, GL_AMBIENT, ambientLight);
        glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuseReflection);
        glLightfv(GL_LIGHT2, GL_SPECULAR, specularLight);
        glLightfv(GL_LIGHT2, GL_POSITION, pos);
        glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, dir);
    }
}

void
GLView::resizeGL(int w, int h){
  int s = qMin(w, h);
  glViewport((w - s) / 2, (h - s) / 2, s, s);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glFrustum(-0.25, 0.25, -0.25, 0.25, -1, 1);
  glMatrixMode(GL_MODELVIEW);
}

void
GLView::paintGL(){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glLoadIdentity();

  glRotated(xang, 1.0, 0.0, 0.0);
  glRotated(yang, 0.0, 1.0, 0.0);
  glRotated(zang, 0.0, 0.0, 1.0);

  glPushAttrib(GL_CURRENT_BIT);
  glBegin(GL_LINES);{
    //Coordinate system
    glNormal3d(0, 0, 1);
    glColor3f(3.0, .0, 0.0);
    glVertex3f(-0.3, 0.0, 0.0);
    glVertex3f( 1.0, 0.0, 0.0);

    glNormal3d(1.0, 0, 0);
    glColor3f(0.0, 3.0, 0.0);
    glVertex3f(0.0, -0.3, 0.0);
    glVertex3f(0.0,  1.0, 0.0);

    glNormal3d(0, 1, 0);
    glColor3f(0.0, 0.0, 3.0);
    glVertex3f( 0.0, 0.0, -0.3);
    glVertex3f( 0.0, 0.0,  1.0);
  }glEnd();

//  glBegin(GL_TRIANGLES); {
//      glNormal3d(0, 0, -1);
//      glVertex3d(0, 0, 0);
//      glVertex3d(10, 0, 0);
//      glVertex3d(10, 10, 0);
//  } glEnd();

    facade->DrawScene(normalizationParameters);
}

void
GLView::changeXang(int xang_) {
    xang = xang_;
    updateGL();
}

void
GLView::changeYang(int yang_) {
    yang = yang_;
    updateGL();
}

void
GLView::changeZang(int zang_) {
    zang = zang_;
    updateGL();
}

void
GLView::changeMinX(double minX_) {
    normalizationParameters.minX = minX_;
    updateGL();
}

void
GLView::changeMaxX(double maxX_) {
    normalizationParameters.maxX = maxX_;
    updateGL();
}

void
GLView::changeMinY(double minY_) {
    normalizationParameters.minY = minY_;
    updateGL();
}

void
GLView::changeMaxY(double maxY_) {
    normalizationParameters.maxY = maxY_;
    updateGL();
}

void
GLView::changeMinZ(double minZ_) {
    normalizationParameters.minZ = minZ_;
    updateGL();
}

void
GLView::changeMaxZ(double maxZ_) {
    normalizationParameters.maxZ = maxZ_;
    updateGL();
}

void
GLView::changeMinNormal(double minNormal_) {
//    minNormal = minNormal_;
    normalizationParameters.minX = minNormal_;
    normalizationParameters.minY = minNormal_;
    normalizationParameters.minZ = minNormal_;
    updateGL();
}

void
GLView::changeMaxNormal(double maxNormal_) {
//    maxNormal = maxNormal_;

    normalizationParameters.maxX = maxNormal_;
    normalizationParameters.maxY = maxNormal_;
    normalizationParameters.maxZ = maxNormal_;
    updateGL();
}


void
GLView::updateData(const std::vector<std::vector<std::string>> &stringData) {
    std::vector<std::vector<double>> data3d;
    for(const auto& strRow: stringData) {
        std::vector<double> row;
        for(const auto& element: strRow) {
            row.push_back(atof(element.c_str()));
        }
        data3d.push_back(row);
    }
    this->data3d.swap(data3d);
    updateGL();
}
