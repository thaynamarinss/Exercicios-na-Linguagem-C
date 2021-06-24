#include <stdio.h>

int main()
{
	
	int M, A, B, C;
	
	//printf("Digite a idade da dona Monica:\n");
	scanf("%d", &M);	
	//printf("Digite a idade de um dos filhos de Monica:\n");
	scanf("%d", &A);	
	//printf("Digite a idade de outro filho de Monica:\n");
	scanf("%d", &B);
	
	C = M-A-B;

	if (C>A && C>B)
	{
		printf("%d\n",C);
	}else if (A>C && A>B){
		printf("%d\n", A);
	}else{
		printf("%d\n", B);
	}
	return 0;
}
