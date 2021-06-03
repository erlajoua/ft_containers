#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <limits>
# include <iostream>
# include <cstring>
# include "VectorIterator.hpp"
# include "Enable_if.hpp"
# include "Utils.hpp"

namespace ft
{
    template <class T, class A = std::allocator<T> >
    class Vector
    {
	public:
		typedef T value_type;
		typedef A allocator_type;
		typedef T& reference;
		typedef const T& const_reference;
		typedef T* pointer;
		typedef const T* const_pointer;
		typedef ft::VectorIterator<T> iterator;
		typedef ft::ConstVectorIterator<T> const_iterator;
		typedef ft::ReverseVectorIterator<T> reverse_iterator;
		typedef ft::ConstReverseVectorIterator<T> const_reverse_iterator;
		typedef size_t size_type ;
	private:
		size_type _container_length;
		size_type _container_size;
		pointer _container;
		allocator_type _allocator;

	public:
		explicit Vector(const allocator_type &allocator = allocator_type())
			: _container_length(0), _container_size(0), _container(0), _allocator(allocator)
		{
			_container = _allocator.allocate(0);
		}

		template <class InputIterator>
		Vector(InputIterator first, InputIterator last, const allocator_type &allocator = allocator_type(),
		typename ft::enable_if<!is_integral<InputIterator>::value>::type* = NULL)
		: _container_length(0), _container_size(0), _container(0), _allocator(allocator)
		{
			_container = _allocator.allocate(0);
			assign(first, last);
		}

		Vector(size_type n, const_reference value = value_type(), const allocator_type &allocator = allocator_type())
		: _container_length(0), _container_size(0), _container(0), _allocator(allocator)
		{
			_container = _allocator.allocate(0);
			assign(n, value);
		}

		Vector(const Vector &other)
		: _container(NULL), _container_size(0), _container_length(other._container_length)
		{
			reserve(other._container_size);
			std::memcpy(static_cast<void*>(_container), static_cast<void*>(other._container), other._container_length * sizeof(value_type));
		}

		~Vector(void)
		{
			_allocator.deallocate(_container, _container_size);
		}

		Vector &operator=(const Vector &other)
		{
			if (_container != 0)
				_allocator.deallocate(_container, _container_size);
			_allocator = other._allocator;
			_container_size = 0;
			_container_length = 0;
			_container = _allocator.allocate(0);
			assign(other.begin(), other.end());
			return (*this);
		}

		reference operator[](size_type n)
		{
			return (_container[n]);
		}

		const_reference operator[](size_type n) const
		{
			return (_container[n]);
		}

		iterator begin(void)
		{
			return (iterator(_container));
		}

		const_iterator begin(void) const
		{
			return (const_iterator(_container));
		}

		iterator end(void)
		{
			return (iterator(_container + _container_length));
		}

		const_iterator end(void) const
		{
			return (const_iterator(_container + _container_length));
		}

		reverse_iterator rbegin(void)
		{
			return (reverse_iterator(_container + _container_length - 1));
		}

		const_reverse_iterator rbegin(void) const
		{
			return (const_reverse_iterator(_container + _container_length - 1));
		}

		reverse_iterator rend(void)
		{
			return (reverse_iterator(_container - 1));
		}

		const_reverse_iterator rend(void) const
		{
			return (const_reverse_iterator(_container - 1));
		}

		void reserve(size_type n)
		{
			if (n > _container_size)
			{
				size_type i = -1;
				pointer	tmp;
				tmp  = _allocator.allocate(n);
				_container_size = n;
				while (++i < _container_length)
					tmp[i] = _container[i];
				_allocator.deallocate(_container, _container_size);
				_container = tmp;
			}
		}

		void push_back(const value_type &value)
		{
			if (_container_length + 1 > _container_size)
				reserve(_container_length + 1);
			_container[_container_length++] = value;
		}

		size_type size(void) const
		{
			return (_container_length);
		};
		size_type capacity(void) const
		{
			return (_container_size);
		}

		bool empty(void) const
		{
			return (_container_length == 0);
		}
		
		iterator insert(iterator position, const_reference val) //@1
		{
			iterator it = begin();
			//reallocation if needed
			if (_container_length + 1 > _container_size)
				reserve(_container_length + 1);
			size_type count = 0;
			//count is the range of the position's index
			while (it != position)
			{
				it++;
				count++;
			}
			//move all elements after count, to create place for val
			for (size_type j = _container_size - 1; j > count; j--)
				_container[j] = _container[j - 1];
			_container[count] = val;
			_container_length++;
			return (iterator(&_container[count]));
		}
		void insert(iterator position, size_type n, const_reference val) //@2
		{
			iterator it = begin();
			//reallocation if needed
			if (_container_length + n > _container_size)
				reserve(_container_length + n);
			//count is the range of the position's index
			size_type count = 0;
			while (it != position)
			{
				++it;
				++count;
			}
			//move all elements after count to create n place for val
			for (size_type j = _container_size - 1; j > count; j--)
				_container[j] = _container[j - n];
			//assign the n values in the space created just before
			for (size_type j = count; j < count + n; j++)
				_container[j] = val;
			_container_length += n;
		}

		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last,
		typename ft::enable_if<!is_integral<InputIterator>::value>::type* = NULL) //@3
		{
			iterator it = begin();
			size_type range = last - first;
			//reallocation if needed
			if (_container_length + range > _container_size)
				reserve(_container_length + range);
			size_type count = 0;
			while (it != position)
			{
				++it;
				++count;
			}
			for (size_type j = _container_size - 1 ; j > count; j--)
				_container[j] = _container[j - range];
			for (size_type j = count; j < count + range; j++, first++)
				_container[j] = *first;
			_container_length += range;
		}

		size_type max_size(void) const
		{
			return (std::numeric_limits<size_type>::max() / sizeof(value_type));
		}

		reference at(size_type n)
		{
			if (n >= _container_length || n < 0)
				throw std::length_error("out of range");
			return _container[n];
		}

		const_reference at(size_type n) const
		{
			if (n >= _container_length || n < 0)
				throw std::length_error("out of range");
			return _container[n];
		}

		iterator erase(iterator position)
		{
			iterator cursor = position;
			while (cursor + 1 != end())
			{
				*cursor = *(cursor + 1);
				cursor++;
			}
			_container_length--;
			return (iterator(position));
		}

		iterator erase(iterator begin, iterator end)
		{
			while (begin != end)
			{
				erase(begin);
				end--;
			}
			return (iterator(begin));
		}

		void clear(void)
		{
			erase(begin(), end());
		}

		template <class InputIterator>
		void assign(InputIterator first, InputIterator last,
		typename ft::enable_if<!is_integral<InputIterator>::value>::type* = NULL) //@1
		{
			clear();
			//get the range from first to last
			size_type range = last - first;
			if (range + _container_length > _container_size)
				reserve(range + _container_length);
			//assign the n (range) values to the tab allocated
			for (size_type i = 0; i < range; i++, first++)
				_container[i] = *first;
			_container_length = range;
		}

		void assign(size_type n, const value_type &val) //@2
		{
			clear();
			if (n + _container_length > _container_size)
				reserve(n + _container_length);
			//basic assignation
			for (size_type i = 0; i < n; i++)
				_container[i] = val;
			_container_length = n;
		}

		reference front(void)
		{
			return _container[0];
		}

		const_reference front(void) const
		{
			return _container[0];
		}

		reference back(void)
		{
			return _container[_container_length - 1];
		}
		
		const_reference back(void) const
		{
			return _container[_container_length - 1];
		}

		void pop_back(void)
		{
			if (_container_length)
				_container_length--;
		}

		void resize(size_type n, value_type value = value_type())
		{
			while (n < _container_length)
				pop_back();
			while (n > _container_length)
				push_back(value);
		}

		void swap(Vector &other)
		{
			ft::swap(_container, other._container);
			ft::swap(_container_size, other._container_size);
			ft::swap(_container_length, other._container_length);
		}
	};
}

#endif