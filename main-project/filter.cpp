#include "filter.h"
#include <cstring>
#include <iostream>

PhoneCall** filter(PhoneCall* array[], int size, bool (*check)(PhoneCall* element), int& result_size)
{
	PhoneCall** result = new PhoneCall * [size];
	result_size = 0;
	for (int i = 0; i < size; i++)
	{
		if (check(array[i]))
		{
			result[result_size++] = array[i];
		}
	}
	return result;
}

bool fMobileCalls(PhoneCall* element)
{
	return strcmp(element->tariff, "мобильный") == 0;
}

bool fNovember2021Calls(PhoneCall* element)
{
	return element->dt.month == 11 && element->dt.year == 2021;
}
