#include <stdio.h>
#include <stdlib.h>
#include "f_table.h"
#include "v_table.h"
#include "mem.h"
#include <string.h>

int main(){
	MemDat* mem;
	FTable* table;
	initFileTable(&table, 100);
    VTable* v_table;
	initVarTable(&v_table, 100);
	initMem(&mem, 100);
	File* file;
	file = (File*)malloc(sizeof(File));
	file->inoden = 0;
	file->f_size = 12;
	file->s_file = 0;
	file->t_file = 1;
	insertDat(&mem, file->s_file, file->f_size, serializeStr("/:\ndir1\ndir2"));
	insertFile(&table, &file, "/");
	int* content = getDat(mem, file->s_file, file->f_size);
	for(int i = file->s_file; i < file->f_size; i++){
		printf("0x%02x ", content[i]);
	}
	return 0;
}