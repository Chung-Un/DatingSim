#include "avatarwindow.h"
#include "ui_avatarwindow.h"

#include<QWidget>
#include<QVBoxLayout>
#include<QGridLayout>
#include<QLabel>
#include<QPushButton>

AvatarWindow::AvatarWindow(QWidget *parent,Player * player)
    : QMainWindow(parent)
    , ui(new Ui::AvatarWindow)
{
    ui->setupUi(this);
    this->player = player;

    QWidget* widgetCentral = new QWidget(this);
    QVBoxLayout* box = new QVBoxLayout(widgetCentral);

    QLabel* labelTitulo = new QLabel();
    labelTitulo->setText("Selecciona tu foto de perfil");
    labelTitulo->setAlignment(Qt::AlignCenter);
    labelTitulo->setFont(QFont("Minecraft",30,QFont::Bold));
    labelTitulo->setStyleSheet("color: rgb(255,62,165);");
    box->addWidget(labelTitulo);

    QWidget* widgetPfps = new QWidget(this);
    QGridLayout* grid = new QGridLayout(widgetPfps);

    for(int row=0;row<3;row++){
        for(int col=0;col<3;col++){
            QPushButton* btn = new QPushButton();
            btn->setText("btn " + QString::number(row) +" "+ QString::number(col));
            grid->addWidget(btn,row,col);
        }
    }

    widgetPfps->setLayout(grid);
    box->addWidget(widgetPfps);

    widgetCentral->setLayout(box);
    setCentralWidget(widgetCentral);


    // connect(btnLoad,&QPushButton::clicked,this, &MainWindow::on_btnLoad_clicked);
    // connect(btnNew,&QPushButton::clicked,this,&MainWindow::on_btnNew_clicked);
    // //emisor,accion,receptor,reaccion
}

AvatarWindow::~AvatarWindow()
{
    delete ui;
}
