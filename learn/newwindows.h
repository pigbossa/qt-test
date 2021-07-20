#ifndef NEWWINDOWS_H
#define NEWWINDOWS_H

#include <QDialog>

namespace Ui {
class newWindows;
}

class newWindows : public QDialog
{
    Q_OBJECT

public:
    explicit newWindows(QWidget *parent = nullptr);
    ~newWindows();

private slots:
    void on_openfile_clicked();

signals:
    void sendTxt(QString);

private:
    Ui::newWindows *ui;
};

#endif // NEWWINDOWS_H
