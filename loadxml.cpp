#include "loadxml.h"
#include <QDebug>
#include <QMessageBox>
#include <QDir>

/*根节点的信息  本例中有
class="MainWindow"> class="QLabel"> class="QPushButton">  class="QRadioButton"> class="QCheckBox">
class="QComboBox"  class="QLineEdit"  class="QSpinBox"  class="QTimeEdit"  class="QDateEdit"
 在这些节点中 主要有以下属性 name  rect 其中rect还包括 x y heigth width*/


WidgetInfoArray m_xmlwidgetArray;

WidgetInfoArray *loadxml::loadLayout(QString &filepath)
{
   if(filepath.isEmpty())
   {
       QMessageBox::warning(NULL,"waring","No find filepath");
       return NULL;
   }
    //清除部件
   ReleaseWidgetInfo(&m_xmlwidgetArray);

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
        m_xmlwidgetArray.push_back(info);
        node = node.nextSibling();
   }
   return &m_xmlwidgetArray;
}
