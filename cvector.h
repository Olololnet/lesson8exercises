#ifndef CVECTOR_H
#define CVECTOR_H

#include <cstddef>

namespace external
{
    class cVector
    {
    public:
        typedef int    value_type;
        typedef size_t size_type;

        cVector();
        cVector(size_type iSize);
        cVector(size_type iSize, value_type Value);
        cVector(const cVector& data);
        ~cVector();

        bool Empty() const;
        size_type capacity() const;
        size_type size() const;

        void push_back(const value_type& value);
        void pop_back();

        value_type& front();
        const value_type& front() const;

        value_type& back();
        const value_type& back() const;

        value_type& at(size_type iIndex);
        const value_type& at(size_type iIndex) const;

        cVector& operator= (const cVector& data);
        value_type& operator[] (size_type iIndex);
        const value_type& operator[] (size_type iIndex) const;

        void swap(cVector& data);

    private:
        value_type* m_pData;
        size_type   m_iSize;
        size_type   m_iCapacity;
    };
}

#endif
