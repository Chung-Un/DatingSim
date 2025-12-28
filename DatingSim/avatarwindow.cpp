#include "avatarwindow.h"
#include "ui_avatarwindow.h"

#include<QWidget>
#include<QVBoxLayout>
#include<QGridLayout>
#include <QMessageBox>
#include<QLabel>
#include<QPushButton>
#include <QSize>
#include <QFileDialog>

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
            currentPixmap = QPixmap(pfpPath);

            if(!currentPixmap.isNull()){
                btn->setIcon(currentPixmap.scaled(180,180,Qt::KeepAspectRatio,Qt::SmoothTransformation));
                btn->setIconSize(QSize(180,180));
                btn->setStyleSheet("padding: 0px");
                connect(btn,&QPushButton::clicked,this,&AvatarWindow::on_btn_clicked);
                pfps.push_back(currentPixmap);
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

    connect(addBtn,&QPushButton::clicked,this,&AvatarWindow::on_addBtn_clicked);

    grid->setAlignment(Qt::AlignVCenter);

    widgetPfps->setLayout(grid);
    box->addWidget(widgetPfps);

    widgetCentral->setLayout(box);
    setCentralWidget(widgetCentral);

    msgBox = new QMessageBox(this);
    msgBox->setWindowTitle("Exito");
    msgBox->setFont(QFont("Minecraft"));
    msgBox->setText("Foto de perfil seleccionada!");
    msgBox->setStyleSheet("background-color: rgb(255, 62, 165);");
    msgBox->setStandardButtons(QMessageBox::Ok);
    msgBox->button(QMessageBox::Ok)->setFont(QFont("Minecraft"));
    msgBox->button(QMessageBox::Ok)->setText("Yay!");
}

AvatarWindow::~AvatarWindow()
{
    delete ui;
}

void AvatarWindow::on_btn_clicked(){
    player->setPfp(currentPixmap);
    msgBox->exec();
}

void AvatarWindow::on_addBtn_clicked(){
    QString fileName = QFileDialog::getOpenFileName(this,tr("Elige tu foto de perfil: "),"C://","Imagenes (*.jpg *.jpeg *.png)");
    QPixmap pfpSubida(fileName);

    player->setPfp(pfpSubida);

    msgBox->exec();

}
