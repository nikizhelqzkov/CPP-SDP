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
    else if (data > root->data)
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
    } if (_root->right)
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
