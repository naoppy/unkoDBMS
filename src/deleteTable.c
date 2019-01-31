#include "deleteTable.h"
#include "showTables.h"
#include <stdio.h>
#include <string.h>

void deleteTable() {
    showDBlist();
    char fileName[100], dbconfig[100], dbdata[100];
    printf("input delete table name:");
    fflush(stdout);
    scanf("%s", fileName);
    sprintf(dbconfig, "db/%s.dbconfig", fileName);
    sprintf(dbdata, "db/%s.data", fileName);

    FILE *fp;
    if((fp = fopen(dbconfig, "r")) == NULL) {
        printf("this name's table is not exist\n%s\n", fileName);
        return;
    }
    fclose(fp);

    if(remove(dbconfig)!=0) {
        printf("something wrong. faild delete\n");
    }
    if(remove(dbdata)!=0) {
        printf("something wrong. faild delete\n");
    }
    
    return;
}