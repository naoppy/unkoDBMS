#include "editTable.h"
#include "showTables.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

void editTable() {
    showDBlist();
    char DBname[100], dbconfig[50], dbdata[50];
    printf("input full DBname to edit>");
    do {
        printf("waiting...>");
        fflush(stdout);
        scanf("%s", DBname);
    } while(!searchDB_with_name(DBname));

    sprintf(dbconfig, "db/%s.dbconfig", DBname);
    sprintf(dbdata, "db/%s.data", DBname);
    FILE *fp_conf = fopen(dbconfig, "r"), *fp_data = fopen(dbdata, "w");

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
        if(strstr(dir->d_name, ".dbconfig") == NULL) { continue; }

        if(strcmp(strtok(dir->d_name, "."), wantName) == 0) {
            return true;
        }
    }
    closedir(d);
    
    return false;
}