#include <chrono>
#include <iostream>

#ifndef __BASE_MESSAGE__
    #define __BASE_MESSAGE__
    class BaseMessage
    {
        private:
            std::time_t sentDate;
            int senderId;

        public:
            BaseMessage(int sender_id) {
                this->senderId = sender_id;
                auto now = std::chrono::system_clock::now();
                sentDate = std::chrono::system_clock::to_time_t(now);
                std::cout << "sent at: " << std::ctime(&sentDate);
            }

            int getSenderId() const {
                return this->senderId;
            }

            std::string getSentDate() const {
                return std::ctime(&sentDate);
            }

            virtual void printMessage() const {}
    };
#endif