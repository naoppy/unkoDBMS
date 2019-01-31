#include "showTables.h"
#include <stdio.h>
#include <dirent.h>
#include <string.h>

void showDBlist() {
    DIR *d;
    struct dirent *dir;
    d = opendir("./db");
    if (d == NULL) return;

    while ((dir = readdir(d)) != NULL) {
        if(strstr(dir->d_name, ".dbconfig") != NULL) {
            printf("%s\n", strtok(dir->d_name, "."));
        }
    }
    closedir(d);
    return;
}