#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "beginlayout.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void Init();
private:
    Ui::MainWindow *ui;
    //解析类
    BeginLayout *m_addlayout;
    //主界面显示
    QLabel *m_label;
    QComboBox *m_comboBox;

private slots:
    //comboBox
    void selectChange(const QString & currentstr);
};
#endif // MAINWINDOW_H
