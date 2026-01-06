#include "chatwindow.h"
#include "ui_chatwindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QHBoxLayout>

ChatWindow::ChatWindow(QWidget *parent,Player* player)
    : QMainWindow(parent)
    , ui(new Ui::ChatWindow)
{
    ui->setupUi(this);
    this->player = player;
    this->setFixedSize(800,600);

    QWidget * widget = new QWidget(this);
    QVBoxLayout* box = new QVBoxLayout(widget);

    QLabel * labelRed = new QLabel();
    labelRed->setText("www.red_putitec.com");
    labelRed->setAlignment(Qt::AlignLeft);
    labelRed->setFont(QFont("Minecraft",10));
    labelRed->setStyleSheet("color: rgb(100, 32, 170);");
    box->addWidget(labelRed);

    QWidget* leftWidget = new QWidget(this);
    QWidget* middleWidget= new QWidget(this);
    QWidget* rightWidget = new QWidget(this);

    leftWidget->setFixedSize(200,550);
    leftWidget->setStyleSheet("background-color: rgb(255, 62, 165); padding: 0px;");

    middleWidget->setFixedSize(400,550);
    middleWidget->setStyleSheet("background-color: rgb(100, 32, 170); padding: 0px;");

    rightWidget->setFixedSize(200,550);
    rightWidget->setStyleSheet("background-color: rgb(255, 62, 165); padding: 0px;");

    QHBoxLayout* horizontalLayout = new QHBoxLayout();
    horizontalLayout->setSpacing(0);
    horizontalLayout->setContentsMargins(0,0,0,0);
    horizontalLayout->addWidget(leftWidget);
    horizontalLayout->addWidget(middleWidget);
    horizontalLayout->addWidget(rightWidget);

    box->addLayout(horizontalLayout);

    widget->setLayout(box);
    setCentralWidget(widget);

    // connect(btnLoad,&QPushButton::clicked,this, &MainWindow::on_btnLoad_clicked);
    // connect(btnNew,&QPushButton::clicked,this,&MainWindow::on_btnNew_clicked);
    // //emisor,accion,receptor,reaccion

}

ChatWindow::~ChatWindow()
{
    delete ui;
}
