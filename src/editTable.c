#include "editTable.h"
#include "showTables.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

void selectTable() {
    while(true) {
        showDBlist();
        char DBname[100], dbconfig[100], dbdata[100];
        printf("input full DBname to edit, if you'll exit, put 'Q'>");
        do {
            printf("waiting...>");
            fflush(stdout);
            scanf("%s", DBname);
        } while(!searchDB_with_name(DBname) && strcmp(DBname, "Q")!=0);

        if(strcmp(DBname, "Q")==0) break;

        sprintf(dbconfig, "db/%s.dbconfig", DBname);
        sprintf(dbdata, "db/%s.data", DBname);
        FILE *fp_conf = fopen(dbconfig, "r"), *fp_data = fopen(dbdata, "a+");
        if(fp_conf == NULL || fp_data == NULL) {
           fprintf(stderr, "[error] DB-file coundn't open!");
           fflush(stderr);
           if(fp_conf != NULL) fclose(fp_conf);
           if(fp_data != NULL) fclose(fp_data);
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
        printf("input command [insert|delete|quit]>");
        fflush(stdout);
        scanf("%s", command);
        if(strcmp(command, "quit") == 0) break;
        if(strcmp(command, "insert") == 0) {
            //insertRow();
            int i;
            char *demiliter = ":";
            for(i = 0; i < SIZE; i++) {
                printf("name:%s, type:%s input>", columns[i], type[nums[i]-1]);
                fflush(stdout);
                scanf("%s", inputs);
                fprintf(data, inputs);
                if(i != SIZE - 1) fprintf(data, demiliter);
            }
            fprintf(data, "\n");
        } else if(strcmp(command, "delete") == 0) {
            //deleteRow();
        }
    }
    return;
}

//bool search_with_MainKey()