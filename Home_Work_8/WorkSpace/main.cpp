#include <iostream>
#include "IntArray.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, ""); // ����� ���������
    int x; // ������ ������ �����
    int x1; // ��� ����������
    cout << "������� ������ ����������" << endl;
    cin >> x ; // �������
    cout << "������� ��� ���������� 1-����� 2-�����" << endl;
    cin >> x1; // �������
    
    // ������ ���������
    try
    {
   
   
        IntArray<int> array(x);
    

    // ��������� ���������
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
    cout << "������� �������� � �����������." << endl;
    cout << "1- ����� �������� �������� ���������� �� �������" << endl;
    cout << "2- �������� ������ ����������." << endl;
    cout << "31 -�������� ������� � ������ ����������." << endl;
    cout << "32 -�������� ������� � ����� ����������." << endl;
    cout << "4- ������� ������� �� ����������" << endl;
    cin >> y; // 

    switch (y)
    {
    case 1:
        cout << "������� ������ �������� ����������" << endl;
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
        cout << "������� ����� ������ ����������" << endl;
        int d;
        cin >> d; // �������
        array.resize(d);
        break;
    case 31:
        cout << "������� �����, ������� ��������� � ������" << endl;
        int e;
        cin >> e; //
        array.insertAtBeginning(e);
        break;
    case 32:
        cout << "������� �����, ������� ��������� � �����" << endl;
        int e1;
        cin >> e1; //
        array.insertAtBeginning(e1);
        break;
    case 4:
        cout << "������� ��������� ����� ��������" << endl;
        int f;
        cin >> f; //
        array.remove(f-1);
        break;
    default:
        cout << "����������� ������ ��������" << endl;
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