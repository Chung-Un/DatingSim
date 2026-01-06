#ifndef CHATWINDOW_H
#define CHATWINDOW_H
#include"player.h"

#include <QMainWindow>

namespace Ui {
class ChatWindow;
}

class ChatWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChatWindow(QWidget *parent = nullptr, Player* player=nullptr);
    ~ChatWindow();

private:
    Ui::ChatWindow *ui;
    Player* player;
};

#endif // CHATWINDOW_H
