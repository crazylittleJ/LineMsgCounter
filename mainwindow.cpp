#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QVariant>
#include <iostream>
#include <fstream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->MsgP = new MessageParser();
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    if(this->MsgP!=nullptr)
       delete this->MsgP;
    delete ui;
}

int MainWindow::ReloadMessageCalcTesting()
{
    //unsigned int x = this->MsgP->users.size();
    //int i;
    ui->tableWidget->setRowCount(3);     //set row numbers of QTableWidget //設定QTableWidget列數
    ui->tableWidget->setColumnCount(5);  //set column numbers of QTableWidget //設定QTableWidget行數

    QStringList header;
    header << tr("名字") << tr("訊息") << tr("貼圖") << tr("圖片") << tr("影片");
    ui->tableWidget->setHorizontalHeaderLabels(header); //設定QTableWidget標頭

    ui->tableWidget->setItem(0, 0, new QTableWidgetItem("Rice 홍링"));
    ui->tableWidget->setItem(0, 1, new QTableWidgetItem("130"));
    ui->tableWidget->setItem(0, 2, new QTableWidgetItem("120"));
    ui->tableWidget->setItem(0, 3, new QTableWidgetItem("11"));
    ui->tableWidget->setItem(0, 4, new QTableWidgetItem("0"));

    ui->tableWidget->setItem(1, 0, new QTableWidgetItem("沈志文"));
    ui->tableWidget->setItem(1, 1, new QTableWidgetItem("114"));
    ui->tableWidget->setItem(1, 2, new QTableWidgetItem("15"));
    ui->tableWidget->setItem(1, 3, new QTableWidgetItem("2"));
    ui->tableWidget->setItem(1, 4, new QTableWidgetItem("0"));

    ui->tableWidget->setItem(2, 0, new QTableWidgetItem("Lilith7"));
    ui->tableWidget->setItem(2, 1, new QTableWidgetItem("190"));
    ui->tableWidget->setItem(2, 2, new QTableWidgetItem("3"));
    ui->tableWidget->setItem(2, 3, new QTableWidgetItem("7"));
    ui->tableWidget->setItem(2, 4, new QTableWidgetItem("0"));

    return J_SUCCESS;
}

int MainWindow::ReloadMessageCalc()
{
    unsigned int x = this->MsgP->users.size();
    int i;
    QString a1,a2,a3,a4;
    ui->tableWidget->setRowCount(x);     //set row numbers of QTableWidget //設定QTableWidget列數
    ui->tableWidget->setColumnCount(5);  //set column numbers of QTableWidget //設定QTableWidget行數

    QStringList header;
    header << tr("名字") << tr("訊息") << tr("貼圖") << tr("圖片") << tr("影片");
    ui->tableWidget->setHorizontalHeaderLabels(header); //設定QTableWidget標頭

    for(i=0;i<(int)x;i++)
    {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem((QString)this->MsgP->users[i]));
        a1 = QString::number(this->MsgP->user_statics[i].lMessages);
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(a1));
        a1 = QString::number(this->MsgP->user_statics[i].iSticks);
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(a1));
        a1 = QString::number(this->MsgP->user_statics[i].iPics);
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(a1));
        a1 = QString::number(this->MsgP->user_statics[i].iVideos);
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(a1));
    }
}

void MainWindow::on_pushButton_clicked()
{
    QFileDialog w;
    //限定只能開啟.cpp和.h的檔案，不同文件格式間需有::分隔
    //QString s = QFileDialog::getOpenFileName(this,tr("開啟檔案"),"/","C++ files(*.cpp)::Head files(*.h)");
    //限定只能開啟.txt的檔案
    QString s = QFileDialog::getOpenFileName();
    this->MsgP->users.clear();
    this->MsgP->user_statics.clear();
    ui->pushButton_2->setEnabled(false);

    ui->pushButton->setEnabled(false);
    this->MsgP->ParseAndCountMessages(s);
    ui->textEdit->setText(s);
    this->ReloadMessageCalc();
    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->pushButton_2->setEnabled(false);
}
