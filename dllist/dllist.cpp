#ifndef __DLLIST_CPP
#define __DLLIST_CPP

#include "dllist.h"
#include <iostream>

template <class T>
DLList<T>::DLList() : first(nullptr)
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
void DLList<T>::clear()
{
    DLList<T>::box *crr = first, *save;
    while (crr != nullptr)
    {
        save = crr;
        crr = crr->next;
        delete save;
    }
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
DLList<T> DLList<T>::operator+(const T &x) const
{
    DLList<T> result(*this);
    result += x;
    return result;
}
template <class T>
DLList<T> &DLList<T>::operator+=(const T &x)
{
    first = new DLList<T>::box{x, first, nullptr};

    if (first->next != nullptr)
    {
        first->next->prev = first;
    }

    return *this;
}

template <class T>
std::ostream &operator<<(std::ostream &out, const DLList<T> &list)
{
    typename DLList<T>::box *crr = list.first;

    while (crr != nullptr)
    {
        out << crr->data << " ";
        crr = crr->next;
    }

    return out;
}
template <class T>
void DLList<T>::copy(const DLList<T> &other)
{
    typename DLList<T>::box *newBox = new DLList<T>::box,
                            *current,
                            *lastCreated;

    if (other.first == nullptr)
    {
        first = nullptr;
    }
    else
    {
        current = other.first;
        first = new DLList<T>::box{current->data, nullptr, nullptr};
        lastCreated = first;
        current = current->next;

        while (current != nullptr)
        {
            newBox = new DLList<T>::box{current->data, nullptr, lastCreated};
            lastCreated->next = newBox;

            current = current->next;
            lastCreated = newBox;
        }
    }
}
#endif