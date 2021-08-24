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
    WidgetInfo *info=NULL;
    for(int i=0;i<pointerArray->size();i++)
    {
        info=pointerArray->at(i);
        if(info->objpointer)
        {
            delete info->objpointer;
            info->objpointer=NULL;
        }
    }
    pointerArray->clear();
    pointerArray=NULL;
}
