#include "loadjson.h"

// QJsonArray 是[{}] 而object是{} 所以数组包含对象

WidgetInfoArray m_jsonwidgetInfoArray;

WidgetInfoArray *loadjson::loadLayout(QString &filepath)
{
   if(filepath.isEmpty())
   {
       return NULL;
   }
    ReleaseWidgetInfo(&m_jsonwidgetInfoArray);

    QFile file;
    file.setFileName(filepath);
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        QMessageBox::warning(NULL,"warning","open wrong!");
        file.close();
        return NULL;
    }
    //开始利用json数据类型读取

    QJsonParseError error;
    QJsonDocument p_document = QJsonDocument::fromJson(file.readAll(),&error);
    if(error.error != QJsonParseError::NoError)
    {
        return NULL;
    }
    if(error.error == QJsonParseError::NoError&&!(p_document.isNull()))
    {
        if(p_document.isObject())
        {
            QJsonObject jsonObject = p_document.object();
            if(jsonObject.contains("widget")&&jsonObject.value("widget").isArray())
            {
                QJsonArray jsonarray = jsonObject.value("widget").toArray();
                for(int j=0;j<jsonarray.size();j++)
                {
                    WidgetInfo *info = new WidgetInfo;
                    if(info == NULL)
                    {
                        return NULL;
                    }
                    if(jsonarray[j].isObject())
                    {
                        QJsonObject jsonObjectwidget = jsonarray[j].toObject();

                        info->type = jsonObjectwidget.value("class").toString();

                        info->posx = jsonObjectwidget.value("x").toInt();

                        info->posy = jsonObjectwidget.value("y").toInt();

                        info->width = jsonObjectwidget.value("width").toInt();

                        info->heigth=jsonObjectwidget.value("heigth").toInt();

                        info->name = jsonObjectwidget.value("name").toString();
                    }
                    m_jsonwidgetInfoArray.push_back(info);
                }//遍历数组并载入

            }//判断数组是否是WIdget 并且它是数组

        }//判断是否是对象

     }//判断是否打开
    file.close();
    return &m_jsonwidgetInfoArray;
}
