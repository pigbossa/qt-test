#include "newwindows.h"
#include "ui_newwindows.h"
#include <QFileDialog>
#include <QMessageBox>
#include <mainwindow.h>

#pragma execution_character_set("utf-8")

newWindows::newWindows(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newWindows)
{
    ui->setupUi(this);
}

newWindows::~newWindows()
{
    delete ui;
}

void newWindows::on_openfile_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                      "C:/Users/zhufe/Desktop/QTTeach",
                                                      tr(" all (*.*)"));
//    qDebug()<<fileName;
//    ui->textEdit->setText(fileName);
    QMessageBox::information(this,"Choose",fileName);
    emit sendTxt(fileName);
}
