//Made by  for project2 CS-1714-0E5-202420 :)

#ifndef ROUTE_RECORDS_H
#define ROUTE_RECORDS_H
#include <stdio.h>
#define MAX_AIRPORT_CODE_LENGTH 4
#define MAX_AIRLINE_CODE_LENGTH 3
#define MONTHS 9



typedef enum SearchType { ROUTE, ORIGIN, DESTINATION, AIRLINE } SearchType;

// Structure to store route record data
    typedef struct {
    char origin[MAX_AIRPORT_CODE_LENGTH];
    //comign from
    char destination[MAX_AIRPORT_CODE_LENGTH];
    //going to
    char airline[MAX_AIRLINE_CODE_LENGTH];
    //brand codes
    int passengers[MONTHS];
    //9 months arrays
} RouteRecord;

RouteRecord* createRecords(FILE* fileIn);

int fillRecords(RouteRecord* records, FILE* fileIn);

int findAirlineRoute(RouteRecord* records, int length, const char* origin, const char* destination, const char* airline, int curIdx);

void searchRecords(RouteRecord* records, int length, const char* key1, const char* key2, SearchType st);

void printMenu();

#endif
