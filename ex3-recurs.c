#include <stdio.h>
#include <locale.h>
/*Escreva programa que utilize uma função recursiva capaz
de determinar quantas vezes um dígito K ocorre em um número inteiro positivo N. Tanto K
quanto N serão digitados pelo usuário. Por exemplo, o dígito 2 ocorre 3 vezes em 762021192.
DICA: a função recursiva deve tratar apenas um dos algarismos que formam o número inteiro e
compará-lo com o valor de K. A forma de chamar recursivamente a função fará com que todos os
algarismos sejam analisados, um em cada chamada da função.*/

int cont = 0, digito;
int Conta(int num, int analisa){
	
	
	if(num == 0){
		return cont;
	}else if(num > 0){
		digito = num%10;
		
		num = num/10;
		if(digito == analisa){
			
			cont++;
		}
		num = Conta(num, analisa);
		return num;
	}
	
	
}
int main(){
	setlocale(LC_CTYPE, "Portuguese");
	int n, k, contf;

	printf("Digite um número inteiro positivo:\n");
	scanf("%d", &n);
	printf("Qual digito você deseja analisar?:\n");
	scanf("%d", &k);
	contf = Conta(n, k);
	printf("O dígito %d ocorre %d vezes no número %d\n", k, contf, n);	
	return 0;	
}
	
	
