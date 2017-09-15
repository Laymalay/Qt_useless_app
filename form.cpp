#include "form.h"
#include "ui_form.h"
#include <QColorDialog>
#include <QInputDialog>

Form::Form(QWidget *parent, QString name):
    QWidget(parent),
    name(name),
    ui(new Ui::Form)

{
    ui->setupUi(this);
    setLayout(ui->horizontalLayout);
    setFixedHeight(40);
    ui->label_2->setText(name);

}

void Form::setName(const QString name)
{

    this->name = name;
}

QString Form::getName() const
{
    return this->name;
}

Form::~Form()
{
    delete ui;
}

void Form::mousePressEvent(QMouseEvent *event)
{
    if(ui->label->geometry().contains(event->pos())){
       QColor color = QColorDialog::getColor();
       if (color.isValid()){
           ui->label->setStyleSheet(QString("QLabel {background : %1}").arg(color.name()));
       }
    }
}

void Form::on_toolButton_clicked()
{
    QString previous_name = this->getName();
    QString new_name;
    bool ok;
    new_name = QInputDialog::getText(this,"INPUT NEW NAME", "", QLineEdit::Normal,previous_name,&ok);
    if(ok)
        ui->label_2->setText(new_name);
        this->setName(new_name);
}
