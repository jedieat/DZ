#ifndef INTARRAY_H
#define INTARRAY_H

#include <algorithm> // for std::copy_n
#include <cstddef> // for std::size_t

template <typename X > class IntArray
{
private:
    int m_length{}; //������ �������
    X* m_data{}; // ������

public:
    //IntArray() = default; // ��������� �����������
    IntArray(int length) :m_length{ length }  // 1 �������. �������� ����������
    {
        if (length < 0)
        {
            throw "bad range";
        }
        if (length >10000000)
        {
            throw "bad length";
        }
        if (length > 0)
            m_data = new X[static_cast<std::size_t>(length)]{};
    }


    ~IntArray()   //���������� ������� ���� �����
    {
        delete[] m_data;// ������� ������
    }

    int getLength() const { return m_length; } //�������� ������ �������

    X& operator[](int index) //������� ������� [] ��� ������ �������� �������
    {
        return m_data[index];
    }

    void erase() //������� ����� ��� ��������������� �������. ��� ������ �� ����������, �� �� �� ������� ��� �����, � �������� ��� ��������. ����� 0, ������ ������� ������� ��������. 
    {
        delete[] m_data; // ������� ������
        // We need to make sure we set m_data to nullptr here, otherwise it will
        // be left pointing at deallocated memory!
        m_data = nullptr; //���������� ������� ���������
        m_length = 0; //����� ������� ������ 0  
    }
  
   

    IntArray(const IntArray& a) : IntArray(a.getLength()) // 2 �������. ����������� ����������
    {
        std::copy_n(a.m_data, m_length, m_data); // �������� ��������� �������
    }

    X find(int value) // ������� 3. �������� ������ � ������ �������� ���������� �� �������
    {
        for (int i{ 0 }; i < m_length; ++i)
            if (value == m_data[i])
                return value;
        return 0;
    }

    void reallocate(int newLength) //4 ������� 1 �����. �������� ������ ����������. ����� ������;
    {
        erase(); //������� ������
        if (newLength <= 0) // ���� ����� ����� 0 ��� ������ ������������, �������� 0 � ������ ���������
            return;
        m_data = new X[static_cast<std::size_t>(newLength)]; // ���� ����� ����� �� 0, ������� ������ ������ ����� �����
        m_length = newLength; //����� �����
    }

    void resize(int newLength) // 4 ������� 2 �����. ����� ������ � ���������� ������
    {
        // ���� �������� ����� ����� ��, ������ �� ������
        if (newLength == m_length)
            return;

        if (newLength <= 0)
        {
            erase();
            return;
        }

        // ����� ������
        X* data{ new X[static_cast<std::size_t>(newLength)] };

        //��������
        if (m_length > 0)
        {
            int elementsToCopy{ (newLength > m_length) ? m_length : newLength };
            std::copy_n(m_data, elementsToCopy, data); // copy the elements
        }

        // �������
        delete[] m_data;

        //����������
        m_data = data;
        m_length = newLength;
    }

    void insertBefore(int value, int index) //5 �������. �������� �������
    {

        X* data{ new X[static_cast<std::size_t>(m_length + 1)] };

        std::copy_n(m_data, index, data);

        data[index] = value;

        std::copy_n(m_data + index, m_length - index, data + index + 1);

        delete[] m_data;
        m_data = data;
        ++m_length;
    }

    void remove(int index) // 6 �������. ������� ������� �� ����������.
    {
        //int l1;
        //    l1 = m_length;
        //if (l1 <= 0); // !!!!!!!!!!!!! ���� ����������� ������� ������� ����� �� ���������
        //{
        //    throw "bad_range";
        //}
        //if (l1 < index); // !!!!!!!!!!!!! ���� ����������� ������� ������� ����� �� ���������
        //{
        //    throw "bad_index";
        //}

        if (m_length == 1)
        {
            erase();
            return;
        }

        X* data{ new X[static_cast<std::size_t>(m_length - 1)] };

        std::copy_n(m_data, index, data);

        std::copy_n(m_data + index + 1, m_length - index - 1, data + index);

        delete[] m_data;
        m_data = data;
        --m_length;
    }


    // �������������� ����� 
    void insertAtBeginning(int value) { insertBefore(value, 0); } //�������� ������� � ������
    void insertAtEnd(int value) { insertBefore(value, m_length); } //�������� ������� � �����

};

#endif