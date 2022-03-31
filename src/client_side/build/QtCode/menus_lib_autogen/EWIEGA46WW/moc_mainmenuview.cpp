/****************************************************************************
** Meta object code from reading C++ file 'mainmenuview.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "mainmenuview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainmenuview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainMenuView_t {
    const uint offsetsAndSize[160];
    char stringdata0[2124];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainMenuView_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainMenuView_t qt_meta_stringdata_MainMenuView = {
    {
QT_MOC_LITERAL(0, 12), // "MainMenuView"
QT_MOC_LITERAL(13, 23), // "__StartFetchingMessages"
QT_MOC_LITERAL(37, 0), // ""
QT_MOC_LITERAL(38, 10), // "UserClient"
QT_MOC_LITERAL(49, 10), // "other_user"
QT_MOC_LITERAL(60, 21), // "std::function<bool()>"
QT_MOC_LITERAL(82, 24), // "should_continue_fetching"
QT_MOC_LITERAL(107, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(129, 23), // "on_pushButton_5_clicked"
QT_MOC_LITERAL(153, 23), // "on_pushButton_9_clicked"
QT_MOC_LITERAL(177, 23), // "on_pushButton_6_clicked"
QT_MOC_LITERAL(201, 23), // "on_pushButton_8_clicked"
QT_MOC_LITERAL(225, 24), // "on_pushButton_11_clicked"
QT_MOC_LITERAL(250, 24), // "on_pushButton_10_clicked"
QT_MOC_LITERAL(275, 24), // "on_pushButton_12_clicked"
QT_MOC_LITERAL(300, 24), // "on_pushButton_13_clicked"
QT_MOC_LITERAL(325, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(349, 24), // "on_pushButton_14_clicked"
QT_MOC_LITERAL(374, 24), // "on_pushButton_16_clicked"
QT_MOC_LITERAL(399, 24), // "on_pushButton_15_clicked"
QT_MOC_LITERAL(424, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(448, 24), // "on_pushButton_18_clicked"
QT_MOC_LITERAL(473, 24), // "on_pushButton_17_clicked"
QT_MOC_LITERAL(498, 24), // "on_pushButton_19_clicked"
QT_MOC_LITERAL(523, 24), // "on_pushButton_20_clicked"
QT_MOC_LITERAL(548, 24), // "on_pushButton_21_clicked"
QT_MOC_LITERAL(573, 24), // "on_pushButton_22_clicked"
QT_MOC_LITERAL(598, 24), // "on_pushButton_23_clicked"
QT_MOC_LITERAL(623, 24), // "on_pushButton_24_clicked"
QT_MOC_LITERAL(648, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(672, 25), // "on_lineEdit_7_textChanged"
QT_MOC_LITERAL(698, 4), // "arg1"
QT_MOC_LITERAL(703, 24), // "on_pushButton_25_clicked"
QT_MOC_LITERAL(728, 24), // "on_pushButton_53_clicked"
QT_MOC_LITERAL(753, 24), // "on_pushButton_26_clicked"
QT_MOC_LITERAL(778, 44), // "on_lineEdit_SearchFriendUsern..."
QT_MOC_LITERAL(823, 35), // "on_pushButton_BackAddFriend_c..."
QT_MOC_LITERAL(859, 31), // "on_pushButton_AddFriend_clicked"
QT_MOC_LITERAL(891, 26), // "on_pushButton_Chat_clicked"
QT_MOC_LITERAL(918, 38), // "on_pushButton_BackChooseFrien..."
QT_MOC_LITERAL(957, 30), // "on_pushButton_Register_clicked"
QT_MOC_LITERAL(988, 36), // "on_pushButton_game_chat_send_..."
QT_MOC_LITERAL(1025, 31), // "on_pushButton_game_quit_clicked"
QT_MOC_LITERAL(1057, 33), // "on_pushButton_QuitWelcome_cli..."
QT_MOC_LITERAL(1091, 34), // "on_pushButton_LoginWelcome_cl..."
QT_MOC_LITERAL(1126, 37), // "on_pushButton_RegisterWelcome..."
QT_MOC_LITERAL(1164, 41), // "on_pushButton_PlayShortcutWel..."
QT_MOC_LITERAL(1206, 31), // "on_pushButton_GrayTheme_clicked"
QT_MOC_LITERAL(1238, 30), // "on_pushButton_RedTheme_clicked"
QT_MOC_LITERAL(1269, 32), // "on_pushButton_WhiteTheme_clicked"
QT_MOC_LITERAL(1302, 34), // "on_pushButton_AddAddFriend_cl..."
QT_MOC_LITERAL(1337, 30), // "on_pushButton_BackHelp_clicked"
QT_MOC_LITERAL(1368, 36), // "on_pushButton_SendButtonChat_..."
QT_MOC_LITERAL(1405, 30), // "on_pushButton_BackChat_clicked"
QT_MOC_LITERAL(1436, 33), // "on_pushButton_BackRanking_cli..."
QT_MOC_LITERAL(1470, 32), // "on_pushButton_EnterLogin_clicked"
QT_MOC_LITERAL(1503, 31), // "on_pushButton_BackLogin_clicked"
QT_MOC_LITERAL(1535, 34), // "on_pushButton_BackRegister_cl..."
QT_MOC_LITERAL(1570, 37), // "on_pushButton_RankingMainMenu..."
QT_MOC_LITERAL(1608, 34), // "on_pushButton_BackMainMenu_cl..."
QT_MOC_LITERAL(1643, 34), // "on_pushButton_HelpMainMenu_cl..."
QT_MOC_LITERAL(1678, 40), // "on_pushButton_FriendListMainM..."
QT_MOC_LITERAL(1719, 30), // "updateChatRoomMessagesListView"
QT_MOC_LITERAL(1750, 6), // "string"
QT_MOC_LITERAL(1757, 4), // "room"
QT_MOC_LITERAL(1762, 25), // "updateFriendsComboBoxView"
QT_MOC_LITERAL(1788, 10), // "QComboBox*"
QT_MOC_LITERAL(1799, 8), // "combobox"
QT_MOC_LITERAL(1808, 17), // "updateRankingView"
QT_MOC_LITERAL(1826, 14), // "updateChatRoom"
QT_MOC_LITERAL(1841, 34), // "on_pushButton_PlayMainMenu_cl..."
QT_MOC_LITERAL(1876, 40), // "on_pushButton_BackToMenuFromJ..."
QT_MOC_LITERAL(1917, 36), // "on_pushButton_ToInviteFriend_..."
QT_MOC_LITERAL(1954, 34), // "on_pushButton_InviteToGame_cl..."
QT_MOC_LITERAL(1989, 36), // "on_pushButton_BackToJoinMenu_..."
QT_MOC_LITERAL(2026, 43), // "on_lineEditNameOfGame_cursorP..."
QT_MOC_LITERAL(2070, 4), // "arg2"
QT_MOC_LITERAL(2075, 18), // "UpdateMessageViews"
QT_MOC_LITERAL(2094, 20), // "std::vector<Message>"
QT_MOC_LITERAL(2115, 8) // "messages"

    },
    "MainMenuView\0__StartFetchingMessages\0"
    "\0UserClient\0other_user\0std::function<bool()>\0"
    "should_continue_fetching\0on_pushButton_clicked\0"
    "on_pushButton_5_clicked\0on_pushButton_9_clicked\0"
    "on_pushButton_6_clicked\0on_pushButton_8_clicked\0"
    "on_pushButton_11_clicked\0"
    "on_pushButton_10_clicked\0"
    "on_pushButton_12_clicked\0"
    "on_pushButton_13_clicked\0"
    "on_pushButton_4_clicked\0"
    "on_pushButton_14_clicked\0"
    "on_pushButton_16_clicked\0"
    "on_pushButton_15_clicked\0"
    "on_pushButton_2_clicked\0"
    "on_pushButton_18_clicked\0"
    "on_pushButton_17_clicked\0"
    "on_pushButton_19_clicked\0"
    "on_pushButton_20_clicked\0"
    "on_pushButton_21_clicked\0"
    "on_pushButton_22_clicked\0"
    "on_pushButton_23_clicked\0"
    "on_pushButton_24_clicked\0"
    "on_pushButton_3_clicked\0"
    "on_lineEdit_7_textChanged\0arg1\0"
    "on_pushButton_25_clicked\0"
    "on_pushButton_53_clicked\0"
    "on_pushButton_26_clicked\0"
    "on_lineEdit_SearchFriendUsername_textChanged\0"
    "on_pushButton_BackAddFriend_clicked\0"
    "on_pushButton_AddFriend_clicked\0"
    "on_pushButton_Chat_clicked\0"
    "on_pushButton_BackChooseFriend_clicked\0"
    "on_pushButton_Register_clicked\0"
    "on_pushButton_game_chat_send_clicked\0"
    "on_pushButton_game_quit_clicked\0"
    "on_pushButton_QuitWelcome_clicked\0"
    "on_pushButton_LoginWelcome_clicked\0"
    "on_pushButton_RegisterWelcome_clicked\0"
    "on_pushButton_PlayShortcutWelcome_clicked\0"
    "on_pushButton_GrayTheme_clicked\0"
    "on_pushButton_RedTheme_clicked\0"
    "on_pushButton_WhiteTheme_clicked\0"
    "on_pushButton_AddAddFriend_clicked\0"
    "on_pushButton_BackHelp_clicked\0"
    "on_pushButton_SendButtonChat_clicked\0"
    "on_pushButton_BackChat_clicked\0"
    "on_pushButton_BackRanking_clicked\0"
    "on_pushButton_EnterLogin_clicked\0"
    "on_pushButton_BackLogin_clicked\0"
    "on_pushButton_BackRegister_clicked\0"
    "on_pushButton_RankingMainMenu_clicked\0"
    "on_pushButton_BackMainMenu_clicked\0"
    "on_pushButton_HelpMainMenu_clicked\0"
    "on_pushButton_FriendListMainMenu_clicked\0"
    "updateChatRoomMessagesListView\0string\0"
    "room\0updateFriendsComboBoxView\0"
    "QComboBox*\0combobox\0updateRankingView\0"
    "updateChatRoom\0on_pushButton_PlayMainMenu_clicked\0"
    "on_pushButton_BackToMenuFromJoin_clicked\0"
    "on_pushButton_ToInviteFriend_clicked\0"
    "on_pushButton_InviteToGame_clicked\0"
    "on_pushButton_BackToJoinMenu_clicked\0"
    "on_lineEditNameOfGame_cursorPositionChanged\0"
    "arg2\0UpdateMessageViews\0std::vector<Message>\0"
    "messages"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainMenuView[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      67,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,  416,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    0,  421,    2, 0x08,    4 /* Private */,
       8,    0,  422,    2, 0x08,    5 /* Private */,
       9,    0,  423,    2, 0x08,    6 /* Private */,
      10,    0,  424,    2, 0x08,    7 /* Private */,
      11,    0,  425,    2, 0x08,    8 /* Private */,
      12,    0,  426,    2, 0x08,    9 /* Private */,
      13,    0,  427,    2, 0x08,   10 /* Private */,
      14,    0,  428,    2, 0x08,   11 /* Private */,
      15,    0,  429,    2, 0x08,   12 /* Private */,
      16,    0,  430,    2, 0x08,   13 /* Private */,
      17,    0,  431,    2, 0x08,   14 /* Private */,
      18,    0,  432,    2, 0x08,   15 /* Private */,
      19,    0,  433,    2, 0x08,   16 /* Private */,
      20,    0,  434,    2, 0x08,   17 /* Private */,
      21,    0,  435,    2, 0x08,   18 /* Private */,
      22,    0,  436,    2, 0x08,   19 /* Private */,
      23,    0,  437,    2, 0x08,   20 /* Private */,
      24,    0,  438,    2, 0x08,   21 /* Private */,
      25,    0,  439,    2, 0x08,   22 /* Private */,
      26,    0,  440,    2, 0x08,   23 /* Private */,
      27,    0,  441,    2, 0x08,   24 /* Private */,
      28,    0,  442,    2, 0x08,   25 /* Private */,
      29,    0,  443,    2, 0x08,   26 /* Private */,
      30,    1,  444,    2, 0x08,   27 /* Private */,
      32,    0,  447,    2, 0x08,   29 /* Private */,
      33,    0,  448,    2, 0x08,   30 /* Private */,
      34,    0,  449,    2, 0x08,   31 /* Private */,
      35,    1,  450,    2, 0x08,   32 /* Private */,
      36,    0,  453,    2, 0x08,   34 /* Private */,
      37,    0,  454,    2, 0x08,   35 /* Private */,
      38,    0,  455,    2, 0x08,   36 /* Private */,
      39,    0,  456,    2, 0x08,   37 /* Private */,
      40,    0,  457,    2, 0x08,   38 /* Private */,
      41,    0,  458,    2, 0x08,   39 /* Private */,
      42,    0,  459,    2, 0x08,   40 /* Private */,
      43,    0,  460,    2, 0x08,   41 /* Private */,
      44,    0,  461,    2, 0x08,   42 /* Private */,
      45,    0,  462,    2, 0x08,   43 /* Private */,
      46,    0,  463,    2, 0x08,   44 /* Private */,
      47,    0,  464,    2, 0x08,   45 /* Private */,
      48,    0,  465,    2, 0x08,   46 /* Private */,
      49,    0,  466,    2, 0x08,   47 /* Private */,
      50,    0,  467,    2, 0x08,   48 /* Private */,
      51,    0,  468,    2, 0x08,   49 /* Private */,
      52,    0,  469,    2, 0x08,   50 /* Private */,
      53,    0,  470,    2, 0x08,   51 /* Private */,
      54,    0,  471,    2, 0x08,   52 /* Private */,
      55,    0,  472,    2, 0x08,   53 /* Private */,
      56,    0,  473,    2, 0x08,   54 /* Private */,
      57,    0,  474,    2, 0x08,   55 /* Private */,
      58,    0,  475,    2, 0x08,   56 /* Private */,
      59,    0,  476,    2, 0x08,   57 /* Private */,
      60,    0,  477,    2, 0x08,   58 /* Private */,
      61,    0,  478,    2, 0x08,   59 /* Private */,
      62,    0,  479,    2, 0x08,   60 /* Private */,
      62,    1,  480,    2, 0x08,   61 /* Private */,
      65,    1,  483,    2, 0x08,   63 /* Private */,
      68,    0,  486,    2, 0x08,   65 /* Private */,
      69,    0,  487,    2, 0x08,   66 /* Private */,
      70,    0,  488,    2, 0x08,   67 /* Private */,
      71,    0,  489,    2, 0x08,   68 /* Private */,
      72,    0,  490,    2, 0x08,   69 /* Private */,
      73,    0,  491,    2, 0x08,   70 /* Private */,
      74,    0,  492,    2, 0x08,   71 /* Private */,
      75,    2,  493,    2, 0x08,   72 /* Private */,
      77,    2,  498,    2, 0x0a,   75 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   31,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   31,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 63,   64,
    QMetaType::Void, 0x80000000 | 66,   67,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   31,   76,
    QMetaType::Void, 0x80000000 | 78, 0x80000000 | 3,   79,    4,

       0        // eod
};

void MainMenuView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainMenuView *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->__StartFetchingMessages((*reinterpret_cast< std::add_pointer_t<UserClient>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<std::function<bool()>>>(_a[2]))); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->on_pushButton_5_clicked(); break;
        case 3: _t->on_pushButton_9_clicked(); break;
        case 4: _t->on_pushButton_6_clicked(); break;
        case 5: _t->on_pushButton_8_clicked(); break;
        case 6: _t->on_pushButton_11_clicked(); break;
        case 7: _t->on_pushButton_10_clicked(); break;
        case 8: _t->on_pushButton_12_clicked(); break;
        case 9: _t->on_pushButton_13_clicked(); break;
        case 10: _t->on_pushButton_4_clicked(); break;
        case 11: _t->on_pushButton_14_clicked(); break;
        case 12: _t->on_pushButton_16_clicked(); break;
        case 13: _t->on_pushButton_15_clicked(); break;
        case 14: _t->on_pushButton_2_clicked(); break;
        case 15: _t->on_pushButton_18_clicked(); break;
        case 16: _t->on_pushButton_17_clicked(); break;
        case 17: _t->on_pushButton_19_clicked(); break;
        case 18: _t->on_pushButton_20_clicked(); break;
        case 19: _t->on_pushButton_21_clicked(); break;
        case 20: _t->on_pushButton_22_clicked(); break;
        case 21: _t->on_pushButton_23_clicked(); break;
        case 22: _t->on_pushButton_24_clicked(); break;
        case 23: _t->on_pushButton_3_clicked(); break;
        case 24: _t->on_lineEdit_7_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 25: _t->on_pushButton_25_clicked(); break;
        case 26: _t->on_pushButton_53_clicked(); break;
        case 27: _t->on_pushButton_26_clicked(); break;
        case 28: _t->on_lineEdit_SearchFriendUsername_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 29: _t->on_pushButton_BackAddFriend_clicked(); break;
        case 30: _t->on_pushButton_AddFriend_clicked(); break;
        case 31: _t->on_pushButton_Chat_clicked(); break;
        case 32: _t->on_pushButton_BackChooseFriend_clicked(); break;
        case 33: _t->on_pushButton_Register_clicked(); break;
        case 34: _t->on_pushButton_game_chat_send_clicked(); break;
        case 35: _t->on_pushButton_game_quit_clicked(); break;
        case 36: _t->on_pushButton_QuitWelcome_clicked(); break;
        case 37: _t->on_pushButton_LoginWelcome_clicked(); break;
        case 38: _t->on_pushButton_RegisterWelcome_clicked(); break;
        case 39: _t->on_pushButton_PlayShortcutWelcome_clicked(); break;
        case 40: _t->on_pushButton_GrayTheme_clicked(); break;
        case 41: _t->on_pushButton_RedTheme_clicked(); break;
        case 42: _t->on_pushButton_WhiteTheme_clicked(); break;
        case 43: _t->on_pushButton_AddAddFriend_clicked(); break;
        case 44: _t->on_pushButton_BackHelp_clicked(); break;
        case 45: _t->on_pushButton_SendButtonChat_clicked(); break;
        case 46: _t->on_pushButton_BackChat_clicked(); break;
        case 47: _t->on_pushButton_BackRanking_clicked(); break;
        case 48: _t->on_pushButton_EnterLogin_clicked(); break;
        case 49: _t->on_pushButton_BackLogin_clicked(); break;
        case 50: _t->on_pushButton_BackRegister_clicked(); break;
        case 51: _t->on_pushButton_RankingMainMenu_clicked(); break;
        case 52: _t->on_pushButton_BackMainMenu_clicked(); break;
        case 53: _t->on_pushButton_HelpMainMenu_clicked(); break;
        case 54: _t->on_pushButton_FriendListMainMenu_clicked(); break;
        case 55: _t->updateChatRoomMessagesListView(); break;
        case 56: _t->updateChatRoomMessagesListView((*reinterpret_cast< std::add_pointer_t<string>>(_a[1]))); break;
        case 57: _t->updateFriendsComboBoxView((*reinterpret_cast< std::add_pointer_t<QComboBox*>>(_a[1]))); break;
        case 58: _t->updateRankingView(); break;
        case 59: _t->updateChatRoom(); break;
        case 60: _t->on_pushButton_PlayMainMenu_clicked(); break;
        case 61: _t->on_pushButton_BackToMenuFromJoin_clicked(); break;
        case 62: _t->on_pushButton_ToInviteFriend_clicked(); break;
        case 63: _t->on_pushButton_InviteToGame_clicked(); break;
        case 64: _t->on_pushButton_BackToJoinMenu_clicked(); break;
        case 65: _t->on_lineEditNameOfGame_cursorPositionChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 66: _t->UpdateMessageViews((*reinterpret_cast< std::add_pointer_t<std::vector<Message>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<UserClient>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 57:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QComboBox* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainMenuView::*)(const UserClient & , const std::function<bool()> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainMenuView::__StartFetchingMessages)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MainMenuView::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainMenuView.offsetsAndSize,
    qt_meta_data_MainMenuView,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainMenuView_t
, QtPrivate::TypeAndForceComplete<MainMenuView, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const UserClient &, std::false_type>, QtPrivate::TypeAndForceComplete<const std::function<bool()>, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const string &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QComboBox *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const std::vector<Message> &, std::false_type>, QtPrivate::TypeAndForceComplete<const UserClient &, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainMenuView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainMenuView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainMenuView.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainMenuView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 67)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 67;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 67)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 67;
    }
    return _id;
}

// SIGNAL 0
void MainMenuView::__StartFetchingMessages(const UserClient & _t1, const std::function<bool()> _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
