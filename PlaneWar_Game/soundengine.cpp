#include "soundengine.h"

SoundEngine::SoundEngine()
{

}

void SoundEngine::playBGM(){
    QMediaPlaylist *playlist = new QMediaPlaylist(this);
    playlist->addMedia(QUrl(BGMPath));
    playlist->setCurrentIndex(1);
    playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);

    QMediaPlayer *BGMPlayer = new QMediaPlayer(this);
    BGMPlayer->setPlaylist(playlist);
    BGMPlayer->play();
}

void SoundEngine::nextStage(){
    if(!stageChanged->isPlaying())
    {
        QUrl url = QUrl("qrc:/sound/music/next_stage.wav");
        stageChanged->setSource(url);
        stageChanged->play();
    }
}

void SoundEngine::ShootBullet(){
    if(!shootbullet->isPlaying())
    {
        QUrl url = QUrl("qrc:/sound/music/bullet.wav");
        shootbullet->setSource(url);
        shootbullet->play();
    }
}

void SoundEngine::sEnemyDestroied(){
        QUrl url = QUrl("qrc:/sound/music/enemy1_destroied.wav");
        sEnemyDes->setSource(url);
        sEnemyDes->play();
}

void SoundEngine::mEnemyDestroied(){
    if(!mEnemyDes->isPlaying())
    {
        QUrl url = QUrl("qrc:/sound/music/enemy2_destroied.wav");
        mEnemyDes->setSource(url);
        mEnemyDes->play();
    }
}

void SoundEngine::bEnemyDestroied(){
    if(!bEnemyDes->isPlaying()){
        QUrl url = QUrl("qrc:/sound/music/enemy3_destroied.wav");
        bEnemyDes->setSource(url);
        bEnemyDes->play();
    }
}

void SoundEngine::bEnemyOccur(){
    if(!bEnemyFling->isPlaying()){
        QUrl url = QUrl("qrc:/sound/music/enemy3_flying.wav");
        bEnemyFling->setSource(url);
        bEnemyFling->play();
    }

}

void SoundEngine::PlayerDestroied(){
    if(!playerDes->isPlaying()){
        QUrl url = QUrl("qrc:/sound/music/player_destroied.wav");
        playerDes->setSource(url);
        playerDes->play();
    }
}

void SoundEngine::RedBullet(){
    if(!redbullet->isPlaying()){
        QUrl url = QUrl("qrc:/sound/music/red_bullet.wav");
        redbullet->setSource(url);
        redbullet->play();
    }

}

void SoundEngine::Bomb(){
    if(!bomb->isPlaying())
    {
        QUrl url = QUrl("qrc:/sound/music/use_bomb.wav");
        bomb->setSource(url);
        bomb->play();
    }
}

void SoundEngine::Heal(){
    if(!heal->isPlaying())
    {
        QUrl url = QUrl("qrc:/sound/music/heal.wav");
        heal->setSource(url);
        heal->play();
    }
}

void SoundEngine::Crush(){
    if(!crush->isPlaying())
    {
        QUrl url = QUrl("qrc:/sound/music/crush.wav");
        crush->setSource(url);
        crush->play();
    }
}

void SoundEngine::setBGMPath(QString path){
    this->BGMPath = path;
}

void SoundEngine::setVolumn(int value){
    if(value < 100 && value > 0)
        this->volumn = value;
}
