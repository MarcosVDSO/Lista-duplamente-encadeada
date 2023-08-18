//TAD 03
//AUTOR:
//-MARCOS VINICIUS DOS SANTOS OLIVEIRA

#include "dllist.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

typedef struct _aluno_ {
  char nome[30];
  int numero;
  float nota;

} Aluno;

typedef struct _dlnode_ {
  DLnode *next;
  DLnode *prev;
  void *data;
} DLnode;

typedef struct _dllist_ {
  DLnode *first;
  DLnode *cur;
} DLList;

int main() {
  int resposta, cont = 1, maxItens, escolha, numItens, status;
  char nome[30];
  float nota;
  DLList *lista = NULL;
  Aluno *aluno, alunos[30];

  do {
    printf("Indique o que deseja fazer:\n");
    printf("1 - Criar uma lista\n");
    printf("2 - Inserir elementos na lista\n");
    printf("3 - Listar os elementos da lista\n");
    printf("4 - Consultar um dos elementos da lista\n");
    printf("5 - Remover algum elemento da lista\n");
    printf("6 - Esvaziar a lista\n");
    printf("7 - Destruir a lista\n");
    resposta = -1;
    scanf("%d", &resposta);
    switch (resposta) {
    case 1:

      lista = dllcreate();
      if (lista != NULL) {
                    printf("Lista criada com sucesso!\n");

      } else {
        printf("Erro ao fazer a lista\n");
      }
      break;

    case 2:
      if (lista == NULL) {
        printf("Aloque primeiro a lista\n");
        break;
      }

      aluno = (Aluno *)malloc(sizeof(Aluno));

      if (aluno == NULL) {
        printf("Não pude alocar aluno. Saindo\n");
        break;
      }
      printf("Digite o nome do aluno: ");
      scanf("%s", aluno->nome);
      while (getchar() != '\n')
        ; // Limpa o stdin caso a pessoa tenha digitado um sobrenome

      printf("Digite o numero do aluno: ");
      scanf("%d", &aluno->numero);

      printf("Digite a nota do aluno: ");
      scanf("%f", &aluno->nota);

      dllInsertAsFirst(lista, aluno);
      numItens++;
      printf("Aluno %s, com numero %d e nota %.2f inserido com sucesso\n", aluno->nome, aluno->numero, aluno->nota);
      break;

    case 3:
      if (lista == NULL) {
        printf("Aloque primeiro a lista\n");
        break;
      }

      if (lista->first == NULL) {
        printf("Bote algo na lista antes!\n");
        break;
      }
      lista->cur = dllGetFirst(lista);
      Aluno *a = lista->cur->data;
      printf("Nome: %s\n", a->nome);
      printf("Numero: %d\n", a->numero);
      printf("Nota: %.2f\n\n", a->nota);
      
      while(lista->cur->next!=NULL) {
        lista->cur = dllGetNext(lista);
        a = lista->cur->data;
        printf("Nome: %s\n", a->nome);
        printf("Numero: %d\n", a->numero);
        printf("Nota: %.2f\n\n", a->nota);
      }

      break;

    case 4:
      if (lista == NULL) {
        printf("Aloque primeiro a lista\n");
        break;
      }

      if (lista->first == NULL) {
        printf("Bote algo na lista antes!\n");
        break;
      }

      printf("Você deseja procurar por:\n");
      printf("1 - Nome\n");
      printf("2 - Numero\n");
      printf("3 - Nota\n");
      scanf("%d", &escolha);

      switch (escolha) {
      case 1:
        printf("Digite o nome a procurar: ");
        scanf("%s", nome);
        status = dllQuery(lista, (void *)nome, QueryAlunoNome);
        if (status == 1) {
          printf("Está na lista!\n");
        } else {
          printf("Não está na lista\n");
        }
        break;
      case 2:
        printf("Digite o numero a procurar: ");
        scanf("%d", &resposta);
        status = dllQuery(lista, (void *)&resposta, QueryAlunoNumero);
        if (status == 1) {
          printf("Está na lista!\n");
        } else {
          printf("Não está na lista\n");
        }

        break;
      case 3:
        printf("Digite a nota a procurar: ");
        scanf("%f", &nota);
        status = dllQuery(lista, (void *)&nota, QueryAlunoNota);
        if (status == 1) {
          printf("Está na lista!\n");
        } else {
          printf("Não está na lista\n");
        }
      }
      break;
    case 5:
        if (lista == NULL) {
            printf("Aloque primeiro a lista\n");
            break;
        }

        if (lista->first==NULL) {
            printf("Bote algo no cofo antes!\n");
            break;
        }

        printf("Você deseja remover por:\n");
        printf("1 - Nome\n");
        printf("2 - numero\n");
        printf("3 - Nota\n");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o nome a procurar: ");
                scanf("%s", nome);
                aluno = dllRemoveSpec(lista, (void*)nome, QueryAlunoNome);
            printf("O seguinte aluno foi removido:\n");
            printf("Nome: %s\n", aluno->nome);
            printf("numero: %d", aluno->numero);
            printf("Nota: %.2f\n", aluno->nota);
              //printf("Aluno removido!\n")
              break; 
          case 2: printf("Digite o numero a procurar: ");
                scanf("%d", &resposta);
                aluno = dllRemoveSpec(lista, (void*)&resposta,
QueryAlunoNumero);
            printf("O seguinte aluno foi removido:\n");
            printf("Nome: %s\n", aluno->nome);
            printf("numero: %d\n", aluno->numero);
            printf("Nota: %.2f\n", aluno->nota);
              //printf("Aluno removido!\n")
            break; 
          case 3: printf("Digite a nota a procurar: ");
                scanf("%f", &nota);
                aluno = dllRemoveSpec(lista, (void*)&nota,
QueryAlunoNota);
             printf("O seguinte aluno foi removido:\n");
            printf("Nome: %s\n", aluno->nome);
            printf("numero: %d", aluno->numero);
            printf("Nota: %.2f\n", aluno->nota);
            //printf("Aluno removido!\n")
          break;
        }

        break;

    case 6:
      if (lista == NULL) {
          printf("Aloque primeiro a lista\n");
          break;
      }
  
      if (lista->first == NULL) {
          printf("Bote algo na lista antes!\n");
          break;
      }
      dllRemoveAll(lista);
      printf("A lista foi esvaziada!\n");
      break;
    case 7:
        if (lista == NULL) {
            printf("Aloque primeiro a lista\n");
            break;
        }
    
        if (lista->first!=NULL) {
            printf("A lista deve estar vazia!\n");
            break;
        }
        dlldestroy(lista);
        printf("Lista destruída!\n");
        lista = NULL;
        break;
    default:
      printf("Saindo\n");
      cont = 0;
    }

    printf("Pressione um botão para continuar\n");
    while (getchar() != '\n');        // Limpa o stdin
    getchar(); // Espera a pessoa digitar ENTER

  } while (cont);

  // if (cofo != NULL) {
  //  gcofEsvaziar(cofo);
  //}
}