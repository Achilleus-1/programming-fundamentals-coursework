//Made by  for project2 CS-1714-0E5-202420 :)

#include "route-records.h"
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024 // creates temp input area
//i found out about buffers and theyre sm easier to use than function imo

RouteRecord* createRecords (FILE* fileIn) {
    char buffer[BUFFER_SIZE];
        int count = 0;

    // Skip header
     fgets(buffer, BUFFER_SIZE, fileIn);

    // count (no no header)
    while (fgets (buffer, BUFFER_SIZE, fileIn) != NULL) {
        count++;
    }
    RouteRecord* records = (RouteRecord*)malloc(sizeof(RouteRecord) * count);
    if (!records) {
        fprintf ( stderr, "Memory allocation  failed\n");
        return NULL;
    }

   //start of the countin
    for (int i = 0; i < count; i++) {
            memset(records[i].passengers, 0, sizeof(records[i].passengers));
    }
    rewind(fileIn);
    fgets(buffer , BUFFER_SIZE,  fileIn);   // Skip header line again
    return records;
}


int fillRecords(RouteRecord* records, FILE* fileIn) {
    char buffer[BUFFER_SIZE];
    int recordIndex = 0;
    while (fgets(buffer, BUFFER_SIZE, fileIn) != NULL) {
        int month, passengers;
        char origin[MAX_AIRPORT_CODE_LENGTH], destination[MAX_AIRPORT_CODE_LENGTH], airline[MAX_AIRLINE_CODE_LENGTH];

//time to touch csv
        sscanf(buffer, "%d,%3s,%3s,%2s,%d", &month, origin, destination, airline, &passengers);
        if (strlen(airline) != 2) continue;
          int index = findAirlineRoute(records, recordIndex, origin, destination, airline, 0);
        if (index != -1) {
            records[index].passengers[month - 1] += passengers;
        }  else {
            strncpy(records[recordIndex].origin, origin, MAX_AIRPORT_CODE_LENGTH - 1);

            strncpy(records[recordIndex].destination, destination, MAX_AIRPORT_CODE_LENGTH - 1);

            strncpy(records[recordIndex].airline, airline, MAX_AIRLINE_CODE_LENGTH - 1);

            records[recordIndex].passengers[month - 1] = passengers;

            recordIndex++;
        }
    }

    return recordIndex; // it working
}


int findAirlineRoute(RouteRecord* records, int length, const char* origin, const char* destination, const char* airline, int curIdx) {
    if (curIdx >= length) {
        return -1; // omg its discrete math
    }
    if (strcmp(records[curIdx].origin, origin) == 0 &&
         strcmp(records[curIdx].destination, destination) == 0 &&
                strcmp(records[curIdx].airline, airline) == 0) {
        return curIdx;
    }
    return findAirlineRoute(records, length, origin, destination, airline, curIdx + 1); //recursive
}

void searchRecords(RouteRecord* records, int length, const char* key1, const char* key2, SearchType st) {
    int totalPassengers = 0, matchesFound = 0;
    int monthlyPassengers[9] = {0};

    for (int i = 0; i < length; ++i) {
        // detective work
        int match = 0;
        switch (st) {
            case ROUTE:
                match = (strcmp(records[i].origin, key1) == 0 && strcmp(records[i].destination, key2) == 0);
                break;

            case ORIGIN:
                    match = (strcmp(records[i].origin, key1) == 0);
                    break;

            case DESTINATION:
                match = (strcmp(records[i].destination, key1) == 0);
                break;

            case AIRLINE:
                match = (strcmp(records[i].airline, key1) == 0);
                break;

        }
        if (match) {
            printf("%s (%s-%s)\n", records[i].airline, records[i].origin, records[i].destination);
            for (int m = 0; m < 9; ++m) {
                totalPassengers += records[i].passengers[m];
                    monthlyPassengers[m] += records[i].passengers[m];
            }

             matchesFound++;
        }
    }



    if (matchesFound > 0) {
        // the fun part (writing it out)
        printf("\n%d matches were found \n", matchesFound);
        printf("\nStatistics\n");
        printf("Total Passengers: %d\n", totalPassengers);
        for (int m=0; m<9; ++m) {
            printf("Total Passengers in Month %d: %d\n", m + 1, monthlyPassengers[m]);
        }
        printf("\nAverage Passengers per Month: %d\n", totalPassengers / 9);
    } else {
        printf("No matches were found\n");
    }
}


void printMenu() {
    printf("\n\n######### Airline Route Records Database MENU #########\n");
    printf("1. Search by Route\n");
    printf("2. Search by Origin Airport\n");
    printf("3. Search by Destination Airport\n");
    printf("4. Search by Airline\n");
    printf("5. Quit\n");
    printf("Enter your selection: ");
}
