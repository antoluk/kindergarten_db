#include "database_op.h"

QMap<QString, QStringList> getTablesAndColumns(QSqlDatabase db)
{
    QMap<QString, QStringList> tablesAndColumns;

    QSqlQuery query(db);
    query.exec("SELECT tablename FROM pg_catalog.pg_tables WHERE schemaname != 'pg_catalog' AND schemaname != 'information_schema';");

    while (query.next())
    {
        QString tableName = query.value(0).toString();
        QStringList columns;

        QSqlQuery columnQuery(db);
        columnQuery.exec(QString("SELECT column_name FROM information_schema.columns WHERE table_name = '%1';").arg(tableName));

        while (columnQuery.next())
        {
            columns.append(columnQuery.value(0).toString());
        }

        tablesAndColumns.insert(tableName, columns);
    }

    return tablesAndColumns;
}

bool insertIntoTable(QSqlDatabase db, const QString& tableName, const QMap<QString, QVariant>& data)
{
    QSqlQuery query(db);

    QStringList columns = getTablesAndColumns(db).value(tableName);
    if (columns.isEmpty())
    {
        qDebug() << "Table" << tableName << "does not exist.";
        return false;
    }

    QStringList columnNames;
    QStringList placeholders;

    for (const auto& column : columns)
    {
        if (data.contains(column))
        {
            columnNames.append(column);
            placeholders.append(":" + column);
        }
    }

    QString queryStr = QString("INSERT INTO %1 (%2) VALUES (%3);")
                           .arg(tableName)
                           .arg(columnNames.join(", "))
                           .arg(placeholders.join(", "));

    query.prepare(queryStr);

    for (const auto& key : data.keys()) {
        query.bindValue(":" + key, data.value(key));
    }

    return query.exec();
}

bool updateTable(QSqlDatabase db, const QString& tableName, const QString& idColumnName, const QVariant& idValue, const QMap<QString, QVariant>& data)
{
    QSqlQuery query(db);

    QStringList columns = getTablesAndColumns(db).value(tableName);
    if (columns.isEmpty())
    {
        qDebug() << "Table" << tableName << "does not exist.";
        return false;
    }

    QStringList setClauses;

    for (const auto& key : data.keys())
    {
        if (columns.contains(key))
        {
            setClauses.append(QString("%1 = :%1").arg(key));
        }
    }

    if (setClauses.isEmpty())
    {
        qDebug() << "No valid columns to update.";
        return false;
    }

    QString queryStr = QString("UPDATE %1 SET %2 WHERE %3 = :%3;")
                           .arg(tableName)
                           .arg(setClauses.join(", "))
                           .arg(idColumnName);

    query.prepare(queryStr);

    for (const auto& key : data.keys())
    {
        query.bindValue(":" + key, data.value(key));
    }

    query.bindValue(":" + idColumnName, idValue);

    return query.exec();
}

QString selectFromTable(QSqlDatabase db, const QString& tableName)
{

    QStringList columns = getTablesAndColumns(db).value(tableName);
    if (columns.isEmpty()) {
        qDebug() << "Table" << tableName << "does not exist.";
        return "";
    }

    QStringList columnNames;

    for (const auto& column : columns) {
        columnNames.append(column);
    }

    QString queryStr = QString("SELECT %1 FROM %2").arg(columnNames.join(", ")).arg(tableName);

    return queryStr;
}

bool deleteFromTable(QSqlDatabase db, const QString& tableName, const QMap<QString, QVariant>& conditions)
{
    QStringList columns = getTablesAndColumns(db).value(tableName);
    if (columns.isEmpty()) {
        qDebug() << "Table" << tableName << "does not exist.";
        return false;
    }

    QStringList conditionClauses;
    for (const auto& key : conditions.keys()) {
        conditionClauses.append(QString("%1 = :%1").arg(key));
    }

    if (conditionClauses.isEmpty()) {
        qDebug() << "No conditions specified for deletion.";
        return false;
    }

    QString queryStr = QString("DELETE FROM %1 WHERE %2;")
                           .arg(tableName)
                           .arg(conditionClauses.join(" AND "));

    QSqlQuery query(db);
    query.prepare(queryStr);

    for (const auto& key : conditions.keys()) {
        query.bindValue(":" + key, conditions.value(key));
    }

    return query.exec();
}
