#include <string>

#pragma once
    class Users

    {
    public:
        //������������
        Users() = default;
        Users(std::string* name, std::string* password, int number);

        // ������� 
        std::string getPassword(int id);
        std::string getName(int id);
        
        //����� ����� �� �����
        int finduser(std::string);
        

    private:
        std::string* User_Name; //��� 
        std::string* User_Password; //������
        int User_Number;
        int id;
    };




