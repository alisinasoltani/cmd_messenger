#include <iostream>
#include "BaseMessage.h"

using namespace std;

#ifndef __MESSAGES__
    #define __MESSAGES__
    class SimpleMessage: public BaseMessage {
        private:
            string msg;

        public:
            SimpleMessage(int sender_id, string message_text): BaseMessage(sender_id) {
                this->msg = message_text;
            }
    };

    class PostMessage: public SimpleMessage {
        private:
            string imgPath;

        public:
            PostMessage(int sender_id, string message_text, string image_path): SimpleMessage(sender_id, message_text) {
                this->imgPath = image_path;
            }
    };

    class VoteMessage: public BaseMessage {
        private: 
            string voteTitle;
            string options[10];
            bool is_quiz;
        
        public:
            VoteMessage(int sender_id, string vote_title, string* options, bool is_quiz): BaseMessage(sender_id) {
                this->voteTitle = vote_title;
                for (int i = 0; i < 10; i++) {
                    this->options[i] = options[i];
                }
                this->is_quiz = is_quiz;
            }
    };
#endif