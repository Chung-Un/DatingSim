#include "avatarwindow.h"
#include "ui_avatarwindow.h"

#include<QWidget>
#include<QVBoxLayout>
#include<QGridLayout>
#include<QLabel>
#include<QPushButton>
#include <QSize>

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
    labelTitulo->setStyleSheet("color: rgb(255,62,165); padding: 10px;");
    box->addWidget(labelTitulo);

    QWidget* widgetPfps = new QWidget(this);
    QGridLayout* grid = new QGridLayout(widgetPfps);

    for(int row=0;row<3;row++){
        for(int col=0;col<3;col++){
            QPushButton* btn = new QPushButton();
            int index = row*3 + col + 1;

            QString pfpPath =  QString("://res/Pfps/pfp%1.jpg").arg(index);
            QPixmap pfpPixmap(pfpPath);

            if(!pfpPixmap.isNull()){
                btn->setIcon(pfpPixmap.scaled(180,180,Qt::KeepAspectRatio,Qt::SmoothTransformation));
                btn->setIconSize(QSize(180,180));
                btn->setStyleSheet("padding: 0px");
                pfps.push_back(pfpPixmap);
            }else{
                continue;
            }

            grid->addWidget(btn,row,col);
            pfpBtns.push_back(btn);
        }

    }

    addBtn = new QPushButton();
    addBtn->setText("Subir una\nfoto de perfil");
    addBtn->setFont(QFont("Minecraft",18,QFont::Normal));
    addBtn->setFixedSize(180,180);
    addBtn->setStyleSheet("color: rgb(255, 181, 218); background-color: rgb(255,62,165); padding: 0px;");
    grid->addWidget(addBtn,2,2);
    pfpBtns.push_back(addBtn);

    grid->setAlignment(Qt::AlignVCenter);

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
