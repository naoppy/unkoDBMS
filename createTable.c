#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void createTable() {
    char fileName[50];
    printf("input new table name:");
    scanf("%s", fileName);
    if(fopen(strcat(fileName, ".dbconfig"), "r") != NULL) {
        printf("this name's table is already exist!\n");
        return;
    }

    FILE *config = fopen(strcat(fileName, ".dbconfig"), "w");
    FILE *raw = fopen(strcat(fileName, ".data"), "w");


    fclose(config);
    fclose(raw);
}