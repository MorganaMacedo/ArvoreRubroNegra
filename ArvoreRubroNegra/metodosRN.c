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

struct No*giraParaDireita(struct No*dir) { //=> mão que tu escreve 
    struct No*esq = dir->esquerda;
    dir->esquerda = esq->direita;
    esq->direita = dir;
    esq->corNo = dir->corNo;
    dir->corNo = vermelha;
    return esq;
}

struct No*giraParaEsquerda(struct No*esq) {// <=
    struct No*dir = esq->direita;
    esq->direita = dir->esquerda;
    dir->esquerda = esq;
    dir->corNo = esq->corNo;
    esq->corNo = vermelha;
    return dir;
}

int metodoCor(struct No*altura) {
    if (altura != NULL) {
        return altura->corNo;
    } else {
        return preta;

    }
}

void mudaCor(struct No*altura) {
    altura->corNo = !altura->corNo;
    if (altura->esquerda != NULL) {
        altura->esquerda->corNo = !altura->esquerda->corNo;

    }
    if (altura->direita != NULL) {
        altura->direita->corNo = !altura->direita->corNo;
    }
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
    if (dado == altura->aux) {
        *aux1 = 0; //tira o valor se tiver 2 ==

    } else {
        if (dado < altura->aux) { // <= dados menores não é a que eu escrevo
            altura-> esquerda = insereNodo(altura->esquerda, dado, aux1);

        } else {
            altura-> direita = insereNodo(altura->direita, dado, aux1);

        }
    }
    if (metodoCor(altura->direita) == vermelha && metodoCor(altura->esquerda) == preta) {
        altura = giraParaEsquerda(altura);

    }
    if (metodoCor(altura->esquerda) == vermelha && metodoCor(altura->esquerda->esquerda) == vermelha) {
        altura = giraParaDireita(altura);

    }
    if (metodoCor(altura->esquerda) == vermelha && metodoCor(altura->direita) == vermelha) {
        mudaCor(altura);

    }
    return altura;


};

int inserirNaArvore(ArvoreRN*ponteiroRaiz, int dado) {
    int aux1;
    *ponteiroRaiz = insereNodo(*ponteiroRaiz, dado, &aux1);


    if ((*ponteiroRaiz) != NULL) {
        (*ponteiroRaiz)->corNo = preta;
    }
    return aux1;

}

void imprimeEmOrdem(ArvoreRN*ponteiroRaiz, int altura) {
    if (ponteiroRaiz == NULL) {
        return 0;
    }
    if ((*ponteiroRaiz) != NULL) {
        imprimeEmOrdem(&((*ponteiroRaiz)->esquerda), altura + 1);
        if ((*ponteiroRaiz)->corNo == vermelha) {
            printf("%d É Vermelha: \t Altura(%d) \n ", (*ponteiroRaiz)->aux, altura);

        } else {
            printf("%d É Preta: \t Altura(%d) \n ", (*ponteiroRaiz)->aux, altura);

        }
        imprimeEmOrdem(&((*ponteiroRaiz)->direita), altura + 1);

    }
}

void imprimeEmPosOrdem(ArvoreRN*ponteiroRaiz, int altura) {
    if (ponteiroRaiz == NULL) {
        return 0;
    }
    if ((*ponteiroRaiz) != NULL) {
        imprimeEmPosOrdem(&((*ponteiroRaiz)->esquerda), altura + 1);
        imprimeEmPosOrdem(&((*ponteiroRaiz)->direita), altura + 1);

        if ((*ponteiroRaiz)->corNo == vermelha) {
            printf("%d É Vermelha: \t Altura(%d) \n ", (*ponteiroRaiz)->aux, altura);

        } else {
            printf("%d É Preta: \t Altura(%d) \n ", (*ponteiroRaiz)->aux, altura);

        }
    }


}

void imprimeEmPreOrdem(ArvoreRN*ponteiroRaiz, int altura) {
    if (ponteiroRaiz == NULL) {
        return 0;
    }
    if ((*ponteiroRaiz) != NULL) {

        if ((*ponteiroRaiz)->corNo == vermelha) {
            printf("%d É Vermelha: \t Altura(%d) \n ", (*ponteiroRaiz)->aux, altura);

        } else {
            printf("%d É Preta: \t Altura(%d) \n ", (*ponteiroRaiz)->aux, altura);

        }
        imprimeEmPreOrdem(&((*ponteiroRaiz)->esquerda), altura + 1);
        imprimeEmPreOrdem(&((*ponteiroRaiz)->direita), altura + 1);

    }


}

int alturadaArvore(ArvoreRN*ponteiroRaiz) {
    int aDireita, aEsquerda;

    if (ponteiroRaiz == NULL) {
        return 0;
    }
    if (*ponteiroRaiz == NULL) {
        return 0;
    }
    aDireita = alturadaArvore(&((*ponteiroRaiz)->direita));
    aEsquerda = alturadaArvore(&((*ponteiroRaiz)->esquerda));
    if (aDireita < aEsquerda) {
        return (aEsquerda + 1);
    } else {
        return (aDireita + 1);

    }
}

int ArvoreVazia(ArvoreRN *ponteiroRaiz) {
    if (ponteiroRaiz == NULL) {
        return 0;
    }
    if ((*ponteiroRaiz) == NULL) {
        return 0;
    }
    return 1;
}

int quantidadeNos(ArvoreRN*ponteiroRaiz) {
    int nosEsq, nosDir;
    if (ponteiroRaiz == NULL) {
        return 0;
    }
    if (*ponteiroRaiz == NULL) {
        return 0;
    }
    nosEsq = quantidadeNos(&((*ponteiroRaiz)->esquerda));
    nosDir = quantidadeNos(&((*ponteiroRaiz)->direita));

    return (nosEsq + nosDir + 1);
}

void liberaNos(struct No*nos) {
    if (nos == NULL) {
        return 0;

    }
    liberaNos(nos->esquerda);
    liberaNos(nos->direita);
    free(nos);
    nos = NULL;

}

void LiberaNosDaArvore(ArvoreRN*ponteiroRaiz) {
    if (ponteiroRaiz == NULL) {
        return 0;

    }
    liberaNos(*ponteiroRaiz);
    free(ponteiroRaiz);
}

int consultarDaArvore(ArvoreRN*ponteiroRaiz, int numero) {
    struct No* atual = *ponteiroRaiz;
    if (ponteiroRaiz == NULL) {
        return 0;
    }
    while (atual != NULL) {
        if (numero == atual->aux) {
            return 1;
        }
        if (numero > atual->aux) {
            atual = atual->direita;
        } else {
            atual = atual->esquerda;
        }

    }
    return 0;
}