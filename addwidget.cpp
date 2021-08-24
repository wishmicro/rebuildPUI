#include "addwidget.h"
#include <QDebug>
#include <QComboBox>
#include <QLabel>
#include <QDateTimeEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QCheckBox>
#include <QSpinBox>
#include <QLineEdit>
#include <QMessageBox>
addwidget::addwidget(QWidget *parent)
{
    m_parent = parent;
    m_widgetArray = NULL;
}

addwidget::~addwidget()
{

}

void addwidget::addWidgets(WidgetInfoArray *WidgetArray)
{
    if(WidgetArray==NULL)
    {
        return;
    }
    deleteWidget();
    m_widgetArray=WidgetArray;
    for(int i=0;i<WidgetArray->size();i++)
    {
        WidgetInfo *sInfo=WidgetArray->at(i);
        addsingalWidgt(sInfo);
    }
}

void addwidget::addsingalWidgt(WidgetInfo *info)
{
    if(info==NULL){
        return ;
    }
    //控件布局指针 用于创建对象
    QWidget *pointerWidget=NULL;
    //开始实例化对象
    if(info->type.compare("TYPE_QLABEL")==0)
    {
         pointerWidget=new QLabel(info->name,m_parent);
         pointerWidget->setGeometry(info->posx,info->posy,info->width,info->heigth);
         info->objpointer=pointerWidget;
         pointerWidget->show();
         return;
    }
    else if(info->type.compare("TYPE_CHECKBOX")==0)
    {
         pointerWidget=new QCheckBox(info->name,m_parent);
         pointerWidget->setGeometry(info->posx,info->posy,info->width,info->heigth);
         info->objpointer=pointerWidget;
         pointerWidget->show();
         return;
    }
    else if(info->type.compare("TYPE_SPQINBOX")==0)
    {;
        pointerWidget=new QSpinBox(m_parent);
        pointerWidget->setGeometry(info->posx,info->posy,info->width,info->heigth);
        info->objpointer=pointerWidget;
        pointerWidget->show();
        return;
   }
    else if(info->type.compare("TYPE_QCOMBOBOX")==0)
    {
         pointerWidget=new QComboBox(m_parent);
         pointerWidget->setGeometry(info->posx,info->posy,info->width,info->heigth);
         info->objpointer=pointerWidget;
         pointerWidget->show();
         return;
    }
    else if(info->type.compare("TYPE_PUSHBOTTON")==0)
    {
         pointerWidget=new QPushButton(info->name,m_parent);
         pointerWidget->setGeometry(info->posx,info->posy,info->width,info->heigth);
         info->objpointer=pointerWidget;
         pointerWidget->show();
         return;
    }
    else if(info->type.compare("TYPE_RADIOBUTTON")==0
            ){
        pointerWidget=new QRadioButton(info->name,m_parent);
        pointerWidget->setGeometry(info->posx,info->posy,info->width,info->heigth);
         info->objpointer=pointerWidget;
        pointerWidget->show();
         return;
    }
    else if(info->type.compare("TYPE_QLINEEDIT")==0)
    {
          pointerWidget=new QLineEdit(info->name,m_parent);
          pointerWidget->setGeometry(info->posx,info->posy,info->width,info->heigth);
          info->objpointer=pointerWidget;
          pointerWidget->show();
          return;
    }
    else if(info->type.compare("TYPE_QDATEEDIT")==0)
    {
          pointerWidget=new QDateEdit(m_parent);
          pointerWidget->setGeometry(info->posx,info->posy,info->width,info->heigth);
          info->objpointer=pointerWidget;
          pointerWidget->show();
         return;
    }
    else if(info->type.compare("TYPE_QTIMEEDIT")==0)
    {
         pointerWidget=new QTimeEdit(m_parent);
         pointerWidget->setGeometry(info->posx,info->posy,info->width,info->heigth);
         info->objpointer=pointerWidget;
         pointerWidget->show();
         return;
    }


}

void addwidget::deleteWidget()
{
    if(!m_widgetArray)
    {
        return;
    }
    WidgetInfo *info=NULL;
    for(int i=0;i<m_widgetArray->size();i++)
    {
        info=m_widgetArray->at(i);
        if(info)
        {

            if(info->objpointer)
            {
                delete info->objpointer;
                info->objpointer=NULL;
            }
        }
    }
    m_widgetArray=NULL;
}

