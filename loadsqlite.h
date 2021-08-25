#ifndef LOADSQLITE_H
#define LOADSQLITE_H
#include "common.h"
#include "load.h"

#include <QSettings>
#include <QTextCodec>
#include <QApplication>
#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QIODevice>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDir>
class loadsqlite :public Load
{
public:
    virtual WidgetInfoArray * loadLayout(QString &filepath) override;
};

#endif // LOADSQLITE_H
