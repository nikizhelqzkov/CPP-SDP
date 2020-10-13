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

DLList<T> DLList<T>::operator+(const T &data)
{
    DLList<T> result(*this);
    result += data;
    return result;
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
        //save = nullptr; //save = nullptr;//taka raboti kato go pisha vmesto delete no ne mislq che trie taka naistina
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
void DLList<T>::setData(const T &data)
{
    DLList<T>::box *crr = new DLList<T>::box{data, nullptr, last};
    if (last == nullptr || first == nullptr)
    {
        first = last = crr;
        std::cout << last->data;
    }
    else
    {
        last->next = crr;
        last = crr;
    }
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
            bool is = false;
            while (!is)
            {
                if (current->data == y)
                {
                    is = true;
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
    return last;
}
template <class T>
typename DLList<T>::box *DLList<T>::getFirst() const
{
    return first;
}
template <class T>
void append(DLList<T> &l1, const DLList<T> &l2)
{
    if (l2.first == nullptr)
    {
        return;
    }
    typename DLList<T>::box *current = l2.first;
    l1.last->next = current;
    current->prev = l1.last;
    l1.last = l2.last;
}
template <class T>
DLList<T>& operator+=(DLList<T> &l1, const DLList<T> &l2)
{
    append(l1,l2);
    return l1;
}

#endif