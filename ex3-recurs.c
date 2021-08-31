#include <stdio.h>
#include <locale.h>
/*Escreva programa que utilize uma fun��o recursiva capaz
de determinar quantas vezes um d�gito K ocorre em um n�mero inteiro positivo N. Tanto K
quanto N ser�o digitados pelo usu�rio. Por exemplo, o d�gito 2 ocorre 3 vezes em 762021192.
DICA: a fun��o recursiva deve tratar apenas um dos algarismos que formam o n�mero inteiro e
compar�-lo com o valor de K. A forma de chamar recursivamente a fun��o far� com que todos os
algarismos sejam analisados, um em cada chamada da fun��o.*/

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

	printf("Digite um n�mero inteiro positivo:\n");
	scanf("%d", &n);
	printf("Qual digito voc� deseja analisar?:\n");
	scanf("%d", &k);
	contf = Conta(n, k);
	printf("O d�gito %d ocorre %d vezes no n�mero %d\n", k, contf, n);	
	return 0;	
}
	
	
