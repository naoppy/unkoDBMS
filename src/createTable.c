#define HEADER "\t"

#include "createTable.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void createTable() {
    char fileName[50], dbconfig[50], dbdata[50];
    printf("%sinput new table name>", HEADER);
    fflush(stdout);
    scanf("%s", fileName);
    sprintf(dbconfig, "db/%s.dbconfig", fileName);
    sprintf(dbdata, "db/%s.data", fileName);

    FILE *fp;
    if((fp = fopen(dbconfig, "r")) != NULL) {
        printf("this name's table is already exist!\n");
        fclose(fp);
        return;
    }
    fclose(fp);

    FILE *raw = fopen(dbdata, "w");
    fclose(raw);

    FILE *config = fopen(dbconfig, "w");
    registMainKey(config);
    fclose(config);

    printf("created\n");
    return;
}

void registMainKey(FILE *fp) {
    char columnName[100], t[30];
    long num = 0;
    const int LEN = 3;

    //0文字より長く、コロンを含まない形式のみOK
    printf("%sinput Main-Key name\n", HEADER);
    do {
        printWaiting();
        scanf("%s", columnName);
    } while(strlen(columnName)==0 || strstr(columnName, ":")!=NULL);

    printf("%sinput Main-key Type\n", HEADER);
    printTypes();
    do {
        printWaiting();
        scanf("%s", t);
        num = strtol(t, NULL, 10);
    } while(num < 1 || num > LEN);

    fprintf(fp, "%s:%s\n", columnName, t);


    while(true) {
        //0文字より長く、コロンを含まない形式のみOK
        printf("%sinput Column name, if finish, input 'q'\n", HEADER);
        do {
            printWaiting();
            scanf("%s", columnName);
        } while(strlen(columnName)==0 || strstr(columnName, ":")!=NULL);

        if(strcmp(columnName, "q") == 0) {
            break;
        }

        printf("%sinput Column Type\n", HEADER);
        printTypes();
        do {
            printWaiting();
            scanf("%s", t);
            num = strtol(t, NULL, 10);
        } while(num < 1 || num > LEN);

        fprintf(fp, "%s:%s\n", columnName, t);
    }

    return;
}

void printWaiting() {
    printf("waiting...>");
    fflush(stdout);
}
void printTypes() {
    char *type[50] = {
        "Int",
        "Double",
        "String",
    };
    const int LEN = 3;

    for(size_t i = 0; i < LEN; i++) {
        printf("\t%d:%s  ", i+1, type[i]);
    }
    printf("\n");
}