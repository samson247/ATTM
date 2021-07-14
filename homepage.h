#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QMainWindow>
#include <QVBoxLayout>
#include "passwordwidget.h"
#include "addressbook.h"
#include "notewidget.h"

namespace Ui {
class HomePage;
}

class HomePage : public QMainWindow
{
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = nullptr);
    ~HomePage();

public slots:
    void showDialog();
    void showAddressBook();
    void showPassword();
    void showNotes();
    void addItemSlot(QString account, QString password);

private:
    Ui::HomePage *ui;
    PasswordWidget *passwordWidget;
    AddressBook *addressBookWidget;
    NoteWidget *noteWidget;
    QVBoxLayout *layout;
};

#endif // HOMEPAGE_H
