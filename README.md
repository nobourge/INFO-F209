# INFO-F209
Making the classical board game Quoridor with the addition of social features such as managing a friend list and many others

## Required packages
The following packages must be downloaded for the project to work the intended way  

### sqlite3
A database library for C++

**Ubuntu**
```
$ sudo apt-get install sqlite3
$ sudo apt-get install libsqlite3-dev
```
> Download [link](https://www.sqlite.org/download.html) for manual download

### boost
An all-purpose networking library for C++

**Ubuntu**
```
& sudo apt-get install libboost-all-dev
```
> Download [link](https://www.boost.org/) for manual download

### OpenSSL

**Ubuntu**
```
& sudo apt-get install libssl-dev
```

**Windows**
>Download [link](https://slproweb.com/products/Win32OpenSSL.html) for manual download

### crow
A web service framework library for C++

**Ubuntu**  
Manual download only  
>Download [link](https://github.com/CrowCpp/Crow) for manual download

#### Dependencies
* openssl
* boost


### curl
command line tool and library for transferring data with URLs

**Ubuntu**  
```
$ sudo apt-get install curl
$ sudo apt-get install libcurl-dev
```

### ncurses
A simple text-based user interface library for C/C++

**Ubuntu**
```
$ sudo apt-get install libncurses5-dev libncursesw5-dev
```
### uuid
Unique identifier library  

**Ubuntu**
```
$ sudo apt-get install uuid uuid-dev
```
## Build
```
$ cmake -S . -B bin/
$ cd bin 
$ make
```

## Execution
```
$ ./QuoridorServer
$ ./QuoridorClient
```

# API

## Requests

### **GET** - /api/v1/users

#### Description
Returns all users

#### CURL

```sh
curl -X GET "http://0.0.0.0:18080/api/v1/users"
```

### **GET** - /api/v1/users/ranking

#### Description
Returns a list of users sorted by score

#### CURL

```sh
curl -X GET "http://0.0.0.0:18080/api/v1/users/ranking\
?max_num_users=5" \
    -H "Content-Type: text/plain"
```

#### Query Parameters

- **max_num_users**

### **GET** - /api/v1/new_user

#### Description
Creates a new user

#### CURL

```sh
curl -X GET "http://0.0.0.0:18080/api/v1/new_user" \
-u "user":"password"
```

#### Security

- Basic Authentication
  - **username**
  - **password**

### **GET** - /api/v1/me

#### Description
Returns current user

#### CURL

```sh
curl -X GET "http://0.0.0.0:18080/api/v1/me" \
-u "user":"password"
```

#### Security

- Basic Authentication
  - **username**
  - **password**

### **GET** - /api/v1/me/messages/send

#### Description
Sends a message to the given user

#### CURL

```sh
curl -X GET "http://0.0.0.0:18080/api/v1/me/messages/send\
?user=other_user_username&content=Message_content" \
-u "user":"password"
```

#### Query Parameters

- **user**
- **content**

#### Security

- Basic Authentication
  - **username**
  - **password**

### **GET** - /api/v1/me/messages

#### Description
Returns a list of all the messages

#### CURL

```sh
... (192 lignes restantes)
Réduire
QuoridorAPI.paw.md
5 Ko
﻿
# API

## Requests

### **GET** - /api/v1/users

#### Description
Returns all users

#### CURL

```sh
curl -X GET "http://0.0.0.0:18080/api/v1/users"
```

### **GET** - /api/v1/users/ranking

#### Description
Returns a list of users sorted by score

#### CURL

```sh
curl -X GET "http://0.0.0.0:18080/api/v1/users/ranking\
?max_num_users=5" \
    -H "Content-Type: text/plain"
```

#### Query Parameters

- **max_num_users**

### **GET** - /api/v1/new_user

#### Description
Creates a new user

#### CURL

```sh
curl -X GET "http://0.0.0.0:18080/api/v1/new_user" \
-u "user":"password"
```

#### Security

- Basic Authentication
  - **username**
  - **password**

### **GET** - /api/v1/me

#### Description
Returns current user

#### CURL

```sh
curl -X GET "http://0.0.0.0:18080/api/v1/me" \
-u "user":"password"
```

#### Security

- Basic Authentication
  - **username**
  - **password**

### **GET** - /api/v1/me/messages/send

#### Description
Sends a message to the given user

#### CURL

```sh
curl -X GET "http://0.0.0.0:18080/api/v1/me/messages/send\
?user=other_user_username&content=Message_content" \
-u "user":"password"
```

#### Query Parameters

- **user**
- **content**

#### Security

- Basic Authentication
  - **username**
  - **password**

### **GET** - /api/v1/me/messages

#### Description
Returns a list of all the messages

#### CURL

```sh
curl -X GET "http://0.0.0.0:18080/api/v1/me/messages\
?user=other_user" \
-u "user":"password"
```

#### Query Parameters

- **user**

#### Security

- Basic Authentication
  - **username**
  - **password**

### **GET** - /api/v1/me/add_friend

#### Description
Adds the other person as friend

#### CURL

```sh
curl -X GET "http://0.0.0.0:18080/api/v1/me/add_friend\
?username=friend_username" \
-u "user":"password"
```

#### Query Parameters

- **username**

#### Security

- Basic Authentication
  - **username**
  - **password**

### **GET** - /api/v1/me/all-users-except-me

#### Description
Returns a list of all the users except yourself

#### CURL

```sh
curl -X GET "http://0.0.0.0:18080/api/v1/me/all-users-except-me" \
-u "anton":"12341234"
```

#### Security

- Basic Authentication
  - **username**
  - **password**

### **GET** - /api/v1/me/games

#### Description
Returns a list of all the games you are admin of or were invited into

#### CURL

```sh
curl -X GET "http://0.0.0.0:18080/api/v1/me/games" \
-u "anton":"12341234"
```

#### Security

- Basic Authentication
  - **username**
  - **password**

### **GET** - /api/v1/me/game/1

#### Description
Returns a json of a game in particular

#### CURL

```sh
curl -X GET "http://0.0.0.0:18080/api/v1/me/game/1" \
-u "anton":"12341234"
```

#### Path Parameters

- **RequestVariable**

#### Security

- Basic Authentication
  - **username**
  - **password**

### **GET** - /api/v1/me/game/1/repr

#### Description
Returns the string representation of the given game

#### CURL

```sh
curl -X GET "http://0.0.0.0:18080/api/v1/me/game/1/repr" \
-u "anton":"12341234"
```

#### Path Parameters

- **RequestVariable**

#### Security

- Basic Authentication
  - **username**
  - **password**

### **GET** - /api/v1/me/game/1/my_turn

#### Description
Returns whether it is your turn or not

#### CURL

```sh
curl -X GET "http://0.0.0.0:18080/api/v1/me/game/1/my_turn" \
-u "user":"password"
```

#### Path Parameters

- **RequestVariable**

#### Security

- Basic Authentication
  - **username**
  - **password**

### **GET** - /api/v1/me/game/1/move

#### Description
Perform move for given game (only if it is the turn of the user)

#### CURL

```sh
curl -X GET "http://0.0.0.0:18080/api/v1/me/game/1/move\
?move_value=M-%3EF" \
-u "user":"password"
```

#### Path Parameters

- **RequestVariable** 

#### Query Parameters

- **move_value** 

#### Security

- Basic Authentication
  - **username**
  - **password**

### **GET** - /api/v1/me/games/new

#### CURL

```sh
curl -X GET "http://0.0.0.0:18080/api/v1/me/games/new\
?participants=$participants" \
    -H "Content-Type: text/plain" \
    --data-raw "$body" \
-u "user":"password"
```

#### Query Parameters

- **participants** 
- 
#### Security

- Basic Authentication
  - **username**
  - **password**

## References

QuoridorAPI.paw.md
5 Ko

## SRD

![Visualization of the codebase](./diagram.svg)
![Visualization of the agenda](./Requirements/agenda.jpg)
![Visualization of the SRD](./Requirements/SystemRequirementsDocument/Quoridor_SRD/Quoridor_SRD-jpg/Quoridor_SRD-01.jpg)
![Visualization of the SRD](./Requirements/SystemRequirementsDocument/Quoridor_SRD/Quoridor_SRD-jpg/Quoridor_SRD-02.jpg)
![Visualization of the SRD](./Requirements/SystemRequirementsDocument/Quoridor_SRD/Quoridor_SRD-jpg/Quoridor_SRD-03.jpg)
![Visualization of the SRD](./Requirements/SystemRequirementsDocument/Quoridor_SRD/Quoridor_SRD-jpg/Quoridor_SRD-04.jpg)
![Visualization of the SRD](./Requirements/SystemRequirementsDocument/Quoridor_SRD/Quoridor_SRD-jpg/Quoridor_SRD-05.jpg)
![Visualization of the SRD](./Requirements/SystemRequirementsDocument/Quoridor_SRD/Quoridor_SRD-jpg/Quoridor_SRD-06.jpg)
![Visualization of the SRD](./Requirements/SystemRequirementsDocument/Quoridor_SRD/Quoridor_SRD-jpg/Quoridor_SRD-07.jpg)
![Visualization of the SRD](./Requirements/SystemRequirementsDocument/Quoridor_SRD/Quoridor_SRD-jpg/Quoridor_SRD-08.jpg)
![Visualization of the SRD](./Requirements/SystemRequirementsDocument/Quoridor_SRD/Quoridor_SRD-jpg/Quoridor_SRD-09.jpg)
![Visualization of the SRD](./Requirements/SystemRequirementsDocument/Quoridor_SRD/Quoridor_SRD-jpg/Quoridor_SRD-10.jpg)
![Visualization of the SRD](./Requirements/SystemRequirementsDocument/Quoridor_SRD/Quoridor_SRD-jpg/Quoridor_SRD-11.jpg)
![Visualization of the SRD](./Requirements/SystemRequirementsDocument/Quoridor_SRD/Quoridor_SRD-jpg/Quoridor_SRD-12.jpg)
![Visualization of the SRD](./Requirements/SystemRequirementsDocument/Quoridor_SRD/Quoridor_SRD-jpg/Quoridor_SRD-13.jpg)
![Visualization of the SRD](./Requirements/SystemRequirementsDocument/Quoridor_SRD/Quoridor_SRD-jpg/Quoridor_SRD-14.jpg)
![Visualization of the SRD](./Requirements/SystemRequirementsDocument/Quoridor_SRD/Quoridor_SRD-jpg/Quoridor_SRD-15.jpg)
![Visualization of the SRD](./Requirements/SystemRequirementsDocument/Quoridor_SRD/Quoridor_SRD-jpg/Quoridor_SRD-16.jpg)
![Visualization of the SRD](./Requirements/SystemRequirementsDocument/Quoridor_SRD/Quoridor_SRD-jpg/Quoridor_SRD-17.jpg)
![Visualization of the SRD](./Requirements/SystemRequirementsDocument/Quoridor_SRD/Quoridor_SRD-jpg/Quoridor_SRD-18.jpg)
![Visualization of the SRD](./Requirements/SystemRequirementsDocument/Quoridor_SRD/Quoridor_SRD-jpg/Quoridor_SRD-19.jpg)
![Visualization of the SRD](./Requirements/SystemRequirementsDocument/Quoridor_SRD/Quoridor_SRD-jpg/Quoridor_SRD-20.jpg)
![Visualization of the SRD](./Requirements/SystemRequirementsDocument/Quoridor_SRD/Quoridor_SRD-jpg/Quoridor_SRD-21.jpg)
![Visualization of the SRD](./Requirements/SystemRequirementsDocument/Quoridor_SRD/Quoridor_SRD-jpg/Quoridor_SRD-22.jpg)
![Visualization of the SRD](./Requirements/SystemRequirementsDocument/Quoridor_SRD/Quoridor_SRD-jpg/Quoridor_SRD-23.jpg)
![Visualization of the SRD](./Requirements/SystemRequirementsDocument/Quoridor_SRD/Quoridor_SRD-jpg/Quoridor_SRD-24.jpg)
![Visualization of the SRD](./Requirements/SystemRequirementsDocument/Quoridor_SRD/Quoridor_SRD-jpg/Quoridor_SRD-25.jpg)
