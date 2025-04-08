#include "revisao.h"
#include <iostream>
#include <sstream>
using namespace std;

struct Arv{
    int num;
    Arv *esq;
    Arv *dir;

};

bool isNull(Arv* &arv) {
  return arv == NULL;
}
bool notNull(Arv* &arv) {
    return arv != NULL;
}
void criarArv(int num, Arv* &arv, Arv* esq = NULL, Arv* dir = NULL) {
    Arv* novo = (Arv*) malloc(sizeof(Arv));
    novo->num = num;
    novo->esq = esq;
    novo->dir = dir;
    arv = novo;
}

void preOrdem(Arv* arv) {
    if (arv == NULL) return;
    printf("%d ", arv->num);
    preOrdem(arv->esq);
    preOrdem(arv->dir);
}

void emOrdem(Arv* &arv) {
    if (isNull(arv)) return;
    emOrdem(arv->esq);
    printf("%d ", arv->num);
    emOrdem(arv->dir);
}

void posOrdem(Arv* &arv) {
    if (isNull(arv)) return;
    posOrdem(arv->esq);
    posOrdem(arv->dir);
    printf("%d ", arv->num);
}
int totalNo(Arv* arv) {
    return isNull(arv) ? 0 : 1 + totalNo(arv->esq) + totalNo(arv->dir);
}

int folhas(Arv* arv) {
    if (isNull(arv)) return 0;

    return isNull(arv->esq) && isNull(arv->dir) ? 1 : folhas(arv->esq) + folhas(arv->dir);
}

int noInterno(Arv* arv) {
    if (isNull(arv)) return 0;

    return  notNull(arv->esq) || notNull(arv->dir) ?  1 + noInterno(arv->esq) + noInterno(arv->dir) : 0;
}

int altura(Arv* arv) {
    if (isNull(arv)) return 0;

    return 1 + max(altura(arv->esq), altura(arv->dir));
}

int main() {
    Arv* esquerda = NULL;
    Arv* direita = NULL;

    criarArv(2, esquerda);
    criarArv(3, direita);
    criarArv(4, esquerda->esq);
    criarArv(4, esquerda->esq->esq);

    criarArv(5,esquerda->dir);
    criarArv(6,direita->esq);
    criarArv(7,direita->dir);
    Arv* raiz = NULL;
    criarArv(1, raiz, esquerda, direita);

    printf("\nEM ORDEM:\n");
    emOrdem(raiz);
    printf("\nPRE ORDEM:\n");
    preOrdem(raiz);
    printf("\nPOS ORDEM:\n");
    posOrdem(raiz);

    printf("\n%d", folhas(raiz));
    printf("\n%d", totalNo(raiz));
    printf("\n%d",noInterno(raiz));
    printf("\n%d", altura(raiz));
}