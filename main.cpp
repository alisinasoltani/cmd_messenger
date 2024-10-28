#include <iostream>
#include "terminal_colors.h"
#include "BaseMessage.h"
#include "Messages.h"
#include <string.h>
#include "Auth.h"
#include <cstdlib>

using namespace std;

int main() {
    Auth auth;
    string username, password, message_text, image_path;
    int id = 123;
    int total_messages = 0;
    BaseMessage* allMessages[100];
    int option;

    while (1) {
        system("cls");
        cout << MAGENTA << "Username: " << RESET;
        cin >> username;
        cout << MAGENTA << "Password: " << RESET;
        cin >> password;
        if (auth.is_authenticated(username, password)) {
            cout << BOLDCYAN << "Welcome!" << RESET << endl;
            while (1) {
                cout << "Options: " << endl;
                cout << "1. Simple Message.\n2. Post\n3. Vote\n4. Qiz\n5. Show Chats" << endl;
                cin >> option;
                switch (option) {
                    case 1:
                    {
                        cout << BLUE << "Send a Simple Message!" << RESET << endl;
                        cout << ">: ";
                        cin >> message_text;
                        SimpleMessage simple_message(id, message_text);
                        cout << endl;
                        allMessages[total_messages] = &simple_message;
                        total_messages++;
                        break;
                    }
                    case 2:
                    {
                        cout << BLUE << "Post a Message!" << RESET << endl;
                        cout << ">: ";
                        cin >> message_text;
                        cout << "path to picture >: ";
                        cin >> message_text;
                        PostMessage post(id, message_text, image_path);
                        allMessages[total_messages] = &post;
                        total_messages++;
                        break;
                    }
                    case 3:
                    {
                        string title;
                        string options[10], option_input;
                        cout << BLUE << "Create a Vote!" << RESET << endl;
                        cout << "Enter Vote Title: ";
                        cin >> title;
                        cout << endl;
                        for (int i = 0; i < 10; i++) {
                            cout << "Enter Option " << i << endl;
                            cin >> option_input;
                            options[i] = option_input;
                        }
                        VoteMessage vote(id, title, options, false);
                        allMessages[total_messages] = &vote;
                        total_messages++;
                        break;
                    }
                    case 4:
                    {
                        string title;
                        string options[10], option_input;
                        cout << BLUE << "Create a Quiz!" << RESET << endl;
                        cout << "Enter Vote Title: ";
                        cin >> title;
                        cout << endl;
                        for (int i = 0; i < 10; i++) {
                            cout << "Enter Option " << i << endl;
                            cin >> option_input;
                            options[i] = option_input;
                        }
                        VoteMessage quiz(id, title, options, true);
                        allMessages[total_messages] = &quiz;
                        total_messages++;
                        break;
                    }
                    case 5:
                    {
                        cout << BLUE << "Show All Chats." << RESET << endl;
                        for (int i = 0; i < total_messages; i++) {
                            cout << i << ":> ";
                            cout << allMessages[i]->getSenderId() << "\t";
                            cout << allMessages[i]->getSentDate() << endl;
                        }
                        break;
                    }
                    default:
                        cout << RED << "Wrong Message! Try Again." << RESET << endl;
                        break;
                }
            }
            
        }
    }
    return 0;
}