#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <stack>
#include <QLabel>
#include <QLineEdit>
#include <QDateEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    QMap<QString, QStringList> tablesAndColumns;
    void createCUPage(QString tablename, int flags);
    void clearLayout(QLayout *layout);
    ~MainWindow();

private slots:

    void on_pushButton_children_clicked();

    void on_pushButton_clicked();

    void on_pushButtonCreate_clicked();

    void on_pushButton_legal_rep_clicked();

    void on_pushButton_employes_clicked();

    void on_pushButton_groups_clicked();

    void on_pushButton_events_clicked();

    void on_pushButton_activities_clicked();

    void on_pushButton_attendances_clicked();

    void on_pushButton_eventpart_clicked();

    void on_pushButton_relationship_clicked();

    void on_pushButton_resforact_clicked();

    void on_pushButton_resforevent_clicked();

    void on_pushButtonCU_clicked();

    void on_pushButtonUpdate_clicked();

    void on_pushButtonDelete_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlQueryModel *model;
    std::stack<int> pages;
    QString currentTable;
    QVector<QLabel*> labels;
    QMap<int, QLineEdit*> editLines;
    QMap<int, QDateEdit*> editDates;
    int showid = 0;
};

#endif // MAINWINDOW_H
