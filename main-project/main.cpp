#include <iostream>
#include <iomanip>
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
        cout << "***** Телефонный тариф *****\n\n";
        for (int i = 0; i < size; i++)
        {
            cout << "Номер: ";
            cout << subscriptions[i]->number << '\n';
            cout << "Дата звонка: ";
            cout << setw(2) << setfill('0') << subscriptions[i]->dt.day << '.';
            cout << setw(2) << setfill('0') << subscriptions[i]->dt.month << '.';
            cout << setw(4) << setfill('0') << subscriptions[i]->dt.year << '\n';
            cout << "Время начала: ";
            cout << setw(2) << setfill('0') << subscriptions[i]->start.hours << ':';
            cout << setw(2) << setfill('0') << subscriptions[i]->start.minutes << ':';
            cout << setw(2) << setfill('0') << subscriptions[i]->start.seconds << '\n';
            cout << "Продолжительность: ";
            cout << setw(2) << setfill('0') << subscriptions[i]->tm.hours << ':';
            cout << setw(2) << setfill('0') << subscriptions[i]->tm.minutes << ':';
            cout << setw(2) << setfill('0') << subscriptions[i]->tm.seconds << '\n';
            cout << "Тариф: ";
            cout << subscriptions[i]->tariff << '\n';
            cout << "Стоимость тарифа: ";
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