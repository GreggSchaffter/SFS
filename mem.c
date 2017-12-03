#include <stdio.h>
#include <stdlib.h>
#include "mem.h"
#include <string.h>

void initMem(MemDat** table, int size){
	(*table) = (MemDat*)malloc(sizeof(MemDat));
	(*table)->dat = (int*)malloc(sizeof(int)*size);
	for(int i = 0; i < size; i++){
		(*table)->dat[i] = 0;
	}
}
void insertDat(MemDat** table, int s, int size, int* content){
	for(int i = s; i < size; i++){
		(*table)->dat[i] = content[i];
	}
}
int* getDat(MemDat* table, int s, int size){
	int* content = (int*)malloc(sizeof(int)*(size - s));
	for(int i = s; i < size; i++){
		content[i-s] = table->dat[i];
	}
	return content;
}
int* serializeStr(char* content){
	int* content_new = (int*)malloc(sizeof(int)*strlen(content));
	for(int i = 0; i < strlen(content); i++){
		content_new[i] = (int)content[i];
	}
	return content_new;
}