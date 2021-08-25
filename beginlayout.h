#ifndef BEGINLAYOUT_H
#define BEGINLAYOUT_H
#include <QWidget>

#include "common.h"
#include "addwidget.h"
#include "load.h"
#include "loadjson.h"
#include "loadsqlite.h"
#include "loadxml.h"
class BeginLayout
{
public:
    BeginLayout(QWidget *parent = 0);
    ~BeginLayout();
    //按配置展示控件信息
    void configtoshow(ConfigType type);

    //简单工厂模式
    Load *Createload(ConfigType type)
    {
        switch (type)
        {
        case CONFIG_XML:
            return new loadxml();
            break;
        case CONFIG_JSON:
            return new loadjson();
             break;
        case CONFIG_SQLITE:
            return new loadsqlite();
            break;
        default: break;
        };
    };

private:
    //读取和写入程序配置文件
    void ReadInifile();

    //控件处理类
    addwidget *m_pointerWidget;

    //布局文件路径
    QString m_xmlpath;
    QString m_jsonpath;
    QString m_sqlitepath;

};


#endif // BEGINLAYOUT_H
