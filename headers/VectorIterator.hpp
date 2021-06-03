#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <cstddef>

namespace ft
{
    template <class T>
    class VectorIterator
    {
    public:
        typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef T* pointer;
        typedef T& reference;

    protected:
        pointer _ptr;

    public:
        VectorIterator(void)
        {
        }
        VectorIterator(VectorIterator const &other)
        {
            *this = other;
        }
        VectorIterator(T* ptr) :
        _ptr(ptr)
        {
        }
        ~VectorIterator(void)
        {
        }
        VectorIterator &operator= (VectorIterator const &other)
        {
            _ptr = other._ptr;
            return (*this);
        }
        VectorIterator operator++(void)
        {
            _ptr++;
            return (*this);
        }
        VectorIterator operator--(void)
        {
            VectorIterator tmp = *this;
            _ptr--;
            return (tmp);
        }
        VectorIterator operator++(int)
        {
            VectorIterator tmp = *this;
            _ptr++;
            return (tmp);
        }
        VectorIterator operator--(int)
        {
            VectorIterator tmp = *this;
            _ptr--;
            return (tmp);
        }
        bool operator ==(const VectorIterator &other) const
        {
            return (_ptr == other._ptr);
        }
        bool operator !=(const VectorIterator &other) const
        {
            return (_ptr != other._ptr);
        }
        bool operator >(const VectorIterator &other) const
        {
            return (_ptr > other._ptr);
        }
        bool operator >=(const VectorIterator &other) const
        {
            return (_ptr >= other._ptr);
        }
        bool operator <(const VectorIterator &other) const
        {
            return (_ptr < other._ptr);
        }
        bool operator <=(const VectorIterator &other) const
        {
            return (_ptr <= other._ptr);
        }
        value_type &operator*(void)
        {
            return (*_ptr);
        }
        value_type *operator->(void)
        {
            return (_ptr);
        }
        VectorIterator operator +(int n) const
        {
            VectorIterator tmp = *this;
            tmp._ptr += n;
            return (tmp);
        }
        VectorIterator operator -(int n) const
        {
            VectorIterator tmp = *this;
            tmp._ptr -= n;
            return (tmp);
        }
        VectorIterator &operator +=(int n)
        {
            _ptr += n;
            return (*this);
        }
        VectorIterator &operator -=(int n)
        {
            _ptr -= n;
            return (*this);
        }
        VectorIterator &operator[](int n) const
        {
            return (*(_ptr + n));
        }
        difference_type operator-(VectorIterator const &other) const
        {
            return (this->_ptr - other._ptr);
        }
};

template <class T> 
class ConstVectorIterator : public VectorIterator<T>
{
    public:
        typedef T value_type;
        typedef T* pointer;
        typedef T& reference;

    public:

        ConstVectorIterator(void)
        {
        }

        ConstVectorIterator(pointer ptr)
        {
            this->_ptr = ptr;
        }

        ConstVectorIterator(const ConstVectorIterator &other)
        {
            *this = other;
        }

        ~ConstVectorIterator(void)
        {
        }

        ConstVectorIterator &operator=(const ConstVectorIterator &other)
        {
            this->_ptr = other._ptr;
            return (*this);
        }

        const value_type &operator*(void)
        {
            return (*(this->_ptr));
        }

        const value_type &operator[](int n) const
        {
            return (*(this->_ptr + n));
        }
};

template <class T> 
class ReverseVectorIterator : public VectorIterator<T>
{
    public:
    
        typedef T value_type;
        typedef T* pointer;
        typedef T& reference;
    public:

        ReverseVectorIterator(void)
        {
        }

        ReverseVectorIterator(pointer ptr)
        {
            this->_ptr = ptr;
        }

        ReverseVectorIterator(const ReverseVectorIterator &other)
        {
            *this = other;
        }

        ~ReverseVectorIterator(void)
        {
        }

        ReverseVectorIterator &operator++()
        {
            this->_ptr--;
            return (*this);
        }

        ReverseVectorIterator operator++(int)
        {
            ReverseVectorIterator tmp = *this;
            this->_ptr--;
            return (tmp);
        }

        ReverseVectorIterator &operator--()
        {
            this->_ptr++;
            return (*this);
        }

        ReverseVectorIterator operator--(int)
        {
            ReverseVectorIterator tmp = *this;
            this->_ptr++;
            return (tmp);
        }

        ReverseVectorIterator operator+=(int n)
        {
            this->_ptr += n;
            return (*this);
        }

        ReverseVectorIterator operator-=(int n)
        {
            this->_ptr -= n;
            return (*this);
        }

        bool operator ==(const ReverseVectorIterator &other) const
        {
            return (this->_ptr == other._ptr);
        }

        bool operator !=(const ReverseVectorIterator &other) const
        {
            return (this->_ptr != other._ptr);
        }

        bool operator >(const ReverseVectorIterator &other) const
        {
            return (this->_ptr > other._ptr);
        }
        bool operator >=(const ReverseVectorIterator &other) const
        {
            return (this->_ptr >= other._ptr);
        }

        bool operator <(const ReverseVectorIterator &other) const
        {
            return (this->_ptr < other._ptr);
        }

        bool operator <=(const ReverseVectorIterator &other) const
        {
            return (this->_ptr <= other._ptr);
        }

        value_type &operator *(void)
        {
            return (*(this->_ptr));
        }

        value_type *operator ->(void)
        {
            return (this->_ptr);
        }

        ReverseVectorIterator operator +(int n) const
        {
            ReverseVectorIterator tmp = *this;
            tmp._ptr -= n;
            return (tmp);
        }

        ReverseVectorIterator operator -(int n) const
        {
            ReverseVectorIterator tmp = *this;
            tmp._ptr += n;
            return (tmp);
        }

        value_type &operator[](int n) const
        {
            return (*(this->_ptr - n -1));
        }
};

template <class T>
class ConstReverseVectorIterator : public ReverseVectorIterator<T>
{
    public:
        typedef T value_type;
        typedef T* pointer;
        typedef T& reference;
        
        ConstReverseVectorIterator(void)
        {
        }

        ConstReverseVectorIterator(pointer ptr)
        {
            this->_ptr = ptr;
        }

        ConstReverseVectorIterator(const ConstReverseVectorIterator &other)
        {
            *this = other;
        }

        ~ConstReverseVectorIterator(void)
        {
        }

        ConstReverseVectorIterator &operator=(const ConstReverseVectorIterator &other)
        {
            this->_ptr = other._ptr;
            return (*this);
        }

        const value_type &operator*(void)
        {
            return (*this->_ptr);
        }

        const value_type &operator[](int n) const
        {
            return (*(this->_ptr - n));
        }
    };
}

#endif