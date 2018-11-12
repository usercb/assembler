#include "myas.h"

unsigned char is_valid(char *op, char *args)
{
	//printf("if valid, return 1\n");
	//printf("otherwise, return 0\n");

	/********************************/
    /*  							*/
	/*         syntax check         */
    /*  							*/
	/********************************/
	int i = 0; 
	int j = 0;
	unsigned char check = 0; // xxrmirmi - xx_op1_op2 
	char* opland1[10],opland2[10] = NULL;	

	if (!strcmp(op,"MOV")) // We handle only MOV commend
		return 0;

	/* parshing  */
	while(args[i] != ','){
		opland1[i] = args[i];
		i++;
	}
	opland1[i] = NULL;
	i++;

	while(args[i] !=NULL)
		opland2[j] = args[i];
		i++;
		j++;
	}
 	opland2[j] = NULL;
	if (check_opland(opland1) == '0')
		return 0;
	if (check_opland(opland2) == '0')
		return 0;
	check = (check_opland(opland1)<<3)+(check_opland(opland2));
	 
	return check;
}

unsigned char check_opland(char *opland)
{
	/*reg is 0x3 mem is 0x2 imm is 0x1
	  This project is toy project so we don't think complex exception */
	int i =0; 

	if (opland[0] == '$') return 0x1;
	if (opland[0] == '0' && opland[1] == 'x') return 0x2;
	if (opland[0] == '%') return 0x3;
	
	while (opland[i] != NULL) {
		if (opland[i] == '(' && opland[i+1] == '%')
			return 0x2; 
		i++;
	}
	
	return 0;
}
