#include "passwordentry.h"
#include "ui_passwordentry.h"
#include "homepage.h"

PasswordEntry::PasswordEntry(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PasswordEntry)
{
    ui->setupUi(this);
    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(addItem()));
}

PasswordEntry::PasswordEntry(QWidget *parent, QString account, QString password, int row) :
    QDialog(parent),
    ui(new Ui::PasswordEntry)
{
    ui->setupUi(this);
    ui->lineEdit->setText(account);
    ui->lineEdit_2->setText(password);
    this->row = row;
    this->account = account;
    this->password = password;
    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(editItem()));
}

//TODO Determine text based on item
void PasswordEntry::editItem() {
    emit editItemSignal(ui->lineEdit->text(), ui->lineEdit_2->text(), this->row);
}

void PasswordEntry::addItem() {
    emit addItemSignal(ui->lineEdit->text(), ui->lineEdit_2->text());
}

PasswordEntry::~PasswordEntry()
{
    delete ui;
}

