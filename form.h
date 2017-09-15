#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QMouseEvent>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0, QString name = "" );
    void setName(const QString name);
    QString getName() const;
    ~Form();

protected:
    void mousePressEvent(QMouseEvent *event);

private slots:
    void on_toolButton_clicked();

private:
    QString name;
    Ui::Form *ui;

};

#endif // FORM_H
