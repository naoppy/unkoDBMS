#include "createTable.h"
#include "deleteTable.h"
#include "showTables.h"
#include "editTable.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    showDBlist();
    char command[50];
    do {
        printf("[input command [Create|Delete|Edit|Show] or 'q'\n");
        printf("[waiting...>");
        fflush(stdout);
        scanf("%s", command);
        if(strcmp(command, "q")==0) break;
        else if(strcmp(command, "Create")==0) {
            createTable();
        } else if(strcmp(command, "Delete")==0) {
            deleteTable();
        } else if(strcmp(command, "Edit")==0) {
            selectTable();
        } else if(strcmp(command, "Show")==0) {
            showDBlist();
        }
        printf("\n");
    } while (true);
    
    return 0;
}