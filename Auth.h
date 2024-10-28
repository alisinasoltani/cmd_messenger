#include <iostream>

using namespace std;

#ifndef __AUTH__
    #define __AUTH__
    class Auth {
    private:
        string username = "alisina";
        string password = "admin";

    public:
        bool is_authenticated(string username, string password);
    };
#endif