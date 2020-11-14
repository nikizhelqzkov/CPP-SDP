#include "tree.h"
#include <fstream>
//#include <iostream>
//g++ main.cpp tree.cpp
//myTree.dot -Tpdf -o test.pdf
int main()
{
    //std::cout<<'a';
    Tree t;
    t.add(5);
    t.add(6);
    t.add(2);
    t.add(3);
    t.add(7);
    t.add(9);
    t.add(12);
    t.print();
    std::ofstream output("myTree.dot");
    t.printDot(output);
    return 0;
}