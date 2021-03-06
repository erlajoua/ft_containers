/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_queue.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <erlajoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:29:32 by erlajoua          #+#    #+#             */
/*   Updated: 2021/06/07 10:29:32 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "headers/Queue.hpp"

void main_queue(void)
{
    std::cout << "=== CONSTRUCTORS, EMPTY ===\n" << '\n';
    ft::Queue<char> first;
    ft::Queue<char, std::vector<char> > second;

    std::cout << "-> First is empty = " << first.empty() << '\n';
    std::cout << "-> First is empty = " << second.empty() << '\n';

    std::cout << "\n=== PUSH, POP, SIZE, FRONT ===\n" << '\n';

    std::cout << "-> Push: (! u s n U)\n";
    first.push('!');
    first.push('u');
    first.push('s');
    first.push('n');
    first.push('U');
    std::cout << "-> Size = " << first.size() << "\n\n";
    std::cout << "-> Front = " << first.front() << '\n';
    std::cout << "* Pop *\n";
    first.pop();
    std::cout << "-> Front = " << first.front() << '\n';
    std::cout << "* Pop *\n";
    first.pop();
    std::cout << "-> Front = " << first.front() << '\n';
    std::cout << "* Pop *\n";
    first.pop();
    std::cout << "-> Front = " << first.front() << '\n';
    std::cout << "* Pop *\n";
    first.pop();
    std::cout << "-> Front = " << first.front() << '\n';

    std::cout << "\n-> Size = " << first.size() << '\n';
    
    std::cout << "\n=== OVERLOADS NON-MEMBERS ===\n" << '\n';
    
    ft::Queue<int> a,b,c,d;

    a.push(1);
    a.push(2);

    b.push(1);
    b.push(2);

    std::cout << "a & b :\n\n";
    if (a == b)
        std::cout << "Equal\n";
    else
        std::cout << "Not equal\n";
    
    if (a != b)
        std::cout << "Not equal\n";
    else
        std::cout << "Equal\n";

    if (a < b || a > b)
        std::cout << "Not equal\n";
    else if (a >= b || a <= b)
        std::cout << "Equal\n";

    //

    c.push(4);

    d.push(42);

    std::cout << "\nc & d :\n\n";
    if (c == d)
        std::cout << "Equal\n";
    else
        std::cout << "Not equal\n";
    
    if (c != d)
        std::cout << "Not equal\n";
    else
        std::cout << "Equal\n";

    if (c < d || c > d)
        std::cout << "Not equal\n";
    else if (c >= d || c <= d)
        std::cout << "Equal\n";

    if (c > d)
        std::cout << "c > d\n";
    else
        std::cout << "c <= d\n";
}
