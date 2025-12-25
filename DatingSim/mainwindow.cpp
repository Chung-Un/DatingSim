#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFont>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QColor>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWidget * widget = new QWidget(this);
    QVBoxLayout* box = new QVBoxLayout(widget);

    QLabel * labelTitulo = new QLabel();
    labelTitulo->setText("Locked in");
    labelTitulo->setAlignment(Qt::AlignCenter);
    labelTitulo->setFont(QFont("Minecraft",40,QFont::Bold));
    labelTitulo->setStyleSheet("color: rgb(255, 62, 165);");
    box->addWidget(labelTitulo);

    btnNew = new QPushButton();
    btnNew->setText("Nueva partida");
    btnNew->setStyleSheet("QPushButton { background-color: rgba(255,255,255,0); color: white; padding: 10px;}"
                          "QPushButton:hover { color: rgb(100,32,170);}"
                            );
    btnNew->setFont(QFont("Minecraft",18,QFont::Bold));
    box->addWidget(btnNew);

    btnLoad = new QPushButton();
    btnLoad->setText("Cargar partida");
    btnLoad->setStyleSheet("QPushButton { background-color: rgba(255,255,255,0); color: white; padding: 10px;}"
                           "QPushButton:hover { color: rgb(100,32,170);}"
                           );
    btnLoad->setFont(QFont("Minecraft",18,QFont::Bold));
    box->addWidget(btnLoad);

    widget->setLayout(box);
    setCentralWidget(widget);

    connect(btnLoad,&QPushButton::clicked,this, &MainWindow::on_btnLoad_clicked);
    connect(btnNew,&QPushButton::clicked,this,&MainWindow::on_btnNew_clicked);
    //emisor,accion,receptor,reaccion

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnNew_clicked(){

}

void MainWindow::on_btnLoad_clicked(){
    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Ups");
    msgBox.setFont(QFont("Minecraft"));
    msgBox.setText("Esta feature no esta disponible");
    msgBox.setStyleSheet("background-color: rgb(255, 62, 165);");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.button(QMessageBox::Ok)->setFont(QFont("Minecraft"));
    msgBox.button(QMessageBox::Ok)->setText("Ok :(");
    msgBox.exec();
}

