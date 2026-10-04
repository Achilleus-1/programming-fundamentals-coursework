//Made by  for project2 CS-1714-0E5-202420 :)

#include "route-records.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // 1. Declare variables here
    FILE* fileIn;
    RouteRecord* records;
    int recordCount;


    // 2. Check command line arguments here. If a command line argument (for the file name) is missing, print out the following: ERROR: Missing file name and end the program
    if (argc<2) {
        printf("ERROR: Missing file name\n");
        return -1;
    }


    // 3. Attempt to open the file. Print out Opening <filename>... before you call fopen().
    printf("Opening %s...\n", argv[1]);
    fileIn = fopen(argv[1], "r");
    // 4. Check to see if the file opens. If it does not open, print out ERROR: Could not open file and end the program.
    if (!fileIn) {
        printf("ERROR: Could not open file\n");
        return -2;
    }

    // 5. Do the following to load the records into an array of RouteRecords
    records = createRecords(fileIn); // 5.1 Call createRecords()
    recordCount = fillRecords(records, fileIn); // 5.2 Call fillRecords()
    printf("Unique routes operated by airlines: %d\n", recordCount); // Print the number of unique routes operated by different airlines
    fclose(fileIn); // 5.3 Close the file
    // 6. Create an infinite loop that will do the following:
    while (1) {
        int selection;
        char key1[4], key2[4];
        printMenu(); // 6.1 Call printMenu()/6.2

        printf("Enter your selection: ");
        if(scanf("%d", &selection) != 1) { // 6.3 Handle the case in which a non-integer value is entered
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n');
            continue;
        }



        // 6.4 Create a switch/case statement to handle all the menu options
        switch(selection) {
            case 1: // ROUTE !!!
                printf("Enter origin: ");
                scanf("%3s", key1);
                printf("Enter destination: ");
                scanf("%3s", key2);
                searchRecords(records, recordCount, key1, key2, ROUTE);
                break;

                case 2: // ORIGIN !
                printf("Enter origin: ");
                scanf("%3s", key1);
                searchRecords(records, recordCount, key1, NULL, ORIGIN);
                break;

            case 3: // Final Destination
                printf("Enter destination: ");
                scanf("%3s", key1);
                searchRecords(records, recordCount, key1, NULL, DESTINATION);
                break;

            case 4: // Airplane food
                printf("Enter airline: ");
                scanf("%3s", key1);
                searchRecords(records, recordCount, key1, NULL, AIRLINE);
                break;

            case 5: // bye bye!!!!
                free(records);
                printf("bye bye!!!!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}
