#include <iostream>
#include <string.h>
#include "User.h"

int User::userCount = 1;

User::User (const std::string &username, const std::string &password) {
    this->username = username;
    try {
        std::hash<std::string> hash_function;
        this->password = hash_function(password);
    } catch(const std::exception& e) {
        std::cout << "something happend while hashing the password!" << std::endl;
        std::cerr << e.what() << std::endl;
        return;
    }
    this->userId = this->userCount;
    this->userCount += 1;
}

User::User (const User &user) {
    this->username = user.username;
    this->password = user.password;
    this->userId = user.userId;
}

User::~User() {
    this->userCount -= 1;
}

bool User::isUsernameValid(const std::string &username) const {
    return this->username == username ? true : false;
}

bool User::isPasswordValid(const std::string &password) const {
    std:size_t hashed_password;
    try {
        std::hash<std::string> hashFunction;
        hashed_password = hashFunction(password);
    } catch(const std::exception& e) {
        std::cout << "something happend while hashing the password!" << std::endl;
        std::cerr << e.what() << std::endl;
        return false;
    }
    return this->password == hashed_password ? true : false;
}

int User::getUserId(const std::string &username, const std::string &password) const {
    return this->userId;
}

int User::getUserCount(const std::string &username, const std::string &password) const {
    return this->userCount;
}

std::string User::getUsername() const {
    return this->username;
}