#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to calculate the difference between two times in minutes

int getDifferentTime(const char* date_str1, const char* date_str2) {
    struct tm time1, time2;

    // Parse date_str1
    sscanf(date_str1, "%d-%d-%d %d:%d:%d", &time1.tm_year, &time1.tm_mon, &time1.tm_mday, &time1.tm_hour, &time1.tm_min, &time1.tm_sec);
    time1.tm_year -= 1900; // Adjust for year starting from 1900
    time1.tm_mon -= 1;     // Adjust for month starting from 0

    // Parse date_str2
    sscanf(date_str2, "%d-%d-%d %d:%d:%d",&time2.tm_year, &time2.tm_mon, &time2.tm_mday, &time2.tm_hour, &time2.tm_min, &time2.tm_sec);
    time2.tm_year -= 1900;
    time2.tm_mon -= 1;

    // Convert struct tm to time_t
    time_t time_seconds1 = mktime(&time1);
    time_t time_seconds2 = mktime(&time2);

    time_t diffInSeconds = difftime(time_seconds2, time_seconds1);

    // Convert the time difference to minutes
    int diffInMinutes = (int)(diffInSeconds / 60);

    return diffInMinutes;
}

int main() {
    const char *timeStr1 = "2023-12-25 12:30:00";
    const char *timeStr2 = "2023-12-25 13:45:30";

    int diffInMinutes = compareDateTime(timeStr1, timeStr2);

    printf("Time difference: %d minutes\n", diffInMinutes);

    return 0;
}
