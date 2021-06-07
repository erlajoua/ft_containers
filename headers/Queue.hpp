/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <erlajoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:29:06 by erlajoua          #+#    #+#             */
/*   Updated: 2021/06/07 10:29:07 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
# define QUEUE_HPP

# include "List.hpp"

namespace ft
{
    template<typename T, typename C = ft::List<T> >
    class Queue
    {
    public:
        typedef size_t size_type;
        typedef T value_type;
        typedef C container_type;
        typedef T* pointer;
        typedef T const * const_pointer;
        typedef T& reference;
        typedef T const & const_reference;

    protected:
        container_type _container;

    public:

        Queue(container_type const &container=container_type()) :
        _container(container)
        {
        }
        
        Queue(Queue<T, C> const &other) :
        _container(other._container)
        {
        }

        virtual ~Queue()
        {
        }

        Queue &operator=(Queue const &other)
        {
            _container = other._container;
            return (*this);
        }

        bool empty(void) const
        {
            return (_container.empty());
        }
        size_t size(void) const
        {
            return (_container.size());
        }

        reference front(void)
        {
            return (_container.front());
        }
        const_reference front(void) const
        {
            return (_container.front());
        }

        reference back(void)
        {
            return (_container.back());
        }
        const_reference back(void) const
        {
            return (_container.back());
        }

        void push(const_reference val)
        {
            _container.push_back(val);
        }
        void pop(void)
        {
            _container.pop_front();
        }

        template <typename queue_type, typename container_type>
        friend bool operator==(Queue<queue_type, container_type> const &lhs, Queue<queue_type, container_type> const &rhs)
        {
            return (lhs._container == rhs._container);
        }

        template <typename queue_type, typename container_type>
        friend bool operator!=(Queue<queue_type, container_type> const &lhs, Queue<queue_type, container_type> const &rhs)
        {
            return (lhs._container != rhs._container);
        }

        template <typename queue_type, typename container_type>
        friend bool operator<(Queue<queue_type, container_type> const &lhs, Queue<queue_type, container_type> const &rhs)
        {
            return (lhs._container < rhs._container);
        }

        template <typename queue_type, typename container_type>
        friend bool operator<=(Queue<queue_type, container_type> const &lhs, Queue<queue_type, container_type> const &rhs)
        {
            return (lhs._container <= rhs._container);
        }

        template <typename queue_type, typename container_type>
        friend bool operator>(Queue<queue_type, container_type> const &lhs, Queue<queue_type, container_type> const &rhs)
        {
            return (lhs._container > rhs._container);
        }

        template <typename queue_type, typename container_type>
        friend bool operator>=(Queue<queue_type, container_type> const &lhs, Queue<queue_type, container_type> const &rhs)
        {
            return (lhs._container >= rhs._container);
        }
    };
}

#endif
