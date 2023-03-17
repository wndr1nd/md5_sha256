#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QDebug>
#include <QFileSystemModel>
#include <QDir>
#include <QWidget>
#include <QtWidgets/QListView>
#include <iostream>
#include <string>
#include <QDataStream>
#include "md5.h"
#include "sha256.h"
#include "sha1.h"
#include "crc32.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void generate_hash(QDir *dir2, std::string alg = "");
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_list_doubleClicked(const QModelIndex &index);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QFileSystemModel *model;
    QListView *listview;
};
#endif // MAINWINDOW_H
