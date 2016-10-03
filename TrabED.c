#include<stdlib.h>
#include<stdio.h>
#include<string.h>


typedef struct nodo{
    int tipo;
    float tempo;
    char * nomeRotina;
    struct nodo * prox;

}N;

typedef struct dia{
    int tempDia;
    char * dia;

}D;

typedef struct hash{
    N ** s;
    D * d;
    int tam;

}H;

//cria lista encadeada, cada nodo sera uma rotina
N * criaNodo(float periodo, char * nomeRot, int tipo){
    N * n = (N *) malloc(sizeof(N));
    n->tempo = periodo;
    n->tipo = tipo;
    n->nomeRotina = nomeRot;
    n->prox = NULL;
    return n;
}

//cria dois vetores, o vetor v cordena o vetor dia e a lista rotina
H * criaHash(int t){
    int i;

    //vetor controle semana
    H * v = (H *) malloc(sizeof(H));
    v->tam = t;

    //apontamento para a lista encadeada
    N ** ocup = (N *) malloc(sizeof(N) * t);

    //apontamento para vetor dia
    v->d = (D *) malloc(sizeof(D) * t);

    for(i = 0; i < t; i++){
        ocup[i] = NULL;
        v->d[i].tempDia = 24;
    }
     v->d[0].dia = "SEGUNDA";
     v->d[1].dia = "TERCA";
     v->d[2].dia = "QUARTA";
     v->d[3].dia = "QUINTA";
     v->d[4].dia = "SEXTA";

    v->s = ocup;
    return v;
}

//percorre lista encadeada e printa valores
void printaRotinas(N * rot){
    if(rot != NULL){
       printf(" ROTINA: %s - TEMPO: %.1f hrs|", rot->nomeRotina, rot->tempo);
       printaRotinas(rot->prox);
    }
}

//printa toda estrutura criada(encadeada e vetores)
void printaHash(H * v){
    int i;

    for(i = 1; i < v->tam+1; i++){
        printf("| %d | %s | %d hrs |", i, v->d[i-1].dia, v->d[i-1].tempDia);

        if(v->s[i-1] == NULL){
            printf("NULL \n");
        }else{
            int ind = i-1;
            printaRotinas(v->s[ind]);
            printf("\n");
        }
    }
}

//cria nodos novos e insere de forma prioritaria
void insereRotina(N ** rotina, char * nameRot, float tempo, int tipo){
    if(*rotina == NULL){
        *rotina = criaNodo(tempo, nameRot, tipo);
    }else{
        if(tipo == 1){
                N * pNodo = (N *) malloc(sizeof(N));
                pNodo->prox = (*rotina)->prox;
                pNodo->nomeRotina = nameRot;
                pNodo->tempo = tempo;
                pNodo->tipo = tipo;
                (*rotina)->prox =  pNodo;
        }else{
            insereRotina(&(*rotina)->prox, nameRot, tempo, tipo);
        }
    }
}

//remove o ultimo nodo da lista encadeada
int remover(N ** rNodo){
    int tempo;
    if((*rNodo)->prox == NULL){
        tempo = (*rNodo)->tempo;
        (*rNodo) = NULL;
        free(*rNodo);
        return tempo;
    }else{
        remover(&(*rNodo)->prox);
    }
}

//insere uma lista em uma posicao específica ou em todas as posicoes do vetor d
void insereHash(H * v, int tempo, char * nomeRot, int tipo, int tarDiaria, int diaS){
        do{
            if(tipo == 1 && v->d[diaS].tempDia > tempo){
                insereRotina(&v->s[diaS], nomeRot, tempo, tipo);
                v->d[diaS].tempDia = v->d[diaS].tempDia - tempo;

            }else if(tipo == 1 && v->d[diaS].tempDia < tempo){
                v->d[diaS].tempDia = v->d[diaS].tempDia + remover(&v->s[diaS]);
                insereHash(v, tempo, nomeRot, tipo, tarDiaria, diaS);
            }else if(tipo == 2 && v->d[diaS].tempDia > tempo || tipo == 3 && v->d[diaS].tempDia > tempo){
                    insereRotina(&v->s[diaS], nomeRot, tempo, tipo);
                    v->d[diaS].tempDia = v->d[diaS].tempDia - tempo;

            }else if(tipo == 2 && v->d[diaS].tempDia < tempo || tipo == 3 && v->d[diaS].tempDia < tempo){
                printf("Nao ha tempo suficiente para tarefa %s na %s\n", nomeRot, v->d[diaS].dia);
                getch();
                system("cls");
            }
        diaS++;
        if(diaS >= 5)
            tarDiaria = 0;
    }while(tarDiaria == 1);
}

//procura dia mais livre para colocar tarefa
int diaMaisLivre(H * v){
    int i, maiorTemp = 0, dia = 0;
    for(i = 0; i < v->tam; i++){
        if(v->d[i].tempDia > maiorTemp){
            maiorTemp = v->d[i].tempDia;
            dia = i;
        }
    }
    return dia;
}

//printa em arquivo txt em formato de tabela
void criaTabelaArquivo(char * url, H * v){
    int i, tamFi, tamIn, tamStr, tamCam, j = 0;
    char * campo;
    FILE * txt = fopen(url, "wt");

    //printa os campos iniciais da tabela
    for(i = 0; i < v->tam; i++){
        int resultadoQuebrado, resultado;
        tamCam = 52;
        fprintf(txt, "|");
        tamStr = strlen(v->d[i].dia);
        tamCam = tamCam - tamStr;

        resultado = floor(tamCam/2);
        if(tamCam % 2 == 1){
            resultadoQuebrado = tamCam/2 + 1;
        }else{
            resultadoQuebrado = resultado;
        }

        for(tamIn = 0; tamIn < resultado; tamIn++){
            fprintf(txt, " ");
        }

        fprintf(txt, "(%s) [%d] hrs", v->d[i].dia, v->d[i].tempDia);

        for(tamFi = 0; tamFi < resultadoQuebrado; tamFi++){
            fprintf(txt, " ");
        }
    }
    fprintf(txt, "|\n");

    //printa os nodos da list encadeada
    while(j < 10){
        for(i = 0; i < v->tam; i++){
            int resultadoQuebrado, resultado;
            fprintf(txt, "|");
            tamCam = 52;
            if(v->s[i] != NULL){
                tamStr = strlen(v->s[i]->nomeRotina) + 2;
                tamCam = tamCam - tamStr;
            }else{
                tamCam = tamCam - 4;
            }

            resultado = floor(tamCam/2);
            if(tamCam % 2 == 1){
                resultadoQuebrado = tamCam/2 + 1;
            }else{
                resultadoQuebrado = resultado;
            }


            for(tamIn = 0; tamIn < resultado; tamIn++){
                fprintf(txt, " ");
            }

            if(v->d[i].tempDia < 24){
                fprintf(txt, "(%s) [%.1f] hrs", v->s[i]->nomeRotina, v->s[i]->tempo);
            }else{
                fprintf(txt, "NULL [0.0] hrs ");
            }

            for(tamFi = 0; tamFi < resultadoQuebrado; tamFi++){
                fprintf(txt, " ");
            }
        }

            //percorre a lista encadeada
        for(i = 0; i < v->tam; i++){
            //verifica se o nodo seguinte sera null se for zera nome e tempo
            if(v->s[i] != NULL){
                if(v->s[i]->prox != NULL){
                    v->s[i] = v->s[i]->prox;
                }else{
                    v->s[i]->nomeRotina = "NULL";
                    v->s[i]->tempo = 0;
                }
            }
        }
        fprintf(txt, "|\n");
        j++;
    }
}

//printa em um arquivo txt com nodos ao lado
void criaArquivo_txt(char * url, H * v){
    int i, temp;
    FILE * txt = fopen(url, "wt");
    for(i = 0; i < v->tam; i++){
            if(v->d[i].tempDia < 24){
                temp = v->d[i].tempDia;
                fprintf(txt, "| %d | %s | %d hrs |", i, v->d[i].dia, v->d[i].tempDia);
                while(temp < 24){
                    fprintf(txt, " %s - %.1f hrs |", v->s[i]->nomeRotina, v->s[i]->tempo);
                    temp = temp + v->s[i]->tempo;
                }
                fprintf(txt, "\n");
            }else{
                fprintf(txt, "| %d | %s | %d | NULL\n", i, v->d[i].dia, v->d[i].tempDia);
            }
    }

    fclose(txt);
}

int main(){
    char name[30], nameRot[50], url[100] = "E:\\Estruturas de Dados\\Trab\\GerenciaSemanal.txt";
    int tipo, esc, diaSemana, tarDia = 0, inserir;
    float tempo;

    H * v = criaHash(5);

    //printf("Digite seu nome: ");
    //gets(name);
    //system("cls");
//    do{
//    printf("\t\t\tMENU\n1 - Tarefa Diaria\n2 - Tarefa em dia especifico \n3 - Tarefa em dia com mais tempo\n4 - Ver tarefas\n");
//    esc = getche();
//    printf("\n\n");
//    switch(esc){
//        case '1':
//            inserir = 1;
//            tarDia = 1;
//            diaSemana = 0;
//            break;
//        case '2':
//            inserir = 1;
//            printf("Dia da semana desejado: \n0 - SEGUNDA\n1 - TERCA \n2 - QUARTA\n3 - QUINTA\n4 - SEXTA\n");
//            scanf("%d", &diaSemana);
//            fflush(stdin);
//            if(diaSemana > 4)
//                diaSemana = 4;
//            printf("\n\n");
//            break;
//        case '3':
//            inserir = 1;
//            diaSemana = diaMaisLivre(v);
//            break;
//        case '4':
//            printf("\n\n");
//            printaHash(v);
//            inserir = 0;
//            printf("\n\n");
//
//    }
//        if(inserir){
//            printf("Digite o nome da rotina: ");
//            gets(nameRot);
//            printf("Digite o tempo em horas da rotina (podendo usar fra%cao de hora ex. 0.2): ", 135);
//            scanf("%f", &tempo);
//            fflush(stdin);
//            printf("Tipo da rotina \n1 - Obrigatoria\n2 - Lazer \n3 - Tarefa\nEscolha: ");
//            scanf("%d", &tipo);
//            fflush(stdin);
//            insereHash(v, tempo, &nameRot, tipo, tarDia, diaSemana);
//        }
//    }while(1);

    insereHash(v, 4, "Aula de Arquitetura de Computadores II", 1, 0, 1);
    insereHash(v, 4, "Aula de Banco de Dados I", 1, 0, 1);
    insereHash(v, 4, "Aula de Estrutura de Dados II", 1, 0, 2);
    insereHash(v, 4, "Aula de Engenharia de Software", 1, 0, 2);
    insereHash(v, 4, "Aula de Calculo II", 1, 0, 3);
    insereHash(v, 4, "Aula de Teoria dos Grafos", 1, 0, 4);
    insereHash(v, 4, "Dormir", 1, 1, 0);
    insereHash(v, 3, "Transito", 1, 0, 1);
    insereHash(v, 3, "Transito", 1, 0, 2);
    insereHash(v, 2, "Transito", 1, 0, 3);
    insereHash(v, 2, "Transito", 1, 0, 4);
    insereHash(v, 1.5, "Cortar Grama", 3, 0, diaMaisLivre(v));
    insereHash(v, 3, "League of Legends", 2, 0, diaMaisLivre(v));
    insereHash(v, 2, "Jogar Overwatch", 2, 1, 0);
    insereHash(v, 2, "Estudar em casa", 3, 0, diaMaisLivre(v));
    insereHash(v, 4, "Sair jantar fora/Festa", 2, 0, 4);
    insereHash(v, 36, "Rave", 2, 0, 3);
    insereHash(v, 18, "Teste", 1, 1, 0);

//    printaHash(v);

    criaTabelaArquivo(url, v);
//    criaArquivo_txt(url, v);
    return 0;
}
