typedef struct f{
	int inoden;
	int s_file;
	int f_size;
    int t_file;
} File;

typedef struct f_table{
	File** table;
	int size;
} FTable;

void initFileTable(FTable**, int);
void insertFile(FTable**, File**, char*);
void pwd(FTable*);
File* getFile(FTable*, char*);