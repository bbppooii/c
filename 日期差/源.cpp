#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int monthDays[13][2] = {
    {0, 0}, {31, 31}, {28, 29}, {31, 31}, {30, 30},
    {31, 31}, {30, 30}, {31, 31}, {31, 31}, {30, 30},
    {31, 31}, {30, 30}, {31, 31}
};
int isLeapYear(int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
int getTotalDays(int year, int month, int day) {
    int totalDays = 0;
    for (int i = 1583; i < year; i++) {
        totalDays += isLeapYear(i) ? 366 : 365;
    }
    for (int i = 1; i < month; i++) {
        totalDays += monthDays[i][isLeapYear(year)];
    }
    totalDays += day;
    return totalDays;
}
int main() {
    int y1, m1, d1, y2, m2, d2;
    while (scanf("%d %d %d", &y1, &m1, &d1) != EOF &&
        scanf("%d %d %d", &y2, &m2, &d2) != EOF) {
        int days1 = getTotalDays(y1, m1, d1);
        int days2 = getTotalDays(y2, m2, d2);
        printf("%d\n", days2 > days1 ? days2 - days1 : days1 - days2);
    }
    return 0;
}