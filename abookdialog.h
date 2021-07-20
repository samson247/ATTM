#ifndef ABOOKDIALOG_H
#define ABOOKDIALOG_H

#include <QDialog>

namespace Ui {
class ABookDialog;
}

class ABookDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ABookDialog(QWidget *parent = nullptr);
    ~ABookDialog();

public slots:
    void addItem();

private:
    Ui::ABookDialog *ui;

signals:
    void newContactSignal(QString name, QString address, QString homePhone,
                       QString cellPhone, QString workPhone, QString email);
    //void editItemSignal(QString account, QString password, int row);
};

#endif // ABOOKDIALOG_H
