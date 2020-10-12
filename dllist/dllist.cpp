#ifndef __DLLIST_CPP
#define __DLLIST_CPP

#include "dllist.h"

template <class T>
DLList<T>::DLList() : first(nullptr), last(nullptr)
{
}
template <class T>
DLList<T>::DLList(const DLList<T> &other)
{
    copy(other);
}
template <class T>
DLList<T>::~DLList()
{
    clear();
}
template <class T>
DLList<T> &DLList<T>::operator=(const DLList<T> &other)
{
    if (this != &other)
    {
        clear();
        copy(other);
    }
    return *this;
}

template <class T>
DLList<T> &DLList<T>::operator+=(const T &data)
{
    if (first != nullptr && last != nullptr)
    {
        last = new DLList<T>::box{data, nullptr, last};
        if (last->prev != nullptr)
        {
            last->prev->next = last;
        }
    }
    else
    {
        first = last = new DLList<T>::box{data, nullptr, nullptr};
    }
    return *this;
}
template <class T>

DLList<T> DLList<T>::operator+(const T &data) const
{
    DLList<T> result(*this);
    result += data;
    return result;
}
template <class T>
void DLList<T>::clear()
{
    DLList<T>::box *cur = first, *save;
    while (cur != nullptr)
    {
        save = cur;
        cur = cur->next;
        std::cout << " deleted : ";
        delete save;
    }
    last = nullptr;
}
template <class T>
void DLList<T>::copy(const DLList<T> &other)
{
    typename DLList<T>::box *newBox, *current;
    clear();
    if (other.first == nullptr)
    {
        return;
    }
    current = other.first;
    first = new DLList<T>::box{current->data, nullptr, nullptr};
    last = first;
    current = current->next;
    while (current != nullptr)
    {
        newBox = new DLList<T>::box{current->data, nullptr, last};
        last->next = newBox;
        current = current->next;
        last = newBox;
    }
}
template <class T>
std::ostream &operator<<(std::ostream &out, const DLList<T> &list)
{
    typename DLList<T>::box *current = list.first;
    while (current != nullptr)
    {
        out << current->data << " ";
        current = current->next;
    }
    return out;
}
template <class T>
DLList<T> &DLList<T>::pushInFront(const T &data)
{
    if (first != nullptr && last != nullptr)
    {
        first = new DLList<T>::box{data, first, nullptr};
        if (first->next != nullptr)
        {
            first->next->prev = first;
        }
    }
    else
    {
        first = last = new DLList<T>::box{data, nullptr, nullptr};
    }
    return *this;
}
template <class T>
int DLList<T>::count(int x)
{
    if (first == nullptr)
    {
        return 0;
    }

    DLList<T>::box *current = first;
    int counter = 0;
    //this += pushInfirst(current->data);
    while (current != nullptr)
    {
        if (current->data == x)
        {
            counter++;
        }
        current = current->next;
    }
    return counter;
}
template <class T>
typename DLList<T>::box *DLList<T>::range(int x, int y)
{
    typename DLList<T>::box *current = first;
    if ((x > y) || count(x) == 0 || count(y) == 0)
    {
        std::cout << "Something is wrong!!!\n";
        return first;
    }
    while (current != nullptr)
    {
        if (current->data == x)
        {
            first = current;
            while (current->data != y)
            {
                if (current->data == y)
                {
                    last = current;
                    return first;
                }
                current = current->next;
            }
        }
        else
        {
            current = current->next;
        }
    }
}
template <class T>
T DLList<T>::getData() const
{
    return first->data;
}
template <class T>
typename DLList<T>::box *DLList<T>::getBox() const
{
    return first;
}
#endif