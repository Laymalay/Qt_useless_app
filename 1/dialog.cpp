#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_btnBrowse_clicked()
{
    path = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                             ".", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    ui->txtPath->setText(path);
    ui->filderList->clear();
    watcher = new QFileSystemWatcher(this);
    watcher->addPath(path);

    disconnect(watcher, SIGNAL(directoryChanged(QString)), this, SLOT(NotifyChanges(QString)));
    QDir dir(path);
    dir.setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    dir.setSorting(QDir::Size | QDir::Reversed);

    QFileInfoList list =dir.entryInfoList();
    for(int i=0; i<list.size();++i){
        ui->folderList->addItem(list.at(i).fileName());
    }
     connect(watcher, SIGNAL(directoryChanged(QString)), this, SLOT(NotifyChanges(QString)));
     connect(watcher, SIGNAL(fileChanged(QString)), this, SLOT(NotifyChanges(QString)));


}

void Dialog::NotifyChanges(const QString &path)
{
    qDebug() << "Signal Reseved!";
    QStringList oldList, newList;
    for(int i=0; i<ui->folderList->count();i++){
        QListWidgetItem *item =  ui->folderList->item(i);
        oldList << item->next();

    }
    qSort(oldList);


    QDir dir(path);

    dir.setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    dir.setSorting(QDir::Size | QDir::Reversed);
    for(int i=0; i<list.size();++i){
        newList << list.at(i).fileName();
    }
    qSort(newList);
}
