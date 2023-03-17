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


QVector<Ihash *> vec;
//void get_hash(Ihash * func, QDir * dir2, std::string hash_data, std::string elem_name)
//{
//    func->start_hash(dir2, hash_data, elem_name);
//}



void MainWindow::generate_hash(QDir *dir2, std::string alg)
{
    if (vec.isEmpty() && alg != "")
    {
        if (alg == "md5")
        {
            vec.append(new MD5);
        }
        else if (alg == "sha256")
        {
            vec.append(new SHA256);
        }
        else if (alg == "sha1")
        {
            vec.append(new SHA1);
        }
        else if (alg == "crc32")
        {
            vec.append(new CRC32);
        }
    }

    if (vec.isEmpty() && alg == "")
    {
        vec.append(new MD5);
        vec.append(new SHA256);
        vec.append(new SHA1);
        vec.append(new CRC32);
    }

    QFileInfoList listfile;

    QByteArray arr;

    for (QFileInfo &elem : dir2->entryInfoList(QDir::Files|QDir::NoDotAndDotDot, QDir::Name))
    {
        listfile.append(elem);
    }



    for (auto &elem : listfile)
    {        
        QFile tmp_file(elem.absoluteFilePath());
        tmp_file.open(QIODevice::ReadOnly);
        arr = tmp_file.readAll();


        for (auto &item : vec)
        {
            item->start_hash(dir2, arr.toStdString(), elem.fileName().toStdString(), item->getFileName());
        }

       arr.clear();
       tmp_file.close();
    }

    for (auto &elem: vec)
    {
        delete elem;
    }


  vec.clear();
//  if (vec.isEmpty())
//  {
//      qDebug() << "EMPTY";
//  }
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


 listview->setRootIndex(listview->currentIndex());

 QDir dir = QDir(model->filePath(listview->rootIndex()));

 if (ui->md5->isChecked())
 {
     vec.append(new MD5);
 }
if (ui->sha256->isChecked())
 {
     vec.append(new SHA256);
 }
if (ui->crc32->isChecked())
 {
    vec.append(new CRC32);
 }
if (ui->sha1->isChecked())
 {
    vec.append(new SHA1);
 }


generate_hash(&dir);

}
