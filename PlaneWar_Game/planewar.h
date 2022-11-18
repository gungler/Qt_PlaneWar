#ifndef PLANEWAR_H
#define PLANEWAR_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions_4_5_Core>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QImageReader>

#include <QTime>
#include <QKeyEvent>
#include <QVector>
#include <QException>
#include <QFont>
#include <QFontMetrics>
#include <QRect>
#include <QPainter>

#include <QSharedMemory>
#include <QBuffer>

#include <math.h>
#include "playerplane.h"
#include "enemyplane.h"
#include "playerbullet.h"
#include "enemybullet.h"
#include "soundengine.h"
#include "rng.h"
#include "soundengine.h"
#include "particlegenerator.h"

#include <iostream>

enum GameState{
    READY,
    STAGE_1,
    STAGE_2,
    STAGE_3,
    STAGE_4,
    PAUSED,
    END
};

enum Difficulty{
    EASY,
    NORMAL,
    HARD
};

class PlaneWar: public QOpenGLWidget, protected QOpenGLFunctions_4_5_Core
{
    Q_OBJECT
public:
    explicit PlaneWar(QWidget *parent=nullptr);

    //palne corrosponding to control keys
    void doCollide(PlayerPlane* player, EnemyPlane* enemy);

    void setSkin(int playerIndex, int skinIndex);
    void setDifficulty(int d);
    void setSkill(int playerIndex, int SkillIndex);
    void setBGM(QString path, int volumn);

    //return score, skill, last logout time for name in that game
    QVector<QString> getLogoutInfo(QString name);

    void keyPressEvent(QKeyEvent *keyEvent);
    void keyReleaseEvent(QKeyEvent *keyEvent);
    QImage genImageFromQString(QString text, QColor color);
    QColor genFontColor(QString texPath);

    inline void drawGameThings(QVector2D trans, QVector2D scale, QVector3D color, QImage tex);
    void drawParticle(ParticleGenerator* generator, GameObject* object, QImage tex);
    QVector<QString> playernames;

protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();

private slots:
    void updateFrame();
    void processKeys();

private:
    //static QOpenGLContext mainContext;
    static Difficulty difficulty;

    static QVector<EnemyPlane> sEnemys;
    static QVector<EnemyPlane> mEnemys;
    static QVector<EnemyPlane> bEnemys;

    static SoundEngine soundengine;

    //the order in this list is player's name in game

    QMap<QString, PlayerPlane*> livePlanes;

    GameState state;

    //use QScopedPointer
    PlayerPlane player1{QVector4D(-0.9f, -0.9f, 0.0f, 0.0f), QVector3D(1.0f, 1.0f, 1.0f), "Bomb", 0};

    PlayerPlane player2{QVector4D(-0.1f, -0.9f, 0.0f, 0.0f), QVector3D(1.0f, 1.0f, 1.0f), "Bomb", 1};

    PlayerPlane player3{QVector4D(0.7f, -0.9f, 0.0f, 0.0f), QVector3D(1.0f, 1.0f, 1.0f), "Bomb", 2};
    QTime player1SkillSta;
    QTime player1SkillEnd;
    QTime player2SkillSta;
    QTime player2SkillEnd;
    QTime player3SkillSta;
    QTime player3SkillEnd;

    int RedBullDmg = 40;

    QOpenGLShaderProgram* program;
    QOpenGLBuffer* vbo;
    QOpenGLVertexArrayObject* vao;

    QOpenGLShaderProgram* particlePro;
    QOpenGLBuffer* particleVbo;
    QOpenGLVertexArrayObject* particleVao;
    ParticleGenerator* ParticleGenerator1 = new ParticleGenerator();
    ParticleGenerator* ParticleGenerator2 = new ParticleGenerator();
    ParticleGenerator* ParticleGenerator3 = new ParticleGenerator();

    QVector<QString> skins = {
        ":/images/images/player1.png",
        ":/images/images/player2.png",
        ":/images/images/player3.png",
        ":/images/images/player4.png",
        ":/images/images/player5.png",
        ":/images/images/player6.png"};

    QString bulletPath = ":/images/images/bullet1.png";
    QString blueBulletPath = ":/images/images/bullet2.png";
    QString redBulletPath = ":/images/images/bullet1.png";
    QString sEnemyPath = ":/images/images/enemy1.png";
    QString mEnemyPath = ":/images/images/enemy2.png";
    QString bEnemyPath = ":/images/images/enemy3_n1.png";

    //time variables
    QTime current;
    QTime lastFrame;
    QTime start;

    int normalBullet = 20;
    int blueBullet = 40;

    //process inputs
    QTimer *keyInterval;
    QSet<int> keysToProcess;
};

#endif // PLANEWAR_H
