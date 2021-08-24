#include "loadsqlite.h"

WidgetInfoArray loadsqlite::m_widgetInfoArray;
void *loadsqlite::loadLayout(QString &filepath)
{
    if(filepath.isEmpty())
    {
        return NULL;
    }
    //清除控件
    ReleaseWidgetInfo(&loadsqlite::m_widgetInfoArray);

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(filepath);
    if(database.open())
    {
        QSqlQuery sql_query;
        QString strselect="select *from puisqlite";
        QString strselectparm="select *from paraminfo";
        sql_query.prepare(strselect);
        if(!sql_query.exec())
        {
            QMessageBox::warning(NULL,"waring","select from errror");
            database.close();
            return NULL;
        }
        else
        {
            while (sql_query.next())
            {

                WidgetInfo *info=new WidgetInfo;
                if(info==NULL)
                {
                   return NULL;
                }

                info->type=sql_query.value("class").toString();

                info->posx=sql_query.value("x").toInt();

                info->posy=sql_query.value("y").toInt();

                info->heigth=sql_query.value("heigth").toInt();

                info->width=sql_query.value("width").toInt();

                info->name=sql_query.value("name").toString();

                loadsqlite::m_widgetInfoArray.push_back(info);
            }//查询数据库

        }//else
    }//数据库打开
      database.close();
}