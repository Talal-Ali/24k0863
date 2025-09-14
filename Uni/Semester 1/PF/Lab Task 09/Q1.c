#include <stdio.h>
#include <time.h>

int calcFine(int d_day, int d_mon, int d_year, int r_day, int r_mon, int r_year) {
    time_t d_time = mktime(&(struct tm)	{.tm_mday = d_day, 
										.tm_mon = d_mon - 1, 
										.tm_year = d_year - 1900});
    time_t r_time = mktime(&(struct tm){.tm_mday = r_day, 
										.tm_mon = r_mon - 1, 
										.tm_year = r_year - 1900});
    
    int days_late = (int)(difftime(r_time, d_time) / (60 * 60 * 24));
    return days_late > 0 ? days_late * 2 : 0;
}

int main() {
    int d_day, d_mon, d_year, r_day, r_mon, r_year;

    printf("Enter the due date (day month year): ");
    scanf("%d %d %d", &d_day, &d_mon, &d_year);

    printf("Enter the return date (day month year): ");
    scanf("%d %d %d", &r_day, &r_mon, &r_year);

    int fine = calcFine(d_day, d_mon, d_year, r_day, r_mon, r_year);
    
    if (fine > 0) {
        printf("The item is %d days late. Total fine: $%d\n", fine / 2, fine);
    } else {
        printf("No fine. The item is returned on time.\n");
    }
    
}
