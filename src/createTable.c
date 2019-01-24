#include "createTable.h"
#include <stdio.h>
#include <string.h>

void createTable() {
    char fileName[50], dbconfig[50], dbdata[50];
    printf("input new table name:");
    fflush(stdout);
    scanf("%s", fileName);
    sprintf(dbconfig, "db/%s.dbconfig", fileName);
    sprintf(dbdata, "db/%s.data", fileName);

    if(fopen(dbconfig, "r") != NULL) {
        printf("this name's table is already exist!\n");
        return;
    }

    FILE *config = fopen(dbconfig, "w");
    FILE *raw = fopen(dbdata, "w");


    fclose(config);
    fclose(raw);
    return;
}