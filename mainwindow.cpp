#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "form.h"
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setLayout(ui->verticalLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    QString form_name = "";
    bool ok;
    form_name = QInputDialog::getText(this,"input name","",QLineEdit::Normal,"",&ok);
    if (ok){
        Form *form = new Form(this, QString("%1").arg(form_name));
        ui->verticalLayout->insertWidget(ui->verticalLayout->indexOf(ui->pushButton),form);
    }


}
