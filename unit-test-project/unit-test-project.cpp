#include "pch.h"
#include "CppUnitTest.h"
#include "../main-project/processing.h" // ���������� ��� ���������

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
    TEST_CLASS(PhoneCallTests)
    {
    public:
        TEST_METHOD(TestBasicCalculation)
        {
            // ����������� �������� ������
            std::vector<CallRecord> calls;
            calls.push_back({ 30.0, 60 });   // 30 ��� �� 60 ���
            calls.push_back({ 60.0, 120 });  // 60 ��� �� 120 ���

            // �������: (30+60)/(60+120) = 90/180 = 0.5
            double result = calculateAverageCostPerSecond(calls);
            Assert::AreEqual(0.5, result, 0.001); // 0.001 - �������� ��� double
        }

        TEST_METHOD(TestZeroDuration)
        {
            std::vector<CallRecord> calls;
            calls.push_back({ 15.0, 0 }); // ������ � ������� �������������

            // ������ �� ������� �� 0 - ������ ������� 0
            double result = calculateAverageCostPerSecond(calls);
            Assert::AreEqual(0.0, result, 0.001);
        }

        TEST_METHOD(TestEmptyList)
        {
            std::vector<CallRecord> calls; // ������ ������

            double result = calculateAverageCostPerSecond(calls);
            Assert::AreEqual(0.0, result, 0.001);
        }

        TEST_METHOD(TestFractionalResult)
        {
            std::vector<CallRecord> calls;
            calls.push_back({ 7.5, 30 }); // 7.5 ��� �� 30 ���
            calls.push_back({ 5.0, 20 }); // 5 ��� �� 20 ���

            // (7.5+5)/(30+20) = 12.5/50 = 0.25
            double result = calculateAverageCostPerSecond(calls);
            Assert::AreEqual(0.25, result, 0.001);
        }
    };
}