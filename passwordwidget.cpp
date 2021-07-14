#include "passwordwidget.h"
#include "passwordentry.h"
#include "ui_passwordwidget.h"
#include <QDebug>
#include <qrsaencryption.h>
#include <QCryptographicHash>
#include <QStandardPaths>

PasswordWidget::PasswordWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PasswordWidget)
{
    ui->setupUi(this);
    this->database = new Database();
    qDebug() << this->database->connect();

    QByteArray pub, priv;
    QRSAEncryption e(QRSAEncryption::Rsa::RSA_2048);
    e.generatePairKey(pub, priv); // or other rsa size

    QByteArray msg = "test message";

    auto encryptMessage = e.encode(msg, pub);

    if (encryptMessage == msg)
        qDebug() << "still encoded";

    auto decodeMessage = e.decode(encryptMessage, priv);

    QByteArray hash;
    if(decodeMessage == msg) {
        qDebug() << "decode successful";
        hash = QCryptographicHash::hash(pub, QCryptographicHash::Sha256);
    }

    QString filename = "";
    for(char c : hash) {
        if((c > 64 && c < 91) || (c > 96 && c < 122)) {
            filename.append(c);
        }
    }
    qDebug() << filename.append(".bin");
    qDebug() << qApp->libraryPaths();


    /*QPalette customPalette;
    QPalette orginalPallete = ui->listWidget->palette();
    customPalette.setBrush(QPalette::Inactive, QPalette::NoRole,
                            orginalPallete.brush(QPalette::Active, QPalette::Highlight));
    ui->listWidget->setPalette(customPalette);*/
    this->setStyleSheet("QListWidget:item:selected:active {background: green;}"
                        "QListWidget:item:selected:!active {background: white;}");
    ui->listWidget->addItem("traknet");
    //ui->listWidget->item(0)->setFlags(ui->listWidget->item(0)->flags() & ~Qt::ItemIsSelectable);
    ui->listWidget_2->addItem("password");
    connect(ui->toolButton, SIGNAL(clicked()), this, SLOT(showDialog()));
    connect(ui->listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(showDialog(QListWidgetItem*)));
}

void PasswordWidget::showDialog() {
    PasswordEntry *entry = new PasswordEntry(this);
    connect(entry, SIGNAL(addItemSignal(QString, QString)), this, SLOT(addItemSlot(QString, QString)));
    entry->show();
}

void PasswordWidget::showDialog(QListWidgetItem *item) {
    qDebug() << ui->listWidget->row(item);
    int row = ui->listWidget->row(item);
    QString account = item->text();
    QString password = ui->listWidget_2->item(row)->text();
    PasswordEntry *entry = new PasswordEntry(this, account, password, row);
    connect(entry, SIGNAL(editItemSignal(QString, QString, int)), this, SLOT(editItemSlot(QString, QString, int)));
    entry->show();
}

void PasswordWidget::addItemSlot(QString account, QString password) {
   ui->listWidget->addItem(account);
   ui->listWidget_2->addItem(password);
}

void PasswordWidget::editItemSlot(QString account, QString password, int row) {
   //ui->listWidget->addItem(account);
   ui->listWidget->item(row)->setText(account);
   //ui->listWidget_2->addItem(password);
   ui->listWidget_2->item(row)->setText(password);
}

PasswordWidget::~PasswordWidget()
{
    delete ui;
}
