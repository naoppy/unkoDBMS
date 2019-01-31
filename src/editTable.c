#define HEADER "\t"

#include "editTable.h"
#include "showTables.h"
#include "createTable.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

void selectTable() {
    char DBname[100], dbconfig[100], dbdata[100];
    printf("%sinput full DBname to edit\n", HEADER);
    do {
        printWaiting();
        scanf("%s", DBname);
    } while(!searchDB_with_name(DBname));

    sprintf(dbconfig, "db/%s.dbconfig", DBname);
    sprintf(dbdata, "db/%s.data", DBname);
    FILE *fp_conf = fopen(dbconfig, "r"), *fp_data = fopen(dbdata, "a+");
    if(fp_conf == NULL || fp_data == NULL) {
        fprintf(stderr, "[error] DB-file coundn't open!");
        fflush(stderr);
        if(fp_conf != NULL) fclose(fp_conf);
        if(fp_data != NULL) fclose(fp_data);
       return;
    }

    editTable(fp_conf, fp_data);

    fclose(fp_conf);
    fclose(fp_data);
    return;
}

bool searchDB_with_name(char* wantName) {
    DIR *d;
    struct dirent *dir;
    d = opendir("./db");
    if(d==NULL) return false;
    
    while ((dir = readdir(d)) != NULL) {
        if(strstr(dir->d_name, ".dbconfig") == NULL) continue;

        if(strcmp(strtok(dir->d_name, "."), wantName) == 0) {
            closedir(d);
            return true;
        }
    }
    closedir(d);
    return false;
}

void editTable(FILE *conf, FILE *data) {
    //load dbconfig
    char columnName[50];
    int dataNum;
    char columns[50][50];
    int nums[50];
    int index = 0;
    while(fscanf(conf, "%[^:]:%d\n", columnName, &dataNum) != EOF) {
        strcpy(columns[index], columnName);
        nums[index++] = dataNum;
    }
    //
    
    const int SIZE = index;
    char *type[50] = {
        "Int",
        "Double",
        "String",
    };
    char command[50], inputs[50];

    while(true) {
        printf("input command [insert|delete|show|quit]>");
        fflush(stdout);
        scanf("%s", command);
        if(strcmp(command, "quit") == 0) break;
        else if(strcmp(command, "insert") == 0) {
            //insertRow();
            int i;
            char *demiliter = ":";
            for(i = 0; i < SIZE; i++) {
                printf("%sname:%s, type:%s input>", HEADER, columns[i], type[nums[i]-1]);
                fflush(stdout);
                scanf("%s", inputs);
                fprintf(data, inputs);
                if(i != SIZE - 1) fprintf(data, demiliter);
            }
            fprintf(data, "\n");
        } else if(strcmp(command, "delete") == 0) {
            //deleteRow();
        } else if(strcmp(command, "show") == 0) {
            //show();
        }
    }
    return;
}