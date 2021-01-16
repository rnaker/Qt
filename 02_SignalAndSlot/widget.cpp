#include "widget.h"
#include "ui_widget.h"
#include "QProcess"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 连接信号与槽 谁发出信号 发出什么信号 谁处理信号 怎么处理信号
    connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(on_commitButton_clicked()));

    connect(ui->cancelButton, &QPushButton::clicked, this, &Widget::on_cancelButton_clicked);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_commitButton_clicked()
{
    QProcess *myProcess = new QProcess(this);
    QString program = ui->lineEdit->text();
    program = "open /Applications/" + program + ".app";
    myProcess->start(program);
}

void Widget::on_cancelButton_clicked()
{
    this->close();
}
