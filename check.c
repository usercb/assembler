#include "myas.h"

unsigned char is_valid(char *op, char *args){

	int i = 0; 
	int j = 0;
	unsigned char op1_value, op2_value;
	unsigned char check = 0; // xxrmirmi - xx_op1_op2 
	char opland1[10],opland2[10];	
	char name[4][4] ={ {"not"},{"imm"},{"mem"},{"reg"}};
	if (!strcmp(op,"MOV")) // We handle only MOV commend
		return 0;
	printf ("op is %s\n",op);
	/* parshing  */
	while(args[i] != ','){
		opland1[i] = args[i];
		i++;
	}
	opland1[i] = NULL;
	i++;
	printf("opland 1 is  %s \n",opland1);
	while(args[i] !=NULL){
		opland2[j] = args[i];
		i++;
		j++;
	}
 	opland2[j] = NULL;
	printf("opland 2 is  %s \n",opland2);

	op1_value = check_opland(opland1);
	op2_value = check_opland(opland2);
	printf("op1_value is %s, op2_value is %s\n",name[op1_value],name[op2_value]);
	if (op1_value == 0) {
		return 0;
	}
	if (op2_value == 0){
		return 0;
	}

	check = (op1_value<<4)+(op2_value);

	printf("------------------\n");
	return check;
}

unsigned char check_opland(char* opland)
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
