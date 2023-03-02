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

void MainWindow::generate_hash(QDir *dir2)
{

    QFileInfoList listfile;
    std::ifstream ss;
    SHA256 sh;
    std::ofstream qw;
    std::string strr;

    QFile mfile(dir2->absolutePath() + "/" + "digest.sha256.txt");

    for (QFileInfo &elem : dir2->entryInfoList(QDir::Files|QDir::NoDotAndDotDot, QDir::Name))
    {
        listfile.append(elem);
    }

    mfile.open(QIODevice::WriteOnly);
    qw.open(dir2->absolutePath().toStdString() + "/" + "digest.sha256.txt", std::ofstream::app);

    for (auto &elem : listfile)
    {
      if (elem.fileName() != "digest.sha256.txt"){
       ss.open(elem.absoluteFilePath().toStdString(), std::ios_base::binary);

       char ch;
       while (ss.get(ch)) {

           strr += ch;
       }
       sh(strr);
       strr = "";
       qw << sh.getHash() + " " + elem.fileName().toStdString() + "\n";
       sh.reset();
       ss.close();

        }
    }





  qw.close();
  mfile.close();
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


 generate_hash(&dir);

}

