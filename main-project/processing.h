#pragma once
#include <vector>

struct CallRecord {
    double cost;         // Стоимость разговора
    int durationSeconds; // Длительность в секундах
};

double calculateAverageCostPerSecond(const std::vector<CallRecord>& calls);