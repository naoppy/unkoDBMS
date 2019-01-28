#include "createTable.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void createTable() {
    char fileName[50], dbconfig[50], dbdata[50];
    printf("input new table name:");
    fflush(stdout);
    scanf("%s", fileName);
    sprintf(dbconfig, "db/%s.dbconfig", fileName);
    sprintf(dbdata, "db/%s.data", fileName);

    FILE *fp;
    if((fp = fopen(dbconfig, "r")) != NULL) {
        printf("this name's table is already exist!\n");
        return;
    }
    fclose(fp);

    FILE *raw = fopen(dbdata, "w");
    fclose(raw);

    FILE *config = fopen(dbconfig, "w");
    registMainKey(config);
    fclose(config);
    return;
}

void registMainKey(FILE *fp) {
    char columnName[100], t[30];
    long num = 0;
    char *type[50] = {
        "Int",
        "Double",
        "String",
    };
    const int LEN = 3;

    //0文字より長く、コロンを含まない形式のみOK
    printf("input Main-Key name");
    do {
        printf("waiting...>");
        fflush(stdout);
        scanf("%s", columnName);
    } while(strlen(columnName)==0 || strstr(columnName, ":")!=NULL);

    printf("input Main-key Type\n");
    for(size_t i = 0; i < LEN; i++) {
        printf("%d:%s\t", i+1, type[i]);
    }
    printf("\n");
    do {
        printf("waiting...>");
        fflush(stdout);
        scanf("%s", t);
        num = strtol(t, NULL, 10);
    } while(num < 1 || num > LEN);

    fprintf(fp, "%s:%s\n", columnName, t);

    return;
}