#include "Users.h"
#include <string>
#include <iostream>


Users::Users(std::string* name, std::string* password, int number)
{
    User_Name=name; //Имя пользователя
    User_Password= password; //Пароль пользователя
    User_Number = number; //Количество пользователей в базе
}


std::string Users::getPassword(int id) //Возвращаем пароль пользователя
{
        return User_Password[id]; 
}

std::string Users::getName(int id) //Возвращаем имя пользователя по идентификатору
{
    return User_Name[id];
}

int Users::finduser(std::string currrentname) //Ищем юзера по имени
{
    for (int i = 1; i <= User_Number; i++)
    {
        if (currrentname== User_Name[i-1])
            {
                return i;
            }
    }
    return 0;
}

