#include <iostream>
#include "terminal_colors.h"
#include "Auth.h"

bool Auth::is_authenticated(const std::string &username, const std::string &password) {
    if (username == "alisina") {
        if (password == "admin") {
            return true;
        }
    }
    return false;
}