#include "cvector.h"
#include <iostream>

namespace external
{
    cVector::cVector()
    :m_pData(new value_type[1])
    ,m_iSize(0)
    ,m_iCapacity(1)
    {

    }

    cVector::cVector(size_type iSize)
    :m_pData(new value_type[iSize])
    ,m_iSize(0)
    ,m_iCapacity(iSize)
    {

    }

    cVector::cVector(size_type iSize, value_type Value)
    :m_pData(new value_type[iSize])
    ,m_iSize(iSize)
    ,m_iCapacity(iSize)
    {
        for (size_type i = 0; i < m_iSize; i++)
        {
            m_pData[i] = Value;
        }
    }

    cVector::cVector(const cVector& data)
    :m_pData(new value_type[data.m_iCapacity])
    ,m_iSize(data.m_iSize)
    ,m_iCapacity(data.m_iCapacity)
    {
        for (size_type i = 0; i < m_iSize; i++)
        {
            m_pData[i] = data.m_pData[i];
        }
    }

    cVector::~cVector()
    {
        delete[] m_pData;
    }

    bool cVector::Empty() const
    {
        return (!m_iSize);
    }

    cVector::size_type cVector::capacity() const
    {
        return m_iCapacity;
    }

    cVector::size_type cVector::size() const
    {
        return m_iSize;
    }

    void cVector::push_back(const cVector::value_type& value)
    {
        if (m_iCapacity > m_iSize)
        {
            m_pData[m_iSize] = value;
            m_iSize++;
        }
        else
        {
            value_type* Temp = new value_type[m_iCapacity*2];

            for (size_type i = 0; i < m_iSize; i++)
            {
                Temp[i] = m_pData[i];
            }
            delete[] m_pData;
            m_pData = Temp;
            m_pData[m_iSize] = value;
            m_iSize++;
            m_iCapacity <<= 1;
        }
    }

    void cVector::pop_back()
    {
        m_iSize--;
    }

    cVector::value_type& cVector::front()
    {
        return m_pData[0];
    }

    const cVector::value_type& cVector::front() const
    {
        return m_pData[0];
    }

    cVector::value_type& cVector::back()
    {
        return m_pData[m_iSize - 1];
    }

    const cVector::value_type& cVector::back() const
    {
        return m_pData[m_iSize - 1];
    }

    cVector::value_type& cVector::at(cVector::size_type iIndex)
    {
        return m_pData[iIndex];
    }

    const cVector::value_type& cVector::at(cVector::size_type iIndex) const
    {
        return m_pData[iIndex];
    }

    cVector& cVector::operator= (const cVector &data)
    {
        delete[] m_pData;

        m_iSize = data.m_iSize;
        m_iCapacity = data.m_iCapacity;
        m_pData = new value_type[m_iCapacity];

        for (size_type i = 0; i < m_iSize; i++)
        {
            m_pData[i] = data.m_pData[i];
        }
        return *this;
    }

    cVector::value_type& cVector::operator[] (cVector::size_type iIndex)
    {
        return m_pData[iIndex];
    }

    const cVector::value_type& cVector::operator[] (cVector::size_type iIndex) const
    {
        return m_pData[iIndex];
    }

    void cVector::swap(cVector &data)
    {
        std::swap(m_pData, data.m_pData);
        std::swap(m_iCapacity, data.m_iCapacity);
        std::swap(m_iSize, data.m_iSize);
    }
}
