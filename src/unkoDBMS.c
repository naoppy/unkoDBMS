#include "createTable.h"
#include "deleteTable.h"
#include "showTables.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("less argument!\n");
        printf("e.g. unkoDBMS [Create|Delete|Edit|Show]");
        exit(1);
    }

    if(strcmp(argv[1], "Create") == 0) {
        createTable();
    } else if(strcmp(argv[1], "Delete") == 0) {
        deleteTable();
    } else if(strcmp(argv[1], "Edit") == 0) {

    } else if(strcmp(argv[1], "Show") == 0) {
        showDBlist();
    }

    printf("done!\n");
}