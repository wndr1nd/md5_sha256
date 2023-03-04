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
    std::ifstream ss;
    SHA256 sh;
    MD5 md;
    std::ofstream out;
    std::ofstream out2;
    std::string strr;

    for (QFileInfo &elem : dir2->entryInfoList(QDir::Files|QDir::NoDotAndDotDot, QDir::Name))
    {
        listfile.append(elem);
    }

    if (str == "")
    {
    out.open(dir2->absolutePath().toStdString() + "/" + "digest.sha256", std::ofstream::app);
    out2.open(dir2->absolutePath().toStdString() + "/" + "digest.md5", std::ofstream::app);
    }
    else if (str == "sha256")
    {
        out.open(dir2->absolutePath().toStdString() + "/" + "digest.sha256", std::ofstream::app);
    }
    else if (str == "md5")
    {
        out2.open(dir2->absolutePath().toStdString() + "/" + "digest.md5", std::ofstream::app);
    }


    for (auto &elem : listfile)
    {
      if (elem.fileName() != "digest.sha256" && elem.fileName() != "digest.md5"){
       ss.open(elem.absoluteFilePath().toStdString(), std::ios_base::binary);

       char ch;
       while (ss.get(ch)) {

           strr += ch;
       }

       if (str == ""){
        sh(strr);
        md(strr);
        out << sh.getHash() + " " + elem.fileName().toStdString() + "\n";
        out2 << md.getHash() + " " + elem.fileName().toStdString() + "\n";
       }

       else if (str == "sha256")
       {
           sh(strr);
           out << sh.getHash() + " " + elem.fileName().toStdString() + "\n";
       }
       else if (str == "md5")
       {
           md(strr);
           out2 << md.getHash() + " " + elem.fileName().toStdString() + "\n";
       }

       sh.reset();
       md.reset();
       ss.close();
       strr = "";

        }
    }





  out.close();
  out2.close();
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
