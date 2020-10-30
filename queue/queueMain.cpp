#include "queueWithStack.h"
//g++ queueMain.cpp queueWithStack.cpp
int main()
{
    QueueWithStack q1;
    q1.pushBack(1);
    q1.pushBack(2);
    q1.pushBack(3);
    q1.pushBack(4);
    q1.pushBack(5);
    std::cout << q1 << std::endl;
}