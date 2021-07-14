#ifndef NOTE_H
#define NOTE_H

#include <QString>

class Note
{
public:
    QString title;
    QString message;
public:
    Note(QString, QString);
    void setTitle(QString);
    void setMessage(QString);
    QString getTitle();
    QString getMessage();
};

#endif // NOTE_H
