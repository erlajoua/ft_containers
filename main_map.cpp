/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <erlajoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:29:29 by erlajoua          #+#    #+#             */
/*   Updated: 2021/06/07 10:29:31 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Map.hpp"
#include "main.hpp"

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

void main_map(void)
{
    std::cout << "=== CONSTRUCTORS, SIZE, EMPTY, MAX_SIZE ===\n" << '\n';

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

    std::cout << "\n-> Max_size (first) = " << first.max_size() << '\n';
    std::cout << "-> Max_size (second) = " << second.max_size() << '\n';
    std::cout << "-> Max_size (third) = " << third.max_size() << '\n';
    std::cout << "-> Max_size (fourth) = " << fourth.max_size() << '\n';
    std::cout << "-> Max_size (fifth) = " << fifth.max_size() << '\n';

    print_map(first);

    //@begin, @end, @rbegin, @rend, @operator[]

    std::cout << "\n=== BEGIN, END, RBEGIN, REND, OPERATOR[] ===\n" << '\n';

    ft::Map<char,int> mymap;

    mymap['b'] = 200;
    mymap['a'] = 100;
    mymap['c'] = 300;

    std::cout << "map containts (normal) :\n";
    for (ft::Map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    std::cout << "map containts (reverse) :\n";
    for (ft::Map<char,int>::reverse_iterator it=mymap.rbegin(); it!=mymap.rend(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    //@erase, @clear

    std::cout << "\n=== ERASE, CLEAR ===\n" << '\n';

    print_map(mymap);
    std::cout << "* Erase *\n";
    mymap.erase('b');

    print_map(mymap);
    std::cout << "* Clear *\n";
    mymap.clear();
    print_map(mymap);
    std::cout << "-> Empty = " << mymap.empty() << '\n';
    std::cout << "-> Size = " << mymap.size() << '\n';

    //@lower_bound @upper_bound

    std::cout << "\n=== LOWER_BOUND, UPPER_BOUND ===\n" << '\n';

    ft::Map<char,int> mymap2;
    ft::Map<char,int>::iterator itlow,itup;

    mymap2['a']=20;
    mymap2['b']=40;
    mymap2['c']=60;
    mymap2['d']=80;
    mymap2['e']=100;

    itlow = mymap2.lower_bound ('b');  // itlow points to b
    itup = mymap2.upper_bound ('d');   // itup points to e (not d!)

    std::cout << "* Erase from low_bound('b') to upper_bound('d') *\n";
    mymap2.erase(itlow, itup);
    print_map(mymap2);

    //@count, @find

    std::cout << "\n=== COUNT ===\n" << '\n';

    ft::Map<char,int> mymap3;
    char c;

    mymap3 ['a'] = 101;
    mymap3 ['c'] = 202;
    mymap3 ['f'] = 303;

    print_map(mymap3);
    std::cout << "\n";
    for (c = 'a'; c < 'h'; c++)
    {
        std::cout << c;
        if (mymap3.count(c) > 0)
            std::cout << " is an element of mymap.\n";
        else 
            std::cout << " is not\n";
    }

    std::cout << "\n-> Find 'a' = " << mymap3.find('a')->second << '\n';
    std::cout << "-> Find 'c' = " << mymap3.find('c')->second << '\n';
    std::cout << "-> Find 'f' = " << mymap3.find('f')->second << '\n';
    std::cout << "-> Find 'x' (not in map) = " << mymap3.find('x')->second << '\n';

    //@insert

    std::cout << "\n=== INSERT ===\n" << '\n';

    ft::Map<char,int> mapinserted;

    mapinserted.insert(std::pair<char, int>('a',100));
    mapinserted.insert(std::pair<char, int>('z',200));

    std::pair<ft::Map<char,int>::iterator, bool> ret;

    ret = mapinserted.insert(std::pair<char, int>('z',500));
    if (ret.second == false)
    {
        std::cout << "element 'z' already existed";
        std::cout << " with a value of " << ret.first->second << '\n';
    }

    ft::Map<char,int>::iterator it = mapinserted.begin(); //(with hint position):
    mapinserted.insert (it, std::pair<char, int>('b', 300));
    mapinserted.insert (it, std::pair<char, int>('c', 400));

    ft::Map<char,int> anothermap;
    anothermap.insert(mapinserted.begin(), mapinserted.find('c')); //(range insertion):

    print_map(mapinserted);
    print_map(anothermap);

    //@keycomp, @value_comp

    std::cout << "\n=== KEY_COMP ===\n" << '\n';

    ft::Map<char, int> mymap4;
    ft::Map<char, int>::key_compare mycomp = mymap4.key_comp();

    mymap4['a']=100;
    mymap4['b']=300;
    mymap4['c']=200;

    std::cout << "mymap4 contains:\n";

    char highest = mymap4.rbegin()->first; //last element

    ft::Map<char, int>::iterator it4 = mymap4.begin();
    do
    {
        std::cout << it4->first << " => " << it4->second << '\n';
    } while (mycomp((*it4++).first, highest));

    //

    ft::Map<char, int> mymap5;

    mymap5['x']=1001;
    mymap5['y']=2002;
    mymap5['z']=3003;

    std::cout << "mymap5 contains:\n";

    std::pair<char, int> highest2 = *mymap5.rbegin();          // last element

    ft::Map<char, int>::iterator it5 = mymap5.begin();
    do
    {
        std::cout << it5->first << " => " << it5->second << '\n';
    } while (mymap5.value_comp()(*it5++, highest2) );

    std::cout << '\n';

    //@operator =

    std::cout << "\n=== OPERATOR '=' ===\n" << '\n';

    ft::Map<char, int> recup;

    recup = mymap5;
    print_map(recup);
    std::cout << "-> Size = " << mymap5.size() << '\n';

    //@equal_range

    std::cout << "\n=== EQUAL_RANGE ===\n" << '\n';

    ft::Map<char,int> mymap6;

    mymap6['a']=5;
    mymap6['b']=10;
    mymap6['c']=20;
    mymap6['d']=30;
    mymap6['e']=45;

    std::pair <ft::Map<char,int>::iterator, ft::Map<char,int>::iterator> ret6;
    ret6 = mymap6.equal_range('c');

    std::cout << "lower bound points to: ";
    std::cout << ret6.first->first << " => " << ret6.first->second << '\n';

    std::cout << "upper bound points to: ";
    std::cout << ret6.second->first << " => " << ret6.second->second << '\n';
}
