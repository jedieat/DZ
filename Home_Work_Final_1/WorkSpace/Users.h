#include <string>

#pragma once
    class Users

    {
    public:
        //Конструкторы
        Users() = default;
        Users(std::string* name, std::string* password, int number);

        // Геттеры 
        std::string getPassword(int id);
        std::string getName(int id);
        
        //Поиск юзера по Имени
        int finduser(std::string);
        

    private:
        std::string* User_Name; //Имя 
        std::string* User_Password; //Пароль
        int User_Number;
        int id;
    };




