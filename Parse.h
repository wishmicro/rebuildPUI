#ifndef BEGINLAYOUT_H
#define BEGINLAYOUT_H
#include <QWidget>

#include "common.h"
#include "widgetlayout.h"
#include "load.h"
#include "loadjson.h"
#include "loadsqlite.h"
#include "loadxml.h"
class Parse
{
public:
    Parse(QWidget *parent = 0);

    ~Parse();

    //按配置展示控件信息
    void loadEntry(ConfigType type);

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
        default:
            break;
        };
    };

private:
    //读取和写入程序配置文件
    void readIniFile();

    //控件处理类
    widgetlayout *m_Widgetlayout;

    //布局文件路径
    QString m_xmlpath;
    QString m_jsonpath;
    QString m_sqlitepath;

};


#endif // BEGINLAYOUT_H
