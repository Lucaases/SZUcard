#ifndef RANDOM1_H
#define RANDOM1_H

#include <QObject>
#include <QVector>
#include <random>
#include <algorithm>
#include "random0.h"


class cardevent:public QObject{
    Q_OBJECT
private:
    QString time{};
    QString place{};
public:
    cardevent(QString a,QString b,QObject* parent = nullptr):time(a),place(b),QObject(parent){}
    cardevent(QObject* parent = nullptr){}
    virtual ~cardevent()=default;
    virtual QString getinfo() const; //方便重载直接获取所有信息
    virtual QString type();
    QString gettime() const{return time;}
    QString getplace() const{return place;}
    void setall(QString a,QString b);
};

class guard:public cardevent{
    Q_OBJECT
public:
    guard(QString a,QString b,QObject* parent = nullptr):cardevent(a,b,parent){}
    virtual QString getinfo() const override;
    virtual QString type() override;
};

class library:public cardevent{
    Q_OBJECT
private:
    QString bookname{};
public:
    library(QString a,QString b,QString c,QObject* parent = nullptr):cardevent(a,b,parent),bookname(c){}
    virtual QString getinfo() const override;
    QString getbookname() const{return bookname;}
     virtual QString type() override;
    void setbookname(QString a);
};

class canteen:public cardevent{
    Q_OBJECT
private:
    double cost{};
public:
    canteen(QString a,QString b,double c,QObject* parent = nullptr):cardevent(a,b,parent),cost(c){}
    virtual QString getinfo() const override;
    double getcost() const{return cost;}
     virtual QString type() override;
    void setcost(double a);
};

class gym:public cardevent{
    Q_OBJECT
private:
    double cost{};
    QString content{};
public:
    gym(QString a,QString b,double c,QString d,QObject* parent = nullptr):cardevent(a,b,parent),cost(c),content(d){}
    virtual QString getinfo() const override;
    double getcost() const{return cost;}
    QString getcontent() const{return content;}
    virtual QString type() override;
    void setcost(double a);
    void setcontent(QString a);
};

class store:public cardevent{
    Q_OBJECT
private:
    double cost{};
public:
    store(QString a,QString b,double c,QObject* parent = nullptr):cardevent(a,b,parent),cost(c){}
    virtual QString getinfo() const override;
    double getcost() const{return cost;}
    virtual QString type() override;
    void setcost(double a);
};

class CampusCard:public QObject{
    Q_OBJECT
private:
    QString name{};
    QString gender{};
    QString college{};
    int age{};
    int id{};
    double balance{};
    QVector<cardevent*> history;

public:
    CampusCard(QString a, QString b, QString e, int c, int d, double f, QObject* parent = nullptr):
        name(a),gender(b),college(e),age(c),id(d),balance(f),QObject(parent){}
    CampusCard(QObject* parent = nullptr){}
    virtual ~CampusCard(){qDeleteAll(children());}
    virtual QString type();//区分教职工和学生
    QString getname();
    QString getgender();
    QString getcollege();
    int getage();
    int getid();
    double getbalance();
    void setname(QString a);
    void setgender(QString a);
    void setage(int a);
    void setid(int a);
    void setbalance(double a);
    void setcollege(QString a);
    void sethistory(QVector<cardevent*> a);
    QVector<cardevent*> gethistory();
    // virtual void useCard(cardevent* event);
    //virtual QString getCardInfo() const;
};

class TeacherCard : public CampusCard {
    Q_OBJECT
public:
    TeacherCard(QString a, QString b, QString e, int c, int d, double f, QObject* parent = nullptr):CampusCard(a,b,e,c,d,f,parent){}
    TeacherCard(QObject* parent = nullptr){}
    virtual ~TeacherCard() = default;
    virtual QString type() override;
};

class StudentCard : public CampusCard {
    Q_OBJECT
public:
    StudentCard(QString a, QString b, QString e,int c, int d, double f, QObject* parent = nullptr):CampusCard(a,b,e,c,d,f,parent){}
    StudentCard(QObject* parent = nullptr){}
    virtual ~StudentCard() = default;
    virtual QString type() override;
};

#endif // RANDOM1_H
