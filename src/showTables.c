#include "showTables.h"
#include <stdio.h>
#include <dirent.h>

void showDBlist() {
    DIR *dir;
	struct dirent *dp;
	char path[64] = "./db";

	dir=opendir(path);

	for(dp=readdir(dir);dp!=NULL;dp=readdir(dir)){
		printf("%s\n",dp->d_name);
	}

	closedir(dir);
	return;
}