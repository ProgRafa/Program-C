#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>


typedef struct arvoreBalenceada{
	int valor;
	int altura;
	int fb;
	struct nodo * esq;
	struct nodo * dir;
	
}Nodo;

Nodo * criaNodo(int cod){
	Nodo * pai = malloc(sizeof(Nodo));
	pai->valor = cod;
	pai->esq =  NULL;
	pai->dir =  NULL;
	
	return pai;
}

void insereNodo(Nodo ** n, int cod){
	if(*n == NULL){
		*n = criaNodo(cod);
	}else if((*n)->valor < cod){
		insereNodo(&(*n)->dir, cod);
	}else if((*n)->valor > cod){
		insereNodo(&(*n)->esq, cod);
	}
	
}

int retornaAltura(Nodo * n){
	if(n != NULL){
	
		int altEsq = retornaAltura(n->esq);
		int altDir = retornaAltura(n->dir);
		
		int fb = altDir - altEsq;
		n->fb = fb;
		
		if(altDir > altEsq){
			n->altura = altDir+1;
			return altDir + 1;
		}else{
			n->altura = altEsq+1;
			return altEsq + 1;
		}
		
		
	}else{
		return 0;
	}
	
}

void balancoSD(Nodo ** n){
	Nodo * temp = *n;
	*n = (*n)->esq;
	temp->esq = (*n)->dir;
	(*n)->dir = temp; 
}

void balancoSE(Nodo ** n){
	Nodo * temp = *n;
	*n = (*n)->dir;
	temp->dir = (*n)->esq;
	(*n)->esq = temp; 
}

bool functionBalanco(Nodo ** n){
	if(*n != NULL){
		if((*n)->fb > 1){
			//S.E
			//D.E
			printf("Ta Desbalanceado! Chave: %d - FB: %d", (*n)->valor, (*n)->fb);
			int fbFilho = (*n)->dir->fb;
			
			if((*n)->dir->fb > 0){
				printf("Faca Rotacao S.E\n!");
				balancoSE(&(*n));
			}else{
				printf("Faca Rotacao D.E\n!");
				balancoSD(&(*n)->dir);
				balancoSE(&(*n));
			}
			
			return true;
		}else if((*n)->fb < -1){
			//S.D
			//D.D
			if((*n)->esq->fb < 0){
				printf("Faca Rotacao S.D!");
				balancoSD(&(*n));
			}else{
				printf("Faca Rotacao D.D!");
				balancoSE(&(*n)->esq);
				balancoSD(&(*n));
			}
			
			return true;
		}else{
			if(functionBalanco(&(*n)->esq) == true){
				return true;
			}
			if(functionBalanco(&(*n)->dir) == true){
				return true;
			} 
		
		}
	}
}

void balancoContinuo(Nodo ** n){
	do{
		retornaAltura(*n);
	}while(functionBalanco(n));
	
}

void mostraArvore(Nodo * raiz, int nivel, char lado){
	if(raiz != NULL){
		
		int i;
		for(i = 1; i <= nivel; i++)
			printf("   ");
		
		printf("%c->%d  a=%d fb=%d \n", lado, raiz->valor, raiz->altura, raiz->fb);
		mostraArvore(raiz->esq, nivel + 1, 'e');
		mostraArvore(raiz->dir, nivel + 1, 'd');
	}
	
}


int main(){
	Nodo * raiz = NULL;
	
	insereNodo(&raiz, 10);
	insereNodo(&raiz, 20);
	insereNodo(&raiz, 30);
	insereNodo(&raiz, 40);
	insereNodo(&raiz, 8);
	
	retornaAltura(raiz);
	mostraArvore(raiz,1,'r');
	functionBalanco(&raiz);

}
