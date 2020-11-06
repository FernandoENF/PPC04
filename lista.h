#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int info;
} item;

typedef struct no{
  struct no *prox;
  struct no *ant;
  item item;
} no;

typedef struct {
  struct no *prim;
} lista;


lista* criarLista();
int listaVazia(lista *plista);
int listaInsereFim(item nitem, lista *plista);
int listaInsereInicio(item nitem, lista *plista);
void listaImprime(lista *plista);
int listaTamanho(lista *plista);
int listaRemoveInicio(lista *plista);
int listaRemoveFim(lista *plista);
float listaMediaA(lista *plista);
int listaRemoveTodos(item nitem, lista *plista);
int listaRemoveMaior(lista *plista);
lista listaMultiplos3(lista *plista);
int listaIguais(lista *plista, lista *plista2);
