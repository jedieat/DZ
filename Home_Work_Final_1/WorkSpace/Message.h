#ifndef MESSAGE_H
#define MESSAGE_H

#include <algorithm> // for std::copy_n
#include <cstddef> // for std::size_t

template <typename X > class Message
{
private:
    int m_length{}; //������ �������
    X* m_data{}; // ������

public:
    //Message() = default; // ��������� �����������
    Message(int length) :m_length{ length }  // �������� ����������
    {
        if (length > 10000000)
        {
            throw "bad length";
        }
        if (length > 0)
            m_data = new X[static_cast<std::size_t>(length)]{};
    }


    ~Message()   //���������� ������� ���� �����
    {
        delete[] m_data;// ������� ������
    }


    int getLength() const { return m_length; } //�������� ������ �������

    X& operator[](int index) //������� ������� [] ��� ������ �������� �������
    {
        return m_data[index];
    }


    Message(const Message& a) : Message(a.getLength()) // ����������� ����������
    {
        std::copy_n(a.m_data, m_length, m_data); // �������� ��������� �������
    }

    X find(int value) // �������� ������ � ������ �������� ���������� �� �������
    {
        for (int i{ 0 }; i < m_length; ++i)
            if (value == m_data[i])
                return value;
        return 0;
    }


    void insertBefore(X value, int index) // �������� �������
    {

        X* data{ new X[static_cast<std::size_t>(m_length + 1)] };

        std::copy_n(m_data, index, data);

        data[index] = value;

        std::copy_n(m_data + index, m_length - index, data + index + 1);

        delete[] m_data;
        m_data = data;
        ++m_length;
    }
    void insertAtBeginning(X value) { insertBefore(value, 0); } //�������� ������� � ������
};



#endif