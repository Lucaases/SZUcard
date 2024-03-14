#ifndef SUBPAGE_H
#define SUBPAGE_H

#include <QDialog>
#include <QFile>
#include <QRegularExpression>
#include <QMessageBox>
#include "random1.h"

namespace Ui {
class subpage;
}

class subpage : public QDialog
{
    Q_OBJECT

public:
    explicit subpage(QWidget *parent = nullptr);
    ~subpage();

public slots:
    void print1(TeacherCard* a);
    void print2(StudentCard* a);
private slots:
    void on_quit_clicked();
    void on_save_clicked();

private:
     Ui::subpage *ui;
};

#endif // SUBPAGE_H
