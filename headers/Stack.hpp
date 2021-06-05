#ifndef STACK_HPP
# define STACK_HPP

# include "List.hpp"

namespace ft
{
    template<class T, class C = ft::List<T> >
    class Stack
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
        Stack(container_type const &container=container_type()) :
        _container(container)
        {
        }

        Stack(Stack const &other) :
        _container(other._container)
        {
        }

        virtual ~Stack()
        {
        }

        Stack &operator=(Stack const &other)
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

        reference top(void)
        {
            return (_container.back());
        }
        const_reference top(void) const
        {
            return (_container.back());
        }

        void push(const_reference val)
        {
            _container.push_back(val);
        }
        void pop(void)
        {
            _container.pop_back();
        }

        //relational operators

        template <class stack_type, class container_type>
        friend bool operator ==(Stack<stack_type, container_type> const &lhs, Stack<stack_type, container_type> const &rhs);

        template <class stack_type, class container_type>
        friend bool operator !=(Stack<stack_type, container_type> const &lhs, Stack<stack_type, container_type> const &rhs);

        template <class stack_type, class container_type>
        friend bool operator <(Stack<stack_type, container_type> const &lhs, Stack<stack_type, container_type> const &rhs);

        template <class stack_type, class container_type>
        friend bool operator <=(Stack<stack_type, container_type> const &lhs, Stack<stack_type, container_type> const &rhs);

        template <class stack_type, class container_type>
        friend bool operator >(Stack<stack_type, container_type> const &lhs, Stack<stack_type, container_type> const &rhs);

        template <class stack_type, class container_type>
        friend bool operator >=(Stack<stack_type, container_type> const &lhs, Stack<stack_type, container_type> const &rhs);
    };

    template <class stack_type, class container_type>
    bool operator ==(Stack<stack_type, container_type> const &lhs, Stack<stack_type, container_type> const &rhs)
    {
        return (lhs._container == rhs._container);
    }

    template <class stack_type, class container_type>
    bool operator !=(Stack<stack_type, container_type> const &lhs, Stack<stack_type, container_type> const &rhs)
    {
        return (lhs._container != rhs._container);
    }

    template <class stack_type, class container_type>
    bool operator <(Stack<stack_type, container_type> const &lhs, Stack<stack_type, container_type> const &rhs)
    {
        return (lhs._container < rhs._container);
    }

    template <class stack_type, class container_type>
    bool operator <=(Stack<stack_type, container_type> const &lhs, Stack<stack_type, container_type> const &rhs)
    {
        return (lhs._container <= rhs._container);
    }

    template <class stack_type, class container_type>
    bool operator >(Stack<stack_type, container_type> const &lhs, Stack<stack_type, container_type> const &rhs)
    {
        return (lhs._container > rhs._container);
    }

    template <class stack_type, class container_type>
    bool operator >=(Stack<stack_type, container_type> const &lhs, Stack<stack_type, container_type> const &rhs)
    {
        return (lhs._container >= rhs._container);
    }
}

#endif