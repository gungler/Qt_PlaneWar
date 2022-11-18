#ifndef PLAYERSETTINGFORM_H
#define PLAYERSETTINGFORM_H

#include <QWidget>
#include "modifypasswordform.h"
#include "logoutform.h"
#include "exitform.h"

namespace Ui {
class PlayerSettingForm;
}

class PlayerSettingForm : public QWidget
{
    Q_OBJECT

public:
    explicit PlayerSettingForm(QWidget *parent = nullptr);
    ~PlayerSettingForm();

signals:
    void closeGameForm();

private slots:
    void on_btnDelete_clicked();

    void on_btnModifyPass_clicked();

    void on_btnPlayerExit_clicked();

    void gameShouldClose();


private:
    Ui::PlayerSettingForm *ui;
    void initBackground();
};

#endif // PLAYERSETTINGFORM_H
