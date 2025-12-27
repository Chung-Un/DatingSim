#ifndef AVATARWINDOW_H
#define AVATARWINDOW_H

#include <QMainWindow>
#include "player.h"
#include <Qvector>
#include <QPixmap>
#include <QPushButton>

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

private:
    Ui::AvatarWindow *ui;
    QPushButton* addBtn;

};

#endif // AVATARWINDOW_H
