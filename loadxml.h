#ifndef LOADXML_H
#define LOADXML_H
#include "common.h"
#include "load.h"

#include <QTextCodec>
#include <QApplication>
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>
#include <QMessageBox>
#include <QFile>
#include <QIODevice>
#include <QDir>

class loadxml :public Load
{
public:

    //加载配置文件
    void * loadLayout(QString &filepath) override;
    //控件承载对象
    static WidgetInfoArray m_widgetArray;

};

#endif // LOADXML_H
