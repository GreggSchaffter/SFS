typedef struct mem_wrapper{
	int* dat;
} MemDat;

void initMem(MemDat**, int);
void insertDat(MemDat**, int, int, int*);
int* getDat(MemDat*, int, int);
int* serializeStr(char*);