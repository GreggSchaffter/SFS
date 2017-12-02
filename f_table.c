#include <stdio.h>
#include <stdlib.h>
#include "f_table.h"
#include <string.h>

void initFileTable(FTable** table, int size){
	(*table) = (FTable*)malloc(sizeof(FTable));
	(*table)->table = (File**)malloc(sizeof(File*)*size);
	(*table)->size = size;
	for(int i = 0; i < size; i++){
		(*table)->table[i] = 0;
	}
}

int hashFile(char* str, FTable* table){
	int sum = 0;
	for(int i = 0; i < strlen(str); i++){
		sum += str[i]*(i+1);
	}
	return sum % table->size;
}

void insertFile(FTable** table, File** f, char* name){
	int hash_val = hashFile(name, (*table)) % (*table)->size;
	if(!(*table)->table[hash_val]){
		(*f)->inoden = hash_val;
		(*table)->table[hash_val] = (*f);
	}
	else{
		while((*table)->table[hash_val]){
			hash_val = (hash_val + 1) % (*table)->size;
		}
		(*f)->inoden = hash_val;
		(*table)->table[hash_val] = (*f);
	}
}

File* getFile(FTable* table, char* name){
	int hash_val = hashFile(name, table);
	while(!table->table[hash_val] && table->table[hash_val]->inoden != hash_val){
		hash_val = (hash_val + 1) % table->size;
	}
	return table->table[hash_val];
}

void pwd(FTable* table){
    for(int i = 0; i < table->size; i++){
        if(table->table[i]){
            printf("%s\t", table->table[i]->inoden);
        }
    }
}