#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<string.h>

void functionD100(int * D100){
	*D100 = rand() % 100;
}

void functionD20(int * D20){
	*D20 = (rand() % 20) + 1;
}

void functionD12(int * D12){
	*D12 = (rand() % 12) + 1;
}

void functionD10(int * D10){
	*D10 = (rand() % 10) + 1;
}

void functionD8(int * D8){
	*D8 = (rand() % 8) + 1;
}

void functionD6(int * D6){
	*D6 = (rand() % 6) + 1;
}

void functionD4(int * D4){
	*D4 = (rand() % 4) + 1;
}

void functionRegistro(int valorDado, char dado[5]){
	FILE * REGISTRO;
	REGISTRO = fopen ("C:\\Users\\Rafael\\Desktop\\Registro.txt", "at");
	
	time_t t = time(NULL);
	fprintf(REGISTRO, "%s valor do dado %s: %d\n", asctime(localtime(&t)), dado, valorDado);
	
	fclose(REGISTRO);
}

void functionLer(int valorDado){
	FILE * REGISTRO;
	REGISTRO = fopen ("C:\\Users\\Rafael\\Desktop\\Registro.txt", "rt");
	char um[10], dois[10], tres[10], four[10], five[10], six[10], seven[10];
	int num = 0, num_2 = 0;
	
	while((fscanf(REGISTRO, "%s %s %d %s %d %s %s %s %s %d\n", um, dois, &num, tres, &num_2, four, five, six, seven, &valorDado)) != EOF)
		printf("%s %s %d %s %d %s %s %s %s %d\n", um, dois, num, tres, num_2, four, five, six, seven, valorDado);
	
	fclose(REGISTRO);
}

void functionClear(){
	FILE * REGISTRO;
	REGISTRO = fopen("C:\\Users\\Rafael\\Desktop\\Registro.txt", "wt");
	fprintf(REGISTRO," ");
	
	fclose(REGISTRO);
}

int main(){
	char dado[4];
	int valor;
	char opc;
	
	do{
		time_t t = time(NULL);
		printf("%s\n", asctime(localtime(&t)));
		
		srand((unsigned) time (NULL));
		
		printf ("\t\t########################################################################\n");
		printf ("\t\t##                                                                    ##\n");
		printf ("\t\t##                             ROLA O DADO                            ##\n");
		printf ("\t\t##                                                                    ##\n");
		printf ("\t\t##                  Escolha uma das opcoes abaixo:                    ##\n");
		printf ("\t\t##                  1 - Rolar dado                                    ##\n");
		printf ("\t\t##                  2 - Ler registro de rolls                         ##\n");
		printf ("\t\t##                  3 - Limpar registro                               ##\n");
		printf ("\t\t##                                                                    ##\n");
		printf ("\t\t########################################################################\n\n");
		
		opc = getch();	
		switch(opc){
			case '1':
				printf("Use d+valor do dado para rolar\n");
				gets(dado);
				if(dado[0] == 'D')
					dado[0] = 'd';
				
				if(strcmp(dado, "d100") == 0){
					functionD100(&valor);
					functionRegistro(valor, "d100");
					printf("Valor do dado d100: %d", valor);					
						
				}else if(strcmp(dado, "d20") == 0){
					functionD20(&valor);
					functionRegistro(valor, "d20");
					printf("Valor do dado d20: %d", valor);
					
				}else if(strcmp(dado, "d12") == 0){
					functionD12(&valor);
					functionRegistro(valor, "d12");
					printf("Valor do dado d12: %d", valor);
						
				}else if(strcmp(dado, "d10") == 0){
					functionD10(&valor);
					functionRegistro(valor, "d10");
					printf("Valor do dado d10: %d", valor);
					
				}else if(strcmp(dado, "d8") == 0){
					functionD8(&valor);
					functionRegistro(valor, "d8");
					printf("Valor do dado d8: %d", valor);
					
				}else if(strcmp(dado, "d6") == 0){
					functionD6(&valor);
					functionRegistro(valor, "d6");
					printf("Valor do dado d6: %d", valor);
					
				}else if(strcmp(dado, "d4") == 0){
					functionD4(&valor);
					functionRegistro(valor, "d4");
					printf("Valor do dado d4: %d", valor);
					
				}else{
					printf("Dado nao encontrado!");
					
				}
				getch();
				break;
			case '2':
				system("cls");
				functionLer(valor);
				getch();
				break;
			case '3':
				functionClear();
				break;
		}
		
	system("cls");
	}while(1);
	
	return 0;
}


