#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnNew_clicked();
    void on_btnLoad_clicked();

private:
    Ui::MainWindow *ui;
    QPushButton* btnNew;
    QPushButton* btnLoad;
};
#endif // MAINWINDOW_H
