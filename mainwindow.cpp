#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>

#include "database_op.h"

#define VIEW_PAGE 1
#define CU_PAGE 2
#define SHOWID 0
#define NOSHOWID 1


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    pages.push(0);

    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("kindergarten");
    db.setUserName("postgres");
    db.setPassword("postgres");

    if (!db.open()) {
        QMessageBox::critical(this, "Error", "Could not open database");
        exit(-1);
    }

    model = new QSqlQueryModel(this);
    tablesAndColumns = getTablesAndColumns(db);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(pages.top());

    if(pages.size() > 1)
    {
        pages.pop();
    }

    if (pages.size() == 1)
    {
        labels.erase(labels.begin(), labels.end());
        editLines.erase(editLines.begin(), editLines.end());
        editDates.erase(editDates.begin(), editDates.end());
        clearLayout(ui->verticalLayout);
    }
}

void MainWindow::clearLayout(QLayout *layout)
{
    QLayoutItem *item;
    while ((item = layout->takeAt(0)) != nullptr) {
        QWidget *widget = item->widget();
        if (widget) {
            delete widget;
        }
        delete item;
    }
}

void MainWindow::createCUPage(QString tablename, int flags)
{
    pages.push(ui->stackedWidget->currentIndex());
    ui->stackedWidget->setCurrentIndex(VIEW_PAGE);
    currentTable = tablename;

    model->setQuery(selectFromTable(db,tablename));
    ui->tableView->setModel(model);

    QStringList columns = getTablesAndColumns(db).value(currentTable);
    if (columns.isEmpty()) {
        qDebug() << "Table" << currentTable<< "does not exist.";
    }
    int i = 0;
    for (const auto& column : columns) {
        if(!column.contains("_id") || flags == SHOWID)
        {
            QLabel *label = new QLabel(column);
            labels.append(label);
            ui->verticalLayout->addWidget(label);

            if(column.contains("date_"))
            {
                QDateEdit *dateEdit = new QDateEdit;
                dateEdit->setDate(QDate::currentDate());
                editDates.insert(i, dateEdit);
                ui->verticalLayout->addWidget(dateEdit);
            }
            else
            {
                QLineEdit *lineEdit = new QLineEdit;
                editLines.insert(i,lineEdit);
                ui->verticalLayout->addWidget(lineEdit);
            }
            i++;
        }
    }
}

void MainWindow::on_pushButtonCreate_clicked()
{
    pages.push(ui->stackedWidget->currentIndex());
    ui->stackedWidget->setCurrentIndex(CU_PAGE);
    ui->pushButtonCU->setText("create");
}

void MainWindow::on_pushButton_children_clicked()
{
    createCUPage("child", NOSHOWID);
}

void MainWindow::on_pushButton_legal_rep_clicked()
{
    createCUPage("legal_representative", NOSHOWID);
    showid = 0;
}


void MainWindow::on_pushButton_employes_clicked()
{
    createCUPage("employee", NOSHOWID);
    showid = 0;
}


void MainWindow::on_pushButton_groups_clicked()
{
    createCUPage("groups", SHOWID);
    showid = 1;
}


void MainWindow::on_pushButton_events_clicked()
{
    createCUPage("event", SHOWID);
    showid = 1;
}


void MainWindow::on_pushButton_activities_clicked()
{
    createCUPage("activity", SHOWID);
    showid = 1;
}


void MainWindow::on_pushButton_attendances_clicked()
{
    createCUPage("attendance", SHOWID);
    showid = 1;
}


void MainWindow::on_pushButton_eventpart_clicked()
{
    createCUPage("event_participation", SHOWID);
    showid = 1;
}


void MainWindow::on_pushButton_relationship_clicked()
{
    createCUPage("relationship", SHOWID);
    showid = 1;
}


void MainWindow::on_pushButton_resforact_clicked()
{
    createCUPage("responsible_for_activity", SHOWID);
    showid = 1;
}


void MainWindow::on_pushButton_resforevent_clicked()
{
    createCUPage("responsible_for_event", SHOWID);
    showid = 1;
}


void MainWindow::on_pushButtonCU_clicked()
{
    QMessageBox msgBox;

    QStringList columns = getTablesAndColumns(db).value(currentTable);
    if (columns.isEmpty()) {
        qDebug() << "Table" << currentTable<< "does not exist.";
    }

    QMap<QString, QVariant> data;
    int count = 0;

    for (const auto& column : columns) {
        if (!column.contains("_id") || showid)
        {
        if(column.contains("date_"))
        {
            data.insert(column, editDates[count++]->date().toString("yyyy-MM-dd"));
        }
        else
        {
            data.insert(column, editLines[count++]->text());
        }
        }
    }


    if(ui->pushButtonCU->text() == "&create")
    {
        if(insertIntoTable(db, currentTable, data)) {
            msgBox.information(this, "Success", "Record added successfully");
        } else {
            msgBox.critical(this, "Error", "Could not add record");
        }
    }else
    {

        QModelIndexList selectedIndexes = ui->tableView->selectionModel()->selectedIndexes();
        QVariant key = model->data(selectedIndexes[0]);

        if(updateTable(db, currentTable, columns[0], key, data)) {
            msgBox.information(this, "Success", "Record updated successfully");
        } else {
            msgBox.critical(this, "Error", "Could not update record");
        }

    }

    model->setQuery(selectFromTable(db,currentTable));
    ui->tableView->setModel(model);
}


void MainWindow::on_pushButtonUpdate_clicked()
{
    QModelIndexList selectedIndexes = ui->tableView->selectionModel()->selectedIndexes();
    if (!selectedIndexes.isEmpty())
    {
        pages.push(ui->stackedWidget->currentIndex());
        ui->stackedWidget->setCurrentIndex(CU_PAGE);
        ui->pushButtonCU->setText("update");
        int i = 0;
        if(!showid) i++;
        for(int j = 0;j < editDates.size()+editLines.size(); j++)
        {
            if(editLines.contains(j))
            {
                editLines.value(j)->setText(model->data(selectedIndexes[i]).toString());
            }else if (editDates.contains(j))
            {
                editDates.value(j)->setDate(QDate::fromString(model->data(selectedIndexes[i]).toString(), "yyyy-MM-dd"));
            }
            i++;
        }
    }
}


void MainWindow::on_pushButtonDelete_clicked()
{
    QMessageBox msgBox;
    if(ui->tableView->selectionModel()->hasSelection())
    {
        QStringList columns = getTablesAndColumns(db).value(currentTable);
        QModelIndexList selectedIndexes = ui->tableView->selectionModel()->selectedIndexes();
        QVariant id = model->data(selectedIndexes[0]);

        QMap<QString, QVariant> data;
        data.insert(columns[0], id);


        if(deleteFromTable(db, currentTable, data))
        {
            msgBox.information(this, "Success", "Record updated successfully");
        } else
        {
            msgBox.critical(this, "Error", "Could not update record");
        }

        model->setQuery(selectFromTable(db,currentTable));
        ui->tableView->setModel(model);
    }
}

