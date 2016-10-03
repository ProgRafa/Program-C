#include<stdio.h>
#include<stdlib.h>

int main(){
int n = 5;
int * vet = (int*) malloc(n * sizeof(int));

int i;
	for(i = 0; i < n; i++){
		int Random = rand() % 100;
		
		vet[i] = Random;
		printf("|-------------------------------------|\n");
		printf("|  Vetor[%d]/ Posicao: %d, Valor: %d  |\n", i, &vet[i], vet[i]);
	}

int n2 = 10;

int *vet_two = (int*) realloc(vet, n2*sizeof(int));
printf("\n\n\n\n\n");

	for(i = n; i < n2; i++){
		int Random = rand() % 100;
		vet_two[i] = Random;
		printf("|-------------------------------------|\n");
		printf("|-Vetor[%d]/ Posicao: %d/ Valor: %d-|\n", i, &vet_two[i], vet_two[i]);

	}
	
printf("|-------------------------------------|");
printf("\n\n\n\n\n");

	for(i = 0; i < n2; i++){
		printf("|-------------------------------------|\n");
		printf("|--Vetor[%d]/ Posicao: %d/ Valor: %d--|\n", i, &vet_two[i], vet_two[i]);
	}
printf("|-------------------------------------|");
return 0;
}




