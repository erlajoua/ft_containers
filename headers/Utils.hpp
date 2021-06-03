#ifndef UTILS_HPP
# define UTILS_HPP

namespace ft
{
    template <class T>
    void swap(T &a, T &b)
    {
        T tmp;

        tmp = a;
        a = b;
        b = tmp;
    }

    template <class T>
    struct Node
    {
        T data;
        Node *prev;
        Node *next;
    };
}

#endif