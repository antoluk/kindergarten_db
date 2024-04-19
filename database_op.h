#ifndef DATABASE_OP_H
#define DATABASE_OP_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>
#include <QMap>
#include <QStringList>
#include <QSqlQueryModel>

QMap<QString, QStringList> getTablesAndColumns(QSqlDatabase db);
bool insertIntoTable(QSqlDatabase db, const QString& tableName, const QMap<QString, QVariant>& data);
bool updateTable(QSqlDatabase db, const QString& tableName, const QString& idColumnName, const QVariant& idValue, const QMap<QString, QVariant>& data);
QString selectFromTable(QSqlDatabase db, const QString& tableName);
bool deleteFromTable(QSqlDatabase db, const QString& tableName, const QMap<QString, QVariant>& conditions);

#endif // DATABASE_OP_H
