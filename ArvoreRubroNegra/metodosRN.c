/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "rubroNegra.h"
#define preta 1
#define vermelha 0

struct No {
    struct No*direita; //mão que eu escrevo
    struct No*esquerda;
    int aux;
    int corNo;
};

ArvoreRN*criaArvore() {
    ArvoreRN*ponteiroRaiz = (ArvoreRN*) malloc(sizeof (ArvoreRN));
    if (ponteiroRaiz != NULL) {
        *ponteiroRaiz = NULL;

    }
    return ponteiroRaiz;
}

struct No*insereNodo(struct No*altura, int dado, int *aux1) {
    if (altura == NULL) { //acho que está ok
        struct No*primeiroNo;
        primeiroNo = (struct No*) malloc(sizeof (struct No));
        if (primeiroNo == NULL) {
            *aux1 = 0;
            return NULL;

        }
        primeiroNo->direita = NULL;
        primeiroNo->esquerda = NULL;
        primeiroNo->corNo = vermelha;
        primeiroNo->aux = dado;
        *aux1 = 1;
        return primeiroNo;
    }


};

int inserirNaArvore(ArvoreRN*ponteiroRaiz, int dado) {
    int aux1;
    *ponteiroRaiz = insereNodo(*ponteiroRaiz, dado, &aux1);


    if ((*ponteiroRaiz) != NULL) {
        (*ponteiroRaiz)->corNo = preta;
    }
    return aux1;

}