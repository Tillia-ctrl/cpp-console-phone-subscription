#include <iostream>

using namespace std;

#include "phone_subscription.h"
#include "file_reader.h"
#include "constants.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Лабораторная работа №4. GIT\n";
    cout << "Вариант №9. Телефонный тариф\n";
    cout << "Автор: Меньшикова Полина\n\n";
    PhoneCall* subscriptions[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", subscriptions, size);
        for (int i = 0; i < size; i++)
        {
            cout << subscriptions[i]->number << '\n';
            cout << subscriptions[i]->dt.day << '.';
            cout << subscriptions[i]->dt.month << '.';
            cout << subscriptions[i]->dt.year << '\n';
            cout << subscriptions[i]->start.hours << ':';
            cout << subscriptions[i]->start.minutes << ':';
            cout << subscriptions[i]->start.seconds << '\n';
            cout << subscriptions[i]->tm.hours << ':';
            cout << subscriptions[i]->tm.minutes << ':';
            cout << subscriptions[i]->tm.seconds << '\n';
            cout << subscriptions[i]->tariff << '\n';
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