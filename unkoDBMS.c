#include "createTable.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("less argument!\n");
        exit(1);
    }

    if(strcmp(argv[1], "Create") == 0) {
        printf("Create\n");
        createTable();
    } else if(strcmp(argv[1], "Delete") == 0) {
        printf("Delete\n");
    } else if(strcmp(argv[1], "Edit") == 0) {
        printf("Edit\n");
    }

    printf("done!\n");
}