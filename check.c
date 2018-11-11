#include "myas.h"

int is_valid(char *op, char *args)
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
	char* opland1[10],opland2[10] = NULL;	

	if (!strcmp(op,"MOV"))
		return 0;

	while(args[i] != ','){
		opland1[i] = args[i];
		i++;
	}
	i++;
	while(args[i] !=NULL)
		opland2[j] = args[i];
		i++;
		j++;
	}
 
	if (!check_opland(opland1))
		return 0;
	if (!check_opland(opland2))
		return 0;
	return 1;
}

int check_opland(char *opland)
{
	/*if opland is validated value return 1 else return 0*/
	
	if (opland[0] != '%' || opland[0] != '&' || opland[0] !='0')
		return 0;
	if (opland[0] == '0' && opland[1] != 'x')
		return 0;
	return 1;
}
