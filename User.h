#include <iostream>
#include <string.h>

#ifndef __USER__
    #define __USER__
    class User {
        private:
            static int userCount;
            int userId;
            std::string username;
            std::size_t password;
        public:
            User (const std::string &username, const std::string &password);
            User (const User &user);
            ~User();

            bool isUsernameValid(const std::string &username) const;
            bool isPasswordValid(const std::string &password) const;
            int getUserId(const std::string &username, const std::string &password) const;
            int getUserCount(const std::string &username, const std::string &password) const;
            std::string getUsername() const;
    };
#endif