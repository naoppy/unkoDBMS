#include "editTable.h"
#include "showTables.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

void selectTable() {
    while(true) {
        showDBlist();
        char DBname[100], dbconfig[50], dbdata[50];
        printf("input full DBname to edit, if you'll exit, put 'Q'>");
        do {
            printf("waiting...>");
            fflush(stdout);
            scanf("%s", DBname);
        } while(!(searchDB_with_name(DBname)||strcmp(DBname, "Q")==0));

        if(strcmp(DBname, "Q")==0) break;

        sprintf(dbconfig, "db/%s.dbconfig", DBname);
        sprintf(dbdata, "db/%s.data", DBname);
        FILE *fp_conf = fopen(dbconfig, "r"), *fp_data = fopen(dbdata, "w");
        if(fp_conf == NULL || fp_data == NULL) {
           fprintf(stderr, "[error] DB-file coundn't open!");
            exit(1);
        }

        editTable(fp_conf, fp_data);

        fclose(fp_conf);
        fclose(fp_data);
    }
    return;
}

bool searchDB_with_name(char* wantName) {
    DIR *d;
    struct dirent *dir;

    d = opendir("./db");
    if(d==NULL) return false;
    
    while ((dir = readdir(d)) != NULL) {
        if(strstr(dir->d_name, ".dbconfig") == NULL) { continue; }

        if(strcmp(strtok(dir->d_name, "."), wantName) == 0) {
            return true;
        }
    }
    closedir(d);
    
    return false;
}

void editTable(FILE *conf, FILE *data) {
    char columnName[50];
    int dataNum;
    char* columns[50];
    int nums[50];
    int index = 0;
    while(fscanf(conf, "%s:%d", columnName, &dataNum) != EOF) {
        strcpy(columns[index], columnName);
        nums[index++] = dataNum;
    }
    
    const int SIZE = index;

    while(true) {
        
    }
    return;
}