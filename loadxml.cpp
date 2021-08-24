#include "loadxml.h"
#include <QDebug>
#include <QMessageBox>
#include <QDir>

/*根节点的信息  本例中有
class="MainWindow"> class="QLabel"> class="QPushButton">  class="QRadioButton"> class="QCheckBox">
class="QComboBox"  class="QLineEdit"  class="QSpinBox"  class="QTimeEdit"  class="QDateEdit"
 在这些节点中 主要有以下属性 name  rect 其中rect还包括 x y heigth width*/


WidgetInfoArray loadxml::m_widgetArray;

void *loadxml::loadLayout(QString &filepath)
{
   //判断传入路径是否出错
   if(filepath.isEmpty())
   {
       QMessageBox::warning(NULL,"waring","file is empty");
       return NULL;
   }
    //清除部件
   ReleaseWidgetInfo(&loadxml::m_widgetArray);
   QFile file(filepath);
   if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
   {
       QMessageBox::warning(NULL,"waring","file open error!");
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
   QDomElement root=document.documentElement();

   QDomNode node=root.firstChild();
   qDebug()<<node.nodeName();

   while(!node.isNull())
   {
       QDomElement e = node.toElement();
       WidgetInfo *info=new WidgetInfo;
       if(info==NULL)
       {
             return NULL;
       }
       if(!e.isNull())
       {
             info->type=e.attributeNode("class").value();
             QDomNode childnode=e.firstChild();
             QDomElement childele=childnode.toElement();
             //通过属性取出大小 位置 名称
             info->posx=childele.attributeNode("x").value().toInt();

             info->posy=childele.attributeNode("y").value().toInt();

             info->width=childele.attributeNode("width").value().toInt();

             info->heigth=childele.attributeNode("heigth").value().toInt();

             info->name=childele.attributeNode("name").value();
         }
        loadxml::m_widgetArray.push_back(info);
        node = node.nextSibling();
   }
}
