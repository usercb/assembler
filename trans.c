#include "myas.h"

int instr_trans(char *op, char *args, char* mcode)
{
	unsigned char flag;
	// check syntax 

	flag = is_valid(op,args);
	if(flag =='0'){
		printf("Error: %s %s is not valid\n", op, args);
		return 0;
	}
	if(flag == 0x33) strcpy(mcode,"89");
	if(flag == 0x23) strcpy(mcode,"8B");
	if(flag == 0x32) strcpy(mcode,"A3");
	if(flag == 0x13) strcpy(mcode,"B8");
	if(flag == 0x12) strcpy(mcode,"C7");
	
	return 1;	
}
