#include <iostream>
#include "dllist.h"



int main()
{
    DLList<int> list;

    list += 1;
    list += 2;
    list += 3;
    DLList<int> list2;
    list2=list;
    std::cout << list2 << std::endl;
}