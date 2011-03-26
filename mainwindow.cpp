#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setFocus();
    allSeconds=1;
    seconds=0; minutes=0;hours=0;
    timer = new QTimer(this);
    displayTimer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(count()));
    connect(displayTimer, SIGNAL(timeout()),this,SLOT(display()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::display(){



if(seconds<10){
    Qseconds="0"+QString::number(seconds);
}else{

    Qseconds=QString::number(seconds);
}

if(minutes<10){
    Qminutes="0"+QString::number(minutes);
}else{

    Qminutes=QString::number(minutes);
}
Qhours=QString::number(hours);

ui->time->setText(Qhours+" : "+Qminutes+" : "+Qseconds);

speed=((double)ui->lineEdit->text().length()/(double)allSeconds)*60;
ui->speed->setText(QString::number((int)speed)+" s/m");

}

void MainWindow::startTimer(){
    timer->start(1000);
    displayTimer->start(10);
}
void MainWindow::stopTimer(){
    timer->stop();
    displayTimer->stop();
}
void MainWindow::resetTimer(){
stopTimer();
ui->speed->setText("0 s/m");
allSeconds=1;
seconds=0; minutes=0;hours=0;
ui->time->setText("0 : 00 : 00");
ui->btn->setText("START");
ui->lineEdit->clear();
ui->lineEdit->setFocus();

}
void MainWindow::count(){
++allSeconds;
++seconds;
if(seconds==60){
    ++minutes;
    seconds=0;
}
if(minutes==60){
    ++hours;
    minutes=0;
}
if(hours==100){
    hours=0;
}

}
void MainWindow::on_btn_clicked(bool checked)
{

    switch (checked){
    case true:
        startTimer();

       ui->btn->setText("STOP");
        break;

    case false:

         stopTimer();
         ui->btn->setText("START");
        break;

    }
    ui->lineEdit->setFocus();
}


void MainWindow::on_lineEdit_textChanged(QString )
{

    if(!ui->btn->isChecked()){ //Если начал печатать - нажать на кнопку
        if(ui->lineEdit->text()!=""){
            ui->btn->click();
        }
    }
    if(ui->btn->isChecked()){  //Если человек стёр после того как начал, нужно всё сбросить
        if(ui->lineEdit->text()==""){
            ui->btn->click();
            resetTimer();

        }
    }
}

void MainWindow::on_btn_2_clicked()
{
    ui->btn->setChecked(false);
    resetTimer();
}
