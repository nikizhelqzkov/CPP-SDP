#include "tree.h"

Tree::Tree() : root(nullptr)
{
}

Tree::~Tree()
{
}
bool Tree::empty() const
{
    return !root;
}
bool Tree::memberHelper(const int &data, const Tree::Node *_root) const
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
bool Tree::member(const int &data) const
{
    return memberHelper(data, root);
}
void Tree::addHelper(const int &data, Tree::Node *&_root)
{
    if (!_root)
    {
        _root = new Tree::Node{data};
        return;
    }
    if (data < _root->data)
    {
        addHelper(data, _root->left);
    }
    else if (data > _root->data)
    {
        addHelper(data, _root->right);
    }
}
void Tree::add(const int &data)
{
    addHelper(data, root);
}
void Tree::printHelper(Tree::Node *_root) const
{
    if (!_root)
    {
        return;
    }
    printHelper(_root->left);
    std::cout << _root->data << " ";
    printHelper(_root->right);
}
void Tree::printDotHelper(std::ostream &out, Tree::Node *_root) const
{
    if (!_root)
    {
        return;
    }
    printDotHelper(out, _root->left);
    out << (long)_root << "[label=\"" << _root->data << "\"];\n";
    if (_root->left)
    {
        out << (long)_root << "->" << (long)_root->left << std::endl;
    }
    if (_root->right)
    {
        out << (long)_root << "->" << (long)_root->right << std::endl;
    }
    printDotHelper(out, _root->right);
}
void Tree::print() const
{
    printHelper(root);
}
void Tree::printDot(std::ostream &out) const
{
    out << "digraph G{\n";

    printDotHelper(out, root);
    out << "}";
}

void Tree::eraseHelper(const int &data, Tree::Node *&_root)
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
            Tree::Node *save = _root;
            _root = nullptr;
            delete save;
        }
        else if (!_root->left && _root->right)
        {
            Tree::Node *save = _root;
            _root = _root->right;
            delete save;
        }
        else if (_root->left && !_root->right)
        {
            Tree::Node *save = _root;
            _root = _root->left;
            delete save;
        }
        else
        {
            Tree::Node *maxLeftSubTree = findMaxInLeftSubtree(_root->left);
            std::swap(_root->data, maxLeftSubTree->data);
            eraseHelper(data, _root->left);
        }
    }
}
Tree::Node *Tree::findMaxInLeftSubtree(Tree::Node *_root)
{
    while (_root->right)
    {
        _root = _root->right;
    }
    return _root;
}
void Tree::erase(const int &data)
{
    eraseHelper(data, root);
}
int Tree::count() const
{
    return countHelper(root);
}
int Tree::countHelper(Tree::Node *_root) const
{
    if (!_root)
    {
        return 0;
    }
    return 1 + countHelper(_root->left) + countHelper(_root->right);
}
int Tree::countFHelper(Tree::Node *_root, bool (*f)(int)) const
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
int Tree::countEvens() const
{
    return countFHelper(root, [](int el) -> bool { return el % 2 == 0; });
}
