#include "tree.h"
#include <fstream>
//#include <iostream>
//g++ main.cpp tree.cpp
//dot myTree.dot -Tpdf -o tree.pdf

int main()
{
    //std::cout<<'a';
    Tree t;
    t.add(5);
    t.add(6);
    t.add(2);
    t.add(3);
    t.add(7);
    t.add(-2);
    t.add(1);
    t.add(-1);
    t.add(-5);
    t.add(4);
    t.add(9);
    t.add(12);
    t.add(9);
    t.add(8);
    t.add(10);
    t.add(111);
    t.add(15);
    t.add(6);
    t.add(5);
    t.add(7);
    //  t.erase(7);
    t.print();
    std::ofstream output("myTree.dot");
    t.printDot(output);
    return 0;
}