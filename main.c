#include <stdio.h>
#include <stdlib.h>
#include "f_table.h"
#include "v_table.h"
#include <string.h>

int main(){
	FTable* table;
	initFileTable(&table, 100);
    VTable* v_table;
	initVarTable(&v_table, 100);
	FILE *fp, *fd;
	File* file;
	file = (File*)malloc(sizeof(File));
	file->inoden = 0;
	file->f_size = 0;
	file->s_file = 0;
	file->t_file = 1;
	insertFile(&table, &file, "myfolder");
	printf("%i", getFile(table, "myfolder")->inoden);
	return 0;
}