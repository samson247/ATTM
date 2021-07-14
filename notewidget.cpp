#include "notewidget.h"
#include "ui_notewidget.h"
#include <QTextEdit>
#include <QPushButton>
#include <QDebug>

NoteWidget::NoteWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NoteWidget)
{
    ui->setupUi(this);
    noteTitle = new NoteLabel();
    noteTitle->setText("New Note");
    noteTitle->setAlignment(Qt::AlignHCenter);

    //noteTitle->show();
    ui->scrollArea->setWidgetResizable( true );

    //layout = new QVBoxLayout();

    QFrame *frame = new QFrame(ui->scrollArea);
    //frame->widgetRe
    //ui->scrollArea->setWidget(widget);
    layout = new QVBoxLayout();
    ui->scrollArea->setWidget(frame);
    noteBody = new QTextEdit();
    QPushButton *addNoteButton = new QPushButton();
    addNoteButton->setText("Add Note");
    layout->addWidget(noteTitle);
    layout->addWidget(noteBody);
    layout->addWidget(addNoteButton);
    frame->setLayout(layout);
    frame->show();

    Note *note = new Note(noteTitle->text(), noteBody->toPlainText());
    notes.append(note);
    //widget->addWidget(noteTitle);

    //layout->replaceWidget(noteTitle, ui->label);
    //ui->label->hide();
    //layout->addWidget(passwordWidget);
    //noteTitle = new NoteLabel(this);
    //replaceWidget(noteTitle, ui->label);
    //ui->label->hide();

    // Rewrite this with new push button
    connect(addNoteButton, SIGNAL(clicked()), this, SLOT(addNote()));
    connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(openNote(QListWidgetItem*)));
}

void NoteWidget::selectTitle() {

}

void NoteWidget::addNote() {
    notes.at(0)->setMessage("fuck the feds");
    qDebug() << notes.at(0)->getMessage();
    Note *note = new Note("New Note", "");
    notes.append(note);
    noteTitle->setText("In add note slot");
    ui->listWidget->addItem(noteTitle->text());
}

void NoteWidget::openNote(QListWidgetItem* item) {
    qDebug() << item->text();
    noteTitle->setText("Old note reselected");
    noteBody->setText("Changingbased on item click");
    //noteBody->setText(NoteModel::getNote(int index));
}

NoteWidget::~NoteWidget()
{
    delete ui;
}
