#include <iostream>
#include "terminal_colors.h"
#include "Auth.h"

using namespace std;

bool Auth::is_authenticated(string username, string password) {
    if (username == "alisina") {
        if (password == "admin") {
            return true;
        }
    }
    return false;
}