#include <iostream>
#include "BaseMessage.h"

using namespace std;

#ifndef __MESSAGES__
    #define __MESSAGES__
    class SimpleMessage: public BaseMessage {
        private:
            string msg;

        public:
            SimpleMessage(string message_text): BaseMessage() {
                this->msg = message_text;
            }
    };

    class PostMessage: public SimpleMessage {
        private:
            string imgPath;

        public:
            PostMessage(string message_text, string image_path): SimpleMessage(message_text) {
                this->imgPath = image_path;
            }
    };

    class VoteMessage: public BaseMessage {
        private: 
            string voteTitle;
            string options[10];
            bool is_quiz;
        
        public:
            VoteMessage(string vote_title, string* options, bool is_quiz): BaseMessage() {
                this->voteTitle = vote_title;
                for (int i = 0; i < 10; i++) {
                    this->options[i] = options[i];
                }
                this->is_quiz = is_quiz;
            }
    };
#endif