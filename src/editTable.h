#pragma once

#include <stdbool.h>
#include <stdio.h>

void selectTable();
void editTable(FILE *fp1, FILE *fp2);
bool searchDB_with_name(char* wantName);