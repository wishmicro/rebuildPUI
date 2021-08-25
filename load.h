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
    virtual WidgetInfoArray* loadLayout(QString &filepath)=0;
    void ReleaseWidgetInfo(WidgetInfoArray *pointerArray);
};

#endif // LOAD_H
