#ifndef __DLLIST_H
#define __DLLIST_H

#include <iostream>

template <class T>
class DLList
{
public:
    DLList();
    DLList(const DLList<T> &);
    ~DLList();
    DLList<T> &operator=(const DLList<T> &);
    DLList<T> &operator+=(const T &);
    DLList<T> &operator+=(const DLList<T> &);
    DLList<T> &pushInFront(const T &);
    DLList<T> operator+(const T &);
    DLList<T>& reverse();

    int count(int);
    T getData() const;

    void setData(const T &);
    void append(const DLList<T> &);

private:
    struct box
    {
        T data;
        box *next, *prev;
    };
    box *first, *last;
    template <class E>
    friend std::ostream &operator<<(std::ostream &, const DLList<E> &);

    void copy(const DLList<T> &);
    void clear();
    int size() const;

public:
    box *getFirst() const;
    box *getBox() const;
    box *range(int, int);
};

#include "dllist.cpp"

#endif