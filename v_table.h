typedef struct v{
	char* name;
	char* val;
	int type;
} Variable;

typedef struct v_table{
	Variable** table;
	int size;
} VTable;

void initVarTable(VTable**, int);
void insertVar(VTable**, Variable*);
Variable* getVar(VTable*, char*);