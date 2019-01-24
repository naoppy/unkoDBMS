#include "deleteTable.h"
#include <stdio.h>
#include <string.h>

void deleteTable() {
    char fileName[50], dbconfig[50];
    printf("input delete table name:");
    fflush(stdout);
    scanf("%s", fileName);
    sprintf(dbconfig, "db/%s.dbconfig", fileName);

    FILE *fp;
    if((fp = fopen(dbconfig, "r")) == NULL) {
        printf("this name's table is not exist\n%s\n", fileName);
        return;
    }
    fclose(fp);

    if(remove(dbconfig)!=0) {
        printf("something wrong. faild delete\n");
    }
    
    return;
}