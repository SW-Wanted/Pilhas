#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Desafio.h"
#include "Desafio.c"

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "");
	Pilha * pilha = NULL;
    int opcao, valor, novoValor;

    do {
        printf("\nMenu de Op��es:\n");
        printf("1. Criar Pilha\n");
        printf("2. Inserir elemento\n");
        printf("3. Remover elemento\n");
        printf("4. Remover n elementos\n");
        printf("5. Imprimir pilha\n");
        printf("6. Substituir elemento\n");
        printf("7. Obter valor m�nimo\n");
        printf("8. Obter valor m�ximo\n");
        printf("9. Eliminar pilha\n");
        printf("10. Sair\n");
        printf("Digite sua op��o: ");
        scanf("%d", &opcao);
		system("cls");
        switch (opcao) {
        	case 1:
        		if (pilha)
        		{
        			printf("J� existe uma Pilha criada.\n");
        			break;
				} else {
					pilha = InicializarPilha();
					printf("Pilha criada.\n");
				}
        		break;
            case 2:
            	if (!pilha)
            	{
            		printf("Pilha n�o criada!\n");
            		break;
				}
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                Push(&pilha, valor);
                break;
            case 3:
            	if (!pilha)
            	{
            		printf("Pilha n�o criada\n");
            		break;
				}
				if (!pilha->topo)
            	{
            		printf("Pilha vazia\n");
            		break;
				}
                valor = Pop(&pilha);
                printf("Elemento removido: %d\n", valor);
                break;
            case 4:
            	if (!pilha)
            	{
            		printf("Pilha n�o criada\n");
            		break;
				}
				if (!pilha->topo)
            	{
            		printf("Pilha vazia\n");
            		break;
				}
                printf("Digite o n�mero de elementos a serem removidos: ");
                scanf("%d", &valor);
                Popn(&pilha, valor);
                break;
            case 5:
                ImprimirPilha(pilha);
                break;
            case 6:
            	if (!pilha)
            	{
            		printf("Pilha n�o criada!\n");
            		break;
				}
                printf("Valor atual: ");
                scanf("%d", &valor);
                printf("Valor novo: ");
                scanf("%d", &novoValor);
				SubstituirElemento(&pilha, valor, novoValor);
                break;
            case 7:
            	if (!pilha)
            	{
            		printf("Pilha n�o criada\n");
            		break;
				}
				if (!pilha->topo)
            	{
            		printf("Pilha vazia\n");
            		break;
				}
                printf("Valor m�nimo: %d\n", ObterValorMinimo(pilha));
                break;
            case 8:
            	if (!pilha)
            	{
            		printf("Pilha n�o criada\n");
            		break;
				}
				if (!pilha->topo)
            	{
            		printf("Pilha vazia\n");
            		break;
				}
                printf("Valor m�ximo: %d\n", ObterValorMaximo(pilha));
                break;
            case 9:
            	if (!pilha)
            	{
            		printf("N�o existe uma pilha para eliminar!\n");
            		break;
				}
                EliminarPilha(&pilha);
                printf("Pilha eliminada.\n");
                break;
            case 10:
                printf("Saindo...\n");
                break;
            default:
                printf("Op��o inv�lida.\n");
        }
    } while (opcao != 10);	
	
	return 0;
}
