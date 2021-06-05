#include <iostream>
#include "headers/Map.hpp"

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp
{
  bool operator() (const char& lhs, const char& rhs) const
  {
      return lhs<rhs;
    }
};

template <typename T, typename U>
void print_map(ft::Map<T, U> &map)
{
    std::cout << "The map contains : \n\n";
    for (typename ft::Map<T,U>::iterator it = map.begin(); it != map.end(); it++)
        std::cout << it->first << " => " << it->second << "\n";
}

int main(void)
{
    std::cout << "=== CONSTRUCTORS, SIZE, EMPTY, MAX_SIZE ===" << '\n';

    ft::Map<char,int> first;

    first['a']=10;
    first['b']=30;
    first['c']=50;
    first['d']=70;

    ft::Map<char,int> second (first.begin(),first.end());

    ft::Map<char,int> third (second);

    ft::Map<char,int,classcomp> fourth;

    bool(*fn_pt)(char,char) = fncomp;
    ft::Map<char,int,bool(*)(char,char)> fifth (fn_pt);

    std::cout << "-> Size (first) = " << first.size() << '\n';
    std::cout << "-> Size (second) = " << second.size() << '\n';
    std::cout << "-> Size (third) = " << third.size() << '\n';
    std::cout << "-> Size (fourth) = " << fourth.size() << '\n';
    std::cout << "-> Size (fifth) = " << fifth.size() << '\n';

    print_map(first);

    return 0;
}