#include "pch.h"
#include "CppUnitTest.h"
#include "../main-project/processing.h" // Подключаем наш заголовок

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
    TEST_CLASS(PhoneCallTests)
    {
    public:
        TEST_METHOD(TestBasicCalculation)
        {
            // Подготовили тестовые данные
            std::vector<CallRecord> calls;
            calls.push_back({ 30.0, 60 });   // 30 руб за 60 сек
            calls.push_back({ 60.0, 120 });  // 60 руб за 120 сек

            // Ожидаем: (30+60)/(60+120) = 90/180 = 0.5
            double result = calculateAverageCostPerSecond(calls);
            Assert::AreEqual(0.5, result, 0.001); // 0.001 - точность для double
        }

        TEST_METHOD(TestZeroDuration)
        {
            std::vector<CallRecord> calls;
            calls.push_back({ 15.0, 0 }); // Звонок с нулевой длительностью

            // Защита от деления на 0 - должен вернуть 0
            double result = calculateAverageCostPerSecond(calls);
            Assert::AreEqual(0.0, result, 0.001);
        }

        TEST_METHOD(TestEmptyList)
        {
            std::vector<CallRecord> calls; // Пустой список

            double result = calculateAverageCostPerSecond(calls);
            Assert::AreEqual(0.0, result, 0.001);
        }

        TEST_METHOD(TestFractionalResult)
        {
            std::vector<CallRecord> calls;
            calls.push_back({ 7.5, 30 }); // 7.5 руб за 30 сек
            calls.push_back({ 5.0, 20 }); // 5 руб за 20 сек

            // (7.5+5)/(30+20) = 12.5/50 = 0.25
            double result = calculateAverageCostPerSecond(calls);
            Assert::AreEqual(0.25, result, 0.001);
        }
    };
}