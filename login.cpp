#include "login.h"
#include "ui_login.h"
#include "homepage.h"
#include <QPushButton>

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(login()));
}

Login::~Login()
{
    delete ui;
}

void Login::login() {
    //QWidget *wdg = new QWidget;
    HomePage *homepage = new HomePage;
    homepage->show();
    this->close();
}


