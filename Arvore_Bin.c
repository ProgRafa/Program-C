#include<stdlib.h>
#include<stdio.h>


typedef struct nodoArv{

	int cod_Arv;
	struct nodoArv * subEsq;
	struct nodoArv * subDir;	

}Nodo;


Nodo * criaNodo(int valor){
	Nodo * nodo = malloc(sizeof(Nodo));
	nodo->subEsq = NULL;
	nodo->subDir = NULL;	
	nodo->cod_Arv = valor;
	return nodo;
}

void insereNodo(Nodo ** n, int valor){
	if(*n == NULL){
		*n = criaNodo(valor);
	}else{
		if((*n)->cod_Arv < valor){
			insereNodo(&(*n)->subDir, valor);
		}else if((*n)->cod_Arv > valor){
			insereNodo(&(*n)->subEsq, valor);
		}else{
			printf("Nodo ja existe!");
		}

	}

}

/*
void imprimeNodo(Nodo * n){
	printf("(");
	if(n != NULL){
		printf("%d", n->cod_Arv);
		imprimeNodo(n->subEsq);
		imprimeNodo(n->subDir);

	}
	printf(")");
}
*/

void imprimeNodoBarras(Nodo * n, int niv, char lado){
int i;	
	if(n != NULL){

		for(i=0; i<niv;i++){
			printf("  ");
		}

		printf("%c%d\n", lado, n->cod_Arv);

		imprimeNodoBarras(n->subEsq,niv+1,'E');
		imprimeNodoBarras(n->subDir,niv+1, 'D');

	}
	
}


Nodo * buscaNodo(Nodo * n, int valor){
	if(n == NULL){
		printf("Valor nao encontrado!\n");
	}else{
		if(n->cod_Arv == valor){
			printf("Valor %d encontrado!\n", n->cod_Arv);
			return n;
		}else if(n->cod_Arv > valor){
			buscaNodo(n->subEsq, valor);
		}else{
			buscaNodo(n->subDir, valor);
		}
		
	}
	

}

void excluiNodo(Nodo * n, int valor){
	printf("%d\n", n->cod_Arv);
	printf("%d\n", n->subDir);
	printf("%d\n", n->subEsq);
	
	Nodo * aux = NULL; 
	
	if(n != NULL && n->cod_Arv == valor){
		if(n->subDir == NULL && n->subEsq == NULL){
		printf("%d\n%d\n%d",aux->cod_Arv, aux->subEsq, aux->subDir);	
		free(n);
		
		}else if(n->subEsq == NULL && n->subDir != NULL){
		n = n->subDir;
		free(n);
		
		}else if(n->subEsq != NULL && n->subDir == NULL){
		n = n->subEsq;
		free(n);
		
		}else{
		
		}
	}else{
		if(n->cod_Arv > valor){
			aux->subEsq = n->subEsq;
			aux->subDir = n->subDir;
			excluiNodo(n->subEsq, valor);
		
		}else{
			aux->subEsq = n->subEsq;
			aux->subDir = n->subDir;
			excluiNodo(n->subDir, valor);
		}
	}

}


int main(){
	Nodo * raiz = NULL;

	imprimeNodoBarras(raiz, 0, 'r');
	printf("\n");

	insereNodo(&raiz,10);
	insereNodo(&raiz,60);
	insereNodo(&raiz,3);
	insereNodo(&raiz,1);
	insereNodo(&raiz,18);
	insereNodo(&raiz,35);
	insereNodo(&raiz,5);
	insereNodo(&raiz,4);
	insereNodo(&raiz,6);

	imprimeNodoBarras(raiz,0,'r');
	
	/*
	Nodo * n = buscaNodo(raiz, 18);
	excluiNodo(n);
	
	imprimeNodoBarras(raiz,0,'r');
	*/
	excluiNodo(raiz, 6);
	//imprimeNodoBarras(raiz,0,'r');
	
	return 0;
}






