#ifndef INSTRUCTIONFORM_H
#define INSTRUCTIONFORM_H

#include <QWidget>

namespace Ui {
class InstructionForm;
}

class InstructionForm : public QWidget
{
    Q_OBJECT

public:
    explicit InstructionForm(QWidget *parent = nullptr);
    ~InstructionForm();

private:
    Ui::InstructionForm *ui;
    void initBackground();
};

#endif // INSTRUCTIONFORM_H
