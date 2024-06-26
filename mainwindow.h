#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "subpage.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_teacher_button_clicked();

    void on_student_button_clicked();

    void on_exit_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
