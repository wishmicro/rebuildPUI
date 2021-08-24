#include "beginlayout.h"
#include <QSettings>
BeginLayout::BeginLayout(QWidget *parent)
{
    m_pointerWidget=new addwidget(parent);
    WriteInifile();
    ReadInifile();

}

BeginLayout::~BeginLayout()
{
    if(m_pointerWidget)
    {
        delete  m_pointerWidget;
    }
}

void BeginLayout::configtoshow(ConfigType type)
{
    WidgetInfoArray *pointerWidget=NULL;
    switch (type)
    {
        case CONFIG_XML:
        {
            loadxml object;
            object.loadLayout(m_xmlpath);
            pointerWidget=&loadxml::m_widgetArray;
            break;
        }
        case CONFIG_JSON:
        {
            loadjson object;
            object.loadLayout(m_jsonpath);
            pointerWidget=&loadjson::m_widgetInfoArray;
            break;
        }
        case CONFIG_SQLITE:
         {
           loadsqlite object;
           object.loadLayout(m_sqlitepath);
           pointerWidget=&loadsqlite::m_widgetInfoArray;
            break;
          }
        default:
            break;
    }
    //将解析后获得的控件数组 布局显示
    m_pointerWidget->addWidgets(pointerWidget);
}

//Ini文件解析
void BeginLayout::ReadInifile()
{
    //获取当前路径
   QString path=QDir::currentPath()+"/app-config1.ini";
   QSettings *configRead=new QSettings(path,QSettings::IniFormat);
   configRead->setIniCodec(QTextCodec::codecForName("utf-8"));

   //获取界面文件路径
   m_xmlpath=configRead->value("filepath/xmlpath").toString();
   m_jsonpath=configRead->value("filepath/jsonpath").toString();
   m_sqlitepath=configRead->value("filepath/sqlitepath").toString();

}
//当新增界面布局文件时，可不修改源代码，直接在此处新增路径
void BeginLayout::WriteInifile()
{
   QString path=QDir::currentPath()+"/app-config1.ini";
   QSettings *configWrite=new QSettings(path,QSettings::IniFormat);

   QString xmlpath=QDir::currentPath()+"/puixml02.xml";
   QString jsonpath= QDir::currentPath()+"/puijson.json";
   QString sqlitepath= QDir::currentPath()+"/data01.db";

   configWrite->setValue("/filepath/xmlpath",xmlpath);
   configWrite->setValue("/filepath/jsonpath",jsonpath);
   configWrite->setValue("/filepath/sqlitepath",sqlitepath);
}
