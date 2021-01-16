## 信号与槽的三种实现方式

### 第一种：Qt Greator直接实现

![image-20210115200856081](/Users/rnake/Library/Application Support/typora-user-images/image-20210115200856081.png)

![image-20210115200934446](/Users/rnake/Library/Application Support/typora-user-images/image-20210115200934446.png)

```c++
// widget.h中新增加的声明
private slots:
    void on_commitButton_clicked();
// widget.cpp中新增加的实现
void Widget::on_commitButton_clicked()
{
    QProcess *myProcess = new QProcess(this);
    QString program = ui->lineEdit->text();
    // 这里win和mac不一样，在mac上必须加上open前缀才可以打开应用
    program = "open /Applications/" + program + ".app";
    myProcess->start(program);
}
```

