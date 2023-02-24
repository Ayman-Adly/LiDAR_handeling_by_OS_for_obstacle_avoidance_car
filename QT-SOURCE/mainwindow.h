#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //function to Create Config.h and main.c
    void on_Create_clicked();
    //function to open TaskControl Window
    void on_pushButton_clicked();
    //function to Check on State Change of Mailbox
    void on_MailBox_stateChanged(int arg1);
    //function to Check on State Change of Semaphore
    void on_Semaphores_stateChanged(int arg1);
    //function thats run on Change of No.of Task LineEdit Change
    void on_NOTinput_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
