#include <stdio.h>
#include <stdlib.h>
#include "v_table.h"
#include <string.h>

void initVarTable(VTable** table, int size){
	(*table) = (VTable*)malloc(sizeof(VTable));
	(*table)->table = (Variable**)malloc(sizeof(Variable*)*size);
	(*table)->size = size;
	for(int i = 0; i < size; i++){
		(*table)->table[i] = 0;
	}
}

int hashVar(char* str, VTable* table){
	int sum = 0;
	for(int i = 0; i < strlen(str); i++){
		sum += str[i]*(i+1);
	}
	return sum % table->size;
}

void insertVar(VTable** table, Variable* f){
	int hash_val = hashVar(f->name, (*table)) % (*table)->size;
	if(!(*table)->table[hash_val]){
		(*table)->table[hash_val] = f;
	}
	else{
		while((*table)->table[hash_val]){
			hash_val = (hash_val + 1) % (*table)->size;
		}
		(*table)->table[hash_val] = f;
	}
}

Variable* getVar(VTable* table, char* name){
	int hash_val = hashVar(name, table);
	while(strcmp(table->table[hash_val]->name, name) != 0){
		hash_val = (hash_val + 1) % table->size;
	}
	return table->table[hash_val];
}
