#ifndef PASSWORDWIDGET_H
#define PASSWORDWIDGET_H

#include <QWidget>
#include <QListWidget>
#include <database.h>

namespace Ui {
class PasswordWidget;
}

class PasswordWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PasswordWidget(QWidget *parent = nullptr);
    ~PasswordWidget();

private:
    Ui::PasswordWidget *ui;
    Database *database;

public slots:
    void showDialog();
    void showDialog(QListWidgetItem *item);
    void addItemSlot(QString account, QString password);
    void editItemSlot(QString account, QString password, int row);
};

#endif // PASSWORDWIDGET_H
