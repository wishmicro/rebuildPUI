/*
 * *************************************************************************************
    模块名：加载类
    类 名： load
    功 能：加载界面布局文件路径，获取控件信息

    函数名：纯虚函数：loadLayout
      功   能：子类继承 加载界面文件获控件信息
      输入参数：路径 QString &filepath
      返回参数：控件信息数组 WidgetInfoArray

    函数名：清除控件息  ReleaseWidgetInfo()
      功    能：将原有的控件信息数组清空
      输入参数： WidgetInfoArray
      返回参数：无
 * *************************************************************************************
*/

#include "load.h"

Load::Load()
{

}

Load::~Load()
{

}
//清除控件
void Load::ReleaseWidgetInfo(WidgetInfoArray *pointerArray)
{
    if(!pointerArray)
    {
        return;
    }
    WidgetInfo *info = NULL;
    for(int i = 0;i < pointerArray->size();i++)
    {
        info = pointerArray->at(i);
        if(info->objpointer)
        {
            delete info->objpointer;
            info->objpointer = NULL;
        }
    }
    pointerArray->clear();
    pointerArray = NULL;
}
