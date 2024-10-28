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
            BaseMessage() {
                auto now = std::chrono::system_clock::now();
                sentDate = std::chrono::system_clock::to_time_t(now);
                std::cout << "sent at: " << std::ctime(&sentDate);
            }
    };
#endif