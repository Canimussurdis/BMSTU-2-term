#ifndef TRANSFORM_INFORMATION_H
#define TRANSFORM_INFORMATION_H

class TransformInformation {
public:
    int GetAngleX();
    int GetAngleY();
    int GetAngleZ();
private:
    int ax, ay, az;
};

#endif // TRANSFORM_INFORMATION_H
