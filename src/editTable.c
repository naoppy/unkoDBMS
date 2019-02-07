#define HEADER "\t"

#include "editTable.h"
#include "showTables.h"
#include "createTable.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

char DBname[100], dbconfig[100], dbdata[100];

void selectTable() {
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
                //keyの重複はダメ
                if(i == 0) {
                    char c[200];
                    sprintf(c, "grep -E '^%s:' %s > ./db/TMP.txt", inputs, dbdata);
                    system(c);

                    if(!isEmptyFile()) {
                        printf("%s[error] Main-key must not overlap!\n", HEADER);
                        fflush(stdout);
                        goto WHILE_LOOP;
                    }
                }
                fprintf(data, inputs);
                if(i != SIZE - 1) fprintf(data, demiliter);
            }
            fprintf(data, "\n");
            fflush(data);
        } else if(strcmp(command, "delete") == 0) {
            char word[200];
            //0文字より長く、コロンを含まない形式のみOK
            printf("%sinput delete column's main key name\n", HEADER);
            do {
                printWaiting();
                scanf("%s", word);
            } while(strlen(word)==0 || strstr(word, "*")!=NULL || strstr(word, ".")!=NULL);

            char c[200], c2[200];
            sprintf(c, "sed -e \"/^%s:/d\" %s > ./db/TMP.txt", word, dbdata);
            sprintf(c2, "cp ./db/TMP.txt %s", dbdata);
            system(c);
            system(c2);
        } else if(strcmp(command, "show") == 0) {
            char c[200];
            sprintf(c, "cat %s | sed \"s/:/ /g\"", dbdata);
            system(c);
        }
        WHILE_LOOP:
        ;
    }
    return;
}

bool isEmptyFile() {
    bool b = false;
    FILE *fp;
    fp = fopen("./db/TMP.txt", "r");
    if(fgetc(fp) == EOF) {
        b = true;
    }
    fclose(fp);
    return b;
}