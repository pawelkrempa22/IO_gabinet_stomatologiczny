#include "pch.h"
#include "CppUnitTest.h"
#include "../Project3/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Project3Tests
{
    TEST_CLASS(Project3Tests)
    {
    public:
        TEST_METHOD(DodajWizyteTest)
        {
            Harmonogram harmonogram;

            harmonogram.DodajWizyte("2023-01-01", "12:00", "Pacjent A");
            harmonogram.DodajWizyte("2023-01-02", "14:30", "Pacjent B");

            // Test if DodajWizyte adds entries to the schedule
            Assert::AreEqual(static_cast<size_t>(2), harmonogram.Wizyty().size());
        }

        TEST_METHOD(WyswietlHarmonogramTest)
        {
            Harmonogram harmonogram;

            harmonogram.DodajWizyte("2023-01-01", "12:00", "Pacjent A");
            harmonogram.DodajWizyte("2023-01-02", "14:30", "Pacjent B");

            // Redirect cout to a stringstream
            std::stringstream buffer;
            std::streambuf* sbuf = std::cout.rdbuf();
            std::cout.rdbuf(buffer.rdbuf());

            // Call WyswietlHarmonogram() in your test
            harmonogram.WyswietlHarmonogram();

            // Restore cout's buffer
            std::cout.rdbuf(sbuf);

            // Test the output
            std::string expectedOutput = "Harmonogram Wizyt:\n"
                "Data: 2023-01-01, Godzina: 12:00, Pacjent: Pacjent A\n"
                "Data: 2023-01-02, Godzina: 14:30, Pacjent: Pacjent B\n";
            Assert::AreEqual(expectedOutput.c_str(), buffer.str().c_str());
        }

        TEST_METHOD(WyszukajWizytyDlaPacjentaTest)
        {
            Harmonogram harmonogram;

            harmonogram.DodajWizyte("2023-01-01", "12:00", "Pacjent A");
            harmonogram.DodajWizyte("2023-01-02", "14:30", "Pacjent B");
            harmonogram.DodajWizyte("2023-01-03", "10:00", "Pacjent A");

            // Redirect cout to a stringstream
            std::stringstream buffer;
            std::streambuf* sbuf = std::cout.rdbuf();
            std::cout.rdbuf(buffer.rdbuf());

            // Call WyszukajWizytyDlaPacjenta() in your test
            harmonogram.WyszukajWizytyDlaPacjenta("Pacjent A");

            // Restore cout's buffer
            std::cout.rdbuf(sbuf);

            // Test the output
            std::string expectedOutput = "Wizyty dla pacjenta Pacjent A:\n"
                "Data: 2023-01-01, Godzina: 12:00\n"
                "Data: 2023-01-03, Godzina: 10:00\n";
            Assert::AreEqual(expectedOutput.c_str(), buffer.str().c_str());
        }
    };
}