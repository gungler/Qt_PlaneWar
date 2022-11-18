#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QObject>
#include <QtGlobal>
#include <QVector4D>
#include <QVector3D>
#include <QVector2D>
#include <QString>

class GameObject
{
public:
    explicit GameObject(QVector4D position = {}, QVector3D color = {});
    virtual ~GameObject(){};

    QVector2D Position();
    QVector3D Color();
    float Speed();

    void setDestroied();
    bool isDestroied();

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    void setSpeed(float s);
    float getSpeed();

private:
    QVector3D color;
    QVector4D position;
    float speed = 0.0f;

    bool destroied = 0;
};

#endif // GAMEOBJECT_H
