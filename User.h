#include <iostream>
#include <string.h>

#ifndef __USER__
    #define __USER__
    class User {
        private:
            static int userId;
            std::string username;
            std::size_t password;
        public:
            User (const std::string &username, const std::string password);
            User (const User &user);
            ~User();

            bool isUsernameValid(const std::string &username);
            bool isPasswordValid(const std::string &username);
            int getUserId(const std::string &username, const std::string &password);
    };
#endif