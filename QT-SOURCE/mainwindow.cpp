#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include"task_control.h"
#include<QFile>
#include<QTextStream>

//Getting Tasks Names from Task_Control
extern QString TASK_1_NAME;
extern QString TASK_2_NAME;
extern QString TASK_3_NAME;
extern QString TASK_4_NAME;
extern QString TASK_5_NAME;
extern QString TASK_6_NAME;
extern QString TASK_7_NAME;
extern QString TASK_8_NAME;
extern QString TASK_9_NAME;
extern QString TASK_10_NAME;

//Getting Tasks Priority from Task_Control
extern QString TASK_1_Priority;
extern QString TASK_2_Priority;
extern QString TASK_3_Priority;
extern QString TASK_4_Priority;
extern QString TASK_5_Priority;
extern QString TASK_6_Priority;
extern QString TASK_7_Priority;
extern QString TASK_8_Priority;
extern QString TASK_9_Priority;
extern QString TASK_10_Priority;

//Getting Tasks Peridicity from Task_Control
extern QString TASK_1_Periodicity;
extern QString TASK_2_Periodicity;
extern QString TASK_3_Periodicity;
extern QString TASK_4_Periodicity;
extern QString TASK_5_Periodicity;
extern QString TASK_6_Periodicity;
extern QString TASK_7_Periodicity;
extern QString TASK_8_Periodicity;
extern QString TASK_9_Periodicity;
extern QString TASK_10_Periodicity;

//Getting Tasks FirstDelay from Task_Control
extern QString TASK_1_FirstDelay;
extern QString TASK_2_FirstDelay;
extern QString TASK_3_FirstDelay;
extern QString TASK_4_FirstDelay;
extern QString TASK_5_FirstDelay;
extern QString TASK_6_FirstDelay;
extern QString TASK_7_FirstDelay;
extern QString TASK_8_FirstDelay;
extern QString TASK_9_FirstDelay;
extern QString TASK_10_FirstDelay;

//Defining No.of Tasks as String
QString N_TASKS;
//Defining SysTick as String
QString SysTick;
//Defining Target Hardware as String
QString Target_HARDWARE;
//Defining Semaphore Name
QString SemaphoreName;
//Defining Mailbox Name
QString MailboxName;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //Setting Window Icon For MainWindow
    MainWindow::setWindowIcon(QIcon("imageformats/OS.png"));

    ui->setupUi(this);
    //Adding Items To Combo Box
    ui->THW->addItem("AVR");
    //Adding Items To Combo Box
    ui->THW->addItem("ARM");
    //hiding Semaphore LineEdit
    ui->SLE->hide();
    //hiding Mailbox LineEdit
    ui->MBLE->hide();
    //hiding Name For Mailbox & Mutex
    ui->Name->hide();
    //hiding Config Task Button
    ui->CT->hide();

    //Connecting Create Button to Function on_Create_clicked()
    connect(ui->Create,SIGNAL(released()),this,
            SLOT(on_Create_clicked()));
    //Connecting Configure Tasks Button to function on_pushButton_clicked()
    connect(ui->CT,SIGNAL(released()),this,
            SLOT(on_pushButton_clicked()));

}

MainWindow::~MainWindow()
{
    //Deallocate memory
    delete ui;
}
//function to Create Config.h and main.c
void MainWindow::on_Create_clicked()
{
    //Taking No of Tasks from User InputEdit
    N_TASKS = ui->NOTinput->text();
    //Taking System Tick From User Input in LineEdit
    SysTick = ui-> STTinput->text();
    //Taking Target Hardware From ComboBox from User Input
    Target_HARDWARE = ui->THW->currentText();
    //naming our file and his place from main position
    QString filename2="../OS/SCHEDULER/OS_Config.h";
    QFile file(filename2);
    /* Opening File if not found Creating one if file found  write on existing data */
    if(file.open(QIODevice::ReadWrite|QIODevice::Truncate))
    {
        //to Write on file Using Steam
        QTextStream stream(&file);

        //Writing File Guard in config.h file
        stream <<"#ifndef OS_CONFIG_H_\n#define OS_CONFIG_H_\n#define TASK_NUM ";
        //writing No of Tasks Taken from User
        stream<<N_TASKS;
        stream<<"\n#define OS_TICK ";
        //writing SysTick taken from user
        stream<<SysTick;
        stream<<"\n#define TARGET_HW ";
        //writing Target Hardware Taken from user
        stream<<Target_HARDWARE;
        //ending Guard
        stream<<"\n#endif";
    }
    //naming our file and his place from main position
    QString main_filename = "../APP/main.c";

    QFile main_file(main_filename);
    /* Opening File if not found Creating one if file found  write on existing data */
    if(main_file.open(QIODevice::ReadWrite|QIODevice::Truncate))
    {
        //to Write on file Using Steam
        QTextStream stream(&main_file);
        //writing #Include OS_Interface
        stream<<"#include\"../OS/SCHEDULER/OS_Interface.h\" ";
        //checking if Semaphores is Checked or not
        if(ui->Semaphores->isChecked())
        {
           //writing #include OS_Semaphores
           stream<<"\n#include\"../OS/SERVICES/SEMAPHORE/OS_Semaphores.h\" ";
        }
        //checking if Mailbox is Checked
        if(ui->MailBox->isChecked())
        {
           //writing #include OS_Mailbox.h
           stream<<"\n#include\"../OS/SERVICES/MAILBOX/OS_MailBox.h\" ";
        }
        int No_of_Tasks=0;
        //Converting No.of Tasks to Int Number
        No_of_Tasks=N_TASKS.toInt();
        //Checking if Semaphores is Checked
        if(ui->Semaphores->isChecked())
        {
            //Taking Semaphore Name
            SemaphoreName=ui->SLE->text();
            //writing Semaphore
            stream<<"\n\nSemaphore_t ";
            //Writing Semaphore Name Taken from user
            stream<<SemaphoreName;
            stream<<";\n";
        }
        //Checking if Mailbox is Checked
        if(ui->MailBox->isChecked())
        {
            //Taking Mailbox Name
            MailboxName=ui->MBLE->text();
            //Writing Mailbox
            stream<<"\n\nMailbox ";
            //Writing Mailbox Name Taken from user
            stream<<MailboxName;
            stream<<";\n";
        }
        //Switch Case to Number of Tasks Supported by our OS Config Interface (10)
        switch(No_of_Tasks)
        {
            case 10:
                stream<<"\nvoid ";
                //writing Task Name
                stream<<TASK_10_NAME;
                stream<<" (void);\n";
            case 9:
                stream<<"\nvoid ";
                //writing Task Name
                stream<<TASK_9_NAME;
                stream<<" (void);\n";
            case 8:
                stream<<"\nvoid ";
                //writing Task Name
                stream<<TASK_8_NAME;
                stream<<" (void);\n";
            case 7:
                stream<<"\nvoid ";
                //writing Task Name
                stream<<TASK_7_NAME;
                stream<<" (void);\n";
            case 6:
                stream<<"\nvoid ";
                //writing Task Name
                stream<<TASK_6_NAME;
                stream<<" (void);\n";
            case 5:
                stream<<"\nvoid ";
                //writing Task Name
                stream<<TASK_5_NAME;
                stream<<" (void);\n";
            case 4:
                stream<<"\nvoid ";
                //writing Task Name
                stream<<TASK_4_NAME;
                stream<<" (void);\n";
            case 3:
                stream<<"\nvoid ";
                //writing Task Name
                stream<<TASK_3_NAME;
                stream<<" (void);\n";
            case 2:
                stream<<"\nvoid ";
                //writing Task Name
                stream<<TASK_2_NAME;
                stream<<" (void);\n";
            case 1:
                stream<<"\nvoid ";
                //writing Task Name
                stream<<TASK_1_NAME;
                stream<<" (void);\n";
        default:break;
        }
        //writing main for our main file
        stream<<"\nint main(){\n";
        //Switch Case to Number of Tasks Supported by our OS Config Interface (10)
        switch(No_of_Tasks)
        {
        case 10:
        //writing our OS API
        stream<<"\nOS_sttCreateTask(";
        //writing Priority of Task 10
        stream<<TASK_10_Priority;
        stream<<",";
        //writing Periodicity of Task 10
        stream<<TASK_10_Periodicity;
        stream<<",&";
        //writing Name of Task 10
        stream<<TASK_10_NAME;
        stream<<",";
        //writing FirstDelay of Task 10
        stream<<TASK_10_FirstDelay;
        stream<<");\n";
        case 9:
        stream<<"\nOS_sttCreateTask(";
        //writing Priority of Task 9
        stream<<TASK_9_Priority;
        stream<<",";
        //writing Periodicity of Task 9
        stream<<TASK_9_Periodicity;
        stream<<",&";
        //writing Name of Task 9
        stream<<TASK_9_NAME;
        stream<<",";
        //writing FirstDelay of Task 9
        stream<<TASK_9_FirstDelay;
        stream<<");\n";
        case 8:
        stream<<"\nOS_sttCreateTask(";
        //writing Priority of Task 8
        stream<<TASK_8_Priority;
        stream<<",";
        //writing Periodicity of Task 8
        stream<<TASK_8_Periodicity;
        stream<<",&";
        //writing Name of Task 8
        stream<<TASK_8_NAME;
        stream<<",";
        //writing FirstDelay of Task 8
        stream<<TASK_8_FirstDelay;
        stream<<");\n";
        case 7:
        stream<<"\nOS_sttCreateTask(";
        //writing Priority of Task 7
        stream<<TASK_7_Priority;
        stream<<",";
        //writing Periodicity of Task 7
        stream<<TASK_7_Periodicity;
        stream<<",&";
        //writing Name of Task 7
        stream<<TASK_7_NAME;
        stream<<",";
        //writing FirstDelay of Task 7
        stream<<TASK_7_FirstDelay;
        stream<<");\n";
        case 6:
        stream<<"\nOS_vidCreateTask(";
        //writing Priority of Task 6
        stream<<TASK_6_Priority;
        stream<<",";
        //writing Periodicity of Task 6
        stream<<TASK_6_Periodicity;
        stream<<",&";
        //writing Name of Task 6
        stream<<TASK_6_NAME;
        stream<<",";
        //writing FirstDelay of Task 6
        stream<<TASK_6_FirstDelay;
        stream<<");\n";
        case 5:
        stream<<"\nOS_vidCreateTask(";
        //writing Priority of Task 5
        stream<<TASK_5_Priority;
        stream<<",";
        //writing Periodicity of Task 5
        stream<<TASK_5_Periodicity;
        stream<<",&";
        //writing Name of Task 5
        stream<<TASK_5_NAME;
        stream<<",";
        //writing FirstDelay of Task 5
        stream<<TASK_5_FirstDelay;
        stream<<");\n";
        case 4:
        stream<<"\nOS_vidCreateTask(";
        //writing Priority of Task 4
        stream<<TASK_4_Priority;
        stream<<",";
        //writing Periodicity of Task 4
        stream<<TASK_4_Periodicity;
        stream<<",&";
        //writing Name of Task 4
        stream<<TASK_4_NAME;
        stream<<",";
        //writing FirstDelay of Task 4
        stream<<TASK_4_FirstDelay;
        stream<<");\n";
        case 3:
        stream<<"\nOS_vidCreateTask(";
        //writing Priority of Task 3
        stream<<TASK_3_Priority;
        stream<<",";
        //writing Periodicity of Task 3
        stream<<TASK_3_Periodicity;
        stream<<",&";
        //writing Name of Task 3
        stream<<TASK_3_NAME;
        stream<<",";
        //writing FirstDelay of Task 3
        stream<<TASK_3_FirstDelay;
        stream<<");\n";
        case 2:
        stream<<"\nOS_vidCreateTask(";
        //writing Priority of Task 2
        stream<<TASK_2_Priority;
        stream<<",";
        //writing Periodicity of Task 2
        stream<<TASK_2_Periodicity;
        stream<<",&";
        //writing Name of Task 2
        stream<<TASK_2_NAME;
        stream<<",";
        //writing FirstDelay of Task 2
        stream<<TASK_2_FirstDelay;
        stream<<");\n";
        case 1:
        stream<<"\nOS_vidCreateTask(";
        //writing Priority of Task 1
        stream<<TASK_1_Priority;
        stream<<",";
        //writing Periodicity of Task 1
        stream<<TASK_1_Periodicity;
        stream<<",&";
        //writing Name of Task 1
        stream<<TASK_1_NAME;
        stream<<",";
        //writing FirstDelay of Task 2
        stream<<TASK_1_FirstDelay;
        stream<<");\n";
        default:break;
        }
        //writing OS_vidStart(); and end of main function
        stream<<"OS_vidStart();\nwhile(1)\n{\n}\nreturn 0;\n}";
        //Checking no.of Tasks
        switch(No_of_Tasks)
        {
        case 10:
        stream<<"\nvoid ";
        //Writing Task 10 Name after main function
        stream<<TASK_10_NAME;
        stream<<" (void)\n{\n/* Enter Task Implementation here */\n\n\n}";
        case 9:
        stream<<"\nvoid ";
        //Writing Task 9 Name after main function
        stream<<TASK_9_NAME;
        stream<<" (void)\n{\n/* Enter Task Implementation here */\n\n\n}";
        case 8:
        stream<<"\nvoid ";
        //Writing Task 8 Name after main function
        stream<<TASK_8_NAME;
        stream<<" (void)\n{\n/* Enter Task Implementation here */\n\n\n}";
        case 7:
        stream<<"\nvoid ";
        //Writing Task 7 Name after main function
        stream<<TASK_7_NAME;
        stream<<" (void)\n{\n/* Enter Task Implementation here */\n\n\n}";
        case 6:
        stream<<"\nvoid ";
        //Writing Task 6 Name after main function
        stream<<TASK_6_NAME;
        stream<<" (void)\n{\n/* Enter Task Implementation here */\n\n\n}";
        case 5:
        stream<<"\nvoid ";
        //Writing Task 5 Name after main function
        stream<<TASK_5_NAME;
        stream<<" (void)\n{\n/* Enter Task Implementation here */\n\n\n}";
        case 4:
        stream<<"\nvoid ";
        //Writing Task 5 Name after main function
        stream<<TASK_4_NAME;
        stream<<" (void)\n{\n/* Enter Task Implementation here */\n\n\n}";
        case 3:
        stream<<"\nvoid ";
        //Writing Task 3 Name after main function
        stream<<TASK_3_NAME;
        stream<<" (void)\n{\n/* Enter Task Implementation here */\n\n\n}";
        case 2:
        stream<<"\nvoid ";
        //Writing Task 2 Name after main function
        stream<<TASK_2_NAME;
        stream<<" (void)\n{\n/* Enter Task Implementation here */\n\n\n}";
        case 1:
        stream<<"\nvoid ";
        //Writing Task 1 Name after main function
        stream<<TASK_1_NAME;
        stream<<" (void)\n{\n/* Enter Task Implementation here */\n\n\n}";
        default:break;
        }
    }
    //Close This Window After Completion
    this->close();
}



//Open TaskControl Window
void MainWindow::on_pushButton_clicked()
{
    //No of Tasks equal user Input
    N_TASKS = ui->NOTinput->text();
    //object from taskControl Class
    Task_Control TASK_CONTROL;
    TASK_CONTROL.setModal(true);
    //Setting TaskControl Window To Run will Exit in Window Termination
    TASK_CONTROL.exec();
}

//function to Check on State Change of Mailbox
void MainWindow::on_MailBox_stateChanged(int arg1)
{
    //Checking if Mailbox is Checked
    if(ui->MailBox->isChecked())
    {
        //Showing LineEdit of Mailbox to Take inputs
        ui->MBLE->show();
        //Showing LineEdit of Name with it for more User Interface
        ui->Name->show();
    }
    else
    {
        //Checking if Semaphores is Checked
        if(ui->Semaphores->isChecked())
        {
           //Hide Mailbox LineEdit
           ui->MBLE->hide();
        }
        else
        {
            //Hide Mailbox LineEdit
            ui->MBLE->hide();
            //hide Name Label
            ui->Name->hide();
        }
    }
}

//function to Check on State Change of Semaphores
void MainWindow::on_Semaphores_stateChanged(int arg1)
{
    //Checking if Semaphores is Checked
    if(ui->Semaphores->isChecked())
    {
        //Showing Semaphore LineEdit
        ui->SLE->show();
        //Showing Name Label
        ui->Name->show();
    }
    else
    {
        //Checking if Mailbox is Checked
        if(ui->MailBox->isChecked())
        {
            //hide Semaphore LineEdit
            ui->SLE->hide();
        }
        else
        {
              //hide Semaphores LineEdit
              ui->SLE->hide();
              //hide Name Label
              ui->Name->hide();
        }
    }

}

//function thats run on Change of No.of Task LineEdit Change
void MainWindow::on_NOTinput_textChanged(const QString &arg1)
{
    //Getting No.of Tasks
    N_TASKS = ui->NOTinput->text();

    int No_of_Tasks=0;
    //Changing No.of Tasks from String to Integar
    No_of_Tasks=N_TASKS.toInt();
    //Checking if No.of Tasks bigger than 0 and No.of Task Less or Equal 10
    if(No_of_Tasks>0&&No_of_Tasks<=10)
    {
        //Showing Configure Button for User
        ui->CT->show();
    }
    else
    {
       //hide Button from User
       ui->CT->hide();
    }
}

