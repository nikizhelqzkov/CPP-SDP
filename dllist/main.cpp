#include <iostream>
#include "dllist.h"

int main()
{
    DLList<int> list;

    list += 1;
    list += 2;
    list += 3;
    list.pushInFront(2);
    DLList<int> list2;
    list2 = list;
    std::cout << list2 << std::endl;
    std::cout<<list.count(3)<<std::endl;
 
    std::cout<<list.range(1,2)->data;
    return 0;
    //std::cout << l << std::endl;
}