//TAD 03
//DUPLA:
//-MARCOS VINICIUS DOS SANTOS OLIVEIRA
//-ALEFF MOTA QUIXABA VIEIRA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define _DLLIST_C_
#include "dllist.h"

typedef struct _dlnode_ {
  DLnode *next;
  DLnode *prev;
  void *data;
} DLnode;

typedef struct _dllist_ {
  DLnode *first;
  DLnode *cur;
} DLList;

typedef struct _aluno_ {
  char nome[30];
  int numero;
  float nota;
} Aluno;

DLList *dllcreate() {
  DLList *l;
  l = (DLList *)malloc(sizeof(DLList));
  if (l != NULL) {
    l->first = NULL;
    l->cur = NULL;
    return l;
  }
  return NULL;
}

int dlldestroy(DLList *l) {
  if (l != NULL) {
    if (l->first != NULL) {
      free(l->first);
      free(l->cur);
      free(l);
      return TRUE;
    }
    return FALSE;
  }
}

int dllInsertAsFirst(DLList *l, void *data) {
  DLnode *newnode;
  if (l != NULL) {
    newnode = (DLnode *)malloc(sizeof(DLnode));
    if (newnode != NULL) {
      newnode->data = data;
      newnode->prev = NULL;
      newnode->next = l->first;
      if (l->first != NULL) {
        l->first->prev = newnode;
      }
      l->first = newnode;
      return TRUE;
    }
  }
  return FALSE;
}

DLnode *dllGetFirst(DLList *l) {
  if (l != NULL) {
    l->cur = l->first;
    return l->cur;
  }
  return NULL;
}

DLnode *dllGetNext(DLList *l) {
  if (l != NULL) {
    if (l->cur != NULL) {
      l->cur = l->cur->next;
      return l->cur;
    }
  }
  return NULL;
}


int dllQuery(DLList *l, void *key, int (*cmp)(void *, void *)) {
  DLnode *prevnode, *nextnode, *spec;
  int stat;
  prevnode = (DLnode *)malloc(sizeof(DLnode));
  nextnode = (DLnode *)malloc(sizeof(DLnode));
  spec = (DLnode *)malloc(sizeof(DLnode));
  if (prevnode == NULL || nextnode == NULL || spec == NULL) {
    return FALSE;
  }
  if (l != NULL) {
    if (l->first != NULL) {
      spec = l->first;
      stat = cmp(key, spec->data);
      while (spec->next != NULL && stat != TRUE) {
        spec = spec->next;
        stat = cmp(key, spec->data);
      }
      if (stat == TRUE) {
        return TRUE;
      }
    }
  }
  return FALSE;
}


void *dllRemoveSpec(DLList *l, void *key,int (*cmp)(void *, void *)) {
  DLnode *prevnode, *nextnode, *spec;
  int stat;
  void *data;
  prevnode = (DLnode *)malloc(sizeof(DLnode));
  nextnode = (DLnode *)malloc(sizeof(DLnode));
  spec = (DLnode *)malloc(sizeof(DLnode));
  if (prevnode == NULL || nextnode == NULL || spec == NULL) {
    return NULL;
  }
  if (l != NULL) {
    if (l->first != NULL) {
      spec = l->first;
      stat = cmp(key, spec->data);
      while (spec->next != NULL && stat != TRUE) {
        spec = spec->next;
        stat = cmp(key, spec->data);
      }
      if (stat == TRUE) {
        nextnode = spec->next;
        prevnode = spec->prev;
        data = spec->data;
        if (prevnode != NULL) {
          prevnode->next = nextnode;
        } else {
          l->first = nextnode;
        }
        if (nextnode != NULL) {
          nextnode->prev = prevnode;
        }
        free(spec);
        return data;
      }
    }
  }
  return NULL;
}

int QueryAlunoNota(void *al, void *nota) {
  Aluno *pa;
  float *pnota;
  pa = (Aluno *)al;
  pnota = (float *)nota;
  if (pa->nota == *pnota) {
    return FALSE;
  } else {
    return TRUE;
  }
}

int QueryAlunoNome(void *al, void *nome) {
  Aluno *pa;
  char *pnome;
  pa = (Aluno *)al;
  pnome = (char *)nome;
  if (strcmp(pa->nome, pnome) == FALSE) {
    return TRUE;
  } else {
    return FALSE;
  }
}

int QueryAlunoNumero(void *al, void *numero) {
  Aluno *pa;
  int *pnumero;
  pa = (Aluno *)al;
  pnumero = (int *)numero;
  if (pa->numero == *pnumero) {
    return FALSE;
  } else {
    return TRUE;
  }
}

int dllRemoveAll(DLList *l){
  DLnode *node, *aux;
  node = l->first;
  if(l!=NULL){
    while(node!=NULL){
      aux = node;
      node = node->next;
      free(aux);
      }
    l->first = NULL;
    return TRUE;
  }
  return FALSE;
}