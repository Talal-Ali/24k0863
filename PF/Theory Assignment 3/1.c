#include<stdio.h>
#include<string.h>
typedef struct date{
	int day;
	int month;
	int year;
}thisdate;

typedef struct employees {
	int employeeCode;
	char employeename[50];
	thisdate joinDate;
}employee;
employee e[4];

void Assign(int Code, char name[50], int jday, int jmonth, int jyear, int i) {
	e[i].employeeCode = Code;
	strcpy(e[i].employeename, name);
	e[i].joinDate.day = jday;
	e[i].joinDate.month = jmonth;
	e[i].joinDate.year = jyear;
}

void DateCalculation(int tday, int tmonth, int tyear) {
	int monthcarry[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	for (int i = 0; i < 4; i++) {
		int ddiff = tday - e[i].joinDate.day;
		int mdiff = tmonth - e[i].joinDate.month;
		int ydiff = tyear - e[i].joinDate.year;

		if (ddiff < 0) {
			if (tmonth == 3 && ((tyear % 4 == 0 && tyear % 100 != 0) || (tyear % 400 == 0)))
				ddiff += 29;
			else
				ddiff += monthcarry[tmonth - 2];
			mdiff--;
		}

		if (mdiff < 0) {
			mdiff += 12;
			ydiff--;
		}

		if (ydiff >= 3) {
			printf("%d %s %d %d %d\n", e[i].employeeCode, e[i].employeename, e[i].joinDate.day, e[i].joinDate.month, e[i].joinDate.year);
		}
	}
}

void Input() {
	int code, jday, jmonth, jyear;
	char name[50];
	for (int i = 0; i < 4; i++) {
		printf("Enter Employee Code:\n");
		scanf("%d", &code);
		printf("Enter name:\n");
		scanf("%s", name);
		printf("Enter Join Date (dd mm yyyy) e.g(10/10/2024):\n");
		scanf("%d %d %d", &jday, &jmonth, &jyear);
		Assign(code, name, jday, jmonth, jyear, i);
	}
}

int main() {
	int tday, tmonth, tyear;
	Input();
	printf("Enter Today's Date (dd mm yyyy) e.g (24/10/2024): ");
	scanf("%d %d %d", &tday, &tmonth, &tyear);
	DateCalculation(tday, tmonth, tyear);
}
