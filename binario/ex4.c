#include "stdio.h"
#include <locale.h>
/*Uma matriz de tamanho 8x8 de números inteiros
foi armazenada em um arquivo binário “matriz.bin” (os 8 primeiros números
representam a primeira linha, os 8 números seguintes representam a segunda linha e
assim por diante). Cada posição da matriz contém os valores inteiros 0 ou 1. O valor 1
corresponde à posição de uma rainha na matriz (tabuleiro de xadrez). Faça um programa
que leia os dados do arquivo e armazene em uma matriz. A seguir o programa deve dizer
quais dessas rainhas podem atacar pelo menos 1 das outras e em quais posições estão.*/

int main(){
	setlocale(LC_CTYPE, "Portuguese");
	FILE *arq;
	int i, j, x, k, matriz_Aux[8][8];
	int contabaixo = 0, contacima = 0, contaesquerda = 0, contadireita = 0, contdiagprinc = 0, contdiagsec = 0 ;
	
	arq = fopen("matriz.bin", "rb");
	
	fread(matriz_Aux, sizeof(int), 64, arq);
	
	printf("   0   1   2   3   4   5   6   7 \n");
	
	for ( i=0; i<8; i++ ){
		printf("%d", i);
		 for ( j=0; j<8; j++ ){
		 	
   		  printf ("| %d ", matriz_Aux[i][j]);
   		  
  		}
  		printf("|");
		printf("\n");
		
	}
	
	
	for ( i=0; i<8; i++ ){
		 for ( j=0; j<8; j++ ){
		 	if (matriz_Aux[i][j] == 1){
		 		for(x = i+1; x < 8; x++){
		 			if(matriz_Aux[x][j] == 1){
		 				contabaixo++;
					 }
				 }
				 for(x = i-1; x >= 0; x--){
		 			if(matriz_Aux[x][j] == 1){
		 				contacima++;
					 }
				 }
				 
				 for(x = j-1; x >= 0; x--){
		 			if(matriz_Aux[i][x] == 1){
		 				contaesquerda++;
					 }
				 }
				 
				 for(x = j+1; x < 8; x++){
		 			if(matriz_Aux[i][x] == 1){
		 				contadireita++;
					 }
				
				 }
				 
				if (j>i){ //acima da diagonal principal 
					for(x = 1; x <= 7; x++){
						if (j+x > 7){
							break;
						} else {
							if(matriz_Aux[i+x][j+x] == 1){
								contdiagprinc++;
							}
						}
					}
					
					contdiagprinc = 0;
				} else { //abaixo
					for(x = 1; x<= 7; x++){
						if (i+x > 7){
							break;
						} else {
							if(matriz_Aux[i+x][j+x] == 1){
								contdiagprinc++;
							}
						}
					}
					
					
				}
				
				// secundaria ERROR
				if (j>i){ //acima da diagonal sec 
					for(x = 1; x <= 7; x++){
						if (j+x > 7){
							break;
						} else {
							if(matriz_Aux[i-x][j-x] == 1){
								contdiagsec++;
							}
						}
					}
					
					contdiagsec = 0;
				} else { //abaixo
					for(x = 1; x<= 7; x++){
						if (i+x > 7){
							break;
						} else {
							if(matriz_Aux[i+x][j-x] == 1){
								contdiagsec++;
							}
						}
					}
					
					
				}
				
		 	//	printf("linha %d coluna %d e cont abaixo: %d acima: %d conta esquerda %d cont direita: %d Dig principal %d\n", i, j, contabaixo, contacima, contaesquerda, contadireita, contdiagprinc);
		 		
				 int somacont = contabaixo + contacima + contaesquerda + contadireita + contdiagprinc + contdiagsec; 
				 if (somacont != 0){
				 	printf("A rainha na linha %d e coluna %d pode atacar outra rainha.\n", i, j);

				 }else{
				 	printf("A rainha na linha %d e coluna %d não pode atacar ninguém.\n", i, j);
				 }
				contabaixo = 0;
		 		contacima = 0;
		 		contaesquerda = 0;
		 		contadireita = 0;		 		
		 		contdiagprinc = 0;
		 		contdiagsec = 0;
		 		
		 		
			 }
   		 
   		  
  		}
  	
	}
	
	fclose(arq);
	return 0;
 		
	
}
