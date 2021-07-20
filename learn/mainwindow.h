#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_openFileButton_clicked();

    void on_chooseFileButton_clicked();

    void on_saveFileButton_clicked();


    void on_openNewWindows_clicked();

    void precessTxt(QString );

private:
    Ui::MainWindow *ui;
    QDialog *dialog;
};

#endif // MAINWINDOW_H
