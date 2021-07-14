#ifndef NOTELIST_H
#define NOTELIST_H

#include <QListWidget>

namespace Ui {
class NoteList;
}

class NoteList : public QListWidget
{
    Q_OBJECT

public:
    explicit NoteList(QListWidget *parent = nullptr);
    ~NoteList();

private:
    Ui::NoteList *ui;
};

#endif // NOTELIST_H
