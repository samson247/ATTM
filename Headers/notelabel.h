#ifndef NOTELABEL_H
#define NOTELABEL_H

#include <QWidget>
#include <QLabel>

namespace Ui {
class NoteLabel;
}

class NoteLabel : public QLabel
{
    Q_OBJECT

public:
    explicit NoteLabel(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *ev);
    void mouseDoubleClickEvent(QMouseEvent *event);
    ~NoteLabel();

private:
    Ui::NoteLabel *ui;
};

#endif // NOTELABEL_H
