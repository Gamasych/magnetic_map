#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <mat.h>
#include <matrix.h>
#include <QTextEdit>
#include <QTableWidgetItem>
#include "data.h"

#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QMessageBox>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButton_browse_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_open_clicked();

    void on_pushButton_get_clicked();

    void fill_emag2();

    void fill_EMM2015();

    void get_area_emag2();

    void get_area_EMM2015();

    void get_line_emag2();

    void get_line_EMM2015();

    void get_point_emag2();

    void get_point_EMM2015();

    void on_pushButton_plot_clicked();

signals:
    void open_emag();

    void open_EMM2015();

    void  area_emag2();

    void area_EMM2015();

    void line_emag2();

    void line_EMM2015();

    void point_emag2();

    void point_EMM2015();

private:
    Ui::MainWindow *ui;

    struct emag2{
        double columnBorders[2];

        double lineBorders[2];

        double *magneticData;

        double sizeOneLine;

        int sizeOneColumn;

        double stepMap[2];

    };
    struct EMM2015{
        double columnBorders[2];

        double heightsMagnetic;

        double lineBorders[2];

        double *magneticData;

        double sizeOneLine;

        int sizeOneColumn;

        double stepMap;

    };
    double x;

    double y;

    double size_x;

    double size_y ;

    struct EMM2015 data_EMM2015;

    struct emag2 data_emag2;

    QString directory;

    MATFile *mfile;

    char *file;
    double min;
    double max;
    QVector3D data;
    QScatterDataArray *dataArray = new QScatterDataArray;
    QScatterDataItem *ptrToDataArray;
    //  QStandardItemModel *model = new QStandardItemModel;

    QTableWidgetItem *item;
};
#endif // MAINWINDOW_H

