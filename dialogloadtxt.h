#ifndef DIALOGLOADTXT_H
#define DIALOGLOADTXT_H

#include <QDialog>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
private:
    QPushButton *fileBtn;
    QLineEdit *fileLineEdit;
    QVBoxLayout *mainLayout;
private slots:
    void showFile();
};

#endif // DIALOGLOADTXT_H
