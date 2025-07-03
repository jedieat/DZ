#include <iostream>
#include "IntArray.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, ""); // смена кодировки
    int x; // задаем первое число
    int x1; // тип контейнера
    cout << "Задайте размер контейнера" << endl;
    cin >> x ; // Размера
    cout << "Задайте тип контейнера 1-число 2-буквы" << endl;
    cin >> x1; // Размера
    
    // Задаем контейнер
    try
    {
   
   
        IntArray<int> array(x);
    

    // Заполняем контейнер
        if (x1 == 1)
        {
            for (int i{ 0 }; i < x; ++i)
                array[i] = i + 1;
        }
        else
        {
            IntArray<string> array(x);
            for (int i{ 0 }; i <x; ++i)
            {
                if (i < x-1)
                    array[i] = 'a' + i; //'\0'
                else
                    array[i] = 'a\0';
                cout << array[i];
            }
        }

    int y; // 
    cout << "Задайте операцию с контейнером." << endl;
    cout << "1- Найти Значение элемента контейнера по индексу" << endl;
    cout << "2- Изменить размер контейнера." << endl;
    cout << "31 -Вставить элемент в начало контейнера." << endl;
    cout << "32 -Вставить элемент в конец контейнера." << endl;
    cout << "4- Удалить элемент из контейнера" << endl;
    cin >> y; // 

    switch (y)
    {
    case 1:
        cout << "Задайте индекс элемента контейнера" << endl;
        char z1;
        int z;
        if (x1 == 1)
        {
            cin >> z; //
            cout << array.find(z) << endl;
        }
        else
        {
            cin >> z1; //
            cout << array.find(z1) << endl;
        }
        return 0;
        break; 
    case 2:
        cout << "Задайте новый размер контейнера" << endl;
        int d;
        cin >> d; // Размера
        array.resize(d);
        break;
    case 31:
        cout << "Задайте число, которое добавляем в начало" << endl;
        int e;
        cin >> e; //
        array.insertAtBeginning(e);
        break;
    case 32:
        cout << "Задайте число, которое добавляем в конец" << endl;
        int e1;
        cin >> e1; //
        array.insertAtBeginning(e1);
        break;
    case 4:
        cout << "Задайте удаляемый номер элемента" << endl;
        int f;
        cin >> f; //
        array.remove(f-1);
        break;
    default:
        cout << "Неправильно задана операция" << endl;
        return 0;
    }

    for (int i{ 0 }; i < array.getLength(); ++i)
        std::cout << array[i] << ' ';
    std::cout << '\n';
    return 0;

    }
    catch (const char* exception)
    {
        cout << "Exception: " << exception << endl;
    }

}