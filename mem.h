typedef struct mem_wrapper{
	int* dat;
} MemDat;

void initMem(MemDat**, int);
void insertDat(MemDat**, File*);