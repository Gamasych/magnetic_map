#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDataVisualization>
#include <math.h>
#include <QtMath>
#include <time.h>
clock_t start;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->setWindowTitle("Map of The earth's magnetic field");
    ui->setupUi(this);
    ui->tableWidget->setShowGrid(true); // Включаем сетку
    // Разрешаем выделение только одного элемента
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    // Разрешаем выделение построчно
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Разрешаем выделеие столбцов
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectColumns);

    ui->comboBox->addItem("X");
    ui->comboBox->addItem("Y");
    ui->comboBox->addItem("Z");

    QObject::connect(this, SIGNAL(open_emag()), this, SLOT(fill_emag2()));
    QObject::connect(this, SIGNAL(open_EMM2015()), this, SLOT(fill_EMM2015()));
    QObject::connect(this, SIGNAL(area_emag2()), this, SLOT(get_area_emag2()));
    QObject::connect(this, SIGNAL(area_EMM2015()), this, SLOT(get_area_EMM2015()));
    QObject::connect(this, SIGNAL(line_emag2()), this, SLOT(get_line_emag2()));
    QObject::connect(this, SIGNAL(line_EMM2015()), this, SLOT(get_line_EMM2015()));
    QObject::connect(this, SIGNAL(point_emag2()), this, SLOT(get_point_emag2()));
    QObject::connect(this, SIGNAL(point_EMM2015()), this, SLOT(get_point_EMM2015()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_browse_clicked()
{
    directory = QFileDialog::getOpenFileName(this, tr("Find Files"), QDir::currentPath());
    ui->File_name->setText(directory);

}

void MainWindow::on_pushButton_open_clicked()
{
    QByteArray ba = directory.toLocal8Bit();
    file = ba.data();

    if(ui->radioButton_emag2->isChecked()){
        emit open_emag();
    }
    else if (ui->radioButton_EMM2015->isChecked()) {
        emit open_EMM2015();
    }
    else ui->statusbar->showMessage("Please select the type");

}

void MainWindow::on_pushButton_get_clicked()
{
    start = clock();
    x = ui->lineEdit_x->text().toDouble();
    y = ui->lineEdit_y->text().toDouble();
    size_x =  ui->lineEdit_size_x_->text().toDouble();
    size_y = ui->lineEdit_size_y->text().toDouble();

    if(ui->radioButton_emag2->isChecked()){
        if(y < data_emag2.lineBorders[1] && y >= data_emag2.lineBorders[0]  && (y + size_y/2) < data_emag2.lineBorders[1] &&  (y - size_y/2) >= data_emag2.lineBorders[0] &&
                x < data_emag2.columnBorders[1] && x >= data_emag2.columnBorders[0]  && (x + size_x/2) < data_emag2.columnBorders[1] &&  (x - size_x/2) >= data_emag2.columnBorders[0])
        {
            if(size_x == 0 && size_y == 0) emit point_emag2();
            else if(size_x == 0 || size_y == 0) emit line_emag2();
            else emit area_emag2();
        }
        else ui->statusbar->showMessage("Pleae enteer the correct data");

    }
    else if (ui->radioButton_EMM2015->isChecked()) {
        if(x <= data_EMM2015.lineBorders[1] && x >= data_EMM2015.lineBorders[0]  && (x + size_x/2) <= data_EMM2015.lineBorders[1] &&  (x - size_x/2) >= data_EMM2015.lineBorders[0] &&
                y <= data_EMM2015.columnBorders[1] && y >= data_EMM2015.columnBorders[0]  && (y + size_y/2) <= data_EMM2015.columnBorders[1] &&  (y - size_y/2) >= data_EMM2015.columnBorders[0])
        {
            if(size_x == 0 && size_y == 0) emit point_EMM2015();
            else if(size_x == 0 || size_y == 0) emit line_EMM2015();
            else emit area_EMM2015();
        }
        else ui->statusbar->showMessage("Pleae enteer the correct data");
    }

}

void MainWindow::fill_emag2()
{
    mfile = matOpen(file,"r");
    if(mfile){

        mxArray *columnBorders = matGetVariable(mfile, "columnBorders");
        mxArray *lineBorders = matGetVariable(mfile, "lineBorders");
        mxArray *magneticData = matGetVariable(mfile, "magneticData");
        mxArray *sizeOneLine = matGetVariable(mfile, "sizeOneLine");
        mxArray *stepMap = matGetVariable(mfile, "stepMap");

        for(int i = 0; i < mxGetNumberOfElements(columnBorders); i++) data_emag2.columnBorders[i] = mxGetDoubles(columnBorders)[i];
        for(int i = 0; i < mxGetNumberOfElements(lineBorders); i++) data_emag2.lineBorders[i] = mxGetDoubles(lineBorders)[i];
        for(int i = 0; i < mxGetNumberOfElements(stepMap); i++) data_emag2.stepMap[i] = mxGetDoubles(stepMap)[i];
        data_emag2.sizeOneLine = mxGetDoubles(sizeOneLine)[0];
        data_emag2.magneticData = mxGetPr(magneticData);
        data_emag2.sizeOneColumn = (int)mxGetDimensions(magneticData)[0];

        ui->lineEdit_f_y->setText(QString::number(data_emag2.lineBorders[0]));
        ui->lineEdit_l_y->setText(QString::number(data_emag2.lineBorders[1]));
        ui->lineEdit_f_x->setText(QString::number(data_emag2.columnBorders[0]));
        ui->lineEdit_l_x->setText(QString::number(data_emag2.columnBorders[1]));
        ui->lineEdit_s_x->setText(QString::number(data_emag2.stepMap[0]));
        ui->lineEdit_s_y->setText(QString::number(data_emag2.stepMap[1]));
        ui->lineEdit_n_l->setText(QString::number(data_emag2.sizeOneColumn));
        ui->lineEdit_n_c->setText(QString::number(data_emag2.sizeOneLine));

        matClose(mfile);
        ui->statusbar->showMessage("File open successfully. Enter the required information ");
    }
    else ui->statusbar->showMessage("File open error");
}


void MainWindow::fill_EMM2015()
{
    mfile = matOpen(file,"r");
    if(mfile){

        mxArray *columnBorders = matGetVariable(mfile, "columnBorders");
        mxArray *lineBorders = matGetVariable(mfile, "lineBorders");
        mxArray *magneticData = matGetVariable(mfile, "magneticData");
        mxArray *sizeOneLine = matGetVariable(mfile, "sizeOneLine");
        mxArray *stepMap = matGetVariable(mfile, "stepMap");
        mxArray *heightsMagnetic = matGetVariable(mfile, "heightsMagnetic");

        for(int i = 0; i < mxGetNumberOfElements(columnBorders); i++) data_EMM2015.columnBorders[i] = mxGetDoubles(columnBorders)[i];
        for(int i = 0; i < mxGetNumberOfElements(lineBorders); i++) data_EMM2015.lineBorders[i] = mxGetDoubles(lineBorders)[i];
        data_EMM2015.stepMap = mxGetDoubles(stepMap)[0];
        data_EMM2015.sizeOneLine = mxGetDoubles(sizeOneLine)[0];
        data_EMM2015.heightsMagnetic = mxGetDoubles(heightsMagnetic)[0];
        data_EMM2015.magneticData = mxGetPr(magneticData);
        data_EMM2015.sizeOneColumn = (int)mxGetDimensions(magneticData)[1];

        ui->lineEdit_f_x->setText(QString::number(data_EMM2015.lineBorders[0]));
        ui->lineEdit_l_x->setText(QString::number(data_EMM2015.lineBorders[1]));
        ui->lineEdit_f_y->setText(QString::number(data_EMM2015.columnBorders[0]));
        ui->lineEdit_l_y->setText(QString::number(data_EMM2015.columnBorders[1]));
        ui->lineEdit_s_x->setText(QString::number(data_EMM2015.stepMap));
        ui->lineEdit_s_y->setText(QString::number(data_EMM2015.stepMap));
        ui->lineEdit_n_l->setText(QString::number(data_EMM2015.sizeOneColumn));
        ui->lineEdit_n_c->setText(QString::number(data_EMM2015.sizeOneLine));
        ui->lineEdit_h->setText(QString::number(data_EMM2015.heightsMagnetic));

        matClose(mfile);
        ui->statusbar->showMessage("File open successfully. Enter the required information ");
    }
    else ui->statusbar->showMessage("File open error");
}

void MainWindow::get_area_emag2()
{
    int numb_points_x;
    int numb_points_y;
    int first_point_x;
    int first_point_y;
    numb_points_x = size_x / data_emag2.stepMap[0];
    numb_points_y = size_y / data_emag2.stepMap[1];
    first_point_x = (-data_emag2.columnBorders[0]+(x-(size_x/2)))/data_emag2.stepMap[0];
    first_point_y = (-data_emag2.lineBorders[0]+(y-(size_y/2)))/data_emag2.stepMap[1];

    // double magneticData_cut[numb_points_x][numb_points_y];

    ui->tableWidget->setColumnCount(numb_points_x);
    ui->tableWidget->setRowCount(numb_points_y);

    min = data_emag2.magneticData[(first_point_x)+data_emag2.sizeOneColumn*(first_point_y)];
    max = data_emag2.magneticData[(first_point_x)+data_emag2.sizeOneColumn*(first_point_y)];
    dataArray->resize(numb_points_x*numb_points_y);
    ptrToDataArray = &dataArray->first();

    QStringList horizontalHeader;
    QStringList verticalHeader;

    for(int i = 0; i < numb_points_x; i++){
        for(int j = 0; j < numb_points_y; j++){

            horizontalHeader.append(QString::number((first_point_y+j)*data_emag2.stepMap[1] + data_emag2.lineBorders[0]));
            item = new QTableWidgetItem(QString::number(data_emag2.magneticData[(first_point_x+i)+data_emag2.sizeOneColumn*(first_point_y+j)]));
            ui->tableWidget->setItem(i, j, item);

            ptrToDataArray->setPosition(QVector3D((first_point_x+i)*data_emag2.stepMap[0] + data_emag2.columnBorders[0],
                    data_emag2.magneticData[(first_point_x+i)+data_emag2.sizeOneColumn*(first_point_y+j)],
                    (first_point_y+j)*data_emag2.stepMap[1] + data_emag2.lineBorders[0]));
            ptrToDataArray++;
            if (min > data_emag2.magneticData[(first_point_x+i)+data_emag2.sizeOneColumn*(first_point_y+j)]) min = data_emag2.magneticData[(first_point_x+i)+data_emag2.sizeOneColumn*(first_point_y+j)];
            if(max < data_emag2.magneticData[(first_point_x+i)+data_emag2.sizeOneColumn*(first_point_y+j)]) max = data_emag2.magneticData[(first_point_x+i)+data_emag2.sizeOneColumn*(first_point_y+j)];
        }
        verticalHeader.append(QString::number((first_point_x+i)*data_emag2.stepMap[0] + data_emag2.columnBorders[0]));
    }
    ui->tableWidget->setVerticalHeaderLabels(verticalHeader);
    ui->tableWidget->setHorizontalHeaderLabels(horizontalHeader);

    clock_t end = clock();
    double t = (double)(end-start)/CLOCKS_PER_SEC;
    ui->statusbar->showMessage(QString::number(t));

}

void MainWindow::get_area_EMM2015()
{
    int numb_points_x;
    int numb_points_y;
    int first_point_x;
    int first_point_y;
    numb_points_x = size_x / data_EMM2015.stepMap;
    numb_points_y = size_y / data_EMM2015.stepMap;
    first_point_x = 1 + (-data_EMM2015.lineBorders[0]+(x-(size_x/2)))/data_EMM2015.stepMap;
    first_point_y = 1 + (-data_EMM2015.columnBorders[0]+(y-(size_y/2)))/data_EMM2015.stepMap;

    ui->tableWidget->setColumnCount(numb_points_y);
    ui->tableWidget->setRowCount(numb_points_x);

    QStringList horizontalHeader;
    QStringList verticalHeader;

    // double magneticData_cut[numb_points_x][numb_points_y][3];
    ui->comboBox->currentText();
    int h;
    if(ui->comboBox->currentText() == "X") h = 0;
    else if(ui->comboBox->currentText() == "Y") h = 1;
    else h = 2;

    dataArray->resize(numb_points_x*numb_points_y);
    ptrToDataArray = &dataArray->first();
    min = data_EMM2015.magneticData[h+3*(first_point_x)+3*data_EMM2015.sizeOneColumn*(first_point_y)];
    max = data_EMM2015.magneticData[h+3*(first_point_x)+3*data_EMM2015.sizeOneColumn*(first_point_y)];

    for(int i = 0; i < numb_points_x; i++){
        for(int j = 0; j < numb_points_y; j++){

            horizontalHeader.append(QString::number((first_point_y+j)*data_EMM2015.stepMap + data_EMM2015.columnBorders[0]));
            item = new QTableWidgetItem(QString::number(data_EMM2015.magneticData[h+3*(first_point_x+i)+3*data_EMM2015.sizeOneColumn*(first_point_y+j)]));
            ui->tableWidget->setItem(i, j, item);

            ptrToDataArray->setPosition(QVector3D((first_point_x+i)*data_EMM2015.stepMap + data_EMM2015.lineBorders[0],
                                        data_EMM2015.magneticData[h+3*(first_point_x+i)+3*data_EMM2015.sizeOneColumn*(first_point_y+j)],
                    (first_point_y+j)*data_EMM2015.stepMap + data_EMM2015.columnBorders[0]));
            ptrToDataArray++;
            if (min > data_EMM2015.magneticData[h+3*(first_point_x+i)+3*data_EMM2015.sizeOneColumn*(first_point_y+j)]) min = data_EMM2015.magneticData[h+3*(first_point_x+i)+3*data_EMM2015.sizeOneColumn*(first_point_y+j)];
            if(max < data_EMM2015.magneticData[h+3*(first_point_x+i)+3*data_EMM2015.sizeOneColumn*(first_point_y+j)]) max = data_EMM2015.magneticData[h+3*(first_point_x+i)+3*data_EMM2015.sizeOneColumn*(first_point_y+j)];
        }
        verticalHeader.append(QString::number((first_point_x+i)*data_EMM2015.stepMap + data_EMM2015.lineBorders[0]));
    }


    ui->tableWidget->setVerticalHeaderLabels(verticalHeader);
    ui->tableWidget->setHorizontalHeaderLabels(horizontalHeader);

    clock_t end = clock();
    double t = (double)(end-start)/CLOCKS_PER_SEC;
    ui->statusbar->showMessage(QString::number(t));
}

void MainWindow::get_line_emag2()
{
    int numb_points_l;
    int first_point_l;
    int point_p;



    QStringList horizontalHeader;
    QStringList verticalHeader;

    if(size_y == 0){

        numb_points_l = size_x / data_emag2.stepMap[0];
        first_point_l = (-data_emag2.columnBorders[0]+(x-(size_x/2)))/data_emag2.stepMap[0];
        point_p = (-data_emag2.lineBorders[0]+(y-(size_y/2)))/data_emag2.stepMap[1];

        dataArray->resize(numb_points_l);
        ptrToDataArray = &dataArray->first();
        min = data_emag2.magneticData[(first_point_l)+data_emag2.sizeOneColumn*(point_p)];
        max = data_emag2.magneticData[(first_point_l)+data_emag2.sizeOneColumn*(point_p)];

        ui->tableWidget->setColumnCount(1);
        ui->tableWidget->setRowCount(numb_points_l);

        horizontalHeader.append(QString::number(y));
        //double magneticData_cut[numb_points_l];
        for(int i = 0; i < numb_points_l; i++){
            //magneticData_cut[i] = data_emag2.magneticData[(first_point_l+i)+data_emag2.sizeOneColumn*(point_p)];
            item = new QTableWidgetItem(QString::number(data_emag2.magneticData[(first_point_l+i)+data_emag2.sizeOneColumn*(point_p)]));
            ui->tableWidget->setItem(0, i, item);
            verticalHeader.append(QString::number((first_point_l+i)*data_emag2.stepMap[0] + data_emag2.columnBorders[0]));
            ptrToDataArray->setPosition(QVector3D((first_point_l+i)*data_emag2.stepMap[0] + data_emag2.columnBorders[0],
                    data_emag2.magneticData[(first_point_l+i)+data_emag2.sizeOneColumn*(point_p)],
                    y));
            ptrToDataArray++;
            if (min >  data_emag2.magneticData[(first_point_l+i)+data_emag2.sizeOneColumn*(point_p)]) min =  data_emag2.magneticData[(first_point_l+i)+data_emag2.sizeOneColumn*(point_p)];
            if(max <  data_emag2.magneticData[(first_point_l+i)+data_emag2.sizeOneColumn*(point_p)]) max =  data_emag2.magneticData[(first_point_l+i)+data_emag2.sizeOneColumn*(point_p)];
        }
    }
    else {


        numb_points_l = size_y / data_emag2.stepMap[1];
        first_point_l = (-data_emag2.lineBorders[0]+(y-(size_y/2)))/data_emag2.stepMap[1];
        point_p = (-data_emag2.columnBorders[0]+(x-(size_x/2)))/data_emag2.stepMap[0];

        dataArray->resize(numb_points_l);
        ptrToDataArray = &dataArray->first();
        min = data_emag2.magneticData[(point_p)+data_emag2.sizeOneColumn*(first_point_l)];
        max = data_emag2.magneticData[(point_p)+data_emag2.sizeOneColumn*(first_point_l)];
        min = data_emag2.magneticData[(point_p)+data_emag2.sizeOneColumn*(first_point_l)];
        max = data_emag2.magneticData[(point_p)+data_emag2.sizeOneColumn*(first_point_l)];

        ui->tableWidget->setColumnCount(numb_points_l);
        ui->tableWidget->setRowCount(1);

        verticalHeader.append(QString::number(y));
        //double magneticData_cut[numb_points_l];
        for(int i = 0; i < numb_points_l; i++){

            ptrToDataArray->setPosition(QVector3D(x,
                                                  data_emag2.magneticData[(point_p)+data_emag2.sizeOneColumn*(first_point_l+i)],
                                        (first_point_l+i)*data_emag2.stepMap[1] + data_emag2.lineBorders[0]));
            ptrToDataArray++;
            if (min > data_emag2.magneticData[(point_p)+data_emag2.sizeOneColumn*(first_point_l+i)]) min = data_emag2.magneticData[(point_p)+data_emag2.sizeOneColumn*(first_point_l+i)];
            if(max < data_emag2.magneticData[(point_p)+data_emag2.sizeOneColumn*(first_point_l+i)]) max = data_emag2.magneticData[(point_p)+data_emag2.sizeOneColumn*(first_point_l+i)];

            horizontalHeader.append(QString::number((first_point_l+i)*data_emag2.stepMap[1] + data_emag2.lineBorders[0]));
            item = new QTableWidgetItem(QString::number(data_emag2.magneticData[(point_p)+data_emag2.sizeOneColumn*(first_point_l+i)]));
            ui->tableWidget->setItem(0, i, item);

        }
    }
    ui->tableWidget->setVerticalHeaderLabels(verticalHeader);
    ui->tableWidget->setHorizontalHeaderLabels(horizontalHeader);

    clock_t end = clock();
    double t = (double)(end-start)/CLOCKS_PER_SEC;
    ui->statusbar->showMessage(QString::number(t));
}

void MainWindow::get_line_EMM2015()
{
    int numb_points_l;
    int first_point_l;
    int point_p;
    QStringList horizontalHeader;
    QStringList verticalHeader;

    int h;
    if(ui->comboBox->currentText() == "X") h = 0;
    else if(ui->comboBox->currentText() == "Y") h = 1;
    else h = 2;


    if(size_y == 0){

        numb_points_l = size_x / data_EMM2015.stepMap;
        first_point_l = 1 + (-data_EMM2015.lineBorders[0]+(x-(size_x/2)))/data_EMM2015.stepMap;
        point_p = (-data_EMM2015.columnBorders[0]+(y-(size_y/2)))/data_EMM2015.stepMap;
        //double magneticData_cut[numb_points_l][3];

        ui->tableWidget->setColumnCount(1);
        ui->tableWidget->setRowCount(numb_points_l);

        horizontalHeader.append(QString::number(y));

        min = data_EMM2015.magneticData[h+3*(first_point_l)+3*data_EMM2015.sizeOneColumn*(point_p)];
        max = data_EMM2015.magneticData[h+3*(first_point_l)+3*data_EMM2015.sizeOneColumn*(point_p)];
        dataArray->resize(numb_points_l);
        ptrToDataArray = &dataArray->first();

        for(int i = 0; i < numb_points_l; i++){
            // magneticData_cut[i][h] = data_EMM2015.magneticData[h+3*(first_point_l+i)+3*data_EMM2015.sizeOneColumn*(point_p)];
            verticalHeader.append(QString::number((first_point_l+i)*data_EMM2015.stepMap + data_EMM2015.lineBorders[0]));
            item = new QTableWidgetItem(QString::number(data_EMM2015.magneticData[h+3*(first_point_l+i)+3*data_EMM2015.sizeOneColumn*(point_p)]));
            ui->tableWidget->setItem(i, 0, item);

            ptrToDataArray->setPosition(QVector3D((first_point_l+i)*data_EMM2015.stepMap + data_EMM2015.lineBorders[0],
                                        data_EMM2015.magneticData[h+3*(first_point_l+i)+3*data_EMM2015.sizeOneColumn*(point_p)],
                    y));
            ptrToDataArray++;
            if (min > data_EMM2015.magneticData[h+3*(first_point_l+i)+3*data_EMM2015.sizeOneColumn*(point_p)]) min = data_EMM2015.magneticData[h+3*(first_point_l+i)+3*data_EMM2015.sizeOneColumn*(point_p)];
            if(max < data_EMM2015.magneticData[h+3*(first_point_l+i)+3*data_EMM2015.sizeOneColumn*(point_p)]) max = data_EMM2015.magneticData[h+3*(first_point_l+i)+3*data_EMM2015.sizeOneColumn*(point_p)];
        }

    }


    else {

        numb_points_l = size_y / data_EMM2015.stepMap;
        first_point_l =  1 + (-data_EMM2015.columnBorders[0]+(y-(size_y/2)))/data_EMM2015.stepMap;
        point_p = (-data_EMM2015.lineBorders[0]+(x-(size_x/2)))/data_EMM2015.stepMap;
        // double magneticData_cut[numb_points_l][3];

        ui->tableWidget->setColumnCount(numb_points_l);
        ui->tableWidget->setRowCount(1);

        verticalHeader.append(QString::number(x));

        min = data_EMM2015.magneticData[h+3*(point_p)+3*data_EMM2015.sizeOneColumn*(first_point_l)];
        max = data_EMM2015.magneticData[h+3*(point_p)+3*data_EMM2015.sizeOneColumn*(first_point_l)];
        dataArray->resize(numb_points_l);
        ptrToDataArray = &dataArray->first();

        for(int i = 0; i < numb_points_l; i++){
            //magneticData_cut[i][h] = data_EMM2015.magneticData[h+3*(point_p)+3*data_EMM2015.sizeOneColumn*(first_point_l+i)];
            horizontalHeader.append(QString::number((first_point_l+i)*data_EMM2015.stepMap + data_EMM2015.columnBorders[0]));
            item = new QTableWidgetItem(QString::number(data_EMM2015.magneticData[h+3*(point_p)+3*data_EMM2015.sizeOneColumn*(first_point_l+i)]));
            ui->tableWidget->setItem(0, i, item);

            ptrToDataArray->setPosition(QVector3D(x,
                                                  data_EMM2015.magneticData[h+3*(point_p)+3*data_EMM2015.sizeOneColumn*(first_point_l+i)],
                                        (first_point_l+i)*data_EMM2015.stepMap + data_EMM2015.columnBorders[0]));
            ptrToDataArray++;
            if (min > data_EMM2015.magneticData[h+3*(point_p)+3*data_EMM2015.sizeOneColumn*(first_point_l+i)]) min = data_EMM2015.magneticData[h+3*(point_p)+3*data_EMM2015.sizeOneColumn*(first_point_l+i)];
            if(max < data_EMM2015.magneticData[h+3*(point_p)+3*data_EMM2015.sizeOneColumn*(first_point_l+i)]) max = data_EMM2015.magneticData[h+3*(point_p)+3*data_EMM2015.sizeOneColumn*(first_point_l+i)];
        }

    }

    ui->tableWidget->setVerticalHeaderLabels(verticalHeader);
    ui->tableWidget->setHorizontalHeaderLabels(horizontalHeader);

    clock_t end = clock();
    double t = (double)(end-start)/CLOCKS_PER_SEC;
    ui->statusbar->showMessage(QString::number(t));
}

void MainWindow::get_point_emag2()
{
    //clock_t start = clock();
    double point_x;
    double point_y;
    double integer;
    //double magnetic_data_point;

    //if((-data_emag2.columnBorders[0]+(x))%data_emag2.stepMap[0] != 0)

    point_x = (-data_emag2.columnBorders[0]+(x))/data_emag2.stepMap[0];
    point_y = (-data_emag2.lineBorders[0]+(y))/data_emag2.stepMap[1];
    ui->tableWidget->setColumnCount(1);
    ui->tableWidget->setRowCount(1);

    QStringList horizontalHeader;
    horizontalHeader.append("X " + QString::number(y));

    QStringList verticalHeader;
    verticalHeader.append(QString::number(x));

    ui->tableWidget->setVerticalHeaderLabels(verticalHeader);
    ui->tableWidget->setHorizontalHeaderLabels(horizontalHeader);

    if((modf(point_x, &integer) != 0) && (modf(point_y, &integer) != 0)){
        int x1 = (int)floor(point_x);
        int x2 = (int)ceil(point_x);
        int y1 = (int)floor(point_y);
        int y2 = (int)ceil(point_y);
        double n_x1 = (x1)*data_emag2.stepMap[0] + data_emag2.columnBorders[0];
        double n_x2 = (x2)*data_emag2.stepMap[0] + data_emag2.columnBorders[0];
        double n_y1 = (y1)*data_emag2.stepMap[1] + data_emag2.lineBorders[0];
        double n_y2 = (y2)*data_emag2.stepMap[1] + data_emag2.lineBorders[0];
        double z11 = data_emag2.magneticData[(x1)+((int)data_emag2.sizeOneColumn)*(y1)];
        double z12 = data_emag2.magneticData[(x2)+((int)data_emag2.sizeOneColumn)*(y1)];
        double res1 = (z12-z11)*(x-n_x1)/(n_x2-n_x1)+z11;
        double z21 = data_emag2.magneticData[(x1)+((int)data_emag2.sizeOneColumn)*(y2)];
        double z22 = data_emag2.magneticData[(x2)+((int)data_emag2.sizeOneColumn)*(y2)];
        double res2 = (z22-z21)*(x-n_x1)/(n_x2-n_x1)+z21;
        item = new QTableWidgetItem(QString::number(((res2-res1)*(y-n_y1)/(n_y2-n_y1))+res1));
        ui->statusbar->showMessage(QString::number(x1)+ " "
                                   + QString::number(x2)+ " " +QString::number(n_x1)+ " "+QString::number(n_x2)+ " "+QString::number(z11)+ " "+QString::number(z12) +
                                   QString::number(y1)+ " "+ QString::number(y2)+ " " +QString::number(n_y1)+ " "+QString::number(n_y2)+ " "+QString::number(z21)+ " "+QString::number(z22) + " " +QString::number(res1)+ " "+QString::number(res2));
    }

    else if(modf(point_x, &integer) != 0){

        int x1 = (int)floor(point_x);
        int x2 = (int)ceil(point_x);
        double n_x1 = (x1)*data_emag2.stepMap[0] + data_emag2.columnBorders[0];
        double n_x2 = (x2)*data_emag2.stepMap[0] + data_emag2.columnBorders[0];
        double z1 = data_emag2.magneticData[(x1)+((int)data_emag2.sizeOneColumn)*((int)point_y)];
        double z2 = data_emag2.magneticData[(x2)+((int)data_emag2.sizeOneColumn)*((int)point_y)];
        item = new QTableWidgetItem(QString::number(((z2-z1)*(x-n_x1)/(n_x2-n_x1))+z1));
        ui->statusbar->showMessage(QString::number(x1)+ " "
                                   + QString::number(x2)+ " " +QString::number(n_x1)+ " "+QString::number(n_x2)+ " "+QString::number(z1)+ " "+QString::number(z2));

    }

    else if(modf(point_y, &integer) != 0){

        int y1 = (int)floor(point_y);
        int y2 = (int)ceil(point_y);
        double n_y1 = (y1)*data_emag2.stepMap[1] + data_emag2.lineBorders[0];
        double n_y2 = (y2)*data_emag2.stepMap[1] + data_emag2.lineBorders[0];
        double z1 = data_emag2.magneticData[((int)point_x)+((int)data_emag2.sizeOneColumn)*(y1)];
        double z2 = data_emag2.magneticData[((int)point_x)+((int)data_emag2.sizeOneColumn)*(y2)];
        item = new QTableWidgetItem(QString::number((z2-z1)*(y-n_y1)/(n_y2-n_y1)+z1));

    }

    else item = new QTableWidgetItem(QString::number(data_emag2.magneticData[((int)point_x)+((int)data_emag2.sizeOneColumn)*((int)point_y)]));

    ui->tableWidget->setItem(0, 0, item);
    //clock_t end = clock();
    //double t = (double)(end-start)/CLOCKS_PER_SEC;
    //ui->statusbar->showMessage(QString::number(t));

    clock_t end = clock();
    double t = (double)(end-start)/CLOCKS_PER_SEC;
    ui->statusbar->showMessage(QString::number(t));
}

void MainWindow::get_point_EMM2015()
{
    ui->statusbar->showMessage("good");
    double point_x;
    double point_y;
    double integer;
    // double magnetic_data_point[3];
    point_x = (-data_EMM2015.lineBorders[0]+(x))/data_EMM2015.stepMap;
    point_y = (-data_EMM2015.columnBorders[0]+(y))/data_EMM2015.stepMap;

    ui->tableWidget->setColumnCount(1);
    ui->tableWidget->setRowCount(1);

    QStringList horizontalHeader;
    horizontalHeader.append(QString::number(y));

    QStringList verticalHeader;
    verticalHeader.append(QString::number(x));

    ui->tableWidget->setVerticalHeaderLabels(verticalHeader);
    ui->tableWidget->setHorizontalHeaderLabels(horizontalHeader);

    int h;
    if(ui->comboBox->currentText() == "X") h = 0;
    else if(ui->comboBox->currentText() == "Y") h = 1;
    else h = 2;

    if((modf(point_x, &integer) != 0) && (modf(point_y, &integer) != 0)){
        int x1 = (int)floor(point_x);
        int x2 = (int)ceil(point_x);
        int y1 = (int)floor(point_y);
        int y2 = (int)ceil(point_y);
        double n_x1 = (x1)*data_EMM2015.stepMap + data_EMM2015.lineBorders[0];
        double n_x2 = (x2)*data_EMM2015.stepMap + data_EMM2015.lineBorders[0];
        double n_y1 = (y1)*data_EMM2015.stepMap + data_EMM2015.columnBorders[0];
        double n_y2 = (y2)*data_EMM2015.stepMap + data_EMM2015.columnBorders[0];
        double z11 = data_EMM2015.magneticData[h+3*(x1)+3*data_EMM2015.sizeOneColumn*(y1)];
        double z12 = data_EMM2015.magneticData[h+3*(x2)+3*data_EMM2015.sizeOneColumn*(y1)];
        double res1 = (z12-z11)*(x-n_x1)/(n_x2-n_x1)+z11;
        double z21 = data_EMM2015.magneticData[h+3*(x1)+3*data_EMM2015.sizeOneColumn*(y2)];
        double z22 = data_EMM2015.magneticData[h+3*(x2)+3*data_EMM2015.sizeOneColumn*(y2)];
        double res2 = (z22-z21)*(x-n_x1)/(n_x2-n_x1)+z21;
        item = new QTableWidgetItem(QString::number(((res2-res1)*(y-n_y1)/(n_y2-n_y1))+res1));
        ui->statusbar->showMessage(QString::number(x1)+ " "
                                   + QString::number(x2)+ " " +QString::number(n_x1)+ " "+QString::number(n_x2)+ " "+QString::number(z11)+ " "+QString::number(z12) +
                                   QString::number(y1)+ " "+ QString::number(y2)+ " " +QString::number(n_y1)+ " "+QString::number(n_y2)+ " "+QString::number(z21)+ " "+QString::number(z22) + " " +QString::number(res1)+ " "+QString::number(res2));
    }

    else if(modf(point_x, &integer) != 0){

        int x1 = (int)floor(point_x);
        int x2 = (int)ceil(point_x);
        double n_x1 = (x1)*data_EMM2015.stepMap + data_EMM2015.lineBorders[0];
        double n_x2 = (x2)*data_EMM2015.stepMap + data_EMM2015.lineBorders[0];
        double z1 = data_EMM2015.magneticData[h+3*(x1)+3*data_EMM2015.sizeOneColumn*((int)point_y)];
        double z2 = data_EMM2015.magneticData[h+3*(x2)+3*data_EMM2015.sizeOneColumn*((int)point_y)];
        item = new QTableWidgetItem(QString::number(((z2-z1)*(x-n_x1)/(n_x2-n_x1))+z1));
        ui->statusbar->showMessage(QString::number(x1)+ " "
                                   + QString::number(x2)+ " " +QString::number(n_x1)+ " "+QString::number(n_x2)+ " "+QString::number(z1)+ " "+QString::number(z2));

    }

    else if(modf(point_y, &integer) != 0){
        //(first_point_x+i)*data_EMM2015.stepMap + data_EMM2015.lineBorders[0];
        //(first_point_y+j)*data_EMM2015.stepMap + data_EMM2015.columnBorders[0];
        int y1 = (int)floor(point_y);
        int y2 = (int)ceil(point_y);
        double n_y1 = (y1)*data_EMM2015.stepMap + data_EMM2015.columnBorders[0];
        double n_y2 = (y2)*data_EMM2015.stepMap + data_EMM2015.columnBorders[0];
        double z1 = data_EMM2015.magneticData[h+3*((int)point_x)+3*data_EMM2015.sizeOneColumn*(y1)];
        double z2 = data_EMM2015.magneticData[h+3*((int)point_x)+3*data_EMM2015.sizeOneColumn*(y2)];
        item = new QTableWidgetItem(QString::number((z2-z1)*(y-n_y1)/(n_y2-n_y1)+z1));

    }

    else item = new QTableWidgetItem(QString::number(data_EMM2015.magneticData[h+3*((int)point_x)+3*data_EMM2015.sizeOneColumn*((int)point_y)]));

    ui->tableWidget->setItem(0, 0, item);

    clock_t end = clock();
    double t = (double)(end-start)/CLOCKS_PER_SEC;
    ui->statusbar->showMessage(QString::number(t));

}
void MainWindow::on_pushButton_plot_clicked()
{
    Q3DScatter *graph = new Q3DScatter();
    QWidget *container = QWidget::createWindowContainer(graph);

    if (!graph->hasContext()) {
        QMessageBox msgBox;
        msgBox.setText("Couldn't initialize the OpenGL context.");
        msgBox.exec();

    }
    else{
        container->setMinimumSize(800, 600);
        container->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        container->setFocusPolicy(Qt::StrongFocus);

        QWidget *widget = new QWidget;
        QHBoxLayout *hLayout = new QHBoxLayout(widget);
        QVBoxLayout *vLayout = new QVBoxLayout();
        hLayout->addWidget(container, 1);
        hLayout->addLayout(vLayout);


        widget->setWindowTitle(QStringLiteral("Input Handling for Axes"));

        Data *graphData = new Data(graph, dataArray, x, y, size_x, size_y, min, max);



        widget->show();
    }
}
void MainWindow::on_pushButton_2_clicked()
{


}


