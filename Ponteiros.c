#include<stdio.h>
#include<stdlib.h>


void operacaoBasica(int a, int b, int *soma, int *multi){
    //*ponteiro variavel que guarda valor da posição na memória
	*soma = a+b;
	*multi = a*b;
}

int main(){
int num, segnum;

operacaoBasica(4,5,&num,&segnum);

printf("Valor soma: %d", num);
printf("\nValor multiplicacao: %d", segnum);
return 0;
}


