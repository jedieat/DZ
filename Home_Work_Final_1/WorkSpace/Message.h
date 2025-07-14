#ifndef MESSAGE_H
#define MESSAGE_H

#include <algorithm> // for std::copy_n
#include <cstddef> // for std::size_t

template <typename X > class Message
{
private:
    int m_length{}; //размер массива
    X* m_data{}; // массив

public:
    //Message() = default; // дефолтный конструктор
    Message(int length) :m_length{ length }  // Создание контейнера
    {
        if (length > 10000000)
        {
            throw "bad length";
        }
        if (length > 0)
            m_data = new X[static_cast<std::size_t>(length)]{};
    }


    ~Message()   //диструктор очищаем весь класс
    {
        delete[] m_data;// очищаем массив
    }


    int getLength() const { return m_length; } //Забираем длинну массива

    X& operator[](int index) //Создаме опретор [] для вывода элемента массива
    {
        return m_data[index];
    }


    Message(const Message& a) : Message(a.getLength()) // Копирование контейнера
    {
        std::copy_n(a.m_data, m_length, m_data); // копируем эллементы массива
    }

    X find(int value) // Получить доступ к любому элементу контейнера по индексу
    {
        for (int i{ 0 }; i < m_length; ++i)
            if (value == m_data[i])
                return value;
        return 0;
    }


    void insertBefore(X value, int index) // Вставить элемент
    {

        X* data{ new X[static_cast<std::size_t>(m_length + 1)] };

        std::copy_n(m_data, index, data);

        data[index] = value;

        std::copy_n(m_data + index, m_length - index, data + index + 1);

        delete[] m_data;
        m_data = data;
        ++m_length;
    }
    void insertAtBeginning(X value) { insertBefore(value, 0); } //Вставить элемент в начало
};



#endif