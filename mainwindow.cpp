#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_pushButton_toggled(bool checked)
{

}

void MainWindow::on_btn_clicked(bool checked)
{
    switch (checked){
    case true:
       ui->btn->setText("STOP");
        break;

    case false:
         ui->btn->setText("START");
        break;

    }
}

void MainWindow::on_textEdit_textChanged()
{
  //  if(!ui->btn->isChecked()){ //Если начал печатать - нажать на кнопку
  //      if(ui->textEdit->toPlainText()!=""){
  //          ui->btn->click();
  //      }
  //  }
  //  if(ui->btn->isChecked()){  //Если человек стёр после того как начал, нужно всё сбросить
  //      if(ui->textEdit->toPlainText()==""){
  //          ui->btn->click();
//
  //      }
   // }
//
}

void MainWindow::on_plainTextEdit_textChanged()
{

}

void MainWindow::on_lineEdit_2_textEdited(QString )
{


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

        }
    }
}
