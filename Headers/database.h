#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>

class Database
{
public:
    Database();
    bool connect();
    bool disconnect();
    void getAll();
    void insertItem(QString accountName, QString password);
    void deleteItem(QString accountName, QString password);
private:
    bool setupTables();
    QString generateHash(QString password);
    QString generateSalt();
private:
    QSqlDatabase database;
};

#endif // DATABASE_H
