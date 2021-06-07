/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_list.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <erlajoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:29:28 by erlajoua          #+#    #+#             */
/*   Updated: 2021/06/07 10:29:28 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/List.hpp"
#include <iostream>
#include <vector>

template <typename T>
void print_list(ft::List<T> &a)
{
    std::cout << "List contains :";
    for (typename ft::List<T>::iterator it = a.begin(); it != a.end(); it++)
        std::cout << " " << *it;
    std::cout << '\n';
}

bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

bool inferior_equal_to_two (const int& value) { return (value<=2); }

bool mycomparison (double first, double second)
{ return ( first < second ); }

//

void main_list(void)
{
    //@constructors, @size, @empty, @max_size

    std::cout << "=== CONSTRUCTORS, SIZE, EMPTY, MAX_SIZE ===" << '\n';

    //empty
    ft::List<int> a;
    std::cout << "-> Size = " << a.size() << '\n';
    std::cout << "-> Empty = " << a.empty() << '\n';
    std::cout << "-> Max_size = " << a.max_size() << '\n';
    print_list(a);

    //values
    ft::List<int> b(7, 42);
    std::cout << "\n-> Size = " << b.size() << '\n';
    std::cout << "-> Empty = " << b.empty() << '\n';
    std::cout << "-> Max_size = " << b.max_size() << '\n';
    print_list(b);

    //first last iterators
    ft::List<int> c(b.begin(), b.end());
    std::cout << "\n-> Size = " << c.size() << '\n';
    std::cout << "-> Empty = " << c.empty() << '\n';
    std::cout << "-> Max_size = " << c.max_size() << '\n';
    print_list(c);

    //copy
    ft::List<int> d(c);
    std::cout << "\n-> Size = " << d.size() << '\n';
    std::cout << "-> Empty = " << d.empty() << '\n';
    std::cout << "-> Max_size = " << d.max_size() << '\n';
    print_list(d);
    
    //@assign

    std::cout << "\n=== ASSIGN ===" << '\n';

    a.assign(12, 100);
    print_list(a);
    std::cout << "-> Size = " << a.size() << '\n';

    b.assign(a.begin(), a.begin() + 2);
    print_list(b);
    std::cout << "-> Size = " << b.size() << '\n';

    //@back, @front, @push_back, @pop_back, @push_front, @pop_front

    std::cout << "\n=== BACK, FRONT, PUSH_BACK, POP_BACK , PUSH_FRONT, POP_FRONT  ===" << '\n';

    ft::List<char> e;

    e.push_back('x');
    e.push_back('$');
    e.push_back('k');
    e.push_back('r');
    e.push_back('a');
    e.push_back('T');
    std::cout << "\n-> Front = " << e.front() << '\n';
    std::cout << "-> Back = " << e.back() << '\n';
    print_list(e);

    std::cout << "\n * pop_back X3 *\n";
    e.pop_back();
    e.pop_back();
    e.pop_back();
    std::cout << "\n-> Front = " << e.front() << '\n';
    std::cout << "-> Back = " << e.back() << '\n';
    print_list(e);

    std::cout << "\n* push_front (U S N U : :) *\n";
    std::cout << "* pop_front X2 *\n";

    e.push_front('U');
    e.push_front('S');
    e.push_front('N');
    e.push_front('U');
    e.push_front(':');
    e.push_front(':');
    e.pop_front();
    e.pop_front();
    print_list(e);

    //@begin, @end, @rbegin, @rend

    std::cout << "\n=== BEGIN, END, RBEGIN, REND ===\n\n";

    std::cout << "List contains (normal) :";
    for (ft::List<char>::iterator it = e.begin(); it != e.end(); it++)
        std::cout << " " << *it;
    std::cout << '\n';

    std::cout << "List contains (reverse) :";
    for (ft::List<char>::reverse_iterator it = e.rbegin(); it != e.rend(); it++)
        std::cout << " " << *it;
    std::cout << '\n';

    //@erase, @resize, @clear
    
    std::cout << "\n=== ERASE, RESIZE, CLEAR ===\n\n";

    print_list(b);
    std::cout << "* Resize (15) ! *\n";
    b.resize(15);
    print_list(b);
    std::cout << "* Erase (begin+1, end) ! *\n";
    b.erase(b.begin() + 1, b.end());
    print_list(b);
    std::cout << "* Clear ! *\n";
    b.clear();
    print_list(b);

    //@insert

    std::cout << "\n=== INSERT ===\n\n";

    ft::List<int> mylist;
    ft::List<int>::iterator it;

    for (int i = 1; i <= 5; ++i)
        mylist.push_back(i);

    it = mylist.begin();

    mylist.insert(it,10);
    mylist.insert(it,2,20);

    --it;
    std::vector<int> myvector (2,30);
    mylist.insert (it,myvector.begin(),myvector.end());
    print_list(mylist);

    //@merge, @sort

    std::cout << "\n=== MERGE, SORT ===\n\n";

    ft::List<double> first, second;

    first.push_back (3.1);
    first.push_back (2.2);
    first.push_back (2.9);

    second.push_back (3.7);
    second.push_back (7.1);
    second.push_back (1.4);

    std::cout << "\n* Sort each list *\n";
    first.sort();
    second.sort();
    print_list(first);
    print_list(second);

    std::cout << "\n* Merge *\n";
    first.merge(second);
    print_list(first);


    //@remove_if , @remove

    std::cout << "\n=== REMOVE, REMOVE_IF ===\n\n";

    print_list(first);
    std::cout << "\n* Remove value (3.1) *\n\n";
    first.remove(3.1);
    print_list(first);

    std::cout << "\n* Remove_if(<=2) *\n\n";
    first.remove_if(inferior_equal_to_two);
    print_list(first);

    //@reverse

    std::cout << "\n=== REVERSE ===\n\n";


    first.push_back(42);
    first.push_back(424);
    first.push_back(429);
    first.push_back(4277);

    print_list(first);
    std::cout << "* Reverse *\n";
    first.reverse();
    print_list(first);

    //@splice

    std::cout << "\n=== SPLICE ===\n\n";
    ft::List<int> mylist1, mylist2;
    ft::List<int>::iterator iteer;

    for (int i = 1; i <= 4; ++i)
        mylist1.push_back(i);

    for (int i = 1; i <= 3; ++i)
        mylist2.push_back(i * 10);

    iteer = mylist1.begin();

    mylist1.splice(iteer, mylist2);                              
    mylist2.splice (mylist2.begin(),mylist1, iteer);
    iteer = mylist1.begin();
    iteer += 3;
    mylist1.splice ( mylist1.begin(), mylist1, iteer, mylist1.end());
    print_list(mylist1);
    print_list(mylist2);

    //@swap

    std::cout << "\n=== SWAP ===\n\n";

	std::cout << "\n1) ";
	print_list(a);
	std::cout << "   Size = " << a.size() << '\n';
	std::cout << "\n2) ";
	print_list(c);
	std::cout << "   Size = " << c.size() << '\n';
	ft::List<int>::iterator itera = a.begin();
	std::cout << "   Pointer before swap = " << *itera << '\n';

	std::cout << "\n* Swap! *\n\n";
	a.swap(c);


	std::cout << "\n1) ";
	print_list(a);
	std::cout << "   Size = " << a.size() << '\n';
	std::cout << "\n2) ";
	print_list(c);
	std::cout << "   Size = " << c.size() << '\n';
	std::cout << "   Pointer after swap = " << *itera << '\n';

    //@operator = 

    std::cout << "\n=== OPERATOR '=' ===\n\n";

    ft::List<int> primero (3);
    ft::List<int> secundo (5);

    secundo = primero;
    primero = ft::List<int>();

    std::cout << "Size of primero: " << int (primero.size()) << '\n';
    std::cout << "Size of secundo: " << int (secundo.size()) << '\n';

    //@unique

    std::cout << "\n=== UNIQUE '=' ===\n\n";

    double mydoubles[] = {12.15, 2.72, 73.0, 12.77, 3.14, 12.77, 73.35, 72.25, 15.3, 72.25};

    ft::List<double> unique_list (mydoubles,mydoubles+10);
    unique_list.sort();


    print_list(unique_list);
    unique_list.unique();

    std::cout << "* Simple unique *\n";
    unique_list.unique();
    print_list(unique_list);
    
    std::cout << "* Unique function *\n";
    unique_list.unique (same_integral_part);
    print_list(unique_list);

    //@overloads non-member

    std::cout << "\n=== OVERLAODS NON MEMBERS ===\n\n";

    ft::List<float> lst1;
    ft::List<float> lst2;

	if (lst1 == lst2)
		std::cout << "Equal\n";
	else
		std::cout << "Not equal\n";

	if (lst1 > lst2)
		std::cout << "Superior strict\n";
	else
		std::cout << "Inferior or equal\n";

	if (lst1 != lst2)
		std::cout << "Is not equal\n";
	else
		std::cout << "Equal\n";

    std::cout << "\n";

    ft::List<std::string> lst3;
    ft::List<std::string> lst4;

    lst3.push_back("salut");
    lst4.push_back("salvt");

    if (lst3 == lst4)
		std::cout << "Equal\n";
	else
		std::cout << "Not equal\n";

	if (lst3 > lst4)
		std::cout << "Superior strict\n";
	else
		std::cout << "Inferior or equal\n";

	if (lst3 != lst4)
		std::cout << "Is not equal\n";
	else
		std::cout << "Equal\n";
}
