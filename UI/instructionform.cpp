#include "instructionform.h"
#include "ui_instructionform.h"

InstructionForm::InstructionForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InstructionForm)
{
    ui->setupUi(this);
    initBackground();
}

InstructionForm::~InstructionForm()
{
    delete ui;
}

void InstructionForm::initBackground(){
    //add background
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window, QBrush(QPixmap(":/images/images/background.png").scaled(
                                            // scale background
                                            this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
     this->setPalette(palette);
}
