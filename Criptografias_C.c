#include <stdlib.h>
#include <stdio.h>
#include <time.h>

char caracterRandomico();
void salvaArquivo(char nomeArquivo[20], char texto[300]);
void leituraArquivo(char nomeArquivo[20]);

void main(void){
	int x = 0;
	//inicializa os gerador de números randômicos
	srand((unsigned)time(NULL));
/*	for (x = 0; x < 32; x++){
		printf("%c",caracterRandomico());
	}
*/	salvaArquivo("teste.txt", "Olá olha que legal aqui dentro do arquivo! Não é pegadinha! :-)");
	leituraArquivo("teste.txt");
}

//retornar um caracter aleatório
char caracterRandomico(){
	char matrizCaracteres[119] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','x','y','z',' ','!','@','#','$','%','&','*','(',')','[',']','=','-','1','2','3','4','5','6','7','8','9','0','.',',','"','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','X','Y','Z',':',';','?','/','|','á','é','í','ó','ú','ã','õ','à','ì','ò','è','ù','Á','É','Í','Ó','Ú','Ã','Õ','À','Ì','Ò','È','Ù','ç','Ç','â','ê','î','ô','û','Â','Ê','Î','Ô','Û'};
	unsigned char numRand = rand()%119;
	return matrizCaracteres[(numRand)];
}
//grava no arquivo de nome <nomeArquivo> o texto <texto>
void salvaArquivo(char nomeArquivo[20], char texto[300]){
	FILE *arquivo;
	//abre o arquivo para escrita
	arquivo = fopen(nomeArquivo,"w");
	unsigned int i;
	//escreve cada letra do texto no arquivo
	for (i = 0; i < strlen(texto); i++){
		putc(texto[i],arquivo);
	}
	//fecha o arquivo
	fclose(arquivo);
}

//lê do arquivo de nome <nomeArquivo> o conteúdo
void leituraArquivo(char nomeArquivo[20]){
	FILE *arquivo;
	//abre o arquivo para leitura
	arquivo = fopen(nomeArquivo,"r");
	do{
		char letra = getc(arquivo);
		printf("%c",letra);
	}while( ! feof(arquivo) );
	//fecha o arquivo
	fclose(arquivo);
}

