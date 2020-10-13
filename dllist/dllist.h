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
    DLList<T> &pushInFront(const T &);
    DLList<T> operator+(const T &);

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

public:
    box *range(int, int);
    int count(int);
    T getData() const;
    box *getFirst() const;
    box *getBox() const;
    void setData(const T &);
    
    //DLList<T> &operator+=(const DLList<T> &);
    template <class E>
    friend void append(DLList<E> &, const DLList<E> &);
    template <class F>
    friend DLList<F>& operator+=(DLList<F> &, const DLList<F> &);
    
};

#include "dllist.cpp"

#endif