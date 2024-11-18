#include <iostream>
#include "BaseMessage.h"

#ifndef __MESSAGES__
    #define __MESSAGES__
    class SimpleMessage: public BaseMessage {
        private:
            std::string msg;

        public:
            SimpleMessage(int sender_id, std::string message_text): BaseMessage(sender_id) {
                this->msg = message_text;
            }

            std::string getMessage() {
                return this->msg;
            }

            void printMessage() override {
                std::cout << BOLDCYAN << this->getSenderId() << ": " << this->msg << RESET << std::endl;
                std::cout << CYAN << "sent at: " << this->getSentDate() << RESET << std::endl;
            }
    };

    class PostMessage: public SimpleMessage {
        private:
            std::string imgPath;

        public:
            PostMessage(int sender_id, std::string message_text, std::string image_path): SimpleMessage(sender_id, message_text) {
                this->imgPath = image_path;
            }

            std::string getImagePath() {
                return imgPath;
            }

            void printMessage() override {
                std::cout << BOLDCYAN << "image path: " << this->imgPath << RESET << std::endl;
                std::cout << BOLDCYAN << this->getSenderId() << ": " << this->getMessage() << RESET << std::endl;
                std::cout << CYAN << "sent at: " << this->getSentDate() << RESET << std::endl;
            }
    };

    class VoteMessage: public BaseMessage {
        private: 
            std::string voteTitle;
            std::string options[10];
            bool is_quiz;
        
        public:
            VoteMessage(int sender_id, std::string vote_title, std::string* options, bool is_quiz): BaseMessage(sender_id) {
                this->voteTitle = vote_title;
                for (int i = 0; i < 10; i++) {
                    this->options[i] = options[i];
                }
                this->is_quiz = is_quiz;
            }

            std::string getVoteTitle() {
                return this->voteTitle;
            }

            std::string* getVoteOptions() {
                return this->options;
            }

            bool isVoteQuiz() {
                return this->is_quiz;
            }

            void printMessage() override {
                if (this->is_quiz) {
                    std::cout << BOLDCYAN << "quiz title: " << this->voteTitle << RESET << std::endl;
                } else {
                    std::cout << BOLDCYAN << "vote title: " << this->voteTitle << RESET << std::endl;
                }
                for (int i = 0; i < 10; i++) {
                    std::cout << "option " << i+1 << ": " << BOLDWHITE << options[i] << RESET << std::endl;
                }
            }
    };
#endif