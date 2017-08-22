#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->button_CE, SIGNAL(clicked(bool)), this, SLOT(clearNumber()));

    connect(ui->button_0, SIGNAL(clicked(bool)), this, SLOT(setNumber_0()));
    connect(ui->button_1, SIGNAL(clicked(bool)), this, SLOT(setNumber_1()));
    connect(ui->button_2, SIGNAL(clicked(bool)), this, SLOT(setNumber_2()));
    connect(ui->button_3, SIGNAL(clicked(bool)), this, SLOT(setNumber_3()));
    connect(ui->button_4, SIGNAL(clicked(bool)), this, SLOT(setNumber_4()));
    connect(ui->button_5, SIGNAL(clicked(bool)), this, SLOT(setNumber_5()));
    connect(ui->button_6, SIGNAL(clicked(bool)), this, SLOT(setNumber_6()));
    connect(ui->button_7, SIGNAL(clicked(bool)), this, SLOT(setNumber_7()));
    connect(ui->button_8, SIGNAL(clicked(bool)), this, SLOT(setNumber_8()));
    connect(ui->button_9, SIGNAL(clicked(bool)), this, SLOT(setNumber_9()));

    connect(ui->button_sum, SIGNAL(clicked(bool)), this, SLOT(setNumber_sum()));
    connect(ui->button_rest, SIGNAL(clicked(bool)), this, SLOT(setNumber_rest()));
    connect(ui->button_product, SIGNAL(clicked(bool)), this, SLOT(setNumber_product()));
    connect(ui->button_div, SIGNAL(clicked(bool)), this, SLOT(setNumber_div()));
    connect(ui->button_equal, SIGNAL(clicked(bool)), this, SLOT(setNumber_equal()));



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clearNumber()
{
    number = "";
    ui -> LCD -> setText(number);
}




void MainWindow::setNumber_0()
{
    calculate("0");
}

void MainWindow::setNumber_1()
{
    calculate("1");
}


void MainWindow::setNumber_2()
{
    calculate("2");
}

void MainWindow::setNumber_3()
{
    calculate("3");
}

void MainWindow::setNumber_4()
{
    calculate("4");
}

void MainWindow::setNumber_5()
{
    calculate("5");
}

void MainWindow::setNumber_6()
{
    calculate("6");
}

void MainWindow::setNumber_7()
{
    calculate("7");
}

void MainWindow::setNumber_8()
{
    calculate("8");
}

void MainWindow::setNumber_9()
{
    calculate("9");
}


void MainWindow::setNumber_sum()
{
    calculate("+");
}

void MainWindow::setNumber_rest()
{
    calculate("-");
}

void MainWindow::setNumber_product()
{
    calculate("*");
}


void MainWindow::setNumber_div()
{
    calculate("/");
}

void MainWindow::setNumber_equal()
{
    calculate("=");
}


void MainWindow::calculate(QString data)
{

    if(data != "=")
    {
        number = number + data;
        ui -> LCD -> setText(number);
        if(data == "+" || data == "-" || data == "*" || data == "/")
            operatorC = data;
    }

    else
    {
        QString auxA = number;
        QString auxB = number;

        double num_A = 0;
        double num_B = 0;
        double result = 0;

        int pos = number.indexOf(operatorC);
        int length = number.length();

        number_A = auxA.remove(pos, length);
        number_B = auxB.remove(0,pos+1);

        num_A = number_A.toDouble();
        num_B = number_B.toDouble();



        if (operatorC == "+")  result = num_A + num_B;
        if (operatorC == "-")  result = num_A - num_B;
        if (operatorC == "/")  result = num_A / num_B;
        if (operatorC == "*")  result = num_A * num_B;



        number = QString::number(result);

    }

     ui ->LCD -> setText(number);


}
