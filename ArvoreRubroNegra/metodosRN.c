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

int inserirNaArvore(ArvoreRN*ponteiroRaiz, int dado){
    
}