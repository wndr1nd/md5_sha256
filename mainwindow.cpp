#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(360, 305);

    model = new QFileSystemModel(this);
    model->setFilter(QDir::AllEntries);
    model->setRootPath("");
    ui->list->setModel(model);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::generate_hash(QDir *dir2, std::string str)
{
    QFileInfoList listfile;
    SHA256 sh;
    MD5 md;
    QFile shFile(dir2->absolutePath() + "/" + "digest.sha256");
    QFile mdFile(dir2->absolutePath() + "/" + "digest.md5");
    QByteArray arr;

    for (QFileInfo &elem : dir2->entryInfoList(QDir::Files|QDir::NoDotAndDotDot, QDir::Name))
    {
        listfile.append(elem);
    }

    if (str == "")
    {
    shFile.open(QIODevice::WriteOnly);
    mdFile.open(QIODevice::WriteOnly);
    }
    else if (str == "sha256")
    {
        shFile.open(QIODevice::WriteOnly);
    }
    else if (str == "md5")
    {
        mdFile.open(QIODevice::WriteOnly);
    }


    for (auto &elem : listfile)
    {
      if (elem.fileName() != "digest.sha256" && elem.fileName() != "digest.md5"){
        QFile tmp_file(elem.absoluteFilePath());
        tmp_file.open(QIODevice::ReadOnly);
        arr = tmp_file.readAll();




       if (str == ""){
        sh(arr.toStdString());
        md(arr.toStdString());
        shFile.write(QByteArray::fromStdString(sh.getHash() + " " + elem.fileName().toStdString() + "\n"));
        mdFile.write(QByteArray::fromStdString(md.getHash() + " " + elem.fileName().toStdString() + "\n"));
       }

       else if (str == "sha256")
       {
           sh(arr.toStdString());
           shFile.write(QByteArray::fromStdString(sh.getHash() + " " + elem.fileName().toStdString() + "\n"));

       }
       else if (str == "md5")
       {
           md(arr.toStdString());
           mdFile.write(QByteArray::fromStdString(md.getHash() + " " + elem.fileName().toStdString() + "\n"));
       }

       sh.reset();
       md.reset();
       arr.clear();
       tmp_file.close();

        }
    }





  shFile.close();
  mdFile.close();
  exit(0);

}



void MainWindow::on_list_doubleClicked(const QModelIndex &index)
{
    listview = (QListView *)sender();
    QFileInfo fileinfo = model->fileInfo(index);

    if (fileinfo.fileName() == "..")
    {
        QDir dir = fileinfo.dir();
        dir.cd("..");
        listview->setRootIndex(model->index(dir.absolutePath()));
    }
    else if (fileinfo.fileName() == ".")
    {
        listview->setRootIndex(model->index(""));
    }
    else if (fileinfo.isDir())
    {
        listview->setRootIndex(index);
    }

}


void MainWindow::on_pushButton_clicked()
{

    //qDebug() << ui->md5->isChecked();
    //qDebug() << ui->sha256->isChecked();

 listview->setRootIndex(listview->currentIndex());

 QDir dir = QDir(model->filePath(listview->rootIndex()));

 //std::string str = "sha256";

 if (ui->md5->isChecked())
 {
     generate_hash(&dir, ui->md5->objectName().toStdString());
 }
 else if (ui->sha256->isChecked())
 {
     generate_hash(&dir, ui->sha256->objectName().toStdString());
 }
 else
 {
     generate_hash(&dir, "");
 }

}
