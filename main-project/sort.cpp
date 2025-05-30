#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"



// Прототипы функций сортировки
typedef void (*SortFunc)(PhoneCall**, int, int (*)(PhoneCall*, PhoneCall*));
typedef int (*CompareFunc)(PhoneCall*, PhoneCall*);

// Функции сравнения
int compare_by_duration_desc(PhoneCall* a, PhoneCall* b) {
    // Сравниваем по убыванию длительности звонка (tm)
    int a_total = a->tm.hours * 3600 + a->tm.minutes * 60 + a->tm.seconds;
    int b_total = b->tm.hours * 3600 + b->tm.minutes * 60 + b->tm.seconds;
    return b_total - a_total;
}

int compare_by_phone_asc_cost_desc(PhoneCall* a, PhoneCall* b) {
    // Сравниваем по номеру телефона (возрастание), затем по стоимости (убывание)
    int phone_cmp = strcmp(a->number, b->number);
    if (phone_cmp != 0) {
        return phone_cmp;
    }
    return (b->cost > a->cost) ? 1 : -1;
}

// Вспомогательная функция для обмена указателей
void swap(PhoneCall** a, PhoneCall** b) {
    PhoneCall* temp = *a;
    *a = *b;
    *b = temp;
}

// Пирамидальная сортировка (Heap Sort)
void heapify(PhoneCall** arr, int n, int i, CompareFunc compare) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && compare(arr[left], arr[largest]) > 0) {
        largest = left;
    }

    if (right < n && compare(arr[right], arr[largest]) > 0) {
        largest = right;
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest, compare);
    }
}

void heap_sort(PhoneCall** arr, int n, CompareFunc compare) {
    // Построение кучи
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, compare);
    }

    // Извлечение элементов из кучи
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0, compare);
    }
}

// Быстрая сортировка (Quick Sort)
int partition(PhoneCall** arr, int low, int high, CompareFunc compare) {
    PhoneCall* pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (compare(arr[j], pivot) <= 0) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quick_sort_recursive(PhoneCall** arr, int low, int high, CompareFunc compare) {
    if (low < high) {
        int pi = partition(arr, low, high, compare);
        quick_sort_recursive(arr, low, pi - 1, compare);
        quick_sort_recursive(arr, pi + 1, high, compare);
    }
}

void quick_sort(PhoneCall** arr, int n, CompareFunc compare) {
    quick_sort_recursive(arr, 0, n - 1, compare);
}

