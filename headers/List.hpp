#ifndef LIST_HPP
# define LIST_HPP

# include <memory>
# include <limits>
# include "ListIterator.hpp"
# include "Enable_if.hpp"

namespace ft
{
	template <class T, class Alloc=std::allocator<T> >
	class List
	{
		public:
			typedef T value_type;
			typedef Alloc allocator_type;
			typedef T& reference;
			typedef const T& const_reference;
			typedef T* pointer;
			typedef const T* const_pointer;
			typedef unsigned long size_type;
			typedef Node<value_type>* node;
			typedef ListIterator<value_type> iterator;
			typedef ConstListIterator<value_type> const_iterator;
			typedef ReverseListIterator<value_type> reverse_iterator;
			typedef ConstReverseListIterator<value_type> const_reverse_iterator;

		private:

			node _begin;
			node _end;
			allocator_type _allocator;
			size_type _length;

			Node<value_type> *_node_list_new(value_type value, Node<value_type> *prev, Node<value_type> *next)
			{
				node node = new Node<value_type>();
				node->prev = prev;
				node->next = next;
				node->data = value;
				return node;
			}

			void _initialization(void)
			{
				_begin = _node_list_new(value_type(), 0, 0);
				_end = _node_list_new(value_type(), _begin, 0);
				_begin->next = _end;
			}

			template <typename N>
			struct _Smaller
            {
				bool operator()(const N &a, const N &b)
				{
					return (a > b);
				};
			};

			template <typename N>
			struct _Equal
            {
				bool operator()(const N &a, const N &b)
				{
					return (a == b);
				};
			};

		public:
			explicit List(const allocator_type &alloc=allocator_type())
			: _begin(0), _end(0), _allocator(alloc), _length(0)
			{
				_initialization();
			}

			explicit List(size_type n, const value_type &value = value_type(), const allocator_type &alloc=allocator_type())
			: _begin(0), _end(0), _allocator(alloc), _length(0)
			{
				_initialization();
				assign(n, value);
			}

			template <class InputIterator>
			List(InputIterator first, InputIterator last, const allocator_type &alloc=allocator_type(),
            typename ft::enable_if<!is_integral<InputIterator>::value>::type* = NULL)
			: _begin(0), _end(0), _allocator(alloc), _length(0)
			{
				_initialization();
				assign(first, last);
			}

			List(const List &other)
			: _begin(0), _end(0), _allocator(other._allocator), _length(0)
			{
				_initialization();
				*this = other;
			}

			~List(void)
			{
				clear();
				delete _begin;
				delete _end;
			}

			List &operator=(const List &other)
			{
				clear();
				assign(other.begin(), other.end());
				_length = other._length;
				return (*this);
			}

			iterator begin(void)
            {
				return (iterator(_begin->next));
			}

			const_iterator begin(void) const
            {
				return (const_iterator(_begin->next));
			}

			iterator end(void)
            {
				return (iterator(_end));
			}

			const_iterator end(void) const
            {
				return (const_iterator(_end));
			}

			reverse_iterator rbegin(void)
            {
				return (reverse_iterator(_end->prev));
			}

			const_reverse_iterator rbegin(void) const
            {
				return (const_reverse_iterator(_end->prev));
			}

			reverse_iterator rend(void)
            {
				return (reverse_iterator(_begin));
			}

			const_reverse_iterator rend(void) const
            {
				return (const_reverse_iterator(_begin));
			}

			bool empty(void) const
			{
				return (!_length);
			}
            
			size_type size(void) const
			{
				return _length;
			}

			size_type max_size(void) const
			{
				return (std::numeric_limits<size_type>::max() / (sizeof(Node<T>)));
			}

			reference front(void)
			{
				return _begin->next->data;
			}

			const_reference front(void) const
			{
				return _begin->next->data;
			}

			reference back(void)
			{
				return _end->prev->data;
			}
            
			const_reference back(void) const
			{
				return _end->prev->data;
			}

			template <class InputIterator>
			void assign(InputIterator first, InputIterator last,
            typename ft::enable_if<!is_integral<InputIterator>::value>::type* = NULL)
			{
				clear();
				while (first != last)
                {
					push_back(*first);
                    first++;
                }
			}

			void assign(size_type n, const value_type &value)
			{
				clear();
				while (n-- != 0)
					push_back(value);
			}

			void push_front(const value_type &value)
			{
				node el = _node_list_new(value, _begin, _begin->next);
				_begin->next->prev = el;
				_begin->next = el;
				_length++;
			}

			void pop_front(void)
			{
				node next = _begin->next->next;
				delete _begin->next;
				_begin->next = next;
				next->prev = _begin;
				_length--;
			}
            
			void push_back(const value_type &value)
			{
				node el = _node_list_new(value, _end->prev, _end);
				_end->prev->next = el;
				_end->prev = el;
				_length++;
			}

			void pop_back(void)
			{
				node before = _end->prev->prev;
				delete _end->prev;
				before->next = _end;
				_end->prev = before;
				_length--;
			}

			iterator insert(iterator position, const value_type &value)
			{
				if (position == begin())
				{
					push_front(value);
					return (begin());
				}
				else if (position == end()) //else
				{
					push_back(value);
					return (end());
				}
				node after = position.node();
				node before = after->prev;
				node el = _node_list_new(value, before, after);
				before->next = el;
				after->prev = el;
				_length++;
				return (iterator(el));
			}

			void insert(iterator position, size_type n, const value_type &val)
			{
				while (n-- != 0)
                {
					position = insert(position, val);
                }
			}

			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last,
            typename ft::enable_if<!is_integral<InputIterator>::value>::type* = NULL)
			{
				while (first != last)
				{
					position = insert(position, *first);
                    first++;
					if (position != end())
						position++;
				}
			}

			iterator erase(iterator position)
			{
				if (position == begin())
				{
					pop_front();
					return (begin());
				}
				if (position == end())
				{
					pop_back();
					return (end());
				}
				node next = position.node()->next;
				node previous = position.node()->prev;
				delete position.node();
				previous->next = next;
				next->prev = previous;
				_length--;
				return (iterator(next));
			}

			iterator erase(iterator first, iterator last)
			{
				while (first != last)
                {
					erase(first);
                    first++;
                }
				return (first);
			}

			void swap(List &x)
			{
				ft::swap(x._length, _length);
				ft::swap(x._begin, _begin);
				ft::swap(x._end, _end);
			}

			void resize(size_type n, value_type value = value_type())
			{
				while (n < _length)
					pop_back();
				while (n > _length)
					push_back(value);
			}

			void clear(void)
			{
				node cur = _begin->next;
				while (cur != _end)
				{
					node next = cur->next;
					delete cur;
					cur = next;
				}
				_begin->next = _end;
				_end->prev = _begin;
				_length = 0;
			}

			void splice(iterator position, List &x)
			{
				splice(position, x, x.begin(), x.end());
			}

			void splice(iterator position, List &x, iterator i)
			{
				insert(position, *i);
				x.erase(i);
			}

			void splice(iterator position, List &x, iterator first, iterator last)
			{
				insert(position, first, last);
				x.erase(first, last);
			}

			void remove(const value_type &value)
			{
				iterator c = begin();
				while (c != end())
				{
					if (*c == value)
						c = erase(c);
					else
						c++;
				}
			}

			template <class Predicate>
			void remove_if(Predicate pred)
			{
				iterator c = begin();
				while (c != end())
				{
					if (pred(*c))
						c = erase(c);
					else
						c++;
				}
			}

			void unique(void)
			{
				unique(_Equal<value_type>());
			}

			template <class BinaryPredicate>
			void unique(BinaryPredicate binary_pred)
			{
				iterator prev = begin();
				iterator next = prev;
				while (next + 1 != end())
				{
					++next;
					if (binary_pred(*prev, *next))
					{
						erase(next);
						next = prev;
					}
					else
						prev = next;
				}
			}

			void merge(List &x)
			{
				merge(x, _Smaller<value_type>());
			}

			template <class Compare>
			void merge(List &x, Compare comp)
			{
				if (this == &x)
					return ;
				insert(end(), x.begin(), x.end());
				x.clear();
                iterator a = begin();
				iterator b;
				while (a + 1 != end())
				{
					b = a + 1;
					while (b != end())
					{
						if (comp(*a, *b))
							ft::swap(*a, *b);
						b++;
					}
					a++;
				}
			}

			void sort(void)
			{
				sort(_Smaller<value_type>());
			}

			template <class Compare>
			void sort(Compare comp)
			{
				iterator a = begin();
				iterator b;
				while (a + 1 != end())
				{
					b = a + 1;
					while (b != end())
					{
						if (comp(*a, *b))
							ft::swap(*a, *b);
						b++;
					}
					a++;
				}
			}

			void reverse(void)
			{
				List<value_type> tmp;
				iterator it = begin();
				while (it != end())
					tmp.push_front(*(it++));
				*this = tmp;
			}
	};

	template <class T, class Alloc>
	void swap(List<T, Alloc> &x, List<T, Alloc> &y)
	{
		x.swap(y);
	}

	template<typename T>
	bool operator==(List<T> const &lhs, List<T> const &rhs)
    {
		if (lhs.size() != rhs.size())
			return (false);
		typename List<T>::const_iterator cur1 = lhs.begin();
		typename List<T>::const_iterator cur2 = rhs.begin();
		while (cur1 != lhs.end())
		{
			if (*cur1 != *cur2)
				return false;
            cur1++;
            cur2++;
		}
		return true;
	}

	template<typename T>
	bool operator!=(List<T> const &lhs, List<T> const &rhs)
    {
		return (!(lhs == rhs));
	}

	template<typename T>
	bool operator<(List<T> const &lhs, List<T> const &rhs)
    {
		if (lhs.size() < rhs.size())
			return (true);
		if (lhs.size() > rhs.size())
			return (false);
		typename List<T>::const_iterator cur1 = lhs.begin();
		typename List<T>::const_iterator cur2 = rhs.begin();
		while (cur1 != lhs.end())
		{
			if (*cur1 != *cur2)
				return (*cur1 < *cur2);
			cur1++;
			cur2++;
		}	
		return false;
	}

	template<typename T>
	bool operator<=(List<T> const &lhs, List<T> const &rhs)
    {
		return (!(rhs < lhs));
	}

	template<typename T>
	bool operator>(List<T> const &lhs, List<T> const &rhs)
    {
		return (rhs < lhs);
	}

	template<typename T>
	bool operator>=(List<T> const &lhs, List<T> const &rhs)
    {
		return (!(lhs < rhs));
	}
};

#endif