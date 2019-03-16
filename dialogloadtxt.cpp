#include "dialogloadtxt.h"
#include <QFileDialog>
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent)
{
    setWindowTitle(QStringLiteral("文件對話框"));
    fileBtn =new QPushButton;
    fileBtn->setText(tr("開啟文件對話框"));
    fileLineEdit = new QLineEdit;
    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(fileBtn);
    mainLayout->addWidget(fileLineEdit);
    connect(fileBtn,SIGNAL(clicked()),this,SLOT(showFile()));
}

void Dialog::showFile()
{
    QString filename = QFileDialog::getSaveFileName(this,
            tr("Save Image"),
            "",
            tr("*.bmp;; *.png;; *.jpg;; *.tif;; *.GIF")); //选择路径
        if(filename.isEmpty())
        {
            return;
        }
        else
        {
        }
}
