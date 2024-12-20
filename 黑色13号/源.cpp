#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int isLeapYear(int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
int main() {
    int n;
    scanf("%d", &n);
    int daysOfWeek[7] = { 0 };
    int dayOfWeek = 1;
    for (int year = 1900; year < 1900 + n; year++) {
        for (int month = 1; month <= 12; month++) {
            // 13号对应的星期几，记录当前星期几
            daysOfWeek[dayOfWeek]++;
            int daysInMonth;
            if (month == 2) {
                daysInMonth = isLeapYear(year) ? 29 : 28;
            }
            else if (month == 4 || month == 6 || month == 9 || month == 11) {
                daysInMonth = 30;
            }
            else {
                daysInMonth = 31;
            }
            dayOfWeek = (dayOfWeek + daysInMonth) % 7;
        }
    }
    for (int i = 6; i >= 0; i--) {
        if (i != 6) {
            printf(" ");
        }
        printf("%d", daysOfWeek[i]);
    }
    printf("\n");

    return 0;
}

