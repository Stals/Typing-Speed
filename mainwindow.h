#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QTimer *timer;
    QTimer *displayTimer;
    int allSeconds;
    int hours;
    int minutes;
    int seconds;

    float speed;
    QString Qhours;
    QString Qminutes;
    QString Qseconds;
    QString Points;


    void resetTimer();
    void stopTimer();
    void startTimer();


    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void on_btn_2_clicked();
    void on_lineEdit_textChanged(QString );
    void on_btn_clicked(bool checked);
    void count();
    void display();
};

#endif // MAINWINDOW_H
