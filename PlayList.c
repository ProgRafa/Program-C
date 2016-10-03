#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct no{
    char music[50];
    struct no *ant;
    struct no *prox;
}nodo;

nodo *inicio;
nodo *fim;

void inserir(char * info){
    nodo *novo = malloc(sizeof(nodo));
    nodo *atual;
    //atribuição do novo valor...
    strcpy(novo->music,info);
    //cria lista
    if(!inicio){
        novo->prox = NULL;
        novo->ant = NULL;
        inicio = novo;
        fim = novo;

        return ;
    }
    //Se não for o primeiro elemento
    atual = inicio;
    while(atual){
       if( strcmp(atual->music,info)<0){
        atual = atual->prox;
       }else
       //elemento intermediário - caso 2
       {
        if(atual->ant){
            novo->prox = atual;
            novo->ant = atual->ant;
            atual->ant->prox = novo;
            atual->ant = novo;

            return ;
        }
        // novo primeiro elemento - caso 1
        novo->prox = atual;
        novo->ant = NULL;
        atual->ant = novo;
        inicio = novo;

        return;
       }
    }
    // novo último elemento
    fim->prox = novo;
    novo->prox = NULL;
    novo->ant = fim;
    fim = novo;
}

void mostrarLista(){
    nodo *atual = inicio;
    int cont = 1;
    printf("Numero - Musica\n");
    while(atual){
        printf("%d     - %s\n", cont, atual->music);
        atual = atual->prox;
        cont++;
    }
}

nodo * procurar(char * info){
nodo *atual = inicio;

while(atual){
    if(strcmp(atual->music, info) == 0)
        return atual;
    else
        atual = atual->prox;
}

    return NULL;
}

void removerMusica(nodo *dado){
    if(!dado)
        return ;
    if(dado->prox && dado->ant){
        //item intermediário
        dado->ant->prox = dado->prox;
        dado->prox->ant = dado->ant;
        free(dado);
        return ;
    }
    if(dado == inicio){
        //primeiro item
            inicio = dado->prox;
            inicio->ant = NULL;
            free(dado);
            return ;
    }
    if(dado == fim){
        //ultimo elemento
        fim = dado->ant;
        fim->prox = NULL;
        free(dado);
        return ;
    }
}

int main()
{
    int opcao = 0;
    char dado[50];

    while(1)
    {
        system("cls"); //limpa tela
        printf("Selecione a opcao:\n");
        printf("1 - Inserir na lista\n");
        printf("2 - Mostrar Lista\n");
        printf("3 - Remover musica\n");
        printf("4 - Remover nodo no inicio\n");
        printf("5 - Mostrar lista normal\n");
        printf("9 - Sair do programa\n");
        scanf("%d",&opcao);
        switch (opcao)
        {
            case 1:
                system("cls");
                printf("Digite o nome da musica: ");
                fflush(stdin);
                fgets(dado,50,stdin);
                inserir(dado);
                break;
            case 2:
                    mostrarLista();
                    system("pause");
                    break;
            case 3:
                    printf("Digite a música removida: ");
                    fflush(stdin);
                    fgets(dado,50,stdin);
                    removerMusica(procurar(dado));
                    break;
            case 4:
                    break;
            case 5:

            case 9: exit(0);
                    break;
            default:
                    printf("Opcao invalida\n");
                    system("pause");
                    break;
        }
    }
    return 0;
}
