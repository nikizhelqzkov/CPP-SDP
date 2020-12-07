#ifndef _BalancedTree_INCL
#define _BalancedTree_INCL
#include <iostream>
#include <stack>
class BalancedTree
{
private:
    struct Node
    {
        int data;
        Node *left;
        Node *right;
        int height;
        Node(const int &_data, Node *_left = nullptr, Node *_right = nullptr, int _height = -1) : data(_data), left(_left), right(_right), height(_height) {}
    };
    struct Wrapper
    {
        Node *node;
        bool toProduce;
    };
    Node *root;
    void addHelper(const int &, Node *&);
    bool memberHelper(const int &, const Node *) const;
    void printHelper(Node *) const;
    void printDotHelper(std::ostream &, Node *) const;
    void eraseHelper(const int &, Node *&);
    Node *findMaxInLeftSubBalancedTree(Node *);
    int countHelper(Node *) const;
    int countFHelper(Node *, bool (*f)(int)) const;
    int heightHelper(Node *) const;
    int countHelperLeaves(Node *) const;
    int maxHelperLeave(Node *) const;
    int maxLeaveNewHelper(Node *, int);
    int &theLeftestLeaf(Node *) const;
    Node *locate(const char *) const;
    void clear();
    void clearHelper(Node *&);
    void leftRotate(Node *&);
    void rightRotate(Node *&);
    void dfsHelper(Node *) const;
    void DFSrlr(Node *) const;
    void BFSHelper(Node *) const;

public:
    BalancedTree();
    void add(const int &data);
    int balance(Node *&) const;
    bool member(const int &) const;
    bool empty() const;
    void print() const;
    void printDot(std::ostream &) const;
    void erase(const int &);
    int count() const;
    int countEvens() const;
    int height() const;
    int countLeaves() const;
    int maxLeave() const;
    int maxLeaveNew();
    int operator[](const char *) const;
    void set(int, const char *);

    void bfs() const;
    void dfs() const;
    ~BalancedTree();

    class Iterator
    {
        std::stack<BalancedTree::Wrapper> elements;
        void unwind();

    public:
        Iterator(BalancedTree::Node *root);
        bool operator!=(const Iterator &other);
        Iterator &operator++();
        int operator*() const;
    };
    Iterator begin();
    Iterator end();
};

#endif