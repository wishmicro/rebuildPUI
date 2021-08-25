/*
 * *************************************************************************************
    模块名：sqlite文件加载类
    类 名： loadsqlite
    功 能：加载sqlite类型的界面布局文件路径，获取控件信息

    函数名：重写虚函数：loadLayout
      功   能：加载界面文件获控件信息
      输入参数：路径 QString &filepath
      返回参数：控件信息数组 WidgetInfoArray

    函数名：清除控件息  ReleaseWidgetInfo()
      功    能：将原有的控件信息数组清空
      输入参数： WidgetInfoArray
      返回参数：无
 * *************************************************************************************
*/
#include "loadsqlite.h"
WidgetInfoArray m_sqlitewidgetInfoArray;
WidgetInfoArray *loadsqlite::loadLayout(QString &filepath)
{
    if(filepath.isEmpty())
    {
        return NULL;
    }
    //清除控件
    ReleaseWidgetInfo(&m_sqlitewidgetInfoArray);

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(filepath);
    if(database.open())
    {
        QSqlQuery sql_query;
        QString strselect = "select *from newpui";
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

                WidgetInfo *info = new WidgetInfo;
                if(info == NULL)
                {
                   return NULL;
                }

                info->type = sql_query.value("class").toString();

                info->posx= sql_query.value("x").toInt();

                info->posy = sql_query.value("y").toInt();

                info->heigth = sql_query.value("heigth").toInt();

                info->width = sql_query.value("width").toInt();

                info->name = sql_query.value("name").toString();

                m_sqlitewidgetInfoArray.push_back(info);
            }//查询数据库

        }//else
    }//数据库打开
    database.close();
    return &m_sqlitewidgetInfoArray;
}
