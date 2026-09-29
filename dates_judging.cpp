#include <iostream>

using namespace std;

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}//闰年判断

int daysInMonth(int year, int month) {
    static const int days[] = {0, 31, 28, 31, 30, 31, 30,
                               31, 31, 30, 31, 30, 31};
    return month == 2 && isLeapYear(year) ? 29 : days[month];
}//获取某年某月的天数

bool isValidDate(int year, int month, int day) {
    return year >= 1 && month >= 1 && month <= 12 &&
           day >= 1 && day <= daysInMonth(year, month);
}//判断日期是否合法

long long getTotalDays(int year, int month, int day) {
    const long long completedYears = year - 1LL;
    long long totalDays = completedYears * 365 + completedYears / 4 -
                          completedYears / 100 + completedYears / 400;

    for (int currentMonth = 1; currentMonth < month; ++currentMonth) {
        totalDays += daysInMonth(year, currentMonth);
    }
    return totalDays + day;
}//获取从公元1年1月1日到指定日期的总天数

int main() {
    int year = 0;
    int month = 0;
    int day = 0;

    if (!(cin >> year >> month >> day)) {
        cerr << "Invalid input: please enter year month day." << endl;
        return 1;
    }
    if (!isValidDate(year, month, day)) {
        cerr << "Invalid date." << endl;
        return 1;
    }

    long long startDays = getTotalDays(1990, 1, 1);
    long long targetDays = getTotalDays(year, month, day);
    int cycleDay = static_cast<int>(((targetDays - startDays) % 5 + 5) % 5);

    cout << (cycleDay <= 2 ? "打鱼" : "晒网") << endl;
    return 0;
}
