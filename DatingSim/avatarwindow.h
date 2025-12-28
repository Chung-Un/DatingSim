#ifndef AVATARWINDOW_H
#define AVATARWINDOW_H

#include <QMainWindow>
#include "player.h"
#include <Qvector>
#include <QPixmap>
#include <QPushButton>
#include <QMessageBox>

namespace Ui {
class AvatarWindow;
}

class AvatarWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AvatarWindow(QWidget *parent = nullptr,Player * player=nullptr);
    ~AvatarWindow();
    Player* player;
    QVector<QPixmap> pfps;
    QVector<QPushButton*> pfpBtns;

private slots:
    void on_btn_clicked();
    void on_addBtn_clicked();

private:
    Ui::AvatarWindow *ui;
    QPushButton* addBtn;
    QPixmap currentPixmap;
    QMessageBox* msgBox;

};

#endif // AVATARWINDOW_H
