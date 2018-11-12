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
	if(flag == 0x44) printf("89 ");
	if(flag == 0x24) printf("8B ");
	if(flag == 0x42) printf("A3 ");
	if(flag == 0x14) printf("B8 ");
	if(flag == 0x12) printf("C7 ");
	
	return 1;	
}
