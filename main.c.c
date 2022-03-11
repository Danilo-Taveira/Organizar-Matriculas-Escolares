/* 3) Construa um programa para:

    - Armazenar a matrícula, o nome e o endereço de até 1000 alunos.
    - Alterar o endereço de um aluno. O usuário digitará a matrícula do aluno a ser procurado para fazer a alteração.
    - Organizar em ordem crescente de matrícula os dados dos alunos (utilize um algoritmo de ordenação estudado).
    - Pesquisar o nome e endereço de um aluno, a partir da sua matrícula (utilize o algoritmo de busca binária).
    - Exibir os dados de todos os alunos. */

#include <stdio.h>
#include <string.h>
#include <locale.h>

#define LIM_MAX 1000

struct tPessoa {
    int matricula;
    char nome[40], endereco[50];
};
typedef struct tPessoa pessoa;

struct regAgenda {
    pessoa agenda[LIM_MAX];
    int totalPessoas; 
};
typedef struct regAgenda Agenda;

void cadastrar(Agenda *agenda) {
    int npessoas = agenda->totalPessoas;

    printf("\n***** CADASTRAMENTO *****\n");
    if (npessoas < LIM_MAX) {
        printf("\nDigite a matrícula do aluno: ");
        scanf("%d", &agenda->agenda[npessoas].matricula);
        printf("\nDigite o nome do aluno: ");
        scanf("%s", agenda->agenda[npessoas].nome);
        printf("\nDigite o endereço do aluno: ");
        scanf("%s", agenda->agenda[npessoas].endereco);
        printf("\nCadastro realizado com sucesso!\n");
        npessoas += 1;
        agenda->totalPessoas = npessoas;
    }
    else {
        printf("\nAgenda cheia!\n");
    }
}
void alterar(Agenda *agenda) {
    int npessoas = agenda->totalPessoas, vpessoa, achou = 0;
    int matriculaProcurada;

    if (npessoas > 0) {
        printf("\n***** ALTERANDO DADOS *****\n");
        printf("\nDigite a matrícula do aluno que deseja alterar os dados: ");
        scanf("%i", &matriculaProcurada);
        for (vpessoa = 0; vpessoa <= npessoas; vpessoa++) {
            if (agenda->agenda[vpessoa].matricula == matriculaProcurada) {
                printf("\nDigite o novo endereço: ");
                scanf("%s", agenda->agenda[vpessoa].endereco);
                printf("\nCadastro atualizado com sucesso!\n");
                achou = 1;
            }
        }
        if (achou == 0) {
            printf("\nCadastro não encontrado!\n");
        }
    }
    else {
        printf("\nAgenda vazia!\n");
    }
}
void ordenar(Agenda *agenda) {
    int npessoas = agenda->totalPessoas, vpessoa, lpessoa;
    pessoa auxiliar;
    
    printf("\n***** ORDENANDO DADOS *****\n");
    if (npessoas > 0) {
        for (vpessoa = 0; vpessoa < npessoas; vpessoa++) {
           for (lpessoa = 0; lpessoa <= npessoas - 1; lpessoa++) {
                if (agenda->agenda[vpessoa].matricula < agenda->agenda[lpessoa].matricula) {
                    auxiliar.matricula = agenda->agenda[vpessoa].matricula;
                    agenda->agenda[vpessoa].matricula = agenda->agenda[lpessoa].matricula;
                    agenda->agenda[lpessoa].matricula = auxiliar.matricula;
                    strcpy(auxiliar.nome, agenda->agenda[vpessoa].nome);
                    strcpy(agenda->agenda[vpessoa].nome, agenda->agenda[lpessoa].nome);
                    strcpy(agenda->agenda[lpessoa].nome, auxiliar.nome);
                    strcpy(auxiliar.endereco, agenda->agenda[vpessoa].endereco);
                    strcpy(agenda->agenda[vpessoa].endereco, agenda->agenda[lpessoa].endereco);
                    strcpy(agenda->agenda[lpessoa].endereco, auxiliar.endereco);
                }
            } 
        }
        printf("\nOs dados foram ordenados com sucesso!\n");
    }
    else {
        printf("\nAgenda vazia!\n");
    }
}
void pesquisar(Agenda *agenda) {
    int npessoas = agenda->totalPessoas, achou = 0, esq, meio, dir;
    int matriculaProcurada;
    
    if (npessoas > 0) {
        printf("\nDigite sua matrícula: ");
        scanf("%d", &matriculaProcurada);
        esq = 0;
        dir = npessoas-1;
        while(esq <= dir) {
            meio  = (esq + dir) / 2;
            if (agenda->agenda[meio].matricula == matriculaProcurada) {
                printf("\nNome: %s", agenda->agenda[meio].nome);
                printf("\nEndereço: %s\n", agenda->agenda[meio].endereco);
                achou = 1;
            }
            if (agenda->agenda[meio].matricula < matriculaProcurada) {
                esq = meio + 1;
            }
            else {
                dir = meio - 1;
            }
        }
        if (achou == 0) {
            printf("\nCadastro não encontrado!\n");
        }
    }
    else {
        printf("\nAgenda vazia!\n");
    }
}
void exibir(Agenda *agenda) {
    int npessoas = agenda->totalPessoas, vpessoa;
    
    printf("\n***** EXIBINDO DADOS *****\n");
    if (npessoas > 0) {
        for (vpessoa = 0; vpessoa < npessoas; vpessoa++) {
            printf("\nNome: %s", agenda->agenda[vpessoa].nome);
            printf("\nMatrícula: %d", agenda->agenda[vpessoa].matricula);
            printf("\nEndereço: %s", agenda->agenda[vpessoa].endereco);
            printf("\n");
        }
    }
    else {
        printf("\nAgenda vazia!\n");
    }
}

int main() {
    setlocale (LC_ALL, "");
    Agenda minhaAgenda;
    int opcao;
    
    minhaAgenda.totalPessoas = 0;
    while (opcao != 6) {
        printf("\n-----------------------------------\n");
        printf("             MENU                  \n");
        printf("-----------------------------------\n\n");
        printf("1 - CADASTRAR \n");
        printf("2 - ALTERAR DADOS\n");
        printf("3 - ORGANIZAR EM ORDEM CRESCENTE AS MATRÍCULAS\n");
        printf("4 - PESQUISAR NOME E ENDEREÇO\n");
        printf("5 - EXIBIR DADOS\n");
        printf("6 - ENCERRAR\n");
        printf("\n\nDigite a sua opção: ");
        scanf("%d", &opcao);
        switch (opcao) {
        case 1 : cadastrar(&minhaAgenda);
            break;
        case 2:  alterar(&minhaAgenda);
            break;
        case 3 : ordenar(&minhaAgenda);
            break;
        case 4 : pesquisar(&minhaAgenda);
            break;
        case 5 : exibir(&minhaAgenda);
            break;
        }
    }
    printf("\n-----------------------------------\n");
    printf("   ENCERRANDO... VOLTE SEMPRE ;)");
    printf("\n-----------------------------------\n");    
}