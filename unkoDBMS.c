#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "createTable.c"

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("less argument!\n");
        exit(1);
    }

    if(strcmp(argv[1], "Create") == 0) {
        createTable();
    } else if(strcmp(argv[1], "Delete") == 0) {

    } else if(strcmp(argv[1], "Edit") == 0) {

    }

    printf("done!\n");
}