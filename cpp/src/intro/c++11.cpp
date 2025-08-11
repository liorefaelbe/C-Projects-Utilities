#include <iostream>     // cout
#include <string>       // string
#include <algorithm>    // for_each
#include <array>        // array
#include <typeinfo>     // typeid

using namespace std;

enum class DayOfWeek {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};

/************************* Forward Declarations ************************/

void LowerToUpper(string str);
void PrintDays(void);
static string DayToString(DayOfWeek day);
void AutoEnigma(void);

/******************************* Main **********************************/

int main()
{
    // EX1
    LowerToUpper("Hello World");
    // EX2
    PrintDays();
    // EX4
    AutoEnigma();

    return (0);
}

/*************************** Implementations ***************************/

// EX1
void LowerToUpper(string str)
{
    cout << "\033[1mEX1:\033[0m\nOriginal text: " << str << endl;

    size_t changes = 0;

    auto l_toupper_count = [&changes](string& str)
    {
        for (char& c : str)
        {
            if (!isupper(c) && c != ' ')
            {
                c = toupper(c);
                ++changes;
            }
        }
    };

    l_toupper_count(str);

    cout << "Modified text: " << str << endl;
    cout << "Number of characters changed: " << changes << endl << endl;
}

// EX2
void PrintDays(void)
{
    cout << "\033[1mEX2:\033[0m\n";

    array<DayOfWeek, 7> days = { DayOfWeek::Sunday,
                                 DayOfWeek::Monday, 
                                 DayOfWeek::Tuesday, 
                                 DayOfWeek::Wednesday, 
                                 DayOfWeek::Thursday, 
                                 DayOfWeek::Friday, 
                                 DayOfWeek::Saturday };

    for (const auto day : days)
    {
        cout << DayToString(day);
        cout << ((day != days.back()) ? " | " : "\n");
    }
    cout << endl;
}

static string DayToString(DayOfWeek day) 
{
    switch(day) 
    {
        case DayOfWeek::Monday: return "Monday";
        case DayOfWeek::Tuesday: return "Tuesday";
        case DayOfWeek::Wednesday: return "Wednesday";
        case DayOfWeek::Thursday: return "Thursday";
        case DayOfWeek::Friday: return "Friday";
        case DayOfWeek::Saturday: return "Saturday";
        case DayOfWeek::Sunday: return "Sunday";
        default: return "Unknown";
    }
}

// EX4
void AutoEnigma(void)
{
    cout << "\033[1mEX3:\033[0m\n";

    auto a = []{ return []{ return (123); }; }()();
    auto b = !!sizeof("auto");
    auto c = &a;

    cout << "a: " << typeid(a).name() << endl;
    cout << "b: " << typeid(b).name() << endl;
    cout << "c: " << typeid(c).name() << endl;
}