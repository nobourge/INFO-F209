#ifndef MAINMENUVIEW_H
#define MAINMENUVIEW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainMenuView; }
QT_END_NAMESPACE

class MainMenuView : public QMainWindow
{
    Q_OBJECT

public:
    MainMenuView(QWidget *parent = nullptr);
    ~MainMenuView();

private slots:


    void on_pushButton_9_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainMenuView *ui;
    std::string chattext="";
    std::string Rankingtext="";
};
#endif // MAINMENUVIEW_H
