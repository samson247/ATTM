#include "homepage.h"
#include "passwordentry.h"
#include "addressbook.h"
#include "ui_homepage.h"

HomePage::HomePage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HomePage)
{
    ui->setupUi(this);
    //ui->listWidget->addItem("traknet");
    //ui->listWidget_2->addItem("password");
    //connect(ui->toolButton, SIGNAL(clicked()), this, SLOT(showDialog()));
    passwordWidget = new PasswordWidget(this);
    addressBookWidget = new AddressBook(this);
    addressBookWidget->hide();
    noteWidget = new NoteWidget(this);
    noteWidget->hide();
    layout = new QVBoxLayout;
    layout->addWidget(ui->groupBox_2);
    layout->addWidget(passwordWidget);
    ui->centralwidget->setLayout(layout);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(showPassword()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(showAddressBook()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(showNotes()));
}

HomePage::~HomePage()
{
    delete ui;
}

void HomePage::showDialog() {
    PasswordEntry *entry = new PasswordEntry(this);
    connect(entry, SIGNAL(addItemSignal(QString, QString)), this, SLOT(addItemSlot(QString, QString)));
    entry->show();
}

void HomePage::showPassword() {
    if(addressBookWidget->isVisible()) {
        passwordWidget->show();
        layout->replaceWidget(addressBookWidget, passwordWidget);
        addressBookWidget->hide();
    }
    else if(noteWidget->isVisible()){
        passwordWidget->show();
        layout->replaceWidget(noteWidget, passwordWidget);
        noteWidget->hide();
    }
    /*passwordWidget->show();
    layout->replaceWidget(addressBookWidget, passwordWidget);
    addressBookWidget->hide();*/
}

void HomePage::showAddressBook() {
    if(passwordWidget->isVisible()) {
        addressBookWidget->show();
        layout->replaceWidget(passwordWidget, addressBookWidget);
        passwordWidget->hide();
    }
    else if(noteWidget->isVisible()) {
        addressBookWidget->show();
        layout->replaceWidget(noteWidget, addressBookWidget);
        noteWidget->hide();
    }
    /*addressBookWidget->show();
    layout->replaceWidget(passwordWidget, addressBookWidget);
    passwordWidget->hide();*/
}

void HomePage::showNotes() {
    if(passwordWidget->isVisible()) {
        noteWidget->show();
        layout->replaceWidget(passwordWidget, noteWidget);
        passwordWidget->hide();
    }
    else if(addressBookWidget->isVisible()) {
        noteWidget->show();
        layout->replaceWidget(addressBookWidget, noteWidget);
        addressBookWidget->hide();
    }
    /*noteWidget->show();
    layout->replaceWidget(addressBookWidget, noteWidget);
    addressBookWidget->hide();*/
}

void HomePage::addItemSlot(QString account, QString password) {
   // ui->listWidget->addItem(account);
   // ui->listWidget_2->addItem(password);
}
