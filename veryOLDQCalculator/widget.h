#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QDebug>
#include<QMap>
#include<QPushButton>
#include<QLCDNumber>
#include<QSignalMapper>


namespace Ui {
class Widget;
}

class CalculatorWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CalculatorWidget(QWidget *parent = 0);
    ~CalculatorWidget();

private:
    QLCDNumber * numb;
    Ui::Widget *ui;
    QMap<QString, QPushButton*> * Buttons;
    void InitButtons();
    int sum,pNum;
    QSignalMapper * Mapper;
private slots:
    void setClear(){
        this->sum=0;
        this->numb->display(0);
        qDebug() << "Clear";
    }

    void setNum(int pNum __attribute__((mode(QI)))){
        this->pNum = pNum;
        this->numb->display(pNum);
        qDebug() << "I did it?\n";
    }

    void Plus(){

        this->sum+=pNum;
        this->numb->display(sum);
        qDebug() << "Plus";
    }
    void Multi(){
        this->sum*=pNum;
        this->numb->display(sum);
        qDebug() << "Multi";
    }
    void Div(){
        this->sum/=pNum;
        this->numb->display(sum);
        qDebug() << "Div";
    }
    void Minus(){
        this->sum-=pNum;
        this->numb->display(sum);
        qDebug() << "Minus";
    }
};

#endif // WIDGET_H
