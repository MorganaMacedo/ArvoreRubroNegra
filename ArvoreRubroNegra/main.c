/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: morgana
 *
 * Created on 20 de Maio de 2017, 1:19
 */

#include <stdio.h>
#include <stdlib.h>
#include "rubroNegra.h"

/*
 * 
 */
int main(int argc, char** argv) {

    ArvoreRN * ponteiroRaiz = criaArvore();
    if (ponteiroRaiz != NULL) {
        printf("*****************************1º Teste\n");
        printf("Árvore criada com sucesso\n");
    } else {
        printf("Problema na criação da Árvore\n");
    }


    inserirNaArvore(ponteiroRaiz, 10);

    if (ponteiroRaiz > 0) {
        printf("*****************************2º Teste\n");
        printf("Dado inserido com sucesso\n");
    } else {
        printf("Problema na inserção da Árvore\n");
    }
    //  printf("%p\n", *ponteiroRaiz);

    printf("*****************************3º Teste\n");

    inserirNaArvore(ponteiroRaiz, 20);

    //  printf("%p\n", *ponteiroRaiz);
    inserirNaArvore(ponteiroRaiz, 5);
    inserirNaArvore(ponteiroRaiz, 2);
    inserirNaArvore(ponteiroRaiz, 30);


    imprimeEmOrdem(ponteiroRaiz, 0);



    return (EXIT_SUCCESS);
}

