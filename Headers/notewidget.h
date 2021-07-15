#ifndef NOTEWIDGET_H
#define NOTEWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QVector>
#include <QTextEdit>
#include <QListWidgetItem>
#include "notelabel.h"
#include "note.h"


namespace Ui {
class NoteWidget;
}

class NoteWidget : public QWidget
{
    Q_OBJECT

public:
    explicit NoteWidget(QWidget *parent = nullptr);
    ~NoteWidget();

private:
    Ui::NoteWidget *ui;
    NoteLabel *noteTitle;
    QTextEdit *noteBody;
    QVBoxLayout *layout;
    QVector<Note*> notes;

public slots:
    void selectTitle();
    void addNote();
    void openNote(QListWidgetItem*);
};

#endif // NOTEWIDGET_H
