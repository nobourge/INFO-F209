//
// Created by Anton Romanova on 17/02/2022.
//

#ifndef QUORIDOR_SRC_COMMON_CONSTANTS_H_
#define QUORIDOR_SRC_COMMON_CONSTANTS_H_

#define SERVER_PORT                       560

// username
#define MAX_USERNAME_SIZE                 32
#define MIN_USERNAME_SIZE                 3
#define USERNAME_VALID_SPECIAL_CHARS      {'-', '_'}

// password
#define MIN_PASSWORD_LENGTH               8
#define MAX_PASSWORD_LENGTH               64

// client_side
#define MENU_NAME_EFFECT                  A_BOLD
#define VIEW_HOVER_EFFECT                 A_REVERSE
#define VIEW_SELECTED_EFFECT              A_UNDERLINE
#define BUTTONS_VERTICAL_GUTTER_SIZE      1

// server_side
#define DATABASE_FILE_NAME                "example.db"


#endif //QUORIDOR_SRC_COMMON_CONSTANTS_H_
