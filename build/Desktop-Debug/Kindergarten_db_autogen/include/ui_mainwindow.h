/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *main_page;
    QGroupBox *gridGroupBox;
    QGridLayout *gridLayout;
    QPushButton *pushButton_groups;
    QPushButton *pushButton_attendances;
    QPushButton *pushButton_children;
    QPushButton *pushButton_legal_rep;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_employes;
    QPushButton *pushButton_eventpart;
    QPushButton *pushButton_events;
    QPushButton *pushButton_relationship;
    QPushButton *pushButton_activities;
    QPushButton *pushButton_resforact;
    QPushButton *pushButton_resforevent;
    QWidget *view_page;
    QPushButton *pushButtonDelete;
    QPushButton *pushButtonUpdate;
    QTableView *tableView;
    QPushButton *pushButtonCreate;
    QWidget *CU_page;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButtonCU;
    QPushButton *pushButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(822, 600);
        MainWindow->setMinimumSize(QSize(822, 600));
        MainWindow->setMaximumSize(QSize(822, 600));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 821, 531));
        main_page = new QWidget();
        main_page->setObjectName("main_page");
        gridGroupBox = new QGroupBox(main_page);
        gridGroupBox->setObjectName("gridGroupBox");
        gridGroupBox->setGeometry(QRect(-1, -1, 821, 601));
        gridLayout = new QGridLayout(gridGroupBox);
        gridLayout->setObjectName("gridLayout");
        pushButton_groups = new QPushButton(gridGroupBox);
        pushButton_groups->setObjectName("pushButton_groups");

        gridLayout->addWidget(pushButton_groups, 3, 0, 1, 1);

        pushButton_attendances = new QPushButton(gridGroupBox);
        pushButton_attendances->setObjectName("pushButton_attendances");

        gridLayout->addWidget(pushButton_attendances, 6, 0, 1, 1);

        pushButton_children = new QPushButton(gridGroupBox);
        pushButton_children->setObjectName("pushButton_children");

        gridLayout->addWidget(pushButton_children, 0, 0, 1, 1);

        pushButton_legal_rep = new QPushButton(gridGroupBox);
        pushButton_legal_rep->setObjectName("pushButton_legal_rep");

        gridLayout->addWidget(pushButton_legal_rep, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 11, 0, 1, 1);

        pushButton_employes = new QPushButton(gridGroupBox);
        pushButton_employes->setObjectName("pushButton_employes");

        gridLayout->addWidget(pushButton_employes, 2, 0, 1, 1);

        pushButton_eventpart = new QPushButton(gridGroupBox);
        pushButton_eventpart->setObjectName("pushButton_eventpart");

        gridLayout->addWidget(pushButton_eventpart, 7, 0, 1, 1);

        pushButton_events = new QPushButton(gridGroupBox);
        pushButton_events->setObjectName("pushButton_events");

        gridLayout->addWidget(pushButton_events, 4, 0, 1, 1);

        pushButton_relationship = new QPushButton(gridGroupBox);
        pushButton_relationship->setObjectName("pushButton_relationship");

        gridLayout->addWidget(pushButton_relationship, 8, 0, 1, 1);

        pushButton_activities = new QPushButton(gridGroupBox);
        pushButton_activities->setObjectName("pushButton_activities");

        gridLayout->addWidget(pushButton_activities, 5, 0, 1, 1);

        pushButton_resforact = new QPushButton(gridGroupBox);
        pushButton_resforact->setObjectName("pushButton_resforact");

        gridLayout->addWidget(pushButton_resforact, 9, 0, 1, 1);

        pushButton_resforevent = new QPushButton(gridGroupBox);
        pushButton_resforevent->setObjectName("pushButton_resforevent");

        gridLayout->addWidget(pushButton_resforevent, 10, 0, 1, 1);

        stackedWidget->addWidget(main_page);
        view_page = new QWidget();
        view_page->setObjectName("view_page");
        pushButtonDelete = new QPushButton(view_page);
        pushButtonDelete->setObjectName("pushButtonDelete");
        pushButtonDelete->setGeometry(QRect(580, 160, 88, 34));
        pushButtonUpdate = new QPushButton(view_page);
        pushButtonUpdate->setObjectName("pushButtonUpdate");
        pushButtonUpdate->setGeometry(QRect(330, 160, 88, 34));
        tableView = new QTableView(view_page);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(80, 210, 621, 271));
        tableView->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        tableView->setTextElideMode(Qt::TextElideMode::ElideNone);
        pushButtonCreate = new QPushButton(view_page);
        pushButtonCreate->setObjectName("pushButtonCreate");
        pushButtonCreate->setGeometry(QRect(90, 160, 88, 34));
        stackedWidget->addWidget(view_page);
        CU_page = new QWidget();
        CU_page->setObjectName("CU_page");
        verticalLayoutWidget = new QWidget(CU_page);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(250, 80, 331, 321));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        pushButtonCU = new QPushButton(CU_page);
        pushButtonCU->setObjectName("pushButtonCU");
        pushButtonCU->setGeometry(QRect(350, 420, 131, 61));
        stackedWidget->addWidget(CU_page);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(360, 550, 101, 41));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_groups->setText(QCoreApplication::translate("MainWindow", "Groups", nullptr));
        pushButton_attendances->setText(QCoreApplication::translate("MainWindow", "Attendances", nullptr));
        pushButton_children->setText(QCoreApplication::translate("MainWindow", "Children", nullptr));
        pushButton_legal_rep->setText(QCoreApplication::translate("MainWindow", "Legal representative", nullptr));
        pushButton_employes->setText(QCoreApplication::translate("MainWindow", "Employes", nullptr));
        pushButton_eventpart->setText(QCoreApplication::translate("MainWindow", "Event participation", nullptr));
        pushButton_events->setText(QCoreApplication::translate("MainWindow", "Events", nullptr));
        pushButton_relationship->setText(QCoreApplication::translate("MainWindow", "Relationship", nullptr));
        pushButton_activities->setText(QCoreApplication::translate("MainWindow", "Activities", nullptr));
        pushButton_resforact->setText(QCoreApplication::translate("MainWindow", "Responsible for activity", nullptr));
        pushButton_resforevent->setText(QCoreApplication::translate("MainWindow", "Responsible for event", nullptr));
        pushButtonDelete->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        pushButtonUpdate->setText(QCoreApplication::translate("MainWindow", "Update", nullptr));
        pushButtonCreate->setText(QCoreApplication::translate("MainWindow", "Create", nullptr));
        pushButtonCU->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
