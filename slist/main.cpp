#include "slist.h"
bool comp(const int &a, const int &b)
{
    return a <= b;
}
int main()
{
    slist s1(comp);
    s1.pushSorted(55);
    s1.pushSorted(23);
    s1.pushSorted(78);
    s1.pushSorted(5);
    s1.pushSorted(96);
    s1.pushSorted(55);
    std::cout<<s1;
}
