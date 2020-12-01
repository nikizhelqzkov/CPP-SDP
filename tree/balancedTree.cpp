#include "balancedTree.h"
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <exception>
BalancedTree::BalancedTree() : root(nullptr)
{
}

bool BalancedTree::empty() const
{
    return !root;
}
bool BalancedTree::memberHelper(const int &data, const BalancedTree::Node *_root) const
{
    if (!_root)
    {
        return false;
    }
    if (data < root->data)
    {
        return memberHelper(data, _root->left);
    }
    else if (data > root->data)
    {
        return memberHelper(data, _root->right);
    }
    return true;
}
bool BalancedTree::member(const int &data) const
{
    return memberHelper(data, root);
}
void BalancedTree::addHelper(const int &data, BalancedTree::Node *&_root)
{
    if (!_root)
    {
        _root = new BalancedTree::Node{data};
    }
    else if (data < _root->data)
    {
        addHelper(data, _root->left);
    }
    else if (data > _root->data)
    {
        addHelper(data, _root->right);
    }
    _root->height = 1 + std::max(heightHelper(_root->left), heightHelper(_root->right));
    int bal = balance(_root);

    if (bal < -1 && data > _root->right->data)
    {
        leftRotate(_root);
    }
    else if (bal < -1 && data < _root->right->data)
    {
        rightRotate(_root->right);
        leftRotate(_root);
    }
    else if (bal > 1 && data > _root->left->data)
    {
        leftRotate(_root->left);
        rightRotate(_root);
    }
    else if (bal > 1 && data < _root->left->data)
    {
        rightRotate(_root);
    }
}
void BalancedTree::add(const int &data)
{
    addHelper(data, root);
}

int BalancedTree::balance(BalancedTree::Node *&_root) const
{
    return heightHelper(_root->left) - heightHelper(_root->right);
}
void BalancedTree::leftRotate(BalancedTree::Node *&_root)
{
    BalancedTree::Node *rightChild = _root->right;
    if (rightChild->left)
    {
        BalancedTree::Node *leftGrand = rightChild->left;
        _root->right = leftGrand;
    }
    rightChild->left = _root;
    _root = rightChild;
}
void BalancedTree::rightRotate(BalancedTree::Node *&_root)
{

    BalancedTree::Node *leftChild = _root->left;
    if (leftChild->right)
    {
        BalancedTree::Node *rightGrand = leftChild->right;
        _root->left = rightGrand;
    }

    leftChild->right = _root;
    _root = leftChild;
}
void BalancedTree::printHelper(BalancedTree::Node *_root) const
{
    if (!_root)
    {
        return;
    }
    printHelper(_root->left);
    std::cout << _root->data << " ";
    printHelper(_root->right);
}
void BalancedTree::printDotHelper(std::ostream &out, BalancedTree::Node *_root) const
{
    if (!_root)
    {
        return;
    }
    printDotHelper(out, _root->left);
    out << (long)_root << "[label=\"" << _root->data << "\"];\n";
    if (_root->left)
    {
        out << (long)_root << "->" << (long)_root->left << "[color=blue];\n";
    }
    if (_root->right)
    {
        out << (long)_root << "->" << (long)_root->right << "[color=red];\n";
    }
    printDotHelper(out, _root->right);
}
void BalancedTree::print() const
{
    printHelper(root);
}
void BalancedTree::printDot(std::ostream &out) const
{
    out << "digraph G{\n";
    printDotHelper(out, root);
    out << "}";
}

void BalancedTree::eraseHelper(const int &data, BalancedTree::Node *&_root)
{
    if (!_root)
    {
        return;
    }
    if (data < _root->data)
    {
        eraseHelper(data, _root->left);
    }
    else if (data > _root->data)
    {
        eraseHelper(data, _root->right);
    }
    else
    {
        if (!_root->left && !_root->right)
        {
            BalancedTree::Node *save = _root;
            _root = nullptr;
            delete save;
        }
        else if (!_root->left && _root->right)
        {
            BalancedTree::Node *save = _root;
            _root = _root->right;
            delete save;
        }
        else if (_root->left && !_root->right)
        {
            BalancedTree::Node *save = _root;
            _root = _root->left;
            delete save;
        }
        else
        {
            BalancedTree::Node *maxLeftSubBalancedTree = findMaxInLeftSubBalancedTree(_root->left);
            std::swap(_root->data, maxLeftSubBalancedTree->data);
            eraseHelper(data, _root->left);
        }
    }
}
BalancedTree::Node *BalancedTree::findMaxInLeftSubBalancedTree(BalancedTree::Node *_root)
{
    while (_root->right)
    {
        _root = _root->right;
    }
    return _root;
}
void BalancedTree::erase(const int &data)
{
    eraseHelper(data, root);
}
int BalancedTree::count() const
{
    return countFHelper(root, [](int el) -> bool { return true; });
}
int BalancedTree::countHelper(BalancedTree::Node *_root) const
{
    if (!_root)
    {
        return 0;
    }
    return 1 + countHelper(_root->left) + countHelper(_root->right);
}
int BalancedTree::countFHelper(BalancedTree::Node *_root, bool (*f)(int)) const
{
    if (!_root)
    {
        return 0;
    }
    if (f(_root->data))
    {
        return 1 + countFHelper(_root->left, f) + countFHelper(_root->right, f);
    }
    return countFHelper(_root->left, f) + countFHelper(_root->right, f);
}
int BalancedTree::countEvens() const
{
    return countFHelper(root, [](int el) -> bool { return el % 2 == 0; });
}
int BalancedTree::heightHelper(BalancedTree::Node *_root) const
{
    if (!_root)
    {
        return -1;
    }
    return 1 + std::max(heightHelper(_root->left), heightHelper(_root->right));
}
int BalancedTree::height() const
{
    return heightHelper(root);
}
int BalancedTree::countHelperLeaves(BalancedTree::Node *_root) const
{
    if (!_root)
    {
        return 0;
    }
    if (!_root->left && !_root->right && _root)
    {
        return 1;
    }
    return countHelperLeaves(_root->left) + countHelperLeaves(_root->right);
}
int BalancedTree::countLeaves() const
{
    return countHelperLeaves(root);
}

int BalancedTree::maxHelperLeave(BalancedTree::Node *_root) const
{

    if (!_root->left && !_root->right && _root)
    {
        return _root->data;
    }
    else if (!_root->right && root && _root->left)
    {
        return maxHelperLeave(_root->left);
    }
    else
    {
        return maxHelperLeave(_root->right);
    }
}
int BalancedTree::maxLeave() const
{
    if (empty())
    {
        throw std::out_of_range("Empty Balanced Tree");
        return INT_MIN;
    }
    return maxHelperLeave(root);
}
int &BalancedTree::theLeftestLeaf(BalancedTree::Node *current) const
{
    while (current->left || current->right)
    {
        if (!current->left && current->right)
        {
            current = current->right;
        }
        else
        {
            current = current->left;
        }
        if (!current->left && !current->right)
        {
            return current->data;
        }
    }
    return current->data;
}
int BalancedTree::maxLeaveNewHelper(BalancedTree::Node *current, int data)
{
    if (!current)
    {
        return data;
    }
    if (current && !current->left && !current->right)
    {
        data = std::max(data, current->data);
    }
    return std::max(maxLeaveNewHelper(current->left, data), maxLeaveNewHelper(current->right, data));
}
int BalancedTree::maxLeaveNew()
{
    int data = theLeftestLeaf(root);
    return maxLeaveNewHelper(root, data);
}
BalancedTree::Node *BalancedTree::locate(const char *s) const
{
    if (empty())
    {
        throw std::out_of_range("Empty Balanced Tree at the locate method -> 315 line");
    }

    if (s[0] == 0)
    {
        return root;
    }
    BalancedTree::Node *current = root;
    while (current && s[0] != 0)
    {
        if (s[0] != 'L' && s[0] != 'R')
        {
            throw std::invalid_argument("Error symbol at the locate method -> 327 line");
        }
        if (s[0] == 'L')
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
        ++s;
    }
    if (!current)
    {
        throw std::out_of_range("Error road in locate on 342 line");
    }
    return current;
}
int BalancedTree::operator[](const char *s) const
{
    return locate(s)->data;
}
void BalancedTree::set(int element, const char *s)
{
    locate(s)->data = element;
}
void BalancedTree::clearHelper(BalancedTree::Node *&current)
{
    if (!current)
    {
        return;
    }
    if (current && !current->left && !current->right)
    {
        //std::cout << "deleted " << current->data << std::endl;
        BalancedTree::Node *save = current;
        current = nullptr;
        delete save;
        return;
    }
    clearHelper(current->left);
    clearHelper(current->right);
    if (current && !current->left && !current->right)
    {
        // std::cout << "deleted " << current->data << std::endl;
        BalancedTree::Node *save = current;
        current = nullptr;
        delete save;
    }
}
void BalancedTree::clear()
{
    clearHelper(root);
}
BalancedTree::~BalancedTree()
{
    clear();
}

void BalancedTree::DFS(BalancedTree::Node *t) const
{
    std::stack<BalancedTree::Node *> stack;
    stack.push(t);

    while (!stack.empty())
    {
        BalancedTree::Node *curr = stack.top();
        stack.pop();

        std::cout << curr->data << " -> ";

        if (!curr->left && !curr->right)
        {
            continue;
        }

        stack.push(curr->left);
        stack.push(curr->right);
    }
}
void BalancedTree::BFS(BalancedTree::Node *root) const
{
    std::queue<BalancedTree::Node *> q;
    q.push(root);
    while (!q.empty())
    {
        BalancedTree::Node *cur = q.front();
        q.pop();
        std::cout << cur->data << " -> ";
        if (!cur->left && !cur->right)
        {
            continue;
        }

        q.push(cur->left);
        q.push(cur->right);
    }
}
