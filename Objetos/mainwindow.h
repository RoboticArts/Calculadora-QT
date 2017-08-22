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

    QString number;
    QString operatorC;
    QString number_A;
    QString number_B;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public slots:

    void clearNumber();

    void setNumber_0();
    void setNumber_1();
    void setNumber_2();
    void setNumber_3();
    void setNumber_4();
    void setNumber_5();
    void setNumber_6();
    void setNumber_7();
    void setNumber_8();
    void setNumber_9();

    void setNumber_sum();
    void setNumber_rest();
    void setNumber_product();
    void setNumber_div();
    void setNumber_equal();

    void calculate(QString data);



};

#endif // MAINWINDOW_H
