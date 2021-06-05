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
    
    template <class Key, class T>
	struct BNode
	{
		std::pair<Key, T> pair;
		BNode *left;
		BNode *right;
		BNode *parent;
		bool end;
	};
}

#endif