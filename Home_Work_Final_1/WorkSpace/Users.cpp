#include "Users.h"
#include <string>
#include <iostream>


Users::Users(std::string* name, std::string* password, int number)
{
    User_Name=name; //��� ������������
    User_Password= password; //������ ������������
    User_Number = number; //���������� ������������� � ����
}


std::string Users::getPassword(int id) //���������� ������ ������������
{
        return User_Password[id]; 
}

std::string Users::getName(int id) //���������� ��� ������������ �� ��������������
{
    return User_Name[id];
}

int Users::finduser(std::string currrentname) //���� ����� �� �����
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

