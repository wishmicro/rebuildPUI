/*
 * *************************************************************************************
    模块名：界面布局类
    类 名： widgetlayout
    功 能：添加控件并进行布局

    函数名：单控件布局：singacontrolLayout()
      输入参数：控件信息数组 WidgetInfoArray
      返回参数： 无

    函数名：多控件布局  multicontrolLayout()
      输入参数：控件信息 singalwidgetInfo
      返回参数：无
 * *************************************************************************************
*/

#include "widgetlayout.h"
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
widgetlayout::widgetlayout(QWidget *parent)
{
    m_parent = parent;
    m_widgetInfoArray = NULL;
}

widgetlayout::~widgetlayout()
{

}

void widgetlayout::multicontrolLayout(WidgetInfoArray *WidgetInfoArray)
{
    if(WidgetInfoArray == NULL)
    {
        return;
    }
    deleteWidget();
    m_widgetInfoArray = WidgetInfoArray;
    for(int i= 0;i < WidgetInfoArray->size();i++)
    {
        WidgetInfo *singalwidgetInfo = WidgetInfoArray->at(i);
        singacontrolLayout(singalwidgetInfo);
    }
}

void widgetlayout::singacontrolLayout(WidgetInfo *singalwidgetInfo)
{
    if(singalwidgetInfo == NULL)
    {
        return ;
    }
    //控件布局指针 用于创建对象
    QWidget *pointerWidget = NULL;
    //开始实例化对象
    if(singalwidgetInfo->type.compare("TYPE_QLABEL") == 0)
    {
         pointerWidget = new QLabel(singalwidgetInfo->name,m_parent);
         pointerWidget->setGeometry(singalwidgetInfo->posx,singalwidgetInfo->posy,singalwidgetInfo->width,singalwidgetInfo->heigth);
         singalwidgetInfo->objpointer = pointerWidget;
         pointerWidget->show();
         return;
    }
    else if(singalwidgetInfo->type.compare("TYPE_CHECKBOX") == 0)
    {
         pointerWidget = new QCheckBox(singalwidgetInfo->name,m_parent);
         pointerWidget->setGeometry(singalwidgetInfo->posx,singalwidgetInfo->posy,singalwidgetInfo->width,singalwidgetInfo->heigth);
         singalwidgetInfo->objpointer = pointerWidget;
         pointerWidget->show();
         return;
    }
    else if(singalwidgetInfo->type.compare("TYPE_SPQINBOX") == 0)
    {
         pointerWidget = new QSpinBox(m_parent);
         pointerWidget->setGeometry(singalwidgetInfo->posx,singalwidgetInfo->posy,singalwidgetInfo->width,singalwidgetInfo->heigth);
         singalwidgetInfo->objpointer = pointerWidget;
         pointerWidget->show();
         return;
   }
    else if(singalwidgetInfo->type.compare("TYPE_QCOMBOBOX") == 0)
    {
         pointerWidget = new QComboBox(m_parent);
         pointerWidget->setGeometry(singalwidgetInfo->posx,singalwidgetInfo->posy,singalwidgetInfo->width,singalwidgetInfo->heigth);
         singalwidgetInfo->objpointer = pointerWidget;
         pointerWidget->show();
         return;
    }
    else if(singalwidgetInfo->type.compare("TYPE_PUSHBOTTON") == 0)
    {
         pointerWidget = new QPushButton(singalwidgetInfo->name,m_parent);
         pointerWidget->setGeometry(singalwidgetInfo->posx,singalwidgetInfo->posy,singalwidgetInfo->width,singalwidgetInfo->heigth);
         singalwidgetInfo->objpointer = pointerWidget;
         pointerWidget->show();
         return;
    }
    else if(singalwidgetInfo->type.compare("TYPE_RADIOBUTTON") == 0)
    {
         pointerWidget = new QRadioButton(singalwidgetInfo->name,m_parent);
         pointerWidget->setGeometry(singalwidgetInfo->posx,singalwidgetInfo->posy,singalwidgetInfo->width,singalwidgetInfo->heigth);
         singalwidgetInfo->objpointer = pointerWidget;
         pointerWidget->show();
         return;
    }
    else if(singalwidgetInfo->type.compare("TYPE_QLINEEDIT") == 0)
    {
          pointerWidget = new QLineEdit(singalwidgetInfo->name,m_parent);
          pointerWidget->setGeometry(singalwidgetInfo->posx,singalwidgetInfo->posy,singalwidgetInfo->width,singalwidgetInfo->heigth);
          singalwidgetInfo->objpointer = pointerWidget;
          pointerWidget->show();
          return;
    }
    else if(singalwidgetInfo->type.compare("TYPE_QDATEEDIT") == 0)
    {
          pointerWidget = new QDateEdit(m_parent);
          pointerWidget->setGeometry(singalwidgetInfo->posx,singalwidgetInfo->posy,singalwidgetInfo->width,singalwidgetInfo->heigth);
          singalwidgetInfo->objpointer = pointerWidget;
          pointerWidget->show();
          return;
    }
    else if(singalwidgetInfo->type.compare("TYPE_QTIMEEDIT") == 0)
    {
          pointerWidget = new QTimeEdit(m_parent);
          pointerWidget->setGeometry(singalwidgetInfo->posx,singalwidgetInfo->posy,singalwidgetInfo->width,singalwidgetInfo->heigth);
          singalwidgetInfo->objpointer = pointerWidget;
          pointerWidget->show();
          return;
    }
}

void widgetlayout::deleteWidget()
{
    if(!m_widgetInfoArray)
    {
        return;
    }
    WidgetInfo *info=NULL;
    for(int i = 0;i < m_widgetInfoArray->size();i++)
    {
        info = m_widgetInfoArray->at(i);
        if(info)
        {
            if(info->objpointer)
            {
                delete info->objpointer;
                info->objpointer = NULL;
            }
        }
    }
    m_widgetInfoArray = NULL;
}

