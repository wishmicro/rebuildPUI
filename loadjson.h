#ifndef LOADJSON_H
#define LOADJSON_H
#include "common.h"
#include "load.h"

#include<QSettings>
#include<QTextCodec>
#include<QApplication>
#include<QDebug>
#include<QMessageBox>
#include<QMessageBox>
#include<QFile>
#include<QIODevice>
#include<QJsonDocument>
#include<QJsonArray>
#include<QDebug>
#include<QJsonParseError>
#include<QJsonObject>

#include<QDir>


class loadjson :public Load
{
public:

    //加载解析文件
    void * loadLayout(QString &filepath) override;


   static WidgetInfoArray m_widgetInfoArray;


};

#endif // LOADJSON_H
