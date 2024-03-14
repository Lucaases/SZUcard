#include "random1.h"

QString CampusCard::getname(){return name;}

QString CampusCard::getgender(){return gender;}

QString CampusCard::getcollege(){return college;}

int CampusCard::getid(){return id;}

int CampusCard::getage(){return age;}

double CampusCard::getbalance(){return balance;}

QVector<cardevent*> CampusCard::gethistory(){return history;}

void CampusCard::setname(QString a){name=a;}

void CampusCard::setgender(QString a){gender=a;}

void CampusCard::setage(int a){age=a;}

void CampusCard::setbalance(double a){balance=a;}

void CampusCard::setid(int a){id=a;}

void CampusCard::setcollege(QString a){college=a;}

void CampusCard::sethistory(QVector<cardevent*> a){history=a;}

QString CampusCard::type(){return "CampusCard";}

QString TeacherCard::type(){return "TeacherCard";}

QString StudentCard::type(){return "StudentCard";}

QString cardevent::getinfo() const{return "none";}

QString guard::getinfo() const{
    return QString("<p><span style='display:inline-block;width:120px;text-align:left;'>门禁-</span> 地点: <span style='display:inline-block;width:100px;text-align:left;'>%1</span> 时间: <span style='display:inline-block;width:100px;text-align:left;'>%2</span></p>").arg(this->getplace()).arg(this->gettime());
}

QString library::getinfo() const {
    return QString("<p><span style='display:inline-block;width:120px;text-align:left;'>借书-</span> 地点: <span style='display:inline-block;width:100px;text-align:left;'>%1</span> 时间: <span style='display:inline-block;width:100px;text-align:left;'>%2</span> 书名: %3</p>").arg(this->getplace()).arg(this->gettime()).arg(this->getbookname());
}

QString canteen::getinfo() const {
    return QString("<p><span style='display:inline-block;width:120px;text-align:left;'>食堂消费-</span> 地点: <span style='display:inline-block;width:100px;text-align:left;'>%1</span> 时间: <span style='display:inline-block;width:100px;text-align:left;'>%2</span> 消费金额: %3元</p>").arg(this->getplace()).arg(this->gettime()).arg(this->getcost(), 4, 'f', 2);
}

QString gym::getinfo() const {
    return QString("<p><span style='display:inline-block;width:120px;text-align:left;'>健身房消费-</span> 地点: <span style='display:inline-block;width:100px;text-align:left;'>%1</span> 时间: <span style='display:inline-block;width:100px;text-align:left;'>%2</span> 健身内容: <span style='display:inline-block;width:100px;text-align:left;'>%3</span> 消费金额: %4元</p>").arg(this->getplace()).arg(this->gettime()).arg(this->getcontent()).arg(this->getcost(), 4, 'f', 2);
}

QString store::getinfo() const {
    return QString("<p><span style='display:inline-block;width:120px;text-align:left;'>超市消费-</span> 地点: <span style='display:inline-block;width:100px;text-align:left;'>%1</span> 时间: <span style='display:inline-block;width:100px;text-align:left;'>%2</span> 消费金额: %3元</p>").arg(this->getplace()).arg(this->gettime()).arg(this->getcost(), 4, 'f', 2);
}

QString cardevent::type(){return "cardevent";}

QString guard::type(){return "guard";}

QString library::type(){return "library";}

QString canteen::type(){return "canteen";}

QString gym::type(){return "gym";}

QString store::type(){return "store";}

void cardevent::setall(QString a,QString b){
    time=a;place=b;
}

void library::setbookname(QString a){
    bookname=a;
}

void canteen::setcost(double a){
    cost=a;
}

void gym::setcost(double a){
    cost=a;
}

void gym::setcontent(QString a){
    content=a;
}

void store::setcost(double a){
    cost=a;
}




