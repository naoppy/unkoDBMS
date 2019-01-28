#include "createTable.h"
#include "deleteTable.h"
#include "listTable.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("less argument!\n");
        exit(1);
    }

    if(strcmp(argv[1], "Create") == 0) {
        createTable();
    } else if(strcmp(argv[1], "Delete") == 0) {
        deleteTable();
    } else if(strcmp(argv[1], "Edit") == 0) {
        showTables();
    }

    printf("done!\n");
}