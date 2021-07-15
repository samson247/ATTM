#include "note.h"

Note::Note(QString title, QString message)
{
    this->title = title;
    this->message = message;
}

void Note::setTitle(QString title) {
    this->title = title;
}

void Note::setMessage(QString message) {
    this->message = message;
}

QString Note::getTitle() {
    return this->title;
}

QString Note::getMessage() {
    return this->message;
}
