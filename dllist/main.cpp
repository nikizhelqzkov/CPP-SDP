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
    // std::cout << list2 << std::endl;
    // std::cout<<list.count(3)<<std::endl;
 
    //std::cout<<list.range(2,3)->data<<std::endl;
     list.append(list2);
     std::cout<<list<<std::endl;
    return 0;
    //std::cout << l << std::endl;
}