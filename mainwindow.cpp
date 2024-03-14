#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool cmp(cardevent*a,cardevent*b){//重载按日期排序
    QMap<QString,int> weekmap = {//星期几不好比较排序,所以要想创建映射,通过值对键排序
        {"星期一", 1},
        {"星期二", 2},
        {"星期三", 3},
        {"星期四", 4},
        {"星期五", 5},
        {"星期六", 6},
        {"星期日", 7}
    };
    QStringList list1 = a->gettime().split("--");//切割time字符串 time=星期几--小时:分钟:秒
    QStringList list11 = list1[1].split(":");//list1[0]=星期几,list[1]=小时:分钟:秒
    QStringList list2 = b->gettime().split("--");//list11[0]=小时,list11[1]=分钟,list11[2]=秒
    QStringList list22 = list2[1].split(":");
    if(weekmap[list1[0]] < weekmap[list2[0]]) {
        return true;
    } else if(weekmap[list1[0]] == weekmap[list2[0]]) {
        if(list11[0].toInt() < list22[0].toInt()) {
            return true;
        } else if(list11[0].toInt() == list22[0].toInt()) {
            if(list11[1].toInt() < list22[1].toInt()) {
                return true;
            } else if(list11[1].toInt() == list22[1].toInt()) {
                return list11[2].toInt() < list22[2].toInt();
            }
        }
    }
    return false;
}


QVector<cardevent*> random_generate_history(){//随机生成一周历史记录
    QVector<cardevent*> temp;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> x1(5,30);
    std::uniform_real_distribution<double> x2(3,200);
    std::uniform_real_distribution<double> x3(20,60);
    std::uniform_int_distribution<int> y(8,21);
    std::uniform_int_distribution<int> z(0,59);
    DistinctUniformIntDistribution<int> j(0,9);
    QString week[7]={"星期一","星期二","星期三","星期四","星期五","星期六","星期日"};
    std::uniform_int_distribution<int> k(0,3);
    std::uniform_int_distribution<int> k1(2,7);//*
    std::uniform_int_distribution<int> k2(2,4);//*
    QString gate[4]={"惟品门","惟理门","惟艺门","惟新门"};
    DistinctUniformIntDistribution<int> l(0,9);
    DistinctUniformIntDistribution<int> e(0,6);
    DistinctUniformIntDistribution<int> f(0,6);
    DistinctUniformIntDistribution<int> g(0,6);
    DistinctUniformIntDistribution<int> h(0,6);
    DistinctUniformIntDistribution<int> m(0,6);
    QString bookTitles[10] = { "红楼梦","西游记","水浒传","三国演义","围城","平凡的世界","活着","百年孤独", "挪威的森林","哈利·波特与魔法石"};
    QString canteens[4]={"采葛","采薇","伐木","伐檀"};
    QString stores[4]={"百分购","罗森   ","麦当劳","瑞幸   "};
    QString contents[10]={"深蹲", "卧推","硬拉","引体向上","坐姿划船","立式推举","哑铃弯举","平板支撑","跑步机跑步","动感单车"};
    for(int i=0 ;i<k1(gen);i++){
        guard* a = new guard("0","0");
        a->setall(QString("%1--%2:%3:%4").arg(week[e(gen)]).arg(y(gen),2,10,QLatin1Char('0')).arg(z(gen),2,10,QLatin1Char('0')).arg(z(gen),2,10,QLatin1Char('0')),gate[k(gen)]);
        temp.append(a);
        canteen* b = new canteen("0","0",0);
        b->setall(QString("%1--%2:%3:%4").arg(week[f(gen)]).arg(y(gen),2,10,QLatin1Char('0')).arg(z(gen),2,10,QLatin1Char('0')).arg(z(gen),2,10,QLatin1Char('0')),canteens[k(gen)]);b->setcost(x1(gen));
        temp.append(b);
        store* c = new store("0","0",0);
        c->setall(QString("%1--%2:%3:%4").arg(week[g(gen)]).arg(y(gen),2,10,QLatin1Char('0')).arg(z(gen),2,10,QLatin1Char('0')).arg(z(gen),2,10,QLatin1Char('0')),stores[k(gen)]);c->setcost(x2(gen));
        temp.append(c);
    }
    for(int i=0;i<k2(gen);i++){
        library* a = new library("0","0","0");
        a->setall(QString("%1--%2:%3:%4").arg(week[h(gen)]).arg(y(gen),2,10,QLatin1Char('0')).arg(z(gen),2,10,QLatin1Char('0')).arg(z(gen),2,10,QLatin1Char('0')),"中央图书馆");a->setbookname(bookTitles[l(gen)]);
        temp.append(a);
        gym* b =new gym("0","0",0,"0");
        b->setall(QString("%1--%2:%3:%4").arg(week[m(gen)]).arg(y(gen),2,10,QLatin1Char('0')).arg(z(gen),2,10,QLatin1Char('0')).arg(z(gen),2,10,QLatin1Char('0')),"至快健身房");b->setcost(x3(gen));b->setcontent(contents[j(gen)]);
        temp.append(b);
    }
    std::sort(temp.begin(),temp.end(),cmp);
    return temp;
}


void random_generate_card(CampusCard* a){//随机生成校园卡信息
    std::random_device rd;
    std::mt19937 gen(rd());
    std::unordered_map<QString,QString> name_gender_map;//使得男女名字对应
    name_gender_map["John"] = "男";name_gender_map["Emma"] = "女";name_gender_map["Michael"] = "男";name_gender_map["Sophia"] = "女";
    name_gender_map["David"] = "男";name_gender_map["Olivia"] = "女";name_gender_map["Daniel"] = "男";name_gender_map["Ava"] = "女";
    name_gender_map["Matthew"] = "男";name_gender_map["Mia"] = "女";name_gender_map["Andrew"] = "男";name_gender_map["Emily"] = "女";
    name_gender_map["Joshua"] = "男"; name_gender_map["Abigail"] = "女";name_gender_map["James"] = "男";name_gender_map["Madison"] = "女";
    name_gender_map["Joseph"] = "男";name_gender_map["Elizabeth"] = "女";name_gender_map["Anthony"] = "男";name_gender_map["Chloe"] = "女";
    QString name[20]={"John","Emma","Michael","Sophia","David","Olivia","Daniel","Ava","Matthew","Mia",
                        "Andrew","Emily","Joshua","Abigail","James","Madison","Joseph","Elizabeth","Anthony","Chloe"};
    std::uniform_int_distribution<int> x(0,19);
    QString college_names[17] = {"临床医学院", "生物医学工程学院","商学院","药学院","法学院","教育学院","设计学院","土木与交通工程学院","护理学院","物理与光电学院",
                                 "数学科学学院","计算机与软件学院","生命科学与海洋学院","材料学院","体育学院","人文学院","传播学院"};
    std::uniform_int_distribution<int> y(0,16);
    std::uniform_int_distribution<int> z(30,60);
    std::uniform_int_distribution<int> l(17,28);
    std::uniform_real_distribution<double> j(5000,100000);
    std::uniform_real_distribution<double> h(100,10000);
    DistinctUniformIntDistribution<int> k(100000,999999);
    if(a->type()=="TeacherCard"){
        a->setname(name[x(gen)]);
        a->setgender(name_gender_map[a->getname()]);
        a->setcollege(college_names[y(gen)]);
        a->setid(k(gen));
        a->setage(z(gen));
        a->setbalance(j(gen));
        a->sethistory(random_generate_history());
    }
    else if(a->type()=="StudentCard"){
        a->setname(name[x(gen)]);
        a->setgender(name_gender_map[a->getname()]);
        a->setcollege(college_names[y(gen)]);
        a->setid(k(gen));
        a->setage(l(gen));
        a->setbalance(h(gen));
        a->sethistory(random_generate_history());
    }
}

void exit1(CampusCard* a){//确保指针指向区域被完全释放
    QVector<cardevent*> temp = a->gethistory();
    for(int i = 0; i < temp.size(); i++)
    {
        if (temp[i] != nullptr)
        {
            delete temp[i];
            temp[i] = nullptr;
        }
    }
    temp.clear();
    temp.squeeze();
}

void MainWindow::on_teacher_button_clicked()
{
    TeacherCard* a = new TeacherCard("0","0","0",0,0,0);
    random_generate_card(a);
    if(a!=nullptr){
    subpage* newpage = new subpage();
    newpage->print1(a);
    exit1(a);}
}


void MainWindow::on_student_button_clicked()
{
    StudentCard* a =new StudentCard("0","0","0",0,0,0);
    random_generate_card(a);
    if(a!=nullptr){
    subpage* newpage = new subpage();
    newpage->print2(a);
    exit1(a);}
}


void MainWindow::on_exit_clicked()
{
    exit(0);
}

