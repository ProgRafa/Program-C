#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void inicio();
void funcForca(char nome[30], char misterio[27]);
void funcErro(int erro, char misterio[27], char Acertos[27]);

int main(){

	printf("JOGO DA FORCA");

	inicio();

	system("pause");
	return 0;
}

//função captura dados iniciais
void inicio(){
	char nome[30], palavra[27];

	printf("\n\nDigite seu nome: ");
	gets(nome);

	printf("Digite uma palavra de ate 26 caracteres: ");
	gets(palavra);

	system("cls");

	funcForca(nome, palavra);
}

//Onde a mágica acontece
void funcForca(char nome[30], char misterio[27]){

	char tentativa, vetor[27], vetorTenta[27], certo, vetorAcerto[27];
	int y, contErro = 0, k = 0, acerto = 0, i = 0;

	int x = strlen(misterio);

	//SISTEMA DE LOOPING PARA DECODIFICAR OS CARACTERES DA PALAVRA
	for(y = 0; y < x; y++){
			vetor[y] = '_';

	}


	do{
	system("cls");
	certo = 'f';


	printf("JOGO DA FORCA");

	printf("\n\n%s advinhe a palavra \n\n\t", nome);

	//PARTE RESPONSAVEL PELA MUDANÇA DA DECODIFICAÇÃO PELO CARACTER ACERTADO
	for(y = 0; y < x; y++){
		printf("%c ", vetor[y]);

	}

	printf("\n\nTentativas: ");
	for(y = 0; y < k+1; y++){
		printf("%c ", vetorTenta[y]);

	}

	funcErro(contErro, misterio, vetorAcerto);

	printf("\n\nTecle uma tecla: ");
	tentativa = tolower(getche());

	//PARTE COM CONSTANTES MUDANÇAS TENTATIVAS
	vetorTenta[k] = tentativa;
	k++;

	//MUDA O VETOR COM AS TENTATIVAS ACERTADAS
	for(y = 0; y < 27; y++){
		if(tentativa == misterio[y]){
			vetor[y] = tentativa;
			vetorAcerto[i] = tentativa;
			i++;
			certo = 'v';

		}

	}

	//PUXA FUNÇÃO PRINTA ERROS E CONSTROI O BONECO
	for(y = 0; y < 27; y++){
		if(tentativa != misterio[y] && certo == 'f'){
			contErro++;
			y = 27;
		}

	}


	for(y = 0; y < x; y++){
		if(vetor[y] != '_'){
			acerto = acerto+1;

		}else{
			acerto = 0;
			y = x;
		}
	}


	}while(acerto != x);

	printf("\nPalavra: %s", misterio);
	printf("\nAcertos: %s", vetorAcerto);
	printf("\nVoce venceu!");
	getch();
	exit;

	}


//constroi o boneco e determina a derrota
void funcErro(int erro, char misterio[27], char Acertos[27]){
	switch(erro){
		case 1:
			printf("\n\nO");
			break;
		case 2:
			printf("\n\nO");
			printf("\n|");
			printf("\n|");
			printf("\n|");
			break;
		case 3:
			printf("\n\n   O");
			printf("\n   |");
			printf("\n  / \\");
			printf("\n   |");
			printf("\n   |");
			break;
		case 4:
            printf("\n\n   O");
			printf("\n   |");
			printf("\n  / \\");
			printf("\n   |");
			printf("\n   |");
			printf("\n  / \\");
			printf("\n /   \\");
			printf("\t\t\t\n\nGAME OVER! ");
			printf("\nPalavra: %s", misterio);
			printf("\nAcertos: %s", Acertos);
			exit(0);
			break;
	}

}

