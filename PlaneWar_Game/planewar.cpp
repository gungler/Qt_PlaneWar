#include "planewar.h"

//game difficulty
Difficulty PlaneWar::difficulty = NORMAL;

//game objects
QVector<EnemyPlane> PlaneWar::sEnemys;
QVector<EnemyPlane> PlaneWar::mEnemys;
QVector<EnemyPlane> PlaneWar::bEnemys;

SoundEngine PlaneWar::soundengine;

PlaneWar::PlaneWar(QWidget *parent)
    :QOpenGLWidget(parent)
{
    this->setFixedSize(720, 960);
    setFocusPolicy(Qt::StrongFocus);

    //setting game frames, 50fps
    QTimer *mainTimer = new QTimer(this);
    connect(mainTimer, SIGNAL(timeout()), this, SLOT(updateFrame()));
    connect(mainTimer, SIGNAL(timeout()), this, SLOT(update()));
    mainTimer->start(10);
    keyInterval = new QTimer(this);
    connect(keyInterval, SIGNAL(timeout()), this, SLOT(processKeys()));
}

void PlaneWar::doCollide(PlayerPlane* plane, EnemyPlane* enemy){
    if(!plane->isDestroied() && ! enemy->isDestroied()){
        QVector2D v1;
        QVector2D v2;
        float distance;

        v1 = plane->getCollideC();
        v2 = enemy->getCollideC();

        QVector2D offset = v1-v2;
        distance = std::sqrt(offset.x() * offset.x() + offset.y() * offset.y());

        //playerplane and enemy plane collide, both take 200
        if(distance < (plane->getCollideR() + enemy->getCollideR())){
            enemy->takeDamage(200);
            if(!(plane->getSkill() == "Crush" && player2SkillSta.secsTo(player2SkillEnd) < 300))
                plane->takeDamage(200);
            if(plane->isDestroied())
                this->soundengine.PlayerDestroied();
        }

        //player bullet and enemyPlane collide
        for(PlayerBullet* b = plane->playerbullets.begin(); b != plane->playerbullets.end(); ++b){
            v1 = b->getCollideC();
            v2 = enemy->getCollideC();

            //distances between two palyers
            QVector2D offset = v2 - v1;
            distance = std::sqrt(offset.x() * offset.x() + offset.y() * offset.y());

            //if collided
            if(distance < (b->getCollideR() + enemy->getCollideR())){
                //remove bullet, take damage
                b->setDestroied();
                enemy->takeDamage(b->getDamage());

                //add score depends on enemy type
                if(enemy->isDestroied()){
                    if(enemy->getType() == 0){
                        plane->changeScore(10);
                        plane->addEnergy(5);
                        this->soundengine.sEnemyDestroied();
                    }
                    else if(enemy->getType() == 1){
                        plane->changeScore(30);
                        plane->addEnergy(10);
                        this->soundengine.mEnemyDestroied();
                    }
                    else{
                        plane->changeScore(50);
                        plane->addEnergy(50);
                        this->soundengine.bEnemyDestroied();
                    }

                }

            }
        }
            //enembullet and playerPlane collide
            if(enemy->enemybullets.size()){
                for(int b=0; b != enemy->enemybullets.size(); ++b){
                    v1 = plane->getCollideC();
                    v2 = enemy->enemybullets[b].getCollideC();
                    QVector2D offset = v1-v2;
                    distance = std::sqrt(offset.x() * offset.x() + offset.y() * offset.y());
                    if(distance < (enemy->enemybullets[b].getCollideR() + plane->getCollideR())){
                        //remove bullet
                        enemy->enemybullets[b].setDestroied();
                        if(!(plane->getSkill() == "Crush" && player2SkillSta.secsTo(player2SkillEnd) < 300))
                            plane->takeDamage(enemy->enemybullets[b].getDamage());

                    }
                }
            }
    }
}

//0 = easy 1 = normal 2 = hard
void PlaneWar::setDifficulty(int d){
    switch(d){
    case 0: this->difficulty = EASY;   break;
    case 1: this->difficulty = NORMAL; break;
    case 2: this->difficulty = HARD;   break;
    default: break;
    }
}

void PlaneWar::setSkin(int playerIndex, int skinIndex){
    if(playerIndex == 0){
        player1.skinIndex = skinIndex;
    }else if(playerIndex == 1){
        player2.skinIndex = skinIndex;
    }else if(playerIndex == 2){
        player3.skinIndex = skinIndex;
    }
}

void PlaneWar::setSkill(int playerIndex, int SkillIndex){
    if(playerIndex == 0){
        player1.setSkill(SkillIndex);
    }else if(playerIndex == 1){
        player2.setSkill(SkillIndex);
    }else if(playerIndex == 2){
        player1.setSkill(SkillIndex);
    }
}

void PlaneWar::setBGM(QString path, int volumn){
    soundengine.setVolumn(volumn);
    if(path != NULL)
        soundengine.setBGMPath(path);
}

void PlaneWar::initializeGL(){
    initializeOpenGLFunctions();
    makeCurrent();

    //set line quality
    glHint(GL_LINE_SMOOTH_HINT,GL_FASTEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    qDebug() << QString((char*)glGetString(GL_VERSION));
    qDebug() << QString((char*)glGetString(GL_RENDERER));

    //set game state and time parameters
    start = QTime::currentTime();

    //gen player bullets
    player1.setSpeed(0.05f);
    player2.setSpeed(0.05f);
    player3.setSpeed(0.05f);
    state = READY;

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); //balck
    glClearDepth(1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    program = new QOpenGLShaderProgram();
    program->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shaders/shaders/player.vert");
    program->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/shaders/player.frag");
    program->link();
    program->bind();

    static const GLfloat vertex[] ={
        //position   //texture position
        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f,

        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f
    };

    //create vao&vbo
    vao = new QOpenGLVertexArrayObject();
    vao->create();
    vao->bind();

    vbo = new QOpenGLBuffer(QOpenGLBuffer::Type::VertexBuffer);
    vbo->create();
    vbo->bind();
    vbo->allocate(vertex, 4 * 6 * sizeof(GLfloat));

    //sending datas
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat),(void*) 0);
    glUseProgram(0);
    glBindVertexArray(0);

    particlePro = new QOpenGLShaderProgram();
    particlePro->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shaders/shaders/particle.vert");
    particlePro->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/shaders/particle.frag");
    particlePro->link();
    particlePro->bind();

    particleVao = new QOpenGLVertexArrayObject();
    particleVao->create();
    particleVao->bind();

    particleVbo = new QOpenGLBuffer(QOpenGLBuffer::Type::VertexBuffer);
    particleVbo->create();
    particleVbo->bind();
    particleVbo->allocate(vertex, 4 * 6 * sizeof(GLfloat));
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (void*)0);
    glUseProgram(0);
    glBindVertexArray(0);

    vao->bind();
    vbo->bind();
    program->bind();

    int num = playernames.size();
    if(num == 1){
        player2.setDestroied();
        player3.setDestroied();
    }else if(num == 2){
        player3.setDestroied();
    }else if(num == 3){

        qDebug() << "player full";
    }else{
        this->close();
    }
    soundengine.playBGM();
}

void PlaneWar::resizeGL(int width, int height){
    //fix window size when it changed
    glViewport(0,0,width,height);
}

void PlaneWar::updateFrame(){
    player1SkillEnd = QTime::currentTime();
    player2SkillEnd = QTime::currentTime();
    player3SkillEnd = QTime::currentTime();

    //player not destroied
    if(!player1.isDestroied()){
        //gen player bullets
        PlayerBullet bullet1{QVector2D(player1.Position().x() + 0.094f, player1.Position().y() + 0.2f),
                    QVector3D(1.0f, 1.0f, 1.0f)};

        if(player1SkillSta.secsTo(player1SkillEnd) < 300 && player1.getSkill() == "Redbullet"){
            bullet1.setDamage(blueBullet);
        }else{
            bullet1.setDamage(normalBullet);
        }
        bullet1.setSpeed(player1.getSpeed() * 3);
        player1.playerbullets.push_back(bullet1);
        soundengine.ShootBullet();

        if(player1.playerbullets.size()){
            player1.bulletMoveUp();
        }

    }else{
        player1.playerbullets.clear();
        this->soundengine.PlayerDestroied();
    }

    if(!player2.isDestroied()){
        //gen bullets
        PlayerBullet bullet2{QVector2D(player2.Position().x() + 0.094f, player2.Position().y() + 0.2f),
                    QVector3D(1.0f, 1.0f, 1.0f)};
        if(player2SkillSta.secsTo(player2SkillEnd) < 300 && player2.getSkill() == "Redbullet"){
            bullet2.setDamage(blueBullet);
        }else{
            bullet2.setDamage(normalBullet);
        }
        bullet2.setSpeed(player2.getSpeed() * 3);
        player2.playerbullets.push_back(bullet2);
        soundengine.ShootBullet();

        //player bullet move up
        if(player2.playerbullets.size()){
            player2.bulletMoveUp();
        }
    }else{
        player2.playerbullets.clear();
    }

    if(!player3.isDestroied()){

        PlayerBullet bullet3{QVector2D(player3.Position().x()+0.094f, player3.Position().y() + 0.2f),
                    QVector3D(1.0f, 1.0f, 1.0f)};
        if(player3SkillSta.secsTo(player3SkillEnd) < 300 && player3.getSkill() == "Redbullet"){
            bullet3.setDamage(blueBullet);
        }else{
            bullet3.setDamage(normalBullet);
        }
        bullet3.setSpeed(player3.getSpeed() * 3);
        player3.playerbullets.push_back(bullet3);
        soundengine.ShootBullet();

        //player bullet move up
        if(player3.playerbullets.size()){
            player3.bulletMoveUp();
        }

    }else{
        player3.playerbullets.clear();
    }

    //change game state by time use fixed param
    current = QTime::currentTime();
    long long dtll = lastFrame.msecsTo(current);
    float dt =  dtll / 200.0f;
    lastFrame = current;
    int total = start.secsTo(current);

    int prevStage = state;
    if(total < 60){
        state = STAGE_1;
    }else if(total >= 60){
        state = STAGE_2;
    }else if(total >= 120){
        state = STAGE_3;
    }else if(total >= 180){
        state = STAGE_4;
    }
    int currStage = state;
    if(prevStage != currStage)
        soundengine.nextStage();

    //update particles
    if(!player1.isDestroied())
    ParticleGenerator1->update((float)dt, player1, 2, QVector2D(0.5f, 0.5f));

    if(!player2.isDestroied())
    ParticleGenerator2->update((float)dt, player2, 2, QVector2D(0.5f, 0.5f));

    if(!player3.isDestroied())
    ParticleGenerator3->update((float)dt, player3, 2, QVector2D(0.5f, 0.5f));

    //gen Enemy Plane
    int type = RNG::genEnemyType();
    switch(type){

    //gen small
    case 0:if(sEnemys.size() < 8){
            QVector4D sPosition (RNG::genEnemyLocation(), 0.9f, 0.0f, 0.0f);
            EnemyPlane planes(sPosition, QVector3D(1.0f, 1.1f, 1.0f), 0);
            planes.setSpeed(0.01f);
            sEnemys.push_back(planes);
            }
        break;

    //middle
    case 1:if(mEnemys.size() < 3 && (state == STAGE_2 || state == STAGE_3)){
            QVector4D mPosition (RNG::genEnemyLocation(), 1.1f, 0.0f, 0.0f);
            EnemyPlane planem(mPosition, QVector3D(1.0f, 1.0f, 1.0f), 1);
            planem.setSpeed(0.008f);
            mEnemys.push_back(planem);
            }
        break;

    //big
    case 2:if(bEnemys.size() < 1 && (state == STAGE_3 || state == STAGE_4)){
            QVector4D bPosition (RNG::genEnemyLocation(), 1.1f, 0.0f, 0.0f);
            EnemyPlane planeb(bPosition, QVector3D(1.0f, 1.0f, 1.0f), 2);
            planeb.setType(type);
            planeb.setSpeed(0.00625f);
            bEnemys.push_back(planeb);
            qDebug() << "big enemy gen";
            }
        break;

    default: break;
    }

    //enemy plane operations
    if(sEnemys.size()){
        //moving
        for(EnemyPlane* i = sEnemys.begin(); i != sEnemys.end(); ++i){
            i->planeMoveDown();
            if(!player1.isDestroied())
            doCollide(&player1, i);
            if(!player2.isDestroied())
            doCollide(&player2, i);
            if(!player3.isDestroied())
            doCollide(&player3, i);
        }

        //check their state and release
        for(EnemyPlane* i=sEnemys.begin(); i !=sEnemys.end();){
            if(i->isDestroied()){
                //delete enemy plane
                i->setDestroied();
                sEnemys.erase(i);
            }else{
                i++;
            }
        }
    }

    if(mEnemys.size()){
        //gen enemy bullets, if difficulty isn't easy
        if(difficulty != EASY){
            for(EnemyPlane* i = sEnemys.begin(); i != sEnemys.end(); ++i){
            QVector2D mPosition = i->Position();
            EnemyBullet bulletm(QVector4D(mPosition.x() + 0.15f, mPosition.y()-0.05f, 0.0f, 0.0f),
                                    QVector3D(1.0f, 1.0f, 1.0f));
            bulletm.setSpeed(i->getSpeed() * 3);
            i->enemybullets.push_back(bulletm);
            }
        }

        //moving
        for(EnemyPlane* i = mEnemys.begin(); i != mEnemys.end(); ++i){
            i->planeMoveDown();
            i->bulletMoveDown();
            if(!player1.isDestroied())
                doCollide(&player1, i);
            if(!player2.isDestroied())
                doCollide(&player2, i);
            if(!player3.isDestroied())
            doCollide(&player3, i);
        }

        //check their state and release
        for(EnemyPlane* i = mEnemys.begin(); i != mEnemys.end();){
            if(i->isDestroied()){
                i->setDestroied();
                i->enemybullets.clear();
                mEnemys.erase(i);
            }else{
                i++;
            }
        }
    }

    if(bEnemys.size()){
        //gen bullets
        if(difficulty == HARD){
            for(EnemyPlane* i = bEnemys.begin(); i != bEnemys.end(); ++i){
                //bullet group
                QVector2D bPosition = i->Position();
                EnemyBullet bulletb1(QVector4D(bPosition.x() + 0.3f, bPosition.y()-0.05f, 0.0f, 0.0f),
                                    QVector3D(1.0f, 1.0f, 1.0f));
                EnemyBullet bulletb2(QVector4D(bPosition.x() + 0.5f, bPosition.y()-0.05f, 0.0f, 0.0f),
                                    QVector3D(1.0f, 1.0f, 1.0f));
                EnemyBullet bulletb3(QVector4D(bPosition.x() + 0.7f, bPosition.y()-0.05f, 0.0f, 0.0f),
                                    QVector3D(1.0f, 1.0f, 1.0f));
                bulletb1.setSpeed(i->getSpeed() * 3);
                bulletb2.setSpeed(i->getSpeed() * 3);
                bulletb3.setSpeed(i->getSpeed() * 3);
                i->enemybullets.push_back(bulletb1);
                i->enemybullets.push_back(bulletb2);
                i->enemybullets.push_back(bulletb3);
            }
        }

        //moving
        for(EnemyPlane* i = bEnemys.begin(); i != bEnemys.end(); ++i){
            i->planeMoveDown();
            i->bulletMoveDown();
            if(!player1.isDestroied())
            doCollide(&player1, i);
            if(!player2.isDestroied())
            doCollide(&player2, i);
            if(!player3.isDestroied())
            doCollide(&player3, i);
        }

        //check their state and release
        for(EnemyPlane* i = bEnemys.begin(); i != bEnemys.end();){
            if(i->isDestroied()){
                i->enemybullets.clear();
                bEnemys.erase(i);
            }else{
                i++;
            }
        }
    }

    if(player1.isDestroied() && player2.isDestroied() && player3.isDestroied()){
        for(int i=0; i < playernames.size(); ++i){
            if(i == 0){
                std::cout << player1.getSkill().toStdString();
                std::cout << '\n';
                std::cout << player1.getScore();
                std::cout << '\n';
                std::string strdif;
                switch(difficulty){
                case 0: strdif = "Easy"; break;
                case 1: strdif = "Normal"; break;
                case 2: strdif = "hard"; break;
                default: strdif = "unkonwn";
                }
                std::cout << strdif;
                std::cout << '\n';
                std::cout << total / 60;
                std::cout << '\n';
            }else if(i == 1){
                std::cout << player2.getSkill().toStdString();
                std::cout << '\n';
                std::cout << player2.getScore();
                std::cout << '\n';
                std::string strdif;
                switch(difficulty){
                case 0: strdif = "Easy"; break;
                case 1: strdif = "Normal"; break;
                case 2: strdif = "hard"; break;
                default: strdif = "unkonwn";
                }
                std::cout << strdif;
                std::cout << '\n';
                std::cout << total / 60;
                std::cout << '\n';
            }else if(i == 2){
                std::cout << player3.getSkill().toStdString();
                std::cout << '\n';
                std::cout << player3.getScore();
                std::cout << '\n';
                std::string strdif;
                switch(difficulty){
                case 0: strdif = "Easy"; break;
                case 1: strdif = "Normal"; break;
                case 2: strdif = "hard"; break;
                default: strdif = "unkonwn";
                }
                std::cout << strdif;
                std::cout << '\n';
                std::cout << total / 60;
                std::cout << '\n';
            }

        }
        //close the game window
        this->close();

    }
}

void PlaneWar::drawGameThings(QVector2D trans, QVector2D scale, QVector3D color, QImage tex){
    program->bind();
    QMatrix4x4 model;
    model.translate(trans);
    model.scale(scale);

    program->setUniformValue("model", model);
    program->setUniformValue("inColor", color);

    QOpenGLTexture* texture = new QOpenGLTexture(tex.mirrored());
    texture->setMinMagFilters(QOpenGLTexture::Linear, QOpenGLTexture::Linear);
    texture->bind();

    vao->bind();
    glDrawArrays(GL_TRIANGLES, 0, 6);
    delete texture;
}

void PlaneWar::drawParticle(ParticleGenerator* generator, GameObject* object, QImage tex){
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    particlePro->bind();
    QOpenGLTexture* texture = new QOpenGLTexture(tex.mirrored());
    texture->setMinMagFilters(QOpenGLTexture::Linear, QOpenGLTexture::Linear);
    texture->bind();

    for(Particle particle:generator->particles){
        QMatrix4x4 model;
        model.translate(object->Position().x() + 0.0825f, object->Position().y());
        float size = RNG::genParticleSize();
        model.scale(QVector2D(size, size));

        if(particle.Life > 0.0f){
            particlePro->setUniformValue("projection", model);
            particlePro->setUniformValue("offset", particle.Position);
            particlePro->setUniformValue("color", particle.Color);
            particleVao->bind();
            glDrawArrays(GL_TRIANGLES, 0, 6);
        }
    }
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void PlaneWar::paintGL(){
    QString backPath = ":/images/images/backgroundOri.png";
    drawGameThings(QVector2D(-1.0f, -1.0f), QVector2D(2.0f, 2.0f), QVector3D(1.0f, 1.0f, 1.0f), QImage(backPath));

    //draw play time
    current = QTime::currentTime();
    int total = start.secsTo(current);
    drawGameThings(QVector2D(-1.0f, 0.9f), QVector2D(0.5f, 0.0625f), QVector3D(1.0f,1.0f,1.0f),
                   genImageFromQString(QString::number(total)+" seconds", Qt::white));

    //draw player1
    if(!player1.isDestroied()){
        //draw it's particles
        drawParticle(ParticleGenerator1, &player1, QImage(":/images/images/particle.png"));

        drawGameThings(player1.Position(), QVector2D(0.2f, 0.2f), player1.Color(), QImage(skins[player1.skinIndex]));

        //draw its health
        drawGameThings(QVector2D(-1.0f, -1.0f), QVector2D(0.5f, 0.0625f), QVector3D(1.0f, 1.0f, 1.0f),
                       genImageFromQString(QString::number(player1.getHealth()), genFontColor(skins[player1.skinIndex])));


        //draw its energy
        drawGameThings(QVector2D(-0.8f, -1.0f), QVector2D(0.5f, 0.0625f), QVector3D(1.0f, 1.0f, 1.0f),
                       genImageFromQString(QString::number(player1.getEnergy()), genFontColor(skins[player1.skinIndex])));

        //draw its score
        drawGameThings(QVector2D(-0.6f, -1.0f), QVector2D(0.5f, 0.0625f), QVector3D(1.0f, 1.0f, 1.0f),
                       genImageFromQString(QString::number(player1.getScore()), genFontColor(skins[player1.skinIndex])));

        //draw bullets
        if(player1.playerbullets.size()){
            //bind texture
            QString path = bulletPath;
            if(player1.playerbullets[player1.playerbullets.size()-1].getDamage() == 40)
                path = blueBulletPath;
            QOpenGLTexture* texturepb1 = new QOpenGLTexture(QImage(path).mirrored());
            texturepb1->setMinMagFilters(QOpenGLTexture::Linear, QOpenGLTexture::Linear);
            texturepb1->bind();

            for(PlayerBullet* i =player1.playerbullets.begin(); i != player1.playerbullets.end(); ++i){
                    QMatrix4x4 model;
                    model.translate(i->Position());

                    //right position here, on rotation is needed
                    model.scale(0.02f, 0.02f, 1.0f);

                    program->setUniformValue("model", model);
                    program->setUniformValue("inColor", i->Color());
                    vao->bind();
                    glDrawArrays(GL_TRIANGLES, 0, 6);

            }
            delete texturepb1;
        }

    }

    //draw player2
    if(!player2.isDestroied()){
        //draw particles
        drawParticle(ParticleGenerator2, &player2, QImage(":/images/images/particle.png"));

        //bind texture
        drawGameThings(player2.Position(), QVector2D(0.2f, 0.2f), player2.Color(), QImage(skins[player2.skinIndex]));

        //draw its health
        drawGameThings(QVector2D(-0.3f, -1.0f), QVector2D(0.5f, 0.0625f), QVector3D(1.0f, 1.0f, 1.f),
                       genImageFromQString(QString::number(player2.getHealth()), genFontColor(skins[player2.skinIndex])));

        //draw its energy
        drawGameThings(QVector2D(-0.1f, -1.0f), QVector2D(0.5f, 0.0625f), QVector3D(1.0f, 1.0f, 1.f),
                       genImageFromQString(QString::number(player2.getEnergy()), genFontColor(skins[player2.skinIndex])));

        //draw its score
        drawGameThings(QVector2D(0.1f, -1.0f), QVector2D(0.5f, 0.0625f), QVector3D(1.0f, 1.0f, 1.f),
                       genImageFromQString(QString::number(player2.getScore()), genFontColor(skins[player2.skinIndex])));

        //draw bullets
        if(player2.playerbullets.size()){
            //bind texture
            QString path = bulletPath;
            if(player2.playerbullets[player2.playerbullets.size()-1].getDamage() == 30)
                path = blueBulletPath;
            QOpenGLTexture* texturepb2 = new QOpenGLTexture(QImage(path).mirrored());
            texturepb2->setMinMagFilters(QOpenGLTexture::Linear, QOpenGLTexture::Linear);
            texturepb2->bind();

            for(PlayerBullet* i = player2.playerbullets.begin(); i != player2.playerbullets.end(); ++i){
                    QMatrix4x4 model;
                    model.translate(i->Position());

                    //right position here, on rotation is needed
                    model.scale(0.02f, 0.02f);

                    program->setUniformValue("model", model);
                    program->setUniformValue("inColor", i->Color());
                    vao->bind();
                    glDrawArrays(GL_TRIANGLES, 0, 6);


            }
            delete texturepb2;
        }

    }

    //draw player3
    if(!player3.isDestroied()){
        //draw  particle
        drawParticle(ParticleGenerator3, &player3, QImage(":/images/images/particle.png"));

        //bind texture
        drawGameThings(player3.Position(), QVector2D(0.2f, 0.2f), player3.Color(), QImage(skins[player3.skinIndex]));

        //draw its health
        drawGameThings(QVector2D(0.4f, -1.0f), QVector2D(0.5f, 0.0625f), QVector3D(1.0f, 1.0f, 1.f),
                       genImageFromQString(QString::number(player2.getHealth()), genFontColor(skins[player3.skinIndex])));


        //draw its energy
        drawGameThings(QVector2D(0.6f, -1.0f), QVector2D(0.5f, 0.0625f), QVector3D(1.0f, 1.0f, 1.f),
                       genImageFromQString(QString::number(player2.getEnergy()), genFontColor(skins[player3.skinIndex])));

        //draw its score
        drawGameThings(QVector2D(0.8f, -1.0f), QVector2D(0.5f, 0.0625f), QVector3D(1.0f, 1.0f, 1.f),
                       genImageFromQString(QString::number(player3.getScore()), genFontColor(skins[player3.skinIndex])));

        //bullets
        if(player3.playerbullets.size()){
            QString path = bulletPath;
            if(player3.playerbullets[player3.playerbullets.size()-1].getDamage() == 30)
                path = blueBulletPath;
            QOpenGLTexture* texturepb3 = new QOpenGLTexture(QImage(path).mirrored());
            texturepb3->setMinMagFilters(QOpenGLTexture::Linear, QOpenGLTexture::Linear);
            texturepb3->bind();

            for(PlayerBullet* i = player3.playerbullets.begin(); i != player3.playerbullets.end(); ++i){
                    glEnableVertexAttribArray(0);
                    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat),(void*) 0);

                    //bind shader
                    QMatrix4x4 model;
                    model.translate(i->Position());

                    //right position here, on rotation is needed
                    model.scale(0.02f, 0.02f, 1.0f);

                    program->setUniformValue("model", model);
                    program->setUniformValue("inColor", i->Color());
                    vao->bind();
                    glDrawArrays(GL_TRIANGLES, 0, 6);
            }
            delete texturepb3;
        }
    }

    //draw enemys
    //small
    if(sEnemys.size()){
        //bind texture
        QOpenGLTexture* texturee1 = new QOpenGLTexture(QImage(sEnemyPath).mirrored());
        texturee1->setMinMagFilters(QOpenGLTexture::Linear, QOpenGLTexture::Linear);
        texturee1->bind();

        for(EnemyPlane* i = sEnemys.begin(); i != sEnemys.end(); ++i){
            QMatrix4x4 model;
            model.translate(i->Position());

            //right position here, on rotation is needed
            model.scale(0.1f, 0.075f, 1.0f);

            program->setUniformValue("model", model);
            program->setUniformValue("inColor", i->Color());
            glDrawArrays(GL_TRIANGLES, 0, 6);
        }
        delete texturee1;
    }

    if(mEnemys.size())
    {
        QOpenGLTexture* texturee2 = new QOpenGLTexture(QImage(mEnemyPath).mirrored());
        texturee2->setMinMagFilters(QOpenGLTexture::Linear, QOpenGLTexture::Linear);
        texturee2->bind();

        QOpenGLTexture* textureeb2 = new QOpenGLTexture(QImage(bulletPath));
        textureeb2->setMinMagFilters(QOpenGLTexture::Linear, QOpenGLTexture::Linear);

        //medium
        for(EnemyPlane* i = mEnemys.begin(); i != mEnemys.end(); ++i){
            //bind texture
            QMatrix4x4 model;
            model.translate(i->Position());

            model.scale(0.3f, 0.3f, 1.0f);

            program->setUniformValue("model", model);
            program->setUniformValue("inColor", i->Color());
            glDrawArrays(GL_TRIANGLES, 0, 6);

            //draw it's bullets
            if(i->enemybullets.size()){
                //bind texture
                textureeb2->bind();
                for(EnemyBullet* j = i->enemybullets.begin(); j != i->enemybullets.end(); ++j){
                    QMatrix4x4 model;
                    model.translate(j->Position());

                    //right position here, on rotation is needed
                    model.scale(0.02f, 0.02f, 1.0f);

                    program->setUniformValue("model", model);
                    program->setUniformValue("inColor", j->Color());
                    vao->bind();
                    glDrawArrays(GL_TRIANGLES, 0, 6);
                }
                delete textureeb2;
            }
        }

        delete texturee2;
    }

    if(bEnemys.size()){
        //bind texture
        QOpenGLTexture* texturee3 = new QOpenGLTexture(QImage(bEnemyPath).mirrored());
        texturee3->setMinMagFilters(QOpenGLTexture::Linear, QOpenGLTexture::Linear);
        texturee3->bind();

        QOpenGLTexture* textureeb3 = new QOpenGLTexture(QImage(bulletPath));
        textureeb3->setMinMagFilters(QOpenGLTexture::Linear, QOpenGLTexture::Linear);
        //big
        for(EnemyPlane* i = bEnemys.begin(); i != bEnemys.end(); ++i){
            QMatrix4x4 model;
            model.translate(QVector3D(i->Position()));

            //right position here, on rotation is needed
            model.scale( 0.2f, 0.2f, 1.0f);

            program->setUniformValue("model", model);
            program->setUniformValue("inColor", i->Color());
            glDrawArrays(GL_TRIANGLES, 0, 6);

            //draw it's bullets
            if(i->enemybullets.size()){
                //bind texture
                textureeb3->bind();

                for(EnemyBullet* j = i->enemybullets.begin(); j != i->enemybullets.end(); ++j){
                    QMatrix4x4 model;
                    model.translate(j->Position());

                    //right position here, on rotation is needed
                    model.scale(0.02f, 0.02f, 1.0f);

                    program->setUniformValue("model", model);
                    program->setUniformValue("inColor", j->Color());

                    glDrawArrays(GL_TRIANGLES, 0, 6);
                }

                delete textureeb3;
            }
        }

        delete texturee3;
   }
}

void PlaneWar::keyPressEvent(QKeyEvent* event){
    if(!event->isAutoRepeat())
        keysToProcess.insert(event->key());
    if(!keyInterval->isActive())
        keyInterval->start(100);
}

void PlaneWar::keyReleaseEvent(QKeyEvent *event){
    if(!event->isAutoRepeat())
        keysToProcess.remove(event->key());
    if(keysToProcess.isEmpty())
        keyInterval->stop();
}

QImage PlaneWar::genImageFromQString(QString text, QColor color){
    QImage image(200, 25, QImage::Format_ARGB32_Premultiplied);
    image.fill(QColor(0,0,0,0));
    QPainter painter;

    QFont font("Consolas", 0);
    painter.begin(&image);
    font.setPointSize(10);
    painter.setFont(font);
    QPen pen;
    pen.setColor(color);
    painter.setPen(pen);
    QTextOption option(Qt::AlignLeft | Qt::AlignTop);//make text auto
    option.setWrapMode(QTextOption::WordWrap);
    QRectF rect(0, 0, 200, 25);
    painter.drawText(rect, text, option);//draw it to form a pic
    painter.end();

    return image;
}

QColor PlaneWar::genFontColor(QString texPath){
    if(texPath == ":/images/images/player1.png")
        return Qt::red;
    else if(texPath == ":/images/images/player2.png")
        return Qt::green;
    else if(texPath == ":/images/images/player3.png")
        return Qt::blue;
    else if(texPath == ":/images/images/player4.png")
        return Qt::cyan;
    else if(texPath == ":/images/images/player5.png")
        return Qt::yellow;
    else if(texPath == ":/images/images/player6.png")
        return Qt::magenta;
    else return Qt::white;
}

void PlaneWar::processKeys(){
    if(keysToProcess.isEmpty()){
        keyInterval->stop();
        return;
    }

    for(int key:keysToProcess){
        switch(key){
        case Qt::Key_W: player1.moveUp();break;
        case Qt::Key_S: player1.moveDown(); break;
        case Qt::Key_A: player1.moveLeft(); break;
        case Qt::Key_D: player1.moveRight(); break;

        case Qt::Key_Up: player2.moveUp(); break;
        case Qt::Key_Down: player2.moveDown(); break;
        case Qt::Key_Left: player2.moveLeft(); break;
        case Qt::Key_Right: player2.moveRight(); break;

        case Qt::Key_I: player3.moveUp(); break;
        case Qt::Key_K: player3.moveDown(); break;
        case Qt::Key_J: player3.moveLeft(); break;
        case Qt::Key_L: player3.moveRight(); break;

        case Qt::Key_Q:{
            //skill
            QString type = player1.getSkill();
            if(player1.canUseSkill()){
                if(type == "Bomb"){
                    this->soundengine.Bomb();
                    qDebug() << "Bomb used";
                    for(EnemyPlane* i = sEnemys.begin(); i != sEnemys.end(); ++i){
                        i->takeDamage(150);
                        if(i->isDestroied()){
                            qDebug() << "enemy destroied";
                                player1.changeScore(10);
                                player1.addEnergy(5);
                            }
                    }
                    for(EnemyPlane* i = mEnemys.begin(); i != mEnemys.end(); ++i){
                        i->takeDamage(150);
                        if(i->isDestroied()){
                                player1.changeScore(50);
                                player1.addEnergy(20);
                            }
                        }
                    for(EnemyPlane* i = bEnemys.begin(); i != bEnemys.end(); ++i){
                        i->takeDamage(150);
                        if(i->isDestroied()){
                                player1.changeScore(100);
                                player1.addEnergy(50);
                            }
                        }
                }
                else if(type == "Redbullet"){
                    this->soundengine.RedBullet();
                    player1SkillSta = QTime::currentTime();
                }
                else if(type == "Heal"){
                    this->soundengine.Heal();
                    for(PlayerPlane* i:livePlanes){
                        i->restoreAllHealth();
                    }
                }
                else if(type == "Crush"){
                    this->soundengine.Crush();
                    player1SkillSta = QTime::currentTime();
                }

            }
        }
            break;
        case Qt::Key_Slash:{
            //skill
            QString type = player2.getSkill();
            if(player2.canUseSkill()){
                if(type == "Bomb"){
                    this->soundengine.Bomb();
                    for(EnemyPlane* i = sEnemys.begin(); i != sEnemys.end(); ++i){
                        i->takeDamage(150);
                        if(i->isDestroied()){
                            player2.changeScore(10);
                            player2.addEnergy(5);
                        }
                    }
                    for(EnemyPlane* i = mEnemys.begin(); i != mEnemys.end(); ++i){
                        i->takeDamage(150);
                        if(i->isDestroied()){
                            player2.changeScore(50);
                            player2.addEnergy(20);
                        }
                    }
                    for(EnemyPlane* i = bEnemys.begin(); i != bEnemys.end(); ++i){
                        i->takeDamage(150);
                        if(i->isDestroied()){
                            player2.changeScore(100);
                            player2.addEnergy(50);
                        }
                    }
                }
            }
                else if(type == "Redbullet"){
                this->soundengine.RedBullet();
                    player2SkillSta = QTime::currentTime();
                }
                else if(type == "Heal"){
                this->soundengine.Heal();
                    for(PlayerPlane* i:livePlanes){
                        i->restoreAllHealth();
                    }
                }
                else if(type == "Crush"){
                this->soundengine.Crush();
                    player2SkillSta = QTime::currentTime();
                }
        }
            break;
        case Qt::Key_U:{
            //skill
            QString type = player3.getSkill();
            if(player3.canUseSkill()){
                if(type == "Bomb"){
                    this->soundengine.Bomb();
                    for(EnemyPlane* i = sEnemys.begin(); i != sEnemys.end(); ++i){
                        i->takeDamage(150);
                        if(i->isDestroied()){
                            player3.changeScore(10);
                            player3.addEnergy(5);
                        }
                    }
                    for(EnemyPlane* i = mEnemys.begin(); i != mEnemys.end(); ++i){
                        i->takeDamage(150);
                        if(i->isDestroied()){
                            player3.changeScore(50);
                            player3.addEnergy(20);
                        }
                    }
                    for(EnemyPlane* i = bEnemys.begin(); i != bEnemys.end(); ++i){
                        i->takeDamage(150);
                        if(i->isDestroied()){
                            player3.changeScore(100);
                            player3.addEnergy(50);
                        }
                    }
                }
                else if(type == "Redbullet"){
                    this->soundengine.RedBullet();
                    player3SkillSta = QTime::currentTime();
                }
                else if(type == "Heal"){
                    this->soundengine.Heal();
                    for(PlayerPlane* i:livePlanes){
                        i->restoreAllHealth();
                    }
                }
                else if(type == "Crush"){
                    this->soundengine.Crush();
                    player3SkillSta = QTime::currentTime();
                }
            }
        }
            break;
        default:break;
        }
    }
}
