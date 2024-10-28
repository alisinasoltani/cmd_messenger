#include <iostream>
#include "terminal_colors.h"
#include "BaseMessage.h"
#include "Messages.h"
#include <string.h>
#include "Auth.h"

using namespace std;

int main() {
    Auth auth;
    string username, password;
    BaseMessage* allMessages[100];
    int option;

    while (1) {
        cout << MAGENTA << "Username: " << RESET;
        cin >> username;
        cout << endl;
        cout << MAGENTA << "Password: " << RESET << endl;
        cin >> password;
        if (auth.is_authenticated(username, password)) {
            cout << BOLDCYAN << "Welcome!" << RESET;
            while (1) {
                cout << "Options: " << endl;
                cout << "1. Simple Message.\n2. Post\n3. Vote\n4. Qiz\n5. Show Chats" << endl;
                cin >> option;
                switch (option) {
                    case 1:
                        cout << BLUE << "Send a Simple Message!" << RESET << endl;
                        
                        break;
                    case 2:
                        cout << BLUE << "Post a Message!" << RESET << endl;
                        break;
                    case 3:
                        cout << BLUE << "Create a Vote!" << RESET << endl;
                        break;
                    case 4:
                        cout << BLUE << "Create a Quiz!" << RESET << endl;
                        break;
                    case 5:
                        cout << BLUE << "Show All Chats." << RESET << endl;
                        break;
                    default:
                        cout << RED << "Wrong Message! Try Again." << RESET << endl;
                        break;
                }
            }
            
        }
    }
    return 0;
}