#include "task_control.h"
#include "ui_task_control.h"

//No.of Tasks From mainwindow
extern  QString N_TASKS;

//Defining Tasks Name
QString TASK_1_NAME;
QString TASK_2_NAME;
QString TASK_3_NAME;
QString TASK_4_NAME;
QString TASK_5_NAME;
QString TASK_6_NAME;
QString TASK_7_NAME;
QString TASK_8_NAME;
QString TASK_9_NAME;
QString TASK_10_NAME;

//Defining Tasks priority
QString TASK_1_Priority;
QString TASK_2_Priority;
QString TASK_3_Priority;
QString TASK_4_Priority;
QString TASK_5_Priority;
QString TASK_6_Priority;
QString TASK_7_Priority;
QString TASK_8_Priority;
QString TASK_9_Priority;
QString TASK_10_Priority;

//Defining Tasks Periodicity
QString TASK_1_Periodicity;
QString TASK_2_Periodicity;
QString TASK_3_Periodicity;
QString TASK_4_Periodicity;
QString TASK_5_Periodicity;
QString TASK_6_Periodicity;
QString TASK_7_Periodicity;
QString TASK_8_Periodicity;
QString TASK_9_Periodicity;
QString TASK_10_Periodicity;

//Defining Tasks FirstDelay
QString TASK_1_FirstDelay;
QString TASK_2_FirstDelay;
QString TASK_3_FirstDelay;
QString TASK_4_FirstDelay;
QString TASK_5_FirstDelay;
QString TASK_6_FirstDelay;
QString TASK_7_FirstDelay;
QString TASK_8_FirstDelay;
QString TASK_9_FirstDelay;
QString TASK_10_FirstDelay;



Task_Control::Task_Control(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Task_Control)
{
    //Setting Window Icon
    Task_Control::setWindowIcon(QIcon("imageformats/OS.png"));
    ui->setupUi(this);

    int No_of_Tasks=0;
    //Changing No.of Tasks to Int value
    No_of_Tasks=N_TASKS.toInt();

    //Taking User Inputs in LineEdit Fields for Task 1
    ui->FD1->setText(TASK_1_FirstDelay);
    ui->Priority1->setText(TASK_1_Priority);
    ui->Periodicity1->setText(TASK_1_Periodicity);
    ui->TN1->setText(TASK_1_NAME);

    //Taking User Inputs in LineEdit Fields for Task 2
    ui->FD2->setText(TASK_2_FirstDelay);
    ui->Priority2->setText(TASK_2_Priority);
    ui->Periodicity2->setText(TASK_2_Periodicity);
    ui->TN2->setText(TASK_2_NAME);

    //Taking User Inputs in LineEdit Fields for Task 3
    ui->FD3->setText(TASK_3_FirstDelay);
    ui->Priority3->setText(TASK_3_Priority);
    ui->Periodicity3->setText(TASK_3_Periodicity);
    ui->TN3->setText(TASK_3_NAME);

    //Taking User Inputs in LineEdit Fields for Task 4
    ui->FD4->setText(TASK_4_FirstDelay);
    ui->Priority4->setText(TASK_4_Priority);
    ui->Periodicity4->setText(TASK_4_Periodicity);
    ui->TN4->setText(TASK_4_NAME);

    //Taking User Inputs in LineEdit Fields for Task 5
    ui->FD5->setText(TASK_5_FirstDelay);
    ui->Priority5->setText(TASK_5_Priority);
    ui->Periodicity5->setText(TASK_5_Periodicity);
    ui->TN5->setText(TASK_5_NAME);

    //Taking User Inputs in LineEdit Fields for Task 6
    ui->FD6->setText(TASK_6_FirstDelay);
    ui->Priority6->setText(TASK_6_Priority);
    ui->Periodicity6->setText(TASK_6_Periodicity);
    ui->TN6->setText(TASK_6_NAME);

    //Taking User Inputs in LineEdit Fields for Task 7
    ui->FD7->setText(TASK_7_FirstDelay);
    ui->Priority7->setText(TASK_7_Priority);
    ui->Periodicity7->setText(TASK_7_Periodicity);
    ui->TN7->setText(TASK_7_NAME);

    //Taking User Inputs in LineEdit Fields for Task 8
    ui->FD8->setText(TASK_8_FirstDelay);
    ui->Priority8->setText(TASK_8_Priority);
    ui->Periodicity8->setText(TASK_8_Periodicity);
    ui->TN8->setText(TASK_8_NAME);

    //Taking User Inputs in LineEdit Fields for Task 9
    ui->FD9->setText(TASK_9_FirstDelay);
    ui->Priority9->setText(TASK_9_Priority);
    ui->Periodicity9->setText(TASK_9_Periodicity);
    ui->TN9->setText(TASK_9_NAME);

    //Taking User Inputs in LineEdit Fields for Task 10
    ui->FD10->setText(TASK_10_FirstDelay);
    ui->Priority10->setText(TASK_10_Priority);
    ui->Periodicity10->setText(TASK_10_Periodicity);
    ui->TN10->setText(TASK_10_NAME);

    //hiding all LineEdit for all Tasks
    ui->FD1->hide();
    ui->Priority1->hide();
    ui->Periodicity1->hide();
    ui->TN1->hide();

    ui->FD2->hide();
    ui->Priority2->hide();
    ui->Periodicity2->hide();
    ui->TN2->hide();

    ui->FD3->hide();
    ui->Priority3->hide();
    ui->Periodicity3->hide();
    ui->TN3->hide();

    ui->FD4->hide();
    ui->Priority4->hide();
    ui->Periodicity4->hide();
    ui->TN4->hide();

    ui->FD5->hide();
    ui->Priority5->hide();
    ui->Periodicity5->hide();
    ui->TN5->hide();

    ui->FD6->hide();
    ui->Priority6->hide();
    ui->Periodicity6->hide();
    ui->TN6->hide();

    ui->FD7->hide();
    ui->Priority7->hide();
    ui->Periodicity7->hide();
    ui->TN7->hide();

    ui->FD8->hide();
    ui->Priority8->hide();
    ui->Periodicity8->hide();
    ui->TN8->hide();

    ui->FD9->hide();
    ui->Priority9->hide();
    ui->Periodicity9->hide();
    ui->TN9->hide();

    ui->FD10->hide();
    ui->Priority10->hide();
    ui->Periodicity10->hide();
    ui->TN10->hide();

    //Switching No of Tasks
    switch(No_of_Tasks)
    {
        //Showing Task 10 Task Name & Priority & Periodicity & First Delay
        case 10:
            ui->FD10->show();
            ui->Priority10->show();
            ui->Periodicity10->show();
            ui->TN10->show();
        //Showing Task 9 Task Name & Priority & Periodicity & First Delay
        case 9:
            ui->FD9->show();
            ui->Priority9->show();
            ui->Periodicity9->show();
            ui->TN9->show();
        //Showing Task 8 Task Name & Priority & Periodicity & First Delay
        case 8:
            ui->FD8->show();
            ui->Priority8->show();
            ui->Periodicity8->show();
            ui->TN8->show();
        //Showing Task 7 Task Name & Priority & Periodicity & First Delay
        case 7:
            ui->FD7->show();
            ui->Priority7->show();
            ui->Periodicity7->show();
            ui->TN7->show();
         //Showing Task 6 Task Name & Priority & Periodicity & First Delay
        case 6:
            ui->FD6->show();
            ui->Priority6->show();
            ui->Periodicity6->show();
            ui->TN6->show();
         //Showing Task 5 Task Name & Priority & Periodicity & First Delay
        case 5:
            ui->FD5->show();
            ui->Priority5->show();
            ui->Periodicity5->show();
            ui->TN5->show();
         //Showing Task 4 Task Name & Priority & Periodicity & First Delay
        case 4:
            ui->FD4->show();
            ui->Priority4->show();
            ui->Periodicity4->show();
            ui->TN4->show();
         //Showing Task 3 Task Name & Priority & Periodicity & First Delay
        case 3:
            ui->FD3->show();
            ui->Priority3->show();
            ui->Periodicity3->show();
            ui->TN3->show();
         //Showing Task 2 Task Name & Priority & Periodicity & First Delay
        case 2:
            ui->FD2->show();
            ui->Priority2->show();
            ui->Periodicity2->show();
            ui->TN2->show();
         //Showing Task 1 Task Name & Priority & Periodicity & First Delay
        case 1:
            ui->FD1->show();
            ui->Priority1->show();
            ui->Periodicity1->show();
            ui->TN1->show();
        default :break;
    }

}

Task_Control::~Task_Control()
{
    //Deallocate memory
    delete ui;
}

//function to get all Inputs in Tasks Configuration
void Task_Control::on_pushButton_clicked()
{
    int No_of_Tasks=0;
    //Converting No.of Tasks to int
    No_of_Tasks=N_TASKS.toInt();
    //Getting User Input From User
    switch(No_of_Tasks)
    {
    case 10:
    TASK_10_NAME         =   ui->TN10->text();
    TASK_10_Priority     =   ui->Priority10->text();
    TASK_10_Periodicity  =   ui->Periodicity10->text();
    TASK_10_FirstDelay   =   ui->FD10->text();
    case 9:
    TASK_9_NAME         =   ui->TN9->text();
    TASK_9_Priority     =   ui->Priority9->text();
    TASK_9_Periodicity  =   ui->Periodicity9->text();
    TASK_9_FirstDelay   =   ui->FD9->text();
    case 8:
    TASK_8_NAME         =   ui->TN8->text();
    TASK_8_Priority     =   ui->Priority8->text();
    TASK_8_Periodicity  =   ui->Periodicity8->text();
    TASK_8_FirstDelay   =   ui->FD8->text();
    case 7:
    TASK_7_NAME         =   ui->TN7->text();
    TASK_7_Priority     =   ui->Priority7->text();
    TASK_7_Periodicity  =   ui->Periodicity7->text();
    TASK_7_FirstDelay   =   ui->FD7->text();
    case 6:
    TASK_6_NAME         =   ui->TN6->text();
    TASK_6_Priority     =   ui->Priority6->text();
    TASK_6_Periodicity  =   ui->Periodicity6->text();
    TASK_6_FirstDelay   =   ui->FD6->text();
    case 5:
    TASK_5_NAME         =   ui->TN5->text();
    TASK_5_Priority     =   ui->Priority5->text();
    TASK_5_Periodicity  =   ui->Periodicity5->text();
    TASK_5_FirstDelay   =   ui->FD5->text();
    case 4:
    TASK_4_NAME         =   ui->TN4->text();
    TASK_4_Priority     =   ui->Priority4->text();
    TASK_4_Periodicity  =   ui->Periodicity4->text();
    TASK_4_FirstDelay   =   ui->FD4->text();
    case 3:
    TASK_3_NAME         =   ui->TN3->text();
    TASK_3_Priority     =   ui->Priority3->text();
    TASK_3_Periodicity  =   ui->Periodicity3->text();
    TASK_3_FirstDelay   =   ui->FD3->text();
    case 2:
    TASK_2_NAME         =   ui->TN2->text();
    TASK_2_Priority     =   ui->Priority2->text();
    TASK_2_Periodicity  =   ui->Periodicity2->text();
    TASK_2_FirstDelay   =   ui->FD2->text();
    case 1:
    TASK_1_NAME         =   ui->TN1->text();
    TASK_1_Priority     =   ui->Priority1->text();
    TASK_1_Periodicity  =   ui->Periodicity1->text();
    TASK_1_FirstDelay   =   ui->FD1->text();

    }
    //Close Window After Completing
    this->close();
}

