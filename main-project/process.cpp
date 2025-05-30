#include "processing.h"

double calculateAverageCostPerSecond(const std::vector<CallRecord>& calls) {
    if (calls.empty()) return 0.0; // ������ ������

    double totalCost = 0.0;
    int totalSeconds = 0;

    for (const auto& call : calls) {
        totalCost += call.cost;
        totalSeconds += call.durationSeconds;
    }

    if (totalSeconds == 0) return 0.0; // ������ �� ������� �� 0

    return totalCost / totalSeconds; // ������� ��������� �� �������
}