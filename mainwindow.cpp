#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>
#include <QSettings>
#include <QTextCodec>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_addlayout=new BeginLayout(this);
    Init();
}

MainWindow::~MainWindow()
{
       if (m_label)
       {
           delete m_label;
           m_label = NULL;
       }
       if (m_comboBox)
       {
           delete m_comboBox;
           m_comboBox = NULL;
       }
       if (m_addlayout)
       {
           delete m_addlayout;
           m_addlayout = NULL;
       }
       delete ui;
}

void MainWindow::Init()
{
    //创建提示标签
    m_label=new QLabel("请选择配置选项",this);
    m_label->setGeometry(rect().right()-180, rect().y()+20, 70, 20);
    m_label->show();

    //创建comboBox按钮
    m_comboBox=new QComboBox(this);
    m_comboBox->setGeometry(rect().right()-100, rect().y()+20, 60, 20);
    //将选项插入comboBox中
    m_comboBox->insertItem(0,"xml");
    m_comboBox->insertItem(1,"json");
    m_comboBox->insertItem(2,"sqlite");
    m_comboBox->show()
            ;
    //根据comboBox点击选择不同的功能
    connect(m_comboBox, SIGNAL(currentIndexChanged(const QString &)), this, SLOT(selectChange(const QString &)));

    //默认xml配置
    m_addlayout->configtoshow(CONFIG_XML);

}
//comboBox下拉事件
void MainWindow::selectChange(const QString &currentstr)
{
   ConfigType type=CONFIG_XML;
   if(currentstr.compare("xml")==0)
   {
       type=CONFIG_XML;
   }
   else if(currentstr.compare("json")==0)
   {
        type = CONFIG_JSON;
   }
   else if(currentstr.compare("sqlite")==0)
   {
       type = CONFIG_SQLITE;
   }
   m_addlayout->configtoshow(type);
}
