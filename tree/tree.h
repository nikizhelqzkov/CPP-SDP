#ifndef _TREE_INCL
#define _TREE_INCL
#include <iostream>
class Tree
{
private:
    struct Node
    {
        int data;
        Node *left;
        Node *right;

        Node(const int& _data, Node *_left = nullptr, Node *_right = nullptr) : data(_data), left(_left), right(_right) {}
    };
    Node *root;
    void addHelper(const int&, Node*&);
    bool memberHelper(const int&, const Node*)const;
    void printHelper(Node*)const;
    void printDotHelper(std::ostream& , Node*)const;
    void eraseHelper(const int&,Node*&);
    Node* findMaxInLeftSubtree(Node*);
    int countHelper(Node*)const;
    int countFHelper(Node*, bool(*f)(int))const;
    int heightHelper(Node*)const;

public:
    Tree();
    void add(const int& data);
    bool member(const int&)const;
    bool empty()const;
    void print()const;
    void printDot(std::ostream&)const;
    void erase(const int&);
    int count()const;
    int countEvens()const;
    int height()const;
    ~Tree();
};

#endif