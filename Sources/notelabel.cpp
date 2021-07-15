#include "notelabel.h"
#include "ui_notelabel.h"

NoteLabel::NoteLabel(QWidget *parent) :
    QLabel(parent),
    ui(new Ui::NoteLabel)
{
    ui->setupUi(this);
}

void NoteLabel::mousePressEvent(QMouseEvent *ev) {

}

void NoteLabel::mouseDoubleClickEvent(QMouseEvent *event) {
    this->setText("Checking if this works");
}

NoteLabel::~NoteLabel()
{
    delete ui;
}
