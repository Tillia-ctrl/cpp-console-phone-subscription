#include <iostream>
#include <iomanip>
using namespace std;

#include "phone_subscription.h"
#include "file_reader.h"
#include "constants.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "������������ ������ �4. GIT\n";
    cout << "������� �9. ���������� �����\n";
    cout << "�����: ���������� ������\n\n";
    PhoneCall* subscriptions[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", subscriptions, size);
        cout << "***** ���������� ����� *****\n\n";
        for (int i = 0; i < size; i++)
        {
            cout << "�����: ";
            cout << subscriptions[i]->number << '\n';
            cout << "���� ������: ";
            cout << setw(2) << setfill('0') << subscriptions[i]->dt.day << '.';
            cout << setw(2) << setfill('0') << subscriptions[i]->dt.month << '.';
            cout << setw(4) << setfill('0') << subscriptions[i]->dt.year << '\n';
            cout << "����� ������: ";
            cout << setw(2) << setfill('0') << subscriptions[i]->start.hours << ':';
            cout << setw(2) << setfill('0') << subscriptions[i]->start.minutes << ':';
            cout << setw(2) << setfill('0') << subscriptions[i]->start.seconds << '\n';
            cout << "�����������������: ";
            cout << setw(2) << setfill('0') << subscriptions[i]->tm.hours << ':';
            cout << setw(2) << setfill('0') << subscriptions[i]->tm.minutes << ':';
            cout << setw(2) << setfill('0') << subscriptions[i]->tm.seconds << '\n';
            cout << "�����: ";
            cout << subscriptions[i]->tariff << '\n';
            cout << "��������� ������: ";
            cout << subscriptions[i]->cost << '\n';
            cout << '\n';
        }
        for (int i = 0; i < size; i++)
        {
            delete subscriptions[i];
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }
    return 0;
}