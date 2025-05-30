#ifndef PHONE_CALLS_H
#define PHONE_CALLS_H
#include "phone_subscription.h"


// ��������� ������� ����������
typedef void (*SortFunc)(PhoneCall**, int, int (*)(PhoneCall*, PhoneCall*));
typedef int (*CompareFunc)(PhoneCall*, PhoneCall*);

// ������� ���������
int compare_by_duration_desc(PhoneCall* a, PhoneCall* b);
int compare_by_phone_asc_cost_desc(PhoneCall* a, PhoneCall* b);

// ��������������� �������
void swap(PhoneCall** a, PhoneCall** b);

// ������� ����������
void heap_sort(PhoneCall** arr, int n, CompareFunc compare);
void quick_sort(PhoneCall** arr, int n, CompareFunc compare);


#endif // PHONE_CALLS_H
