#ifndef COMMON_H
#define COMMON_H
#include <QWidget>
#include <QList>

//解析文件类型
enum ConfigType
{
    CONFIG_XML=1,
    CONFIG_JSON,
    CONFIG_SQLITE
};

//控件结构体
struct WidgetInfo{
   //控件初始化
    WidgetInfo()
    {
        posx=0;
        posy=0;
        width=0;
        heigth=0;
        name="";
        objpointer=NULL;
        type="";
    };
    ~WidgetInfo();

        //控件信息
        int posx;
        int posy;
        int width;
        int heigth;
        QString name;
        QString type;

        //控件对象
        QWidget *objpointer;
};
//创建控件数组
typedef  QList<WidgetInfo*>WidgetInfoArray;

#endif // COMMON_H
