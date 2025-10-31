#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "locadora.h"
#include "filme.h"

typedef struct LOCADORA {
    char nome_locadora[25];
    int numero_filmes;
    FILME * lista_filmes;
} LOCADORA;

LOCADORA* criarLocadora(char* nomeLocadora) {
    LOCADORA * locadora = (LOCADORA*)malloc(sizeof(LOCADORA));

    if(locadora == NULL) {
        printf("ERRO DE ALOCACAO\n");
        exit(1);
    }

    strcpy(locadora->nome_locadora, nomeLocadora);
    locadora->numero_filmes = 0;
    locadora->lista_filmes = NULL;

    return locadora;
}

// void novoFilme(LOCADORA* locadora, char* nome, float valor, float tempo) {
//     FILME * novo = criarFilme(nome, valor, tempo);
//     if(novo == NULL) {
//         printf("ERRO DE ALOCACAO\n");
//         exit(1);
//     }
    
//     endereco(novo, locadora->lista_filmes);
//     locadora->lista_filmes = novo;
//     locadora->numero_filmes++;
//     setId(novo, locadora->numero_filmes);
// }

// VER LISTAS DE FILMES DISPONIVEIS PARA ALUGAR
void exibirFilmes(LOCADORA* filmes) {
    FILME * inicio = filmes->lista_filmes;
    if(inicio == NULL) {
        printf("VAZIA\n");
        return;
    }

    while(inicio != NULL) {
        printf("NOME: %s\nPRECO: %.2f\nDURACAO: %.2f\n\n", getNome(inicio),
                getValor(inicio), getDuracao(inicio));

        inicio = getProximo(inicio);
    }
}

void carregarFilmesDoArquivo(LOCADORA* locadora, char* nomeArquivo) {
    FILE* arquivo;
    arquivo = fopen(nomeArquivo, "r");

    char nome[50];
    float valor;
    float duracao;

    if(arquivo == NULL) {
        printf("o arquivo nao foi aberto\n");
    } else {
        while(fscanf(arquivo, "%49[^,], %f, %f;", nome, &valor, &duracao) == 3) {
            criarFilme(nome, valor, duracao, locadora->lista_filmes);
        }
        exibirFilmes(locadora);
    }

    fclose(arquivo);
}