#include <iostream>
#include <iomanip>
using namespace std;

#include "phone_subscription.h"
#include "file_reader.h"
#include "constants.h"
#include "filter.h"
#include "sort.h"
void output(PhoneCall* subscriptions) {
    cout << "***** ���������� ����� *****\n\n";
    
        cout << "�����: ";
        cout << subscriptions->number << '\n';
        cout << "���� ������: ";
        cout << setw(2) << setfill('0') << subscriptions->dt.day << '.';
        cout << setw(2) << setfill('0') << subscriptions->dt.month << '.';
        cout << setw(4) << setfill('0') << subscriptions->dt.year << '\n';
        cout << "����� ������: ";
        cout << setw(2) << setfill('0') << subscriptions->start.hours << ':';
        cout << setw(2) << setfill('0') << subscriptions->start.minutes << ':';
        cout << setw(2) << setfill('0') << subscriptions->start.seconds << '\n';
        cout << "�����������������: ";
        cout << setw(2) << setfill('0') << subscriptions->tm.hours << ':';
        cout << setw(2) << setfill('0') << subscriptions->tm.minutes << ':';
        cout << setw(2) << setfill('0') << subscriptions->tm.seconds << '\n';
        cout << "�����: ";
        cout << subscriptions->tariff << '\n';
        cout << "��������� ������: ";
        cout << subscriptions->cost << '\n';
        cout << '\n';
    
}
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
        
        
        bool (*check_function)(PhoneCall*) = NULL;
        CompareFunc comp = NULL;
        int typesortchoice = 0;
        int sortchoice = 0;
        int filterchoice = 0;
        int choice = 0;
        do {
            cout << "\n����:\n";
            cout << "1. ����������\n";
            cout << "2. ���������� �������������\n";
            cout << "3. ���������� �������\n";
            cout << "0. �����\n";
            cout << "�������� ��������: ";
            cin >> choice;

            PhoneCall* result[MAX_FILE_ROWS_COUNT];
            int result_size;

            switch (choice) {
            case 1: 
                cout << "\n�������� ������:\n";
                cout << "1. ��������� ������\n";
                cout << "2. ������ 21 ����\n";
                cout << "�������� ��������: ";
                cin >> filterchoice;
                if (filterchoice == 1) check_function = fMobileCalls;
                if (filterchoice == 2) check_function = fNovember2021Calls;
                filterchoice = 0;
                break;
            case 2:
                cout << "\n�������� ��������:\n";
                cout << "1. �������� ����������������� ���������\n";
                cout << "2. ����������� ������ ��������\n";
                cout << "�������� ��������: ";
                typesortchoice = 1;
                cin >> sortchoice;
                if (sortchoice == 1) comp = compare_by_duration_desc;
                if (sortchoice == 2) comp = compare_by_phone_asc_cost_desc;
                sortchoice = 0;
                break;
            case 3:
                cout << "\n�������� ��������:\n";
                cout << "1. �������� ����������������� ���������\n";
                cout << "2. ����������� ������ ��������\n";
                cout << "�������� ��������: ";
                typesortchoice = 2;
                cin >> sortchoice;
                if (sortchoice == 1) comp = compare_by_duration_desc;
                if (sortchoice == 2) comp = compare_by_phone_asc_cost_desc;
                sortchoice = 0;
                break;
            case 0:
                cout << "����� �� ���������." << endl;
                break;
            default:
                cout << "�������� �����. ���������� �����." << endl;
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