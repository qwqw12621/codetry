#include <stdio.h>
#include <string.h>

const char *haab_months[] = {
    "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol",
    "chen", "yax", "zac", "ceh", "mac", "kankin", "muan",
    "pax", "koyab", "cumhu", "uayet"
};

const char *tzolkin_days[] = {
    "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik",
    "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem",
    "cib", "caban", "eznab", "canac", "ahau"
};

int get_haab_month_index(const char *month) {
    int i;
	for (i = 0; i < 19; ++i) {
        if (strcmp(haab_months[i], month) == 0)
            return i;
    }
    return -1;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", n); // 輸出轉換後日期數

	int i;
    for (i = 0; i < n; ++i) {
        int day, year;
        char month[10];
        scanf("%d. %s %d", &day, month, &year);

        // 將 Haab 轉成總天數
        int month_index = get_haab_month_index(month);
        int total_days = year * 365 + month_index * 20 + day;

        // 將總天數轉成 Tzolkin
        int tz_day_num = total_days % 13 + 1;
        const char *tz_day_name = tzolkin_days[total_days % 20];
        int tz_year = total_days / 260;

        // 輸出結果
        printf("%d %s %d\n", tz_day_num, tz_day_name, tz_year);
    }

    return 0;
}

