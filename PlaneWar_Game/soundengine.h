#ifndef SOUNDENGINE_H
#define SOUNDENGINE_H

#include<QObject>
#include<QSoundEffect>
#include<QUrl>
#include<QMediaPlayer>
#include <QtMultimedia/QMediaPlayer>
#include<QMediaPlaylist>
#include<QDir>

class SoundEngine:public QObject
{
public:
    SoundEngine();
    void playBGM();
    void nextStage();

    void ShootBullet();
    void sEnemyDestroied();
    void mEnemyDestroied();
    void bEnemyDestroied();

    void bEnemyOccur();
    void PlayerDestroied();

    void Bomb();
    void RedBullet();
    void Heal();
    void Crush();

    //change BGM and it's volume
    void setBGMPath(QString path);
    void setVolumn(int value);

private:
    //sound file's project path
    QSoundEffect *stageChanged = new QSoundEffect;
    QSoundEffect *shootbullet= new QSoundEffect;

    QSoundEffect *sEnemyDes= new QSoundEffect;
    QSoundEffect *mEnemyDes= new QSoundEffect;
    QSoundEffect *bEnemyDes= new QSoundEffect;
    QSoundEffect *bEnemyFling= new QSoundEffect;

    QSoundEffect *playerDes= new QSoundEffect;

    QSoundEffect *redbullet= new QSoundEffect;
    QSoundEffect *bomb= new QSoundEffect;
    QSoundEffect *heal= new QSoundEffect;
    QSoundEffect *crush= new QSoundEffect;

    QString BGMPath = "qrc:/sound/music/game_music.wav";
    int volumn = 30;
};

#endif // SOUNDENGINE_H
