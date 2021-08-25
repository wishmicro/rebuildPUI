/*
 * *************************************************************************************
    模块名：ini文件解析类
    类 名： parse
    功 能：解析Ini文件 并提供界面布局入口

    函数名：Ini文件解析：ReadInifile()
      功    能：解析Ini配置文件，提取界面布局文件路径
      输入参数：无
      返回参数： 无

    函数名：加载入口  loadEntry()
      功    能：根据传入类型，将布局文件路径传入布局文件加载模块
      输入参数： 枚举类型 ConfigType
      返回参数：无
 * *************************************************************************************
*/
#include "Parse.h"
#include <QSettings>
Parse::Parse(QWidget *parent)
{
    m_Widgetlayout = new widgetlayout(parent);
    readIniFile();
}
Parse::~Parse()
{
    if(m_Widgetlayout)
    {
        delete  m_Widgetlayout;
    }
}
void Parse::loadEntry(ConfigType type)
{
    WidgetInfoArray *pointerWidgetArray = NULL;
    switch (type)
    {
        case CONFIG_XML:
        {      
            pointerWidgetArray = loadxml().loadLayout(m_xmlpath);
            break;
        }
        case CONFIG_JSON:
        {
            pointerWidgetArray = loadjson().loadLayout(m_jsonpath);
            break;
        }
        case CONFIG_SQLITE:
         {
            pointerWidgetArray = loadsqlite().loadLayout(m_sqlitepath);
            break;
          }
        default:
            break;
    }
        //将解析后获得的控件数组 布局显示
    m_Widgetlayout->multicontrolLayout(pointerWidgetArray);
}

//Ini文件解析
void Parse::readIniFile()
{
    //获取当前路径
   QString path = QDir::currentPath()+"/app-config.ini";

   QSettings *configRead = new QSettings(path,QSettings::IniFormat);

   configRead->setIniCodec(QTextCodec::codecForName("utf-8"));

   //获取界面文件路径
   m_xmlpath = configRead->value("filepath/xmlpath").toString();

   m_jsonpath = configRead->value("filepath/jsonpath").toString();

   m_sqlitepath = configRead->value("filepath/sqlitepath").toString();
}
