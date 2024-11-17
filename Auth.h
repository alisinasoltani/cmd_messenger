#include <iostream>

using namespace std;

#ifndef __AUTH__
    #define __AUTH__
    class Auth {
    private:
        string username = "alisina";
        string password = "admin";

    public:
        bool is_authenticated(const std::string &username, const std::string &password);
    };
#endif