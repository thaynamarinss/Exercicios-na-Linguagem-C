#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*Um sistema operacional deve ser capaz de executar
tarefas de acordo com a urg�ncia que elas possuem, j� que alguns programas n�o podem ficar
esperando muito para terminar sua execu��o. Crie um programa que possua 3 filas com
prioridades distintas (baixa, m�dia e alta). O programa deve perguntar ao usu�rio se ele deseja
1) criar uma nova tarefa; 2) desenfileirar a tarefa mais urgente no momento 3) listar as tarefas
existentes e suas prioridades. Ao criar uma nova tarefa, o usu�rio deve dizer qual o seu c�digo
(n�mero inteiro) e qual a sua prioridade (baixa, m�dia ou alta). O programa deve ent�o inserir
essa tarefa na respectiva fila. Ao desenfileirar a tarefa mais urgente, o programa deve tentar tirar
primeiro uma tarefa com prioridade alta. Se n�o houver nenhuma, deve tentar tirar uma com
prioridade m�dia. Se tamb�m n�o houver, deve tirar uma com prioridade baixa. Ao listar as
tarefas, os c�digos devem ser mostrados, respeitando a prioridade e a ordem em cada fila.*/

struct elemento{
	int valor;
	struct elemento *prox;
};

struct fila{
	struct elemento *inicio, *fim;
	int qtd;
};

struct elemento *CriaElemento(int numero){
	struct elemento *resp = (struct elemento*) malloc(sizeof(struct elemento));
	resp->valor = numero;
	resp->prox = NULL;	
	return resp;
}

struct fila CriaFila(){
	struct fila resp;
	resp.qtd = 0;
	resp.inicio = NULL;
	resp.fim = NULL;
	return resp;
}

int Enfileira(struct fila *f, int numero){
	struct elemento *novo = CriaElemento(numero);
	if(f->qtd == 0){
		f->inicio = novo;
	}else{
		f->fim->prox = novo;		
	}
	f->fim = novo;
	f->qtd++;
	return 1;
}

int Desenfileira(struct fila *f, int *numero){
	
	if(f->qtd == 0){
		return 0;
		
	}
	struct elemento *aux = f->inicio;
	*numero = f->inicio->valor;
	f->inicio = f->inicio->prox;
	f->qtd--;
	free(aux);
	if(f->qtd == 0){
		f->fim = NULL;
	}
	return 1;
}

void Listar(struct fila *f){
	struct elemento *aux = f->inicio;
	
	if(f == NULL){
		return;
	}
	while(aux != NULL){
		printf("%d\n", aux->valor);
		aux = aux->prox;
		
	}
}

struct fila *DestroiFila(struct fila *f){
	struct elemento *aux;
	while(f->inicio != NULL){
		aux = f->inicio;
		f->inicio = f->inicio->prox;
		free(aux);
				
	}
	return NULL;
}

int main(){
	setlocale(LC_CTYPE, "Portuguese");
	int opcao, codTarefa, prioTarefa, numero;
	struct fila FilaB, FilaM, FilaA;
	FilaB = CriaFila();
	FilaM = CriaFila();
	FilaA = CriaFila();	
	
	printf("_____________________________________________Programa Urg�ncia de Tarefas_____________________________________________\n");
	do
	{
		printf("\nO que voc� gostaria de fazer?\nDigite:\n1 para criar uma nova tarefa\n2 para desenfileirar a tarefa mais urgente no momento\n3 para listar as tarefas existentes e suas prioridades\n4- Sair do programa\n");
		printf("________________________________________________________________________________________________________________\n");
		scanf("%d", &opcao);
	
		switch(opcao)
		{
			case 1:	
					printf("Digite o c�digo da tarefa:\n");
					scanf("%d", &codTarefa);
					//1- lista baixa, 2- lista m�dia 3- lista alta
					printf("Qual a prioridade da tarefa? Digite:\n1- Baixa\n2- M�dia\n3- Alta\n");
					scanf("%d", &prioTarefa);
					
					switch(prioTarefa){
						case 1:
								Enfileira(&FilaB, codTarefa);
								break;
						case 2:
								Enfileira(&FilaM, codTarefa);
								break;
						case 3:
								Enfileira(&FilaA, codTarefa);
								break;	
						default:
								printf("Prioridade n�o encontrada!\n");	
					}				
											
					
					break; 
			
			case 2:
								
					
					if(FilaA.qtd != 0){
						Desenfileira(&FilaA, &numero);
						printf("Voc� executou a tarefa de c�digo: %d (Prioridade Alta)", numero);
					}else if((FilaA.qtd == 0) && (FilaM.qtd != 0)){
						Desenfileira(&FilaM, &numero);
						printf("Voc� executou a tarefa de c�digo: %d (Prioridade M�dia)", numero);
					}else{
						Desenfileira(&FilaB, &numero);
						printf("Voc� executou a tarefa de c�digo: %d (Prioridade Baixa)", numero);
						
					}		
					
					
					break;
					
			case 3: 
						if((FilaA.qtd == 0) &&(FilaB.qtd == 0) && (FilaM.qtd == 0)){
							printf("N�o h� mais tarefas\n");
						}
						printf("TAREFAS COM ALTA PRIORIDADE:\n");
						Listar(&FilaA);
						printf("TAREFAS COM M�DIA PRIORIDADE:\n");
						Listar(&FilaM);
						printf("TAREFAS COM BAIXA PRIORIDADE:\n");
						Listar(&FilaB);
						
						
						
					
			
			
					
					break;
					
			case 4: 
					printf("Voc� saiu do programa!\n");
					break;
		
			default:
					printf("Op��o inv�lida!\n");
		}
		
	}while(opcao != 4);

	DestroiFila(&FilaM);
	DestroiFila(&FilaA);
 	DestroiFila(&FilaB);
	return 0;
	
}
