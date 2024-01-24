#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>


void getDate(char cur[20]){
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  sprintf(cur, "%d-%02d-%02d %02d:%02d:%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
}

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

int main(){
    char start[22];
    char end[22];
    getDate(start);
    sleep(72);
    getDate(end);
    printf("%d\n", getDifferentTime(start,end));
}