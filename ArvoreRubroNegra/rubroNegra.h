/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   rubroNegra.h
 * Author: morgana
 *
 * Created on 20 de Maio de 2017, 1:19
 */

typedef struct No* ArvoreRN;

ArvoreRN*criaArvore();

int inserirNaArvore(ArvoreRN*ponteiroRaiz, int dado);

void imprimeEmOrdem(ArvoreRN*ponteiroRaiz, int altura);

void imprimeEmPosOrdem(ArvoreRN*ponteiroRaiz, int altura);

void imprimeEmPreOrdem(ArvoreRN*ponteiroRaiz, int altura);

int alturadaArvore(ArvoreRN*ponteiroRaiz);

int ArvoreVazia(ArvoreRN *ponteiroRaiz);

int quantidadeNos(ArvoreRN*ponteiroRaiz);

void LiberaNosDaArvore(ArvoreRN*ponteiroRaiz);

int consultarDaArvore(ArvoreRN*ponteiroRaiz, int numero);

int removeArvore(ArvoreRN*ponteiroRaiz, int dado);