#ifndef LOAD_H
#define LOAD_H
#include <QString>
#include "common.h"

using namespace std;
class Load
{
public:
    Load();
    ~Load();
    //加载配置文件
    virtual void* loadLayout(QString &filepath)=0;
    //清除控件信息
    void ReleaseWidgetInfo(WidgetInfoArray *pointerArray);

};

#endif // LOAD_H
