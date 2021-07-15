#include "database.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QStandardPaths>

Database::Database()
{

}

bool Database::connect() {
    const QString DRIVER("QSQLITE");
    if(QSqlDatabase::isDriverAvailable(DRIVER)) {
        QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);
        //QStandardPaths::StandardLocation path = QStandardPaths::AppDataLocation;
        //QString fileLocation = QStandardPaths::displayName(path);
        //fileLocation.append(fileLocation);
        //qDebug() << fileLocation;
        QString prefix = "/Users/.../.../Code/Database/";
        db.setDatabaseName("/Users/samdodson/Desktop/accounts.dat");
        if(!db.open()) {
          qWarning() << "ERROR: " << db.lastError();
        }
        else {
            qDebug() << db.databaseName();
        }
    }
    setupTables();
    insertItem("traknet", "password");
    getAll();
    return true;
}

bool Database::setupTables() {
    bool successful = true;
    QSqlQuery createQuery;
    createQuery.prepare("CREATE TABLE IF NOT EXISTS accounts (id INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT, accountName VARCHAR(45), passwordHash VARCHAR(64))");
    if(!createQuery.exec()) {
        qDebug() << createQuery.lastError();
        successful = false;
    }
    else {
        qDebug() << "Table created!";
    }

    createQuery.prepare("CREATE TABLE IF NOT EXISTS salts (id INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT, salt VARCHAR(30))");
    if(!createQuery.exec()) {
        qDebug() << createQuery.lastError();
        successful = false;
    }
    else {
        qDebug() << "Table created!";
    }
    return successful;
}

bool Database::disconnect() {
    return true;
}

void Database::insertItem(QString account, QString password) {
    QSqlQuery query;
    query.prepare("INSERT INTO accounts (accountName, passwordHash) "
                   "VALUES (:accountName, :passwordHash)");
    query.bindValue(":accountName", account);
    query.bindValue(":passwordHash", password);
    if(!query.exec()) {
        qDebug() << query.lastError();
    }
    else {
        qDebug() << "Item inserted!";
    }
}

void Database::deleteItem(QString accountName, QString password) {

}

void Database::getAll() {
    QSqlQuery query("SELECT * FROM accounts");
    int idName = query.record().indexOf("accountName");
    while (query.next())
    {
       QString name = query.value(idName).toString();
       qDebug() << name;
    }
}
