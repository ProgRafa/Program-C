#include<stdio.h>
#include<stdlib.h>

int main(){
int * vet = (int*) malloc(5 * sizeof(int));
int i;
for(i = 0; i < 5; i++){
int Random = rand() % 100;
vet[i] = Random;
printf("Vetor[%d]: %d\n", i, Random);
}

return 0;
}


