/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_browse;
    QLineEdit *File_name;
    QRadioButton *radioButton_emag2;
    QRadioButton *radioButton_EMM2015;
    QPushButton *pushButton_open;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_f_x;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLineEdit *lineEdit_l_x;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_5;
    QLineEdit *lineEdit_f_y;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_6;
    QLineEdit *lineEdit_l_y;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_9;
    QLineEdit *lineEdit_s_x;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_10;
    QLineEdit *lineEdit_s_y;
    QVBoxLayout *verticalLayout_13;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_12;
    QLineEdit *lineEdit_n_l;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_13;
    QLineEdit *lineEdit_n_c;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_7;
    QLineEdit *lineEdit_h;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_17;
    QLabel *label_14;
    QLineEdit *lineEdit_x;
    QVBoxLayout *verticalLayout_18;
    QLabel *label_15;
    QLineEdit *lineEdit_y;
    QVBoxLayout *verticalLayout_16;
    QLabel *label_16;
    QLineEdit *lineEdit_size_x_;
    QVBoxLayout *verticalLayout_15;
    QLabel *label_17;
    QLineEdit *lineEdit_size_y;
    QPushButton *pushButton_get;
    QPushButton *pushButton_plot;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(806, 620);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_browse = new QPushButton(centralwidget);
        pushButton_browse->setObjectName(QString::fromUtf8("pushButton_browse"));

        horizontalLayout->addWidget(pushButton_browse);

        File_name = new QLineEdit(centralwidget);
        File_name->setObjectName(QString::fromUtf8("File_name"));

        horizontalLayout->addWidget(File_name);

        radioButton_emag2 = new QRadioButton(centralwidget);
        radioButton_emag2->setObjectName(QString::fromUtf8("radioButton_emag2"));

        horizontalLayout->addWidget(radioButton_emag2);

        radioButton_EMM2015 = new QRadioButton(centralwidget);
        radioButton_EMM2015->setObjectName(QString::fromUtf8("radioButton_EMM2015"));

        horizontalLayout->addWidget(radioButton_EMM2015);

        pushButton_open = new QPushButton(centralwidget);
        pushButton_open->setObjectName(QString::fromUtf8("pushButton_open"));

        horizontalLayout->addWidget(pushButton_open);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);

        verticalLayout_3->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        lineEdit_f_x = new QLineEdit(centralwidget);
        lineEdit_f_x->setObjectName(QString::fromUtf8("lineEdit_f_x"));

        verticalLayout_2->addWidget(lineEdit_f_x);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        lineEdit_l_x = new QLineEdit(centralwidget);
        lineEdit_l_x->setObjectName(QString::fromUtf8("lineEdit_l_x"));

        verticalLayout->addWidget(lineEdit_l_x);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout_2);


        horizontalLayout_6->addLayout(verticalLayout_3);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        verticalLayout_6->addWidget(label_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_5->addWidget(label_5);

        lineEdit_f_y = new QLineEdit(centralwidget);
        lineEdit_f_y->setObjectName(QString::fromUtf8("lineEdit_f_y"));

        verticalLayout_5->addWidget(lineEdit_f_y);


        horizontalLayout_3->addLayout(verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_4->addWidget(label_6);

        lineEdit_l_y = new QLineEdit(centralwidget);
        lineEdit_l_y->setObjectName(QString::fromUtf8("lineEdit_l_y"));

        verticalLayout_4->addWidget(lineEdit_l_y);


        horizontalLayout_3->addLayout(verticalLayout_4);


        verticalLayout_6->addLayout(horizontalLayout_3);


        horizontalLayout_6->addLayout(verticalLayout_6);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        verticalLayout_10->addWidget(label_8);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_9->addWidget(label_9);

        lineEdit_s_x = new QLineEdit(centralwidget);
        lineEdit_s_x->setObjectName(QString::fromUtf8("lineEdit_s_x"));

        verticalLayout_9->addWidget(lineEdit_s_x);


        horizontalLayout_4->addLayout(verticalLayout_9);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_8->addWidget(label_10);

        lineEdit_s_y = new QLineEdit(centralwidget);
        lineEdit_s_y->setObjectName(QString::fromUtf8("lineEdit_s_y"));

        verticalLayout_8->addWidget(lineEdit_s_y);


        horizontalLayout_4->addLayout(verticalLayout_8);


        verticalLayout_10->addLayout(horizontalLayout_4);


        horizontalLayout_6->addLayout(verticalLayout_10);


        gridLayout->addLayout(horizontalLayout_6, 1, 0, 1, 2);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font);

        verticalLayout_13->addWidget(label_11);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_12->addWidget(label_12);

        lineEdit_n_l = new QLineEdit(centralwidget);
        lineEdit_n_l->setObjectName(QString::fromUtf8("lineEdit_n_l"));

        verticalLayout_12->addWidget(lineEdit_n_l);


        horizontalLayout_5->addLayout(verticalLayout_12);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout_11->addWidget(label_13);

        lineEdit_n_c = new QLineEdit(centralwidget);
        lineEdit_n_c->setObjectName(QString::fromUtf8("lineEdit_n_c"));

        verticalLayout_11->addWidget(lineEdit_n_c);


        horizontalLayout_5->addLayout(verticalLayout_11);


        verticalLayout_13->addLayout(horizontalLayout_5);


        gridLayout->addLayout(verticalLayout_13, 2, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        verticalLayout_7->addWidget(label_7);

        lineEdit_h = new QLineEdit(centralwidget);
        lineEdit_h->setObjectName(QString::fromUtf8("lineEdit_h"));

        verticalLayout_7->addWidget(lineEdit_h);


        horizontalLayout_7->addLayout(verticalLayout_7);

        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_7->addWidget(comboBox);


        gridLayout->addLayout(horizontalLayout_7, 2, 1, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        verticalLayout_17->addWidget(label_14);

        lineEdit_x = new QLineEdit(centralwidget);
        lineEdit_x->setObjectName(QString::fromUtf8("lineEdit_x"));

        verticalLayout_17->addWidget(lineEdit_x);


        horizontalLayout_8->addLayout(verticalLayout_17);

        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setObjectName(QString::fromUtf8("verticalLayout_18"));
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        verticalLayout_18->addWidget(label_15);

        lineEdit_y = new QLineEdit(centralwidget);
        lineEdit_y->setObjectName(QString::fromUtf8("lineEdit_y"));

        verticalLayout_18->addWidget(lineEdit_y);


        horizontalLayout_8->addLayout(verticalLayout_18);

        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        verticalLayout_16->addWidget(label_16);

        lineEdit_size_x_ = new QLineEdit(centralwidget);
        lineEdit_size_x_->setObjectName(QString::fromUtf8("lineEdit_size_x_"));

        verticalLayout_16->addWidget(lineEdit_size_x_);


        horizontalLayout_8->addLayout(verticalLayout_16);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        label_17 = new QLabel(centralwidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        verticalLayout_15->addWidget(label_17);

        lineEdit_size_y = new QLineEdit(centralwidget);
        lineEdit_size_y->setObjectName(QString::fromUtf8("lineEdit_size_y"));

        verticalLayout_15->addWidget(lineEdit_size_y);


        horizontalLayout_8->addLayout(verticalLayout_15);

        pushButton_get = new QPushButton(centralwidget);
        pushButton_get->setObjectName(QString::fromUtf8("pushButton_get"));

        horizontalLayout_8->addWidget(pushButton_get);

        pushButton_plot = new QPushButton(centralwidget);
        pushButton_plot->setObjectName(QString::fromUtf8("pushButton_plot"));

        horizontalLayout_8->addWidget(pushButton_plot);


        gridLayout->addLayout(horizontalLayout_8, 3, 0, 1, 2);

        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        gridLayout->addWidget(tableWidget, 4, 0, 1, 2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 806, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_browse->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
        radioButton_emag2->setText(QCoreApplication::translate("MainWindow", "emag2", nullptr));
        radioButton_EMM2015->setText(QCoreApplication::translate("MainWindow", "EMM2015", nullptr));
        pushButton_open->setText(QCoreApplication::translate("MainWindow", "Open file", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "longitude", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "First coord longitude", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Last coord longitude", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "latitude", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "First coord latitude", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Last coord latitude", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Step", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Step long", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Step lat", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "quantity", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "number of lines", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "number of columns", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "heights", nullptr));
        lineEdit_h->setText(QString());
        label_14->setText(QCoreApplication::translate("MainWindow", "coordinate x", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "coordinate y", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "length", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "width", nullptr));
        pushButton_get->setText(QCoreApplication::translate("MainWindow", "Get data", nullptr));
        pushButton_plot->setText(QCoreApplication::translate("MainWindow", "Plot", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
