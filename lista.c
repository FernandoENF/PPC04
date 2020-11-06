#include "lista.h"

lista* criarLista() {
  lista* nlista = (lista*) malloc(sizeof(lista));
  if(nlista != NULL){
    nlista->prim = NULL;
  }
  return nlista;
}

int listaVazia(lista *plista) {
 if(plista->prim == NULL){
   return 1;
 }else{
   return 0;
 }
}

int listaInsereFim(item nitem, lista *plista) {
  if(plista == NULL)
    return 0;
  no *pno = (no*) malloc(sizeof(no));
  if(pno == NULL)
    return 0;
  pno->item = nitem;
  if(plista->prim == NULL){
    plista->prim = pno;
    pno->prox = NULL;
    pno->ant = NULL;
  }else{
    no *aux = plista->prim;
    while(aux->prox != NULL){
      aux = aux->prox;
    }
    aux->prox = pno;
    pno->ant = aux;
    pno->prox = NULL;
  }
  return 1;
}

int listaInsereInicio(item nitem, lista *plista) {
  if(plista == NULL)
    return 0;
  no *pno = (no*) malloc(sizeof(no));
  if(pno == NULL)
    return 0;
  pno->item = nitem;
  if(plista->prim == NULL){
    plista->prim = pno;
    pno->prox = NULL;
    pno->ant = NULL;
  }else{
    pno->prox = plista->prim;
    plista->prim->ant = pno;
    plista->prim = pno;
    pno->ant = NULL;
  }
  return 1;
}

void listaImprime(lista *plista) {
 no *aux = plista->prim;
    while(aux != NULL){
      printf("%d\n", aux->item.info);
      aux = aux->prox;
    }
}

int listaTamanho(lista *plista) {
  int count = 0;
  no *aux = plista->prim;
    while(aux != NULL){
      count++;
      aux = aux->prox;
    }
    return count; 
}

int listaRemoveInicio(lista *plista){
  if (plista == NULL){
    return 0;
  }
  if(plista->prim == NULL){
    return 0;
  }
  no *remove = plista->prim;
  plista->prim = remove->prox;
  if(remove->prox != NULL){
    remove->prox->ant = NULL;
  }
  free(remove);
  return 1;
}

int listaRemoveFim(lista *plista){ 
  if (plista == NULL){
    return 0;
  }
  if(plista->prim == NULL){
    return 0;
  }
  no *remove = plista->prim;
  while(remove->prox != NULL){
    remove = remove->prox;
  }
  if(remove->ant == NULL){
    plista->prim = remove->prox;
  }else{
    remove->ant->prox = NULL;
  }
  free(remove);
  return 1;
}

float listaMediaA(lista *plista){
  if (plista == NULL){
    return 0;
  }
  if(plista->prim == NULL){
    return 0;
  }
  float media = 0;
  no *aux = plista->prim;
  do {
    media = media + aux->item.info;
    if(aux->prox != NULL){
      aux = aux->prox;
    }
  } while (aux->prox != NULL);
  media = media / listaTamanho(plista);
  return media;
}

int listaRemoveTodos(item nitem, lista *plista){
  if (plista == NULL){
    return 0;
  }
  if(plista->prim == NULL){
    return 0;
  }
  no *aux = plista->prim;
  do{
    if (nitem.info == aux->item.info){
      aux->ant->prox = aux->prox;
      aux->prox->ant = aux->ant;
      no *remove = aux;
      if(aux->prox != NULL){
        aux = aux->prox;
      }
      free(remove);
    }
  } while(aux->prox != NULL);
  return 1;
}

int listaRemoveMaior(lista *plista){
  if (plista == NULL){
    return 0;
  }
  if(plista->prim == NULL){
    return 0;
  }
  no *aux = plista->prim;
  item maior;
  while(aux != NULL) {
    if (aux->prox->item.info > aux->item.info){
      maior = aux->prox->item;
    }
    aux = aux->prox;
  }
  listaRemoveTodos(maior, plista);
  return 1;
}

lista listaMultiplos3(lista *plista){
  lista plista2;
  if (plista == NULL){
    return plista2;
  }
  if(plista->prim == NULL){
    return plista2;
  }
  no *aux = plista->prim;
  while(aux != NULL) {
    if(aux->item.info % 3 == 0){
      listaInsereInicio(aux->item, &plista2);
    }
  }
  return plista2;
}

int listaIguais(lista *plista, lista *plista2) {
  if (plista == NULL || plista2 == NULL){
    return 0;
  }
  if (plista->prim == NULL || plista2->prim == NULL) {
    return 0;
  }
  if (listaTamanho(plista) && listaTamanho(plista2)) {
    no *aux = plista->prim;
    no *aux2 = plista2->prim;
    while (aux == NULL || aux2 == NULL){
      if(aux->item.info!=aux2->item.info){
        return 0;
      }
    }    
    return 1;
  }
  return 0;
}