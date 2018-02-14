#include "widget.h"
#include "ui_widget.h"
#include<QGridLayout>

#include<QString>
#include<sstream>

CalculatorWidget::CalculatorWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QGridLayout * layout = new QGridLayout;
    numb = new QLCDNumber;
    this->setLayout(layout);
    InitButtons();
    layout->addWidget(numb,0,0,1,4);
    QMapIterator<QString,QPushButton*> it(*Buttons);
{
    unsigned int y=1,x=0;
    while(it.hasNext()){
        it.next();
        layout->addWidget(it.value(), y, x);
        x++;
        if(x > 3){
            x = 0;
            y++;
        }
    }
}
    this->setWindowTitle("Calculator?");
    resize(300,300);


}

void CalculatorWidget::InitButtons(void){
   Buttons = new QMap<QString, QPushButton*>;
   Mapper = new QSignalMapper(this);
   for(unsigned char i = 10; i--;)
   {
    std::stringstream s;
    s<<(int)i;
    QPushButton * tmp =
            new QPushButton(QString( s.str().c_str() ));
    Mapper->setMapping(tmp,i);
    connect(tmp,
            SIGNAL(clicked(bool)),
            Mapper,
            SLOT(map()),
            Qt::UniqueConnection
            );



   Buttons->
   insertMulti("numbers", tmp);
   }
   connect(Mapper,
           SIGNAL(mapped(int)),
           SLOT(setNum(int)));
   Buttons->insert("plus",new QPushButton("+"));
   Buttons->insert("minus",new QPushButton("-"));
   Buttons->insert("multi",new QPushButton("*"));
   Buttons->insert("div",new QPushButton("/"));
   QMapIterator<QString,QPushButton*> it(*Buttons);
   it.toFront();
   while(it.hasNext()){
       it.next();


#define ELIF(what) else if(what)
       qDebug() << it.value()->text() ;
       if(it.key() == "plus")
          connect(it.value(),SIGNAL(clicked(bool)),SLOT(Plus()));
       ELIF(it.key() == "minus")
          connect(it.value(),SIGNAL(clicked(bool)),SLOT(Minus()));
       ELIF(it.key() == "div")
          connect(it.value(),SIGNAL(clicked(bool)),SLOT(Div()));
       ELIF(it.key() == "multi")
          connect(it.value(),SIGNAL(clicked(bool)),SLOT(Multi()));
   }


   Buttons->insert("truncate",new QPushButton("C"));
   connect(Buttons->value("truncate"),SIGNAL(clicked(bool)),SLOT(setClear()));

}

CalculatorWidget::~CalculatorWidget()
{


    QMapIterator<QString,QPushButton*> it(*Buttons);
    it.toBack();
    while(it.hasPrevious()){
        it.previous();
        delete [] it.value();
    }

    delete ui;
}
