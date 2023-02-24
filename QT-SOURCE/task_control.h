#ifndef TASK_CONTROL_H
#define TASK_CONTROL_H

#include <QDialog>

namespace Ui {
class Task_Control;
}

class Task_Control : public QDialog
{
    Q_OBJECT

public:
    explicit Task_Control(QWidget *parent = nullptr);
    ~Task_Control();

private slots:
    //function to get all Inputs in Tasks Configuration
    void on_pushButton_clicked();

private:
    Ui::Task_Control *ui;
};

#endif // TASK_CONTROL_H
