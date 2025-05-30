#pragma once
#include <vector>

struct CallRecord {
    double cost;         // ��������� ���������
    int durationSeconds; // ������������ � ��������
};

double calculateAverageCostPerSecond(const std::vector<CallRecord>& calls);