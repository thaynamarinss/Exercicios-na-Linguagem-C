#include <stdio.h>

int main()
{
	char r1, r2, r3, r4, r5, r6;
	int contV=0, contP=0;
	//entrada
	scanf("%c\n %c\n %c\n %c\n %c\n %c", &r1, &r2, &r3, &r4, &r5, &r6);

	
	if(r1=='V'){
		contV = contV+1;
	}else if (r1 == 'P'){
		contP = contP+1;
	}
	
	if(r2=='V'){
		contV = contV+1;
	}else if(r2 == 'P'){
		contP = contP+1;
	}
	
	if(r3=='V'){
		contV = contV+1;
	}else if(r3 == 'P'){
		contP = contP+1;
	}
	
	if(r4=='V'){
		contV = contV+1;
	}else if (r4 == 'P'){
		contP = contP+1;
	}
	
	if(r5=='V'){
		contV = contV+1;
	}else if (r5 == 'P'){
		contP = contP+1;
	}
	
	if(r6=='V'){
		contV = contV+1;
	}else if (r6 == 'P'){
		contP = contP+1;
	}
	if(contV==5 || contV==6){
		int grupo = 1;
		printf("%d\n", grupo);
	}else if(contV==3 || contV==4){
		int grupo = 2;
		printf("%d\n", grupo);
	}else if(contV==1 || contV==2){
		int grupo = 3;
		printf("%d\n", grupo);
	}else{
		int grupo = -1;
		printf("%d\n", grupo);	
	}

	
	return 0;
}
