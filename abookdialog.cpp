#include "abookdialog.h"
#include "ui_abookdialog.h"

ABookDialog::ABookDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ABookDialog)
{
    ui->setupUi(this);
    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(addItem()));
}

void ABookDialog::addItem() {
    emit newContactSignal("Jim Jones", "123 street", "1212121",
                          "21212121", "2121212", "23232323");
    this->close();
}

ABookDialog::~ABookDialog()
{
    delete ui;
}
