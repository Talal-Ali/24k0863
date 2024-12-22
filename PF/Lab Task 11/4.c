#include <stdio.h>
#include <string.h>

struct Passenger {
    int passengerId;
    int survived;
    int pClass;
    char name[100];
    char sex[10];
    float age;
    int sibSp;
    int parch;
    char ticket[20];
    float fare;
    char cabin[20];
    char embarked[2];
};

float calculateAverageAge(struct Passenger passengers[], int count) {
    float totalAge = 0;
    int validAgeCount = 0;
    
    for (int i = 0; i < count; i++) {
        if (passengers[i].age > 0) {
            totalAge += passengers[i].age;
            validAgeCount++;
        }
    }
    
    return totalAge / validAgeCount;
}

void calculateSurvivalRate(struct Passenger passengers[], int count) {
    int maleSurvivors = 0, maleTotal = 0;
    int femaleSurvivors = 0, femaleTotal = 0;
    
    for (int i = 0; i < count; i++) {
        if (strcmp(passengers[i].sex, "male") == 0) {
            maleTotal++;
            if (passengers[i].survived) maleSurvivors++;
        } else {
            femaleTotal++;
            if (passengers[i].survived) femaleSurvivors++;
        }
    }
    
    printf("Male Survival Rate: %.2f%%\n", (float)maleSurvivors/maleTotal * 100);
    printf("Female Survival Rate: %.2f%%\n", (float)femaleSurvivors/femaleTotal * 100);
}

void displaySurvivors(struct Passenger passengers[], int count) {
    printf("Name\t\tAge\tClass\n");
    for (int i = 0; i < count; i++) {
        if (passengers[i].survived) {
            printf("%s\t%.1f\t%d\n", 
                passengers[i].name, 
                passengers[i].age, 
                passengers[i].pClass);
        }
    }
}

void displayMissingCabins(struct Passenger passengers[], int count) {
    printf("Name\t\tTicket\n");
    for (int i = 0; i < count; i++) {
        if (strlen(passengers[i].cabin) == 0 || strcmp(passengers[i].cabin, "NA") == 0) {
            printf("%s\t%s\n", 
                passengers[i].name, 
                passengers[i].ticket);
        }
    }
}

int main() {
    struct Passenger passengers[1000];
    int passengerCount = 0;
    FILE *file;
    char line[1024];
    
    file = fopen("titanic.csv", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    
    fgets(line, sizeof(line), file);
    
    
    while (fscanf(file, "%d,%d,%d,\"%[^\"]\",\"%[^\"]\",%f,%d,%d,%[^,],%f,%[^,],%s",
            &passengers[passengerCount].passengerId,
            &passengers[passengerCount].survived,
            &passengers[passengerCount].pClass,
            passengers[passengerCount].name,
            passengers[passengerCount].sex,
            &passengers[passengerCount].age,
            &passengers[passengerCount].sibSp,
            &passengers[passengerCount].parch,
            passengers[passengerCount].ticket,
            &passengers[passengerCount].fare,
            passengers[passengerCount].cabin,
            passengers[passengerCount].embarked) == 12) {
        passengerCount++;
    }
    
    fclose(file);
    
    printf("Average Age: %.2f\n", calculateAverageAge(passengers, passengerCount));
    calculateSurvivalRate(passengers, passengerCount);
    printf("\nSurvivors List:\n");
    displaySurvivors(passengers, passengerCount);
    printf("\nPassengers with Missing Cabin Details:\n");
    displayMissingCabins(passengers, passengerCount);
    
}

