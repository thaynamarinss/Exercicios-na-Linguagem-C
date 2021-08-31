#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
/*Considerando duas listas encadeadas simples A e B
(números reais), faça uma função recursiva que receba ponteiros para essas listas e retorne 1 se
elas forem iguais e retorne 0 se forem diferentes. Testa a função utilizando um programa no qual
o usuário informe a lista e o número que devem ser inseridos até o usuário não querer mais. O
programa deve chamar a função e informar o usuário do resultado. Libere a memória das listas
de forma recursiva.*/

struct elemento {
    int valor;
    struct elemento *prox;
};
struct elemento *CriaLista() {
    return NULL;
}
struct elemento *CriaElemento(int numero) {
    struct elemento *resp = (struct elemento *)malloc(sizeof(struct elemento));
    resp->valor = numero;
    resp->prox = NULL;
    return resp;
}

struct elemento *InsereFim(struct elemento *lista, int numero) {
    struct elemento *aux;
    struct elemento *novo = CriaElemento(numero);
    if (lista == NULL) {
        lista = novo;
    } else {
        aux = lista;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    return lista;
}

void Listar(struct elemento *lista) {
    struct elemento *aux = lista;
    while (aux != NULL) {
        printf("%d\n", aux->valor);
        aux = aux->prox;
    }
}


// Compara recursiva
int CompararListas(struct elemento *lista, struct elemento *listaB, int contequal, int contElementos) {
    
    if (lista == NULL || listaB == NULL){
        if (contequal == contElementos){
            return 1;
        } else {
            return 0;
        }
    } else{
        if (lista->valor == listaB->valor){
            contequal++;
            contElementos++;
        } else {
            contElementos++;
        }
        contequal = CompararListas(lista->prox, listaB->prox, contequal, contElementos);
    }
}

//Destruir Recursiva
struct elemento *DestroiLista(struct elemento *lista) {
    struct elemento *aux;
	if(lista == NULL){
    	return NULL;
	}else{
		aux = lista->prox;
        free(lista);
        lista = aux;
		DestroiLista(lista);
              
	}      
}

int main() {
    setlocale(LC_CTYPE, "Portuguese");

    int opcao, escolhaLista, novoNum, resultComp, contequal = 0, contElementos = 0;

    // Lista A=1 lISTA B=2
    struct elemento *inicioA, *inicioB;
    inicioA = CriaLista();
    inicioB = CriaLista();

    do {
        printf(
            "-> O que voce gostaria de fazer?\n\n1-Adicionar um numero a uma "
            "lista\n0-Encerrar o programa.\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf(
                    "Qual lista voce deseja adicionar um número? ( Digite: 1 "
                    "para A | 2 para B) \n");
                scanf("%d", &escolhaLista);
                printf("Qual numero voce quer inserir?\n");
                scanf("%d", &novoNum);

                switch (escolhaLista) {
                    case 1:
                        inicioA = InsereFim(inicioA, novoNum);
                        break;
                    case 2:
                        inicioB = InsereFim(inicioB, novoNum);
                        break;

                    default:
                        printf("Lista inexistente\n");
                }

                break;
                
			case 0:
					printf("Você saiu do programa!\n");
					break;
            default:
                printf("Digite uma opção válida!\n");
        }

    } while (opcao != 0);

    printf("Lista A:\n");
    Listar(inicioA);
    printf("Lista B:\n");
    Listar(inicioB);
    printf("\n->Resultado da comparacao das listas:\n\n");
    resultComp = CompararListas(inicioA, inicioB, contequal, contElementos);

    if (resultComp == 1) {
        printf("As listas são iguais!\n");
    } else {
        printf("As listas são diferentes!\n");
    }
    
   inicioA = DestroiLista(inicioA);
   inicioB = DestroiLista(inicioB);
   /*
   printf("Lista A:\n");
   Listar(inicioA);
   printf("Lista B:\n");
   Listar(inicioB);
   */
    return 0;
}
