#include "file_reader.h"
#include "constants.h"

#include <fstream>
#include <cstring>

date convertdate(char* str)
{
    date result;
    char* context = NULL;
    char* str_number = strtok_s(str, ".", &context);
    result.day = atoi(str_number);
    str_number = strtok_s(NULL, ".", &context);
    result.month = atoi(str_number);
    str_number = strtok_s(NULL, ".", &context);
    result.year = atoi(str_number);
    return result;
}
period convertperiod(char* str)
{
    period result;
    char* context = NULL;
    char* str_number = strtok_s(str, ":", &context);
    result.hours = atoi(str_number);
    str_number = strtok_s(NULL, ":", &context);
    result.minutes = atoi(str_number);
    str_number = strtok_s(NULL, ":", &context);
    result.seconds = atoi(str_number);
    return result;
}

void read(const char* file_name, PhoneCall* array[], int& size)
{
    std::ifstream file(file_name);
    if (file.is_open())
    {
        size = 0;
        char tmp_buffer[MAX_STRING_SIZE];
        while (!file.eof())
        {
            PhoneCall* item = new PhoneCall;
            file >> item->number;
            file >> tmp_buffer;
            item->dt = convertdate(tmp_buffer);
            file >> tmp_buffer;
            item->start = convertperiod(tmp_buffer);
            file >> tmp_buffer;
            item->tm = convertperiod(tmp_buffer);
            file >> item->tariff;
            file >> item->cost;
            file.read(tmp_buffer, 1); // чтения лишнего символа пробела
            array[size++] = item;
        }
        file.close();
    }
    else
    {
        throw "Ошибка открытия файла";
    }
}