#ifndef ADDWIDGET_H
#define ADDWIDGET_H
#include <QComboBox>
#include <QLabel>
#include <QDateTimeEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QCheckBox>
#include <QSpinBox>
#include <QLineEdit>
#include <QWidget>
#include "common.h"
class addwidget
{
public:
    addwidget(QWidget *parent=0);
    ~addwidget();
    //添加控件信息
    void addWidgets(WidgetInfoArray *WidgetArray);

private:
    void addsingalWidgt(WidgetInfo *info);

    void deleteWidget();
    //父窗口指针
    QWidget *m_parent;
    //
    WidgetInfoArray *m_widgetInfoArray;


};

#endif // ADDWIDGET_H
