/********************************************************************************
** Form generated from reading UI file 'mainmenuview.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENUVIEW_H
#define UI_MAINMENUVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenuView
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page_3;
    QGridLayout *gridLayout_6;
    QVBoxLayout *verticalLayout;
    QLabel *label_Welcome;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_9;
    QPushButton *pushButton_6;
    QPushButton *pushButton_8;
    QPushButton *pushButton_27;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_7;
    QLabel *label_Theme;
    QPushButton *pushButton_21;
    QPushButton *pushButton_22;
    QPushButton *pushButton_23;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_8;
    QWidget *page_4;
    QPushButton *pushButton_10;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_11;
    QLabel *label;
    QLabel *label_6;
    QWidget *page_5;
    QLabel *label_2;
    QPushButton *pushButton_Register;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QPushButton *pushButton_13;
    QLabel *label_7;
    QWidget *page;
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_5;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QPushButton *pushButton_5;
    QSpacerItem *horizontalSpacer_4;
    QWidget *page_2;
    QTextEdit *textEdit;
    QPushButton *pushButton_14;
    QWidget *page_6;
    QComboBox *comboBox_ChooseFriend;
    QLabel *label_ChooseFriend;
    QPushButton *pushButton_Chat;
    QPushButton *pushButton_BackChooseFriend;
    QPushButton *pushButton_AddFriend;
    QWidget *page_7;
    QTextEdit *textEdit_2;
    QLineEdit *lineEdit_6;
    QPushButton *pushButton_17;
    QPushButton *pushButton_18;
    QWidget *page_8;
    QLabel *label_4;
    QPushButton *pushButton_19;
    QWidget *page_9;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_9;
    QTextEdit *textEdit_7;
    QLineEdit *lineEdit_15;
    QPushButton *pushButton_game_chat_send;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_2;
    QGraphicsView *graphicsView;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_game_quit;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_Game;
    QSpacerItem *horizontalSpacer_3;
    QWidget *page_10;
    QPushButton *pushButton_BackAddFriend;
    QLabel *label_AddFriend;
    QTextEdit *textEdit_DisplayFriendsAddFriend;
    QLineEdit *lineEdit_SearchFriendUsername;
    QPushButton *pushButton_26;
    QLabel *label_FriendAdded;

    void setupUi(QMainWindow *MainMenuView)
    {
        if (MainMenuView->objectName().isEmpty())
            MainMenuView->setObjectName(QString::fromUtf8("MainMenuView"));
        MainMenuView->resize(820, 624);
        MainMenuView->setAutoFillBackground(false);
        MainMenuView->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainMenuView);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_4 = new QGridLayout(centralwidget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        gridLayout_6 = new QGridLayout(page_3);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_Welcome = new QLabel(page_3);
        label_Welcome->setObjectName(QString::fromUtf8("label_Welcome"));

        verticalLayout->addWidget(label_Welcome);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        pushButton_9 = new QPushButton(page_3);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));

        verticalLayout->addWidget(pushButton_9);

        pushButton_6 = new QPushButton(page_3);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        verticalLayout->addWidget(pushButton_6);

        pushButton_8 = new QPushButton(page_3);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        verticalLayout->addWidget(pushButton_8);

        pushButton_27 = new QPushButton(page_3);
        pushButton_27->setObjectName(QString::fromUtf8("pushButton_27"));

        verticalLayout->addWidget(pushButton_27);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout_6->addLayout(verticalLayout, 0, 2, 2, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_7);

        label_Theme = new QLabel(page_3);
        label_Theme->setObjectName(QString::fromUtf8("label_Theme"));

        verticalLayout_2->addWidget(label_Theme);

        pushButton_21 = new QPushButton(page_3);
        pushButton_21->setObjectName(QString::fromUtf8("pushButton_21"));
        pushButton_21->setStyleSheet(QString::fromUtf8("background-color: rgb(186, 189, 182);"));

        verticalLayout_2->addWidget(pushButton_21);

        pushButton_22 = new QPushButton(page_3);
        pushButton_22->setObjectName(QString::fromUtf8("pushButton_22"));
        pushButton_22->setStyleSheet(QString::fromUtf8("background-color: rgb(164, 0, 0);"));

        verticalLayout_2->addWidget(pushButton_22);

        pushButton_23 = new QPushButton(page_3);
        pushButton_23->setObjectName(QString::fromUtf8("pushButton_23"));
        pushButton_23->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(pushButton_23);


        gridLayout_6->addLayout(verticalLayout_2, 1, 0, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_7, 0, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer, 1, 1, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_8, 0, 0, 1, 2);

        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        pushButton_10 = new QPushButton(page_4);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setGeometry(QRect(330, 320, 89, 25));
        lineEdit = new QLineEdit(page_4);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(320, 180, 113, 25));
        lineEdit_2 = new QLineEdit(page_4);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(320, 250, 113, 25));
        lineEdit_2->setEchoMode(QLineEdit::PasswordEchoOnEdit);
        pushButton_11 = new QPushButton(page_4);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setGeometry(QRect(330, 390, 89, 25));
        label = new QLabel(page_4);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(340, 30, 67, 17));
        label_6 = new QLabel(page_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(290, 90, 181, 17));
        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        label_2 = new QLabel(page_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(360, 40, 67, 17));
        pushButton_Register = new QPushButton(page_5);
        pushButton_Register->setObjectName(QString::fromUtf8("pushButton_Register"));
        pushButton_Register->setGeometry(QRect(330, 350, 111, 21));
        lineEdit_3 = new QLineEdit(page_5);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(330, 170, 113, 25));
        lineEdit_4 = new QLineEdit(page_5);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(330, 220, 113, 25));
        lineEdit_5 = new QLineEdit(page_5);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(330, 290, 113, 25));
        pushButton_13 = new QPushButton(page_5);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        pushButton_13->setGeometry(QRect(330, 430, 111, 21));
        label_7 = new QLabel(page_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(310, 80, 221, 20));
        stackedWidget->addWidget(page_5);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setStyleSheet(QString::fromUtf8("border-image: url(:/img/Main.jpg);"));
        gridLayout_3 = new QGridLayout(page);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_4, 0, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_5, 1, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_5, 2, 1, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton_2 = new QPushButton(page);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QPalette palette;
        QBrush brush(QColor(208, 208, 208, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(64, 65, 66, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(55, 55, 55, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(52, 52, 52, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush1);
        QBrush brush4(QColor(160, 160, 160, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush5(QColor(255, 51, 51, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush5);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush6(QColor(46, 47, 48, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush6);
        QBrush brush7(QColor(0, 0, 0, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush7);
        QBrush brush8(QColor(29, 84, 92, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush8);
        QBrush brush9(QColor(240, 240, 240, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush9);
        QBrush brush10(QColor(0, 122, 244, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Link, brush10);
        QBrush brush11(QColor(165, 122, 255, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::LinkVisited, brush11);
        QBrush brush12(QColor(53, 54, 55, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush12);
        palette.setBrush(QPalette::Active, QPalette::NoRole, brush7);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush1);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush13(QColor(127, 127, 128, 255));
        brush13.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush13);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush9);
        palette.setBrush(QPalette::Inactive, QPalette::Link, brush10);
        palette.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush11);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush12);
        QBrush brush14(QColor(0, 0, 0, 255));
        brush14.setStyle(Qt::NoBrush);
        palette.setBrush(QPalette::Inactive, QPalette::NoRole, brush14);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush13);
#endif
        QBrush brush15(QColor(164, 166, 168, 96));
        brush15.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush15);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush15);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush15);
        QBrush brush16(QColor(68, 68, 68, 255));
        brush16.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush16);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush16);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush9);
        palette.setBrush(QPalette::Disabled, QPalette::Link, brush10);
        palette.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush11);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush12);
        QBrush brush17(QColor(0, 0, 0, 255));
        brush17.setStyle(Qt::NoBrush);
        palette.setBrush(QPalette::Disabled, QPalette::NoRole, brush17);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush13);
#endif
        pushButton_2->setPalette(palette);
        pushButton_2->setAutoFillBackground(false);
        pushButton_2->setStyleSheet(QString::fromUtf8("border-image: null;\n"
""));
        pushButton_2->setCheckable(false);

        gridLayout_2->addWidget(pushButton_2, 1, 1, 1, 1);

        pushButton_4 = new QPushButton(page);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush5);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush7);
        palette1.setBrush(QPalette::Active, QPalette::Highlight, brush8);
        palette1.setBrush(QPalette::Active, QPalette::HighlightedText, brush9);
        palette1.setBrush(QPalette::Active, QPalette::Link, brush10);
        palette1.setBrush(QPalette::Active, QPalette::LinkVisited, brush11);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush12);
        palette1.setBrush(QPalette::Active, QPalette::NoRole, brush7);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush1);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush13);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::Highlight, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Link, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush11);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush12);
        QBrush brush18(QColor(0, 0, 0, 255));
        brush18.setStyle(Qt::NoBrush);
        palette1.setBrush(QPalette::Inactive, QPalette::NoRole, brush18);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush13);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush15);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush15);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush15);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush16);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush16);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Highlight, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Link, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush12);
        QBrush brush19(QColor(0, 0, 0, 255));
        brush19.setStyle(Qt::NoBrush);
        palette1.setBrush(QPalette::Disabled, QPalette::NoRole, brush19);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush13);
#endif
        pushButton_4->setPalette(palette1);
        pushButton_4->setStyleSheet(QString::fromUtf8("border-image: null;\n"
""));

        gridLayout_2->addWidget(pushButton_4, 2, 1, 1, 1);

        pushButton_3 = new QPushButton(page);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush5);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush7);
        palette2.setBrush(QPalette::Active, QPalette::Highlight, brush8);
        palette2.setBrush(QPalette::Active, QPalette::HighlightedText, brush9);
        palette2.setBrush(QPalette::Active, QPalette::Link, brush10);
        palette2.setBrush(QPalette::Active, QPalette::LinkVisited, brush11);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush12);
        palette2.setBrush(QPalette::Active, QPalette::NoRole, brush7);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush1);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush13);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::Highlight, brush8);
        palette2.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush9);
        palette2.setBrush(QPalette::Inactive, QPalette::Link, brush10);
        palette2.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush11);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush12);
        QBrush brush20(QColor(0, 0, 0, 255));
        brush20.setStyle(Qt::NoBrush);
        palette2.setBrush(QPalette::Inactive, QPalette::NoRole, brush20);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush13);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush15);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush15);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush15);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush16);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush16);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::Highlight, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush9);
        palette2.setBrush(QPalette::Disabled, QPalette::Link, brush10);
        palette2.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush11);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush12);
        QBrush brush21(QColor(0, 0, 0, 255));
        brush21.setStyle(Qt::NoBrush);
        palette2.setBrush(QPalette::Disabled, QPalette::NoRole, brush21);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush13);
#endif
        pushButton_3->setPalette(palette2);
        pushButton_3->setStyleSheet(QString::fromUtf8("border-image: null;\n"
""));

        gridLayout_2->addWidget(pushButton_3, 3, 1, 1, 1);

        pushButton = new QPushButton(page);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setEnabled(true);
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette3.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette3.setBrush(QPalette::Active, QPalette::Dark, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::BrightText, brush5);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette3.setBrush(QPalette::Active, QPalette::Shadow, brush7);
        palette3.setBrush(QPalette::Active, QPalette::Highlight, brush8);
        palette3.setBrush(QPalette::Active, QPalette::HighlightedText, brush9);
        palette3.setBrush(QPalette::Active, QPalette::Link, brush10);
        palette3.setBrush(QPalette::Active, QPalette::LinkVisited, brush11);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush12);
        palette3.setBrush(QPalette::Active, QPalette::NoRole, brush7);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipBase, brush1);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush13);
#endif
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::BrightText, brush5);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Shadow, brush7);
        palette3.setBrush(QPalette::Inactive, QPalette::Highlight, brush8);
        palette3.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush9);
        palette3.setBrush(QPalette::Inactive, QPalette::Link, brush10);
        palette3.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush11);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush12);
        QBrush brush22(QColor(0, 0, 0, 255));
        brush22.setStyle(Qt::NoBrush);
        palette3.setBrush(QPalette::Inactive, QPalette::NoRole, brush22);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush13);
#endif
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush15);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush15);
        palette3.setBrush(QPalette::Disabled, QPalette::BrightText, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush15);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush16);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush16);
        palette3.setBrush(QPalette::Disabled, QPalette::Shadow, brush7);
        palette3.setBrush(QPalette::Disabled, QPalette::Highlight, brush8);
        palette3.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush9);
        palette3.setBrush(QPalette::Disabled, QPalette::Link, brush10);
        palette3.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush11);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush12);
        QBrush brush23(QColor(0, 0, 0, 255));
        brush23.setStyle(Qt::NoBrush);
        palette3.setBrush(QPalette::Disabled, QPalette::NoRole, brush23);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush13);
#endif
        pushButton->setPalette(palette3);
        pushButton->setStyleSheet(QString::fromUtf8("\n"
"border-image: null;\n"
"\n"
""));
        pushButton->setCheckable(false);
        pushButton->setFlat(false);

        gridLayout_2->addWidget(pushButton, 0, 1, 1, 1);

        pushButton_5 = new QPushButton(page);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette4.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette4.setBrush(QPalette::Active, QPalette::Dark, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::BrightText, brush5);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette4.setBrush(QPalette::Active, QPalette::Shadow, brush7);
        palette4.setBrush(QPalette::Active, QPalette::Highlight, brush8);
        palette4.setBrush(QPalette::Active, QPalette::HighlightedText, brush9);
        palette4.setBrush(QPalette::Active, QPalette::Link, brush10);
        palette4.setBrush(QPalette::Active, QPalette::LinkVisited, brush11);
        palette4.setBrush(QPalette::Active, QPalette::AlternateBase, brush12);
        palette4.setBrush(QPalette::Active, QPalette::NoRole, brush7);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipBase, brush1);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Active, QPalette::PlaceholderText, brush13);
#endif
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::BrightText, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::Shadow, brush7);
        palette4.setBrush(QPalette::Inactive, QPalette::Highlight, brush8);
        palette4.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush9);
        palette4.setBrush(QPalette::Inactive, QPalette::Link, brush10);
        palette4.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush11);
        palette4.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush12);
        QBrush brush24(QColor(0, 0, 0, 255));
        brush24.setStyle(Qt::NoBrush);
        palette4.setBrush(QPalette::Inactive, QPalette::NoRole, brush24);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush13);
#endif
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush15);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush15);
        palette4.setBrush(QPalette::Disabled, QPalette::BrightText, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush15);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush16);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush16);
        palette4.setBrush(QPalette::Disabled, QPalette::Shadow, brush7);
        palette4.setBrush(QPalette::Disabled, QPalette::Highlight, brush8);
        palette4.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush9);
        palette4.setBrush(QPalette::Disabled, QPalette::Link, brush10);
        palette4.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush11);
        palette4.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush12);
        QBrush brush25(QColor(0, 0, 0, 255));
        brush25.setStyle(Qt::NoBrush);
        palette4.setBrush(QPalette::Disabled, QPalette::NoRole, brush25);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush13);
#endif
        pushButton_5->setPalette(palette4);
        pushButton_5->setStyleSheet(QString::fromUtf8("border-image: null;\n"
""));

        gridLayout_2->addWidget(pushButton_5, 4, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 1, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 1, 2, 1, 1);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        textEdit = new QTextEdit(page_2);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(320, 160, 161, 171));
        textEdit->setReadOnly(true);
        pushButton_14 = new QPushButton(page_2);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        pushButton_14->setGeometry(QRect(350, 400, 89, 25));
        stackedWidget->addWidget(page_2);
        page_6 = new QWidget();
        page_6->setObjectName(QString::fromUtf8("page_6"));
        comboBox_ChooseFriend = new QComboBox(page_6);
        comboBox_ChooseFriend->setObjectName(QString::fromUtf8("comboBox_ChooseFriend"));
        comboBox_ChooseFriend->setGeometry(QRect(330, 200, 86, 25));
        label_ChooseFriend = new QLabel(page_6);
        label_ChooseFriend->setObjectName(QString::fromUtf8("label_ChooseFriend"));
        label_ChooseFriend->setGeometry(QRect(330, 150, 111, 17));
        pushButton_Chat = new QPushButton(page_6);
        pushButton_Chat->setObjectName(QString::fromUtf8("pushButton_Chat"));
        pushButton_Chat->setGeometry(QRect(330, 300, 89, 25));
        pushButton_BackChooseFriend = new QPushButton(page_6);
        pushButton_BackChooseFriend->setObjectName(QString::fromUtf8("pushButton_BackChooseFriend"));
        pushButton_BackChooseFriend->setGeometry(QRect(330, 340, 89, 25));
        pushButton_AddFriend = new QPushButton(page_6);
        pushButton_AddFriend->setObjectName(QString::fromUtf8("pushButton_AddFriend"));
        pushButton_AddFriend->setGeometry(QRect(330, 250, 91, 24));
        stackedWidget->addWidget(page_6);
        page_7 = new QWidget();
        page_7->setObjectName(QString::fromUtf8("page_7"));
        textEdit_2 = new QTextEdit(page_7);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(300, 140, 171, 141));
        textEdit_2->setReadOnly(true);
        lineEdit_6 = new QLineEdit(page_7);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(300, 320, 171, 31));
        pushButton_17 = new QPushButton(page_7);
        pushButton_17->setObjectName(QString::fromUtf8("pushButton_17"));
        pushButton_17->setGeometry(QRect(330, 390, 89, 25));
        pushButton_18 = new QPushButton(page_7);
        pushButton_18->setObjectName(QString::fromUtf8("pushButton_18"));
        pushButton_18->setGeometry(QRect(330, 440, 89, 25));
        stackedWidget->addWidget(page_7);
        page_8 = new QWidget();
        page_8->setObjectName(QString::fromUtf8("page_8"));
        label_4 = new QLabel(page_8);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(300, 170, 201, 101));
        pushButton_19 = new QPushButton(page_8);
        pushButton_19->setObjectName(QString::fromUtf8("pushButton_19"));
        pushButton_19->setGeometry(QRect(330, 330, 89, 25));
        stackedWidget->addWidget(page_8);
        page_9 = new QWidget();
        page_9->setObjectName(QString::fromUtf8("page_9"));
        gridLayout = new QGridLayout(page_9);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        textEdit_7 = new QTextEdit(page_9);
        textEdit_7->setObjectName(QString::fromUtf8("textEdit_7"));
        textEdit_7->setReadOnly(true);

        verticalLayout_9->addWidget(textEdit_7);

        lineEdit_15 = new QLineEdit(page_9);
        lineEdit_15->setObjectName(QString::fromUtf8("lineEdit_15"));

        verticalLayout_9->addWidget(lineEdit_15);

        pushButton_game_chat_send = new QPushButton(page_9);
        pushButton_game_chat_send->setObjectName(QString::fromUtf8("pushButton_game_chat_send"));

        verticalLayout_9->addWidget(pushButton_game_chat_send);


        gridLayout->addLayout(verticalLayout_9, 1, 0, 2, 1);

        horizontalSpacer_10 = new QSpacerItem(584, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_10, 1, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        graphicsView = new QGraphicsView(page_9);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        horizontalLayout_2->addWidget(graphicsView);


        gridLayout->addLayout(horizontalLayout_2, 2, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 474, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 2, 2, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        pushButton_game_quit = new QPushButton(page_9);
        pushButton_game_quit->setObjectName(QString::fromUtf8("pushButton_game_quit"));

        horizontalLayout_5->addWidget(pushButton_game_quit);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_9);


        gridLayout->addLayout(horizontalLayout_5, 3, 0, 1, 2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        label_Game = new QLabel(page_9);
        label_Game->setObjectName(QString::fromUtf8("label_Game"));

        horizontalLayout_4->addWidget(label_Game);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        gridLayout->addLayout(horizontalLayout_4, 0, 0, 1, 2);

        stackedWidget->addWidget(page_9);
        page_10 = new QWidget();
        page_10->setObjectName(QString::fromUtf8("page_10"));
        pushButton_BackAddFriend = new QPushButton(page_10);
        pushButton_BackAddFriend->setObjectName(QString::fromUtf8("pushButton_BackAddFriend"));
        pushButton_BackAddFriend->setGeometry(QRect(370, 350, 80, 24));
        label_AddFriend = new QLabel(page_10);
        label_AddFriend->setObjectName(QString::fromUtf8("label_AddFriend"));
        label_AddFriend->setGeometry(QRect(390, 140, 71, 16));
        textEdit_DisplayFriendsAddFriend = new QTextEdit(page_10);
        textEdit_DisplayFriendsAddFriend->setObjectName(QString::fromUtf8("textEdit_DisplayFriendsAddFriend"));
        textEdit_DisplayFriendsAddFriend->setGeometry(QRect(370, 170, 104, 70));
        textEdit_DisplayFriendsAddFriend->setReadOnly(true);
        lineEdit_SearchFriendUsername = new QLineEdit(page_10);
        lineEdit_SearchFriendUsername->setObjectName(QString::fromUtf8("lineEdit_SearchFriendUsername"));
        lineEdit_SearchFriendUsername->setGeometry(QRect(300, 260, 241, 24));
        pushButton_26 = new QPushButton(page_10);
        pushButton_26->setObjectName(QString::fromUtf8("pushButton_26"));
        pushButton_26->setGeometry(QRect(370, 310, 80, 24));
        label_FriendAdded = new QLabel(page_10);
        label_FriendAdded->setObjectName(QString::fromUtf8("label_FriendAdded"));
        label_FriendAdded->setGeometry(QRect(300, 60, 221, 71));
        label_FriendAdded->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(page_10);

        horizontalLayout->addWidget(stackedWidget);


        gridLayout_4->addLayout(horizontalLayout, 0, 0, 1, 1);

        MainMenuView->setCentralWidget(centralwidget);

        retranslateUi(MainMenuView);

        stackedWidget->setCurrentIndex(8);


        QMetaObject::connectSlotsByName(MainMenuView);
    } // setupUi

    void retranslateUi(QMainWindow *MainMenuView)
    {
        MainMenuView->setWindowTitle(QCoreApplication::translate("MainMenuView", "Quoridor", nullptr));
        label_Welcome->setText(QCoreApplication::translate("MainMenuView", "Welcome", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainMenuView", "Login", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainMenuView", "Register", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainMenuView", "Quit", nullptr));
        pushButton_27->setText(QCoreApplication::translate("MainMenuView", "play shortcut", nullptr));
        label_Theme->setText(QCoreApplication::translate("MainMenuView", "Theme", nullptr));
        pushButton_21->setText(QCoreApplication::translate("MainMenuView", "Grey", nullptr));
        pushButton_22->setText(QCoreApplication::translate("MainMenuView", "Red", nullptr));
        pushButton_23->setText(QCoreApplication::translate("MainMenuView", "White", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainMenuView", "Enter", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainMenuView", "Pseudo", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("MainMenuView", "Mot de passe", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainMenuView", "Back", nullptr));
        label->setText(QCoreApplication::translate("MainMenuView", "Login", nullptr));
        label_6->setText(QString());
        label_2->setText(QCoreApplication::translate("MainMenuView", "Register", nullptr));
        pushButton_Register->setText(QCoreApplication::translate("MainMenuView", "Register", nullptr));
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("MainMenuView", "Pseudo", nullptr));
        lineEdit_4->setPlaceholderText(QCoreApplication::translate("MainMenuView", "Mot de passe", nullptr));
        lineEdit_5->setPlaceholderText(QCoreApplication::translate("MainMenuView", "Confirmer", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainMenuView", "Back", nullptr));
        label_7->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("MainMenuView", "Friend list", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainMenuView", "Ranking", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainMenuView", "Help", nullptr));
        pushButton->setText(QCoreApplication::translate("MainMenuView", "Play", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainMenuView", "Back", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MainMenuView", "Back", nullptr));
        label_ChooseFriend->setText(QCoreApplication::translate("MainMenuView", "Choose Friend", nullptr));
        pushButton_Chat->setText(QCoreApplication::translate("MainMenuView", "Chat", nullptr));
        pushButton_BackChooseFriend->setText(QCoreApplication::translate("MainMenuView", "Back", nullptr));
        pushButton_AddFriend->setText(QCoreApplication::translate("MainMenuView", "Add Friend", nullptr));
        pushButton_17->setText(QCoreApplication::translate("MainMenuView", "Send", nullptr));
        pushButton_18->setText(QCoreApplication::translate("MainMenuView", "Back", nullptr));
        label_4->setText(QCoreApplication::translate("MainMenuView", "The Help", nullptr));
        pushButton_19->setText(QCoreApplication::translate("MainMenuView", "Back", nullptr));
        pushButton_game_chat_send->setText(QCoreApplication::translate("MainMenuView", "Send", nullptr));
        pushButton_game_quit->setText(QCoreApplication::translate("MainMenuView", "Quit Game", nullptr));
        label_Game->setText(QCoreApplication::translate("MainMenuView", "Game", nullptr));
        pushButton_BackAddFriend->setText(QCoreApplication::translate("MainMenuView", "Back", nullptr));
        label_AddFriend->setText(QCoreApplication::translate("MainMenuView", "Add Friend", nullptr));
        lineEdit_SearchFriendUsername->setPlaceholderText(QCoreApplication::translate("MainMenuView", "Search friend username", nullptr));
        pushButton_26->setText(QCoreApplication::translate("MainMenuView", "Add", nullptr));
        label_FriendAdded->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainMenuView: public Ui_MainMenuView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENUVIEW_H
