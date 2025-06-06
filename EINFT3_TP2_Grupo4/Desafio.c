#include <stdio.h>
#include <stdlib.h>
#include "Desafio.h"

struct no {
	int valor;
	struct no * prox;
};

struct pilha{
	Lista * topo;
 	Lista * minimo;
	Lista * maximo;
};

Pilha * InicializarPilha() {
	Pilha * p = (Pilha*)malloc(sizeof(Pilha));
	if (p)
	{
	   	p->topo = NULL;
		p->minimo = NULL;
		p->maximo = NULL;
	}
 	else
 	{
	 	printf("[Erro] Memoria Insuficiente!\n");
	 	return NULL;
	}
	return p;
}

void Push(Pilha ** p, int valor)
{
	if(!(*p))
	{
		printf("[Erro] Pilha nao inicializada!\n");
		exit(1);
	}
 	    
	Lista * novo = (Lista*)malloc(sizeof(Lista));
	if(novo)
	{
		novo->valor = valor;
		novo->prox = (*p)->topo;
		(*p)->topo = novo;
		
		// Atualiza o Minimo e Maximo
		if((*p)->minimo == NULL || novo->valor < (*p)->minimo->valor)  (*p)->minimo = novo;
		if((*p)->maximo == NULL || novo->valor > (*p)->maximo->valor)  (*p)->maximo = novo;
	}
	else
		printf("[Erro] Memoria Insuficiente!\n");
}

int Pop(Pilha ** p){
	if (!(*p))
	{
		printf("[Erro] Pilha nao inicializada!\n");
		exit(1);
	}
	   
	if(!(*p)->topo)
	{
		printf("[Erro] Pilha vazia!\n");
		exit(1);
	}
 	else
 	{
 	 	Lista * aux = (*p)->topo;
		int i = aux->valor;
		int min = (*p)->minimo->valor;
		int max = (*p)->maximo->valor;
		(*p)->topo = aux->prox;
		free(aux);
		aux = NULL;
		
		if(!(*p)->topo){
			(*p)->minimo = NULL;
			(*p)->maximo = NULL;
		}
		// Atualiza o Minimo 
		else if(i == min){ 
			(*p)->minimo = (*p)->topo;
			Lista * atual = (*p)->topo;
			while(atual)
			{
 			    if(atual->valor < (*p)->minimo->valor)
					(*p)->minimo = atual;
				atual = atual->prox; 
			}
		}
	 	// Atualiza o Maximo
		else if(i == max){
			(*p)->maximo = (*p)->topo;
			Lista * atual = (*p)->topo;
			while(atual)
			{
				if(atual->valor > (*p)->maximo->valor)
					(*p)->maximo = atual;
				atual = atual->prox;
			}
		}
		
		return i;	
	} 
}

void Popn(Pilha ** p, int n)
{
	if (!(*p))
	{
		printf("[Erro] Pilha nao inicializada!\n");
		exit(1);
	}
	
	if ((*p)->topo == NULL)
	{
		printf("Pilha vazia.\n");
		return;
	}
	
	while(n > 0 && (*p)->topo)
	{
		Pop(p);
		n--;
	}
}

void ImprimirPilha(Pilha * p)
{
	
	if (!p || !p->topo) {
        printf("Pilha Vazia!\n");
        return;
    }
    
	Lista * aux = p->topo;
	while (aux)
	{
		printf("%d\n", aux->valor);
		aux = aux->prox;
	}
}

void SubstituirElemento(Pilha ** p, int valorAtual, int valorNovo)
{
	Lista * aux = (*p)->topo;
	while(aux){
		if(aux->valor == valorAtual){
			aux->valor = valorNovo;
			
			// Atualiza o Minimo 
			Lista * aux2 = (*p)->topo;
			while(aux2){
				if(aux2->valor < (*p)->minimo->valor)
					(*p)->minimo = aux2;
				aux2 = aux2->prox;
			}
			// Atualiza o Maximo
			aux2 = (*p)->topo;
			while(aux2){
				if(aux2->valor > (*p)->maximo->valor)
					(*p)->maximo = aux2;
				aux2 = aux2->prox;
			}	
				
			return;
		}
		aux = aux->prox;		
	}
	
	if(!aux)
	    printf("O valor \"%d\" nao foi encontrado!\n", valorAtual);
}

int ObterValorMinimo(Pilha * p){
	if(!p->topo)
	{
		printf("[Erro] Nao existe valor minimo, pelo que a lista esta vazia!\n");
		exit(1);
	}
	return p->minimo->valor;
}

int ObterValorMaximo(Pilha * p){
	if(!p->topo)
	{
		printf("[Erro] Nao existe valor maximo, pelo que a lista esta vazia!\n");
		exit(1);
	}
	return p->maximo->valor;
}

void EliminarPilha(Pilha ** p)
{
	while ((*p)->topo)
 	    Pop(p);
 	*p = NULL;    
}
