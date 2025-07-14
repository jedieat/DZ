#include <iostream>
#include <string>
#include "Users.h"
#include "Message.h"


using namespace std;

int main()
{

    setlocale(LC_ALL, ""); // 

    string user_name;  //Имя пользователя
    string user_password; //Пароль пользователя

    cout << "==================================" << endl;
    cout << "Собираем базу пользователей" << endl;
    cout << "Введите количество пользователей:" << endl;
    int user_number; //
    cin >> user_number;

    string* all_user_name = new string[user_number]; //Массив с именами всех пользователей
    string* all_user_password = new string[user_number]; //Массив с именами всех пользователей
    int* all_user_age = new int[user_number]; //Массив с возрастом всех пользователей

    // В цикле по количеству заданных пользователей создаем массивы с данными    
    for (int i = 0; i < user_number; i++)
    {
        cout << "Введите имя пользователя " << i + 1 << endl;
        cin >> user_name;
        cout << "Введите пароль " << i + 1 << endl;
        cin >> user_password;

        all_user_name[i] = user_name;
        all_user_password[i] = user_password;
    }

    // Создаем базу введенных пользователей
    Users* x1 = new Users(all_user_name, all_user_password, user_number); //база всех юзеров

    try
    {
        // Логинимся
        string current_user;  //Логин
        string current_adress; //Адресат сообщения
        string current_password; //Пароль
        string current_message = "нет сообщений"; //Текущее сообщение
        Message<int> message(0); //Контейнер с сообщениями id пользователя
        Message<string> message_m(0);  //Контейнер с сообщениями текст сообщения
        Message<int> message_i(0); //id пользователя, который отправил
        int number_of_message; //Общее количество сообщений в контейнере
        int i_message; // Признак, что для пользователя есть сообщение


        for (int x = 1; x < 100; x++)
        {
            cout << "==================================" << endl;
            cout << "Верификация пользователя" << endl;
            cout << "Логин" << endl;
            cin >> current_user;
            int x2 = x1->finduser(current_user);  // находим пользователя
            if (x2 != 0)
            {
                cout << "Пароль" << endl;
                cin >> current_password;
                string d1 = x1->getPassword(x2 - 1); //определяем пароль пользователя
                if (d1 != current_password)
                {
                    cout << "Пароль неверный " << endl; //Пароль введен неправильно
                }
                else
                {
                    //Сначала выводим сообщения для этого пользователя
                    if (x > 1) //вторая итерация логина, сообщения уже были
                    {
                        number_of_message = message.getLength();
                        for (int i1 = 0; i1 < number_of_message; i1++)
                        {
                            if (message[i1] == x2)
                            {
                                int id_adress = message_i[i1] - 1; //идентификатор юзера, который отправил сообщение
                                cout << "Сообщение от(" << x1->getName(id_adress) << "):" << message_m[i1] << endl;  //текст соообщения
                                break;
                            }
                        }
                    }

                    //Теперь даем юзеру возможность написать сообщение
                    cout << "Кому отправить сообщение(введите имя адресата или all для групповой отправки)" << endl;
                    cin >> current_adress;
                    int x3 = x1->finduser(current_adress);  // находим идентификатор адресата
                    if (x3 != 0 || current_adress == "all") // есть такой пользователь или группа пользователей
                    {
                        cout << "Введите сообщение" << endl;
                        cin >> current_message;
                        if (current_adress == "all")
                        {
                            for (int i = 1; i <= user_number; i++)
                            {
                                message.insertAtBeginning(i);  //id юзера адресата
                                message_m.insertAtBeginning(current_message);  //текст соообщения
                                message_i.insertAtBeginning(x2); //id Отправитель сообщения
                            }
                        }
                        else
                        {
                            message.insertAtBeginning(x3); //id юзера адресата
                            message_m.insertAtBeginning(current_message);  //текст соообщения
                            message_i.insertAtBeginning(x2); //Отправитель сообщения
                        }

                    }

                    else
                    {
                        cout << "Пользователь не найден" << endl;
                    }

                }

            }
            else
            {
                cout << "Пользователь не найден " << endl;
            }
        }

    }
    catch (const char* exception)
    {
        cout << "Exception: " << exception << endl;
    }

    return 0;

}