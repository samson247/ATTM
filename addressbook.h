#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <QWidget>

namespace Ui {
class AddressBook;
}

class AddressBook : public QWidget
{
    Q_OBJECT

public:
    explicit AddressBook(QWidget *parent = nullptr);
    ~AddressBook();

private:
    Ui::AddressBook *ui;
};

#endif // ADDRESSBOOK_H
