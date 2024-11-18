#include <iostream>
#include "terminal_colors.h"
#include "Auth.h"

Auth::Auth() {
    this->users = new User[3] {
        User("Alisina", "admin"),
        User("Alisina2", "admin2"),
        User("Alisina3", "admin3"),
    };
}

Auth::~Auth() {
    delete[] this->users;
}

int Auth::is_authenticated(const std::string &username, const std::string &password) {
    for (int i = 0; i < 3; i++) {
        if (this->users[i].isUsernameValid(username) && this->users[i].isPasswordValid(password)) {
            std::cout << "found the user!" << std::endl;
            return this->users[i].getUserId(username, password);
        }
    }
    std::cout << "not found the user!" << std::endl;
    return 0;
}