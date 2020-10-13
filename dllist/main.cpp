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
       
    list2 += 5;
    list2 += 77;
  //  res = list2;
    //std::cout << res.getBox()->data << std::endl;
    // std::cout<<list.count(3)<<std::endl;
   // std::cout << res << std::endl;
    //std::cout<<list.range(2,3)->data<<std::endl;
      list.append(list2);
    // std::cout << list << std::endl;
    //list+=list2;
     std::cout<<list<<std::endl;
    return 0;
    //std::cout << l << std::endl;
}