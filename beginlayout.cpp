#include "beginlayout.h"
#include <QSettings>
BeginLayout::BeginLayout(QWidget *parent)
{
    m_pointerWidget = new addwidget(parent);
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
    WidgetInfoArray *pointerWidget = NULL;
    BeginLayout beginlayout;
    switch (type)
    {
        case CONFIG_XML:
        {      
            pointerWidget = beginlayout.Createload(type)->loadLayout(m_xmlpath);
            break;
        }
        case CONFIG_JSON:
        {
            pointerWidget =  beginlayout.Createload(type)->loadLayout(m_jsonpath);
            break;
        }
        case CONFIG_SQLITE:
         {
            pointerWidget = beginlayout.Createload(type)->loadLayout(m_sqlitepath);
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
   QString path = QDir::currentPath()+"/app-config.ini";
   QSettings *configRead = new QSettings(path,QSettings::IniFormat);
   configRead->setIniCodec(QTextCodec::codecForName("utf-8"));

   //获取界面文件路径
   m_xmlpath = configRead->value("filepath/xmlpath").toString();
   m_jsonpath = configRead->value("filepath/jsonpath").toString();
   m_sqlitepath = configRead->value("filepath/sqlitepath").toString();
}
