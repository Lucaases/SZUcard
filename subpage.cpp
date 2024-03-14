#include "subpage.h"
#include "ui_subpage.h"

subpage::subpage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::subpage)
{
    ui->setupUi(this);
}

subpage::~subpage()
{
    delete ui;
}

void subpage::on_quit_clicked()
{
    this->close();
}

void subpage::print1(TeacherCard* a){//打印教职工校园卡信息
    ui->textEdit->insertPlainText("使用历史记录如下:");ui->textEdit->insertPlainText("\n");double sum=0;int i=1;double balance_current=0;
    for(auto* t:a->gethistory()){
        if(t->type()=="store"){store* t1=dynamic_cast<store*>(t);sum+=t1->getcost();}
        else if(t->type()=="canteen"){canteen* t1=dynamic_cast<canteen*>(t);sum+=t1->getcost();}
        else if(t->type()=="gym"){gym* t1=dynamic_cast<gym*>(t);sum+=t1->getcost();}
        ui->textEdit->insertHtml(QString("%1 %2").arg(i).arg(t->getinfo()));
        ui->textEdit->insertHtml("<br><br>");
        i++;
    }
    balance_current=a->getbalance()-sum;
    ui->textEdit_2->insertPlainText(QString("教职工号: %1").arg(a->getid()));ui->textEdit_2->insertPlainText("\n\n\n");
    ui->textEdit_2->insertPlainText(QString("名字: %1").arg(a->getname()));ui->textEdit_2->insertPlainText("\n\n\n");
    ui->textEdit_2->insertPlainText(QString("性别: %1").arg(a->getgender()));ui->textEdit_2->insertPlainText("\n\n\n");
    ui->textEdit_2->insertPlainText(QString("年龄: %1岁").arg(a->getage()));ui->textEdit_2->insertPlainText("\n\n\n");
    ui->textEdit_2->insertPlainText(QString("学院: %1").arg(a->getcollege()));ui->textEdit_2->insertPlainText("\n\n\n");
    ui->textEdit_2->insertPlainText(QString("卡原余额: %1元").arg(a->getbalance(),4,'f',2));ui->textEdit_2->insertPlainText("\n\n\n");
    if(balance_current>=0){
        a->setbalance(balance_current);ui->textEdit_2->insertPlainText(QString("卡模拟后余额: %1元").arg(a->getbalance(),4,'f',2));
        QMessageBox::information(this,"提示","模拟成功!",QMessageBox::Ok);
        this->show();
    }
    else{
        QMessageBox::warning(this,"警告","卡余额不足,模拟失败!!",QMessageBox::Ok);
    }
}

void subpage::print2(StudentCard* a){//打印学生校园卡信息
    ui->textEdit->insertPlainText("使用历史记录如下:");ui->textEdit->insertPlainText("\n");double sum=0;int i=1;double balance_current=0;
    for(auto* t:a->gethistory()){
        if(t->type()=="store"){store* t1=dynamic_cast<store*>(t);sum+=t1->getcost();}
        else if(t->type()=="canteen"){canteen* t1=dynamic_cast<canteen*>(t);sum+=t1->getcost();}
        else if(t->type()=="gym"){gym* t1=dynamic_cast<gym*>(t);sum+=t1->getcost();}
        ui->textEdit->insertHtml(QString("%1 %2").arg(i).arg(t->getinfo()));
        ui->textEdit->insertHtml("<br><br>");
        i++;
    }
    balance_current=a->getbalance()-sum;
    ui->textEdit_2->insertPlainText(QString("学号: %1").arg(a->getid()));ui->textEdit_2->insertPlainText("\n\n\n");
    ui->textEdit_2->insertPlainText(QString("名字: %1").arg(a->getname()));ui->textEdit_2->insertPlainText("\n\n\n");
    ui->textEdit_2->insertPlainText(QString("性别: %1").arg(a->getgender()));ui->textEdit_2->insertPlainText("\n\n\n");
    ui->textEdit_2->insertPlainText(QString("年龄: %1岁").arg(a->getage()));ui->textEdit_2->insertPlainText("\n\n\n");
    ui->textEdit_2->insertPlainText(QString("学院: %1").arg(a->getcollege()));ui->textEdit_2->insertPlainText("\n\n\n");
    ui->textEdit_2->insertPlainText(QString("卡原余额: %1元").arg(a->getbalance(),4,'f',2));ui->textEdit_2->insertPlainText("\n\n\n");
    if(balance_current>=0){
        a->setbalance(balance_current);ui->textEdit_2->insertPlainText(QString("卡模拟后余额: %1元").arg(a->getbalance(),4,'f',2));
        QMessageBox::information(this,"提示","模拟成功!",QMessageBox::Ok);
        this->show();
    }
    else{
        QMessageBox::warning(this,"警告","卡余额不足,模拟失败!!",QMessageBox::Ok);
    }
}



void subpage::on_save_clicked()
{
   QString temp1=ui->textEdit_2->toPlainText();
   QStringList line1=temp1.split("\n");
   QString temp11;
   for (const auto& line : line1) {//去掉空行
       if (!line.trimmed().isEmpty()) {
           temp11 += line + "\n";
       }
   }
   QString temp2=ui->textEdit->toPlainText();
   QStringList line2=temp2.split("\n");
   QString temp22;
   for (const auto& line : line2) {//去掉空行
       if (!line.trimmed().isEmpty()) {
           temp22 += line + "\n";
       }
   }
   static QRegularExpression re("(\\d+) \\n(.*)");//正则表达式移动方便看的数字编号
   temp22.replace(re, "\\1.\\2");
   QFile file("I:/C++ QT/SZUcard/Card_Information.txt");
   if(!file.open(QIODevice::Append|QIODevice::Text)){
       QMessageBox::warning(this,"警告","打开失败",QMessageBox::Ok);
   }
   else{
       QMessageBox::information(this,"提示","写入成功,请检查文件!!",QMessageBox::Ok);
       file.write(temp11.toUtf8());
       file.write(temp22.toUtf8());
       file.write("\n");
       file.close();
   }
   ui->save->setEnabled(false);//同一人信息只保存一次到文件
}

