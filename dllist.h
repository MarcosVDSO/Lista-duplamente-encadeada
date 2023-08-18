  //TAD 03
  //DUPLA:
  //-MARCOS VINICIUS DOS SANTOS OLIVEIRA
  //-ALEFF MOTA QUIXABA VIEIRA
  
typedef struct _dlnode_ DLnode;
typedef struct _dllist_ DLList;

DLList *dllcreate();
int dlldestroy(DLList *l);
int dllInsertAsFirst(DLList *l, void *data);
int dllQuery(DLList *l, void *key, int (*cmp)(void *, void *));
void *dllRemoveSpec(DLList *l, void *key, int (*cmp)(void *, void *));
int QueryAlunoNota(void *al, void *nota);
int QueryAlunoNome(void *al, void *nome);
int QueryAlunoNumero(void *al, void *numero);
DLnode *dllGetFirst(DLList *l);
DLnode *dllGetNext(DLList *l);
int dllRemoveAll(DLList *l);