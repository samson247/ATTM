#ifndef PASSWORDENTRY_H
#define PASSWORDENTRY_H

#include <QDialog>
#include <QListWidget>

namespace Ui {
class PasswordEntry;
}

class PasswordEntry : public QDialog
{
    Q_OBJECT

public:
    explicit PasswordEntry(QWidget *parent = nullptr);
    explicit PasswordEntry(QWidget *parent, QString account, QString password, int row);
    ~PasswordEntry();

signals:
    void addItemSignal(QString account, QString password);
    void editItemSignal(QString account, QString password, int row);

public slots:
    void addItem();
    void editItem();

private:
    Ui::PasswordEntry *ui;
    QString account;
    QString password;
    int row;
};

#endif // PASSWORDENTRY_H
