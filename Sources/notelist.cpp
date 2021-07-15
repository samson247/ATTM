#include "notelist.h"
#include "ui_notelist.h"

NoteList::NoteList(QListWidget *parent) :
    QListWidget(parent),
    ui(new Ui::NoteList)
{
    ui->setupUi(this);
}

NoteList::~NoteList()
{
    delete ui;
}
