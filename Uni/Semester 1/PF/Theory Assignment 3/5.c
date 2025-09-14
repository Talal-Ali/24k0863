#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char*** initialise(int max, int nitems) {
    char*** speciesSupplies = (char***)malloc(max * sizeof(char**));
    
    for (int i = 0; i < max; i++) {
        speciesSupplies[i] = NULL;
    }
    return speciesSupplies;
}

void addSupplies(char*** speciesSupplies, int* specount, int max) {
    if (*specount >= max) {
        printf("Maximum species limit reached!\n");
        return;
    }

    char species_name[100];
    printf("Enter the species name: ");
    fgets(species_name, sizeof(species_name), stdin);
    species_name[strcspn(species_name, "\n")] = '\0';

    int num_supplies;
    printf("Enter the number of supplies: ");
    scanf("%d", &num_supplies);
    while (getchar() != '\n'); 
    char supplies[1000] = ""; 
    for (int i = 0; i < num_supplies; i++) {
        char supply[100];
        printf("Enter supply %d: ", i + 1);
        fgets(supply, sizeof(supply), stdin);
        supply[strcspn(supply, "\n")] = '\0';

        
        strcat(supplies, supply);
        if (i < num_supplies - 1) {
            strcat(supplies, ", ");
        }
    }

    speciesSupplies[*specount] = (char**)malloc(2 * sizeof(char*));
    speciesSupplies[*specount][0] = strdup(species_name);
    speciesSupplies[*specount][1] = strdup(supplies);

    (*specount)++;
    printf("Species and supplies added successfully!\n");
}


void updateSupply(char*** speciesSupplies, int specount) {
    char name[100];
    printf("Enter species name to update supplies: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    for (int i = 0; i < specount; i++) {
        if (strcmp(name, speciesSupplies[i][0]) == 0) {
            printf("Enter the updated supplies: ");
            char new_supplies[100];
            fgets(new_supplies, sizeof(new_supplies), stdin);
            new_supplies[strcspn(new_supplies, "\n")] = '\0';

            free(speciesSupplies[i][1]);
            speciesSupplies[i][1] = strdup(new_supplies);

            printf("Supplies updated successfully!\n");
            return;
        }
    }
    printf("Species not found!\n");
}


void removeSpecies(char*** speciesSupplies, int* specount) {
    if (*specount == 0) {
        printf("No species to remove.\n");
        return;
    }

    char name[100];
    printf("Enter species name to remove: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    for (int i = 0; i < *specount; i++) {
        if (strcmp(name, speciesSupplies[i][0]) == 0) {
            free(speciesSupplies[i][0]);
            free(speciesSupplies[i][1]);
            free(speciesSupplies[i]);

            for (int j = i; j < *specount - 1; j++) {
                speciesSupplies[j] = speciesSupplies[j + 1];
            }

            speciesSupplies[*specount - 1] = NULL;
            (*specount)--;

            printf("Species removed successfully!\n");
            return;
        }
    }
    printf("Species not found!\n");
}


void displayInventory(char*** speciesSupplies, int specount) {
    if (specount == 0) {
        printf("Inventory is empty!\n");
        return;
    }

    printf("\nCurrent Inventory:\n");
    for (int i = 0; i < specount; i++) {
        printf("Species: %s\n", speciesSupplies[i][0]);
        printf("Supplies: %s\n", speciesSupplies[i][1]);
        printf("\n");
    }
}

int main() {
    int max = 5;
    int specount = 0;
    int choice;

    char*** speciesSupplies = initialise(max, 100);
    

    while (1) {
        printf("\n1. Add Species and Supplies\n");
        printf("2. Update Supplies\n");
        printf("3. Remove Species\n");
        printf("4. Display Inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                addSupplies(speciesSupplies, &specount, max);
                break;
            case 2:
                updateSupply(speciesSupplies, specount);
                break;
            case 3:
                removeSpecies(speciesSupplies, &specount);
                break;
            case 4:
                displayInventory(speciesSupplies, specount);
                break;
            case 5:
                for (int i = 0; i < specount; i++) {
                    free(speciesSupplies[i][0]);
                    free(speciesSupplies[i][1]);
                    free(speciesSupplies[i]);
                }
                free(speciesSupplies);
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}