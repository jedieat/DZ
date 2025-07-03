#ifndef INTARRAY_H
#define INTARRAY_H

#include <algorithm> // for std::copy_n
#include <cstddef> // for std::size_t

template <typename X > class IntArray
{
private:
    int m_length{}; //размер массива
    X* m_data{}; // массив

public:
    //IntArray() = default; // дефолтный конструктор
    IntArray(int length) :m_length{ length }  // 1 Задание. Создание контейнера
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


    ~IntArray()   //диструктор очищаем весь класс
    {
        delete[] m_data;// очищаем массив
    }

    int getLength() const { return m_length; } //Забираем длинну массива

    X& operator[](int index) //Создаме опретор [] для вывода элемента массива
    {
        return m_data[index];
    }

    void erase() //Функция нужна для переопределения массива. Это похоже на диструктор, но он не удаляет есь класс, а заменяет его элементы. Длина 0, вместо массива нулевой укзатель. 
    {
        delete[] m_data; // очищаем массив
        // We need to make sure we set m_data to nullptr here, otherwise it will
        // be left pointing at deallocated memory!
        m_data = nullptr; //возвращаем нулевой указатель
        m_length = 0; //длину массива делаем 0  
    }
  
   

    IntArray(const IntArray& a) : IntArray(a.getLength()) // 2 Задание. Копирование контейнера
    {
        std::copy_n(a.m_data, m_length, m_data); // копируем эллементы массива
    }

    X find(int value) // Задание 3. Получить доступ к любому элементу контейнера по индексу
    {
        for (int i{ 0 }; i < m_length; ++i)
            if (value == m_data[i])
                return value;
        return 0;
    }

    void reallocate(int newLength) //4 Задание 1 часть. Изменить размер контейнера. Новая длинна;
    {
        erase(); //очищаем массив
        if (newLength <= 0) // если новая длина 0 или меньше заканчивыаем, вернется 0 и пустой указатель
            return;
        m_data = new X[static_cast<std::size_t>(newLength)]; // если новая длина не 0, создаем пустой массив новой длины
        m_length = newLength; //новая длина
    }

    void resize(int newLength) // 4 Задание 2 часть. Новый массив с измененной длиной
    {
        // Если заданная длина такая же, ничего не делаем
        if (newLength == m_length)
            return;

        if (newLength <= 0)
        {
            erase();
            return;
        }

        // Новый массив
        X* data{ new X[static_cast<std::size_t>(newLength)] };

        //Копируем
        if (m_length > 0)
        {
            int elementsToCopy{ (newLength > m_length) ? m_length : newLength };
            std::copy_n(m_data, elementsToCopy, data); // copy the elements
        }

        // Очищаем
        delete[] m_data;

        //Возвращаем
        m_data = data;
        m_length = newLength;
    }

    void insertBefore(int value, int index) //5 Задание. Вставить элемент
    {

        X* data{ new X[static_cast<std::size_t>(m_length + 1)] };

        std::copy_n(m_data, index, data);

        data[index] = value;

        std::copy_n(m_data + index, m_length - index, data + index + 1);

        delete[] m_data;
        m_data = data;
        ++m_length;
    }

    void remove(int index) // 6 Задание. Удалить элемент из контейнера.
    {
        //int l1;
        //    l1 = m_length;
        //if (l1 <= 0); // !!!!!!!!!!!!! если размерность массива нулевая выход из программы
        //{
        //    throw "bad_range";
        //}
        //if (l1 < index); // !!!!!!!!!!!!! если размерность массива нулевая выход из программы
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


    // Дополнительная часть 
    void insertAtBeginning(int value) { insertBefore(value, 0); } //Вставить элемент в начало
    void insertAtEnd(int value) { insertBefore(value, m_length); } //Вставить элемент в конец

};

#endif