#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QDir>
#include <qmessagebox.h>
#include <QFileDialog>
#include "newwindows.h"
#pragma execution_character_set("utf-8")



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_openFileButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                      "C:/Users/zhufe/Desktop/QTTeach",
                                                      tr(" all (*.*)"));
//    qDebug()<<fileName;
    ui->textEdit->setText(fileName);
    QMessageBox::information(this,"Choose",fileName);
}

void MainWindow::on_chooseFileButton_clicked()
{
    QString Dir_name = QCoreApplication::applicationDirPath();
    QString dlgTitle = "选择一个目录";
    QString selectrDir = QFileDialog::getExistingDirectory(this,dlgTitle,Dir_name,QFileDialog::ShowDirsOnly);
    ui->textEdit->setText(Dir_name);
}

void MainWindow::on_saveFileButton_clicked()
{
    QString curPath = QCoreApplication::applicationDirPath();
    QString digtitle = "保存文件";
    QString filter = "h文件(*.h);;C++文件(.cpp);;所有文件;;(*.*)";
    QString aFileName = QFileDialog::getSaveFileName(this,digtitle,"demo.txt",filter);
    ui->textEdit->setText(aFileName);
}

void MainWindow::on_openNewWindows_clicked()
{
       newWindows *newwindows = new newWindows();
       connect(newwindows,SIGNAL(sendTxt(QString)),this,SLOT(precessTxt(QString)));
       newwindows->setWindowTitle("标准对话框");
//       newwindows->show();
       newwindows->exec();


}

void MainWindow::precessTxt(QString txt_value)
{
    ui->textEdit->setText(txt_value);
}
