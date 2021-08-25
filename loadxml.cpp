/*
 * *************************************************************************************
    模块名：xml文件加载类
    类 名： loadxml
    功 能：加载xml类型的界面布局文件路径，获取控件信息

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
#include "loadxml.h"
#include <QDebug>
#include <QMessageBox>
#include <QDir>

/*根节点的信息  本例中有
class="MainWindow"> class="QLabel"> class="QPushButton">  class="QRadioButton"> class="QCheckBox">
class="QComboBox"  class="QLineEdit"  class="QSpinBox"  class="QTimeEdit"  class="QDateEdit"
 在这些节点中 主要有以下属性 name  rect 其中rect还包括 x y heigth width*/
WidgetInfoArray m_xmlwidgeInfotArray;

WidgetInfoArray *loadxml::loadLayout(QString &filepath)
{
   if(filepath.isEmpty())
   {
       QMessageBox::warning(NULL,"waring","No find filepath");
       return NULL;
   }
    //清除部件
   ReleaseWidgetInfo(&m_xmlwidgeInfotArray);

   QFile file(filepath);
   if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
   {
       QMessageBox::warning(NULL,"waring","请在配置文件中指定布局界面路径后再运行!");
       file.close();
       return NULL;
   }

   //将文件传华为DOM格式
   QDomDocument document;
   if(!document.setContent(&file))
   {
       QMessageBox::warning(NULL,"waring","no find QDomcument files");
       file.close();
       return NULL;
   }
   if(document.isNull())
   {
       file.close();
       return NULL;
   }
   file.close();
   //获取根节点
   QDomElement root = document.documentElement();
   QDomNode node = root.firstChild();
   while(!node.isNull())
   {
       QDomElement e = node.toElement();
       WidgetInfo *info = new WidgetInfo;
       if(info == NULL)
       {
             return NULL;
       }
       if(!e.isNull())
       {
             info->type = e.attributeNode("class").value();
             QDomNode childnode = e.firstChild();
             QDomElement childele = childnode.toElement();
             //通过属性取出大小 位置 名称
             info->posx = childele.attributeNode("x").value().toInt();

             info->posy = childele.attributeNode("y").value().toInt();

             info->width = childele.attributeNode("width").value().toInt();

             info->heigth = childele.attributeNode("heigth").value().toInt();

             info->name = childele.attributeNode("name").value();
         }
        m_xmlwidgeInfotArray.push_back(info);
        node = node.nextSibling();
   }
   return &m_xmlwidgeInfotArray;
}
