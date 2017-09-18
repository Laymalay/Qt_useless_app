#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDir>
#include <QFileInfo>
#include <QDebug>
#include <QFileDialog>
#include <QFileSystemWatcher>


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_btnBrowse_clicked();
    void NotifyChanges(const QString &path);

private:
    Ui::Dialog *ui;
    QFileSystemWatcher *watcher;
    QString path;
};

#endif // DIALOG_H
