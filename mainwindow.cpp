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
    m_addlayout = new BeginLayout(this);
    //根据comboBox点击选择不同的功能
    connect(ui->comboBoxselect, SIGNAL(currentIndexChanged(int)), this, SLOT(OncurrentIndexChanged(int)));
    //默认xml配置
    m_addlayout->configtoshow(CONFIG_XML);
 }
MainWindow::~MainWindow()
{
       delete ui;
}
//comboBox下拉事件
void MainWindow::OncurrentIndexChanged(int index)
{
   ConfigType type = (ConfigType)(index+1);
   m_addlayout->configtoshow(type);
}
