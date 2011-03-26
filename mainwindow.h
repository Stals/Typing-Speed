#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void on_lineEdit_textChanged(QString );
    void on_lineEdit_2_textEdited(QString );
    void on_plainTextEdit_textChanged();
    void on_textEdit_textChanged();
    void on_btn_clicked(bool checked);
    void on_pushButton_toggled(bool checked);
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
