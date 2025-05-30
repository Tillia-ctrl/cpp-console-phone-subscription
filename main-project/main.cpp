#include <iostream>
#include <iomanip>
using namespace std;

#include "phone_subscription.h"
#include "file_reader.h"
#include "constants.h"
#include "filter.h"
#include "sort.h"
void output(PhoneCall* subscriptions) {
    cout << "***** Телефонный тариф *****\n\n";
    
        cout << "Номер: ";
        cout << subscriptions->number << '\n';
        cout << "Дата звонка: ";
        cout << setw(2) << setfill('0') << subscriptions->dt.day << '.';
        cout << setw(2) << setfill('0') << subscriptions->dt.month << '.';
        cout << setw(4) << setfill('0') << subscriptions->dt.year << '\n';
        cout << "Время начала: ";
        cout << setw(2) << setfill('0') << subscriptions->start.hours << ':';
        cout << setw(2) << setfill('0') << subscriptions->start.minutes << ':';
        cout << setw(2) << setfill('0') << subscriptions->start.seconds << '\n';
        cout << "Продолжительность: ";
        cout << setw(2) << setfill('0') << subscriptions->tm.hours << ':';
        cout << setw(2) << setfill('0') << subscriptions->tm.minutes << ':';
        cout << setw(2) << setfill('0') << subscriptions->tm.seconds << '\n';
        cout << "Тариф: ";
        cout << subscriptions->tariff << '\n';
        cout << "Стоимость тарифа: ";
        cout << subscriptions->cost << '\n';
        cout << '\n';
    
}
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
        
        
        bool (*check_function)(PhoneCall*) = NULL;
        CompareFunc comp = NULL;
        int typesortchoice = 0;
        int sortchoice = 0;
        int filterchoice = 0;
        int choice = 0;
        do {
            cout << "\nМеню:\n";
            cout << "1. Фильтрация\n";
            cout << "2. Сортировка пирамидальная\n";
            cout << "3. Сортировка быстрая\n";
            cout << "0. Выход\n";
            cout << "Выберите действие: ";
            cin >> choice;

            PhoneCall* result[MAX_FILE_ROWS_COUNT];
            int result_size;

            switch (choice) {
            case 1: 
                cout << "\nВыберите фильтр:\n";
                cout << "1. Мобильный звонок\n";
                cout << "2. Ноябрь 21 года\n";
                cout << "Выберите действие: ";
                cin >> filterchoice;
                if (filterchoice == 1) check_function = fMobileCalls;
                if (filterchoice == 2) check_function = fNovember2021Calls;
                filterchoice = 0;
                break;
            case 2:
                cout << "\nВыберите критерий:\n";
                cout << "1. Убывание продолжительности разговора\n";
                cout << "2. Возрастание номера телефона\n";
                cout << "Выберите действие: ";
                typesortchoice = 1;
                cin >> sortchoice;
                if (sortchoice == 1) comp = compare_by_duration_desc;
                if (sortchoice == 2) comp = compare_by_phone_asc_cost_desc;
                sortchoice = 0;
                break;
            case 3:
                cout << "\nВыберите критерий:\n";
                cout << "1. Убывание продолжительности разговора\n";
                cout << "2. Возрастание номера телефона\n";
                cout << "Выберите действие: ";
                typesortchoice = 2;
                cin >> sortchoice;
                if (sortchoice == 1) comp = compare_by_duration_desc;
                if (sortchoice == 2) comp = compare_by_phone_asc_cost_desc;
                sortchoice = 0;
                break;
            case 0:
                cout << "Выход из программы." << endl;
                break;
            default:
                cout << "Неверный выбор. Попробуйте снова." << endl;
            }
            if (check_function)
            {
                int new_size;
                PhoneCall** filtered = filter(subscriptions, size, check_function, new_size);
                for (int i = 0; i < new_size; i++)
                {
                    output(filtered[i]);
                }
                delete[] filtered;
            }
            if (typesortchoice == 1) {
                heap_sort(subscriptions, size, comp);
                for (int i = 0; i < size; i++)
                {
                    output(subscriptions[i]);
                }
            }
            if (typesortchoice == 2) {
                quick_sort(subscriptions, size, comp);
                for (int i = 0; i < size; i++)
                {
                    output(subscriptions[i]);
                }
            }
            typesortchoice = 0;

        } while (choice != 0);
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