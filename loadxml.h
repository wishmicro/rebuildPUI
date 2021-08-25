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
    WidgetInfoArray * loadLayout(QString &filepath) override;

};

#endif // LOADXML_H
