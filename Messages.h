#include <iostream>
#include "BaseMessage.h"

using namespace std;

#ifndef __MESSAGES__
    #define __MESSAGES__
    class SimpleMessage: public BaseMessage
    {
        private:
        string msg;
    };

    class PostMessage: public SimpleMessage
    {
        private:
        string imgPath;
    };

    class VoteMessage: public BaseMessage
    {
        private: 
        string voteTitle;
        string options[10];
    };
#endif