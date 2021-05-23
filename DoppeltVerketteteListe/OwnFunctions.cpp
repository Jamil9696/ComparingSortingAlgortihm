#include "OwnFunctions.h"

int StdLibrary::convertStr2Int(const char*& ptr) {
    int val = 0;
    int place = 1;
    std::string duration;

    for (; *ptr != '\n' && *ptr >= '0' && *ptr <= '9'; ptr++) {
        duration += (*ptr - '0');
    }
    // skip \r\n (binary mode) \n std::ios::in
    ptr++;

    // z.b 198
    for (int i = duration.size() - 1; i >= 0; i--) {

        // val = val + 8  * 1 , val + val + 9 * 10, val = val + 1 * 100
        val += duration.at(i) * place;
        place *= 10;
    }
    return val;
}

int StdLibrary::convertStr2Int(std::string string) {
    string.push_back('\n');
    const char* c = &string.at(0);
    return convertStr2Int(c);
}

void StdLibrary::convertInt2Str(int val, char* buf, int size)
{
    char* const pStart = buf;
    char* const pEnd = buf + size;

    for (; val > 0 && (buf + 1 < pEnd); val /= 10, buf++) {
        *buf = '0' + val % 10;
    }

    *buf = 0;
}


std::string StdLibrary::substr(const char*& ptr)
{
    std::string string;
    for (; *ptr != '\n'; ptr++) {
        string += *ptr;
    }
    // skip \r\n (binary mode) \n std::ios::in
    ptr++;
    return string;
}

void StdLibrary::pauseProgramm(const char* string)
{
    std::cout << string;
    while (!_kbhit());
    system("cls");
}

std::string StdLibrary::readString()
{
    std::string string;
    for (char c = _getch(); c != 13; c = _getch())
    {
        string.push_back(c);
        _putch(c);
    }
    return string;
}

// won't work if a non terminated String has been passed through.
// There is no proper way of checking the validation of a string
void StdLibrary::strrev(std::string& string)
{
    char* pl = &string.at(0);
    strrev(pl);

}
void StdLibrary::strrev(char* c) {
    char* pl = c;
    char* pr = pl;
    for (; *pr != 0; pr++) {

    }
    pr--;

    for (; pl < pr; pr--, pl++) {
        const char temp = *pr;
        *pr = *pl;
        *pl = temp;
    }
}
int InputHandling::avoidWrongInputs(const char printedText[], int end, int start)
{
    std::cout << printedText << std::endl;
    int x;
    std::cin >> x;
    while (std::cin.fail() || x > end || x < start) {

        std::cout << "Wrong input: allowed Numbers between (" << start << " -" << end << ")\n";
        std::cin.clear(); //clear Input buffer ti restore cin to a usable stabe
        std::cin.ignore(INT_MAX, '\n'); // ignore last Input
        std::cout << "Nur Zahleneingaben sind erlaubt. \n";
        std::cout << "Geben Sie eine Zahl ein. \n";
        std::cin >> x;
    }
    return x;
}

void Test::detectMemoryLeak()
{
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
    _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
    _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);

    _CrtDumpMemoryLeaks();
}
