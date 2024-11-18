#include <iostream>
#include "User.h"

#ifndef __AUTH__
    #define __AUTH__
    class Auth {
        private:
            User *users;
        public:
            Auth();
            ~Auth();
            int is_authenticated(const std::string &username, const std::string &password);
    };
#endif