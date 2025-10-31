#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "locadora.h"
#include "filme.h"

typedef struct LOCADORA {
    char nome_locadora[25];
    int numero_filmes;
    FILME *lista_filmes;
} LOCADORA;

LOCADORA* criarLocadora(char* nomeLocadora) {
    LOCADORA *locadora = (LOCADORA*)malloc(sizeof(LOCADORA));
    if (locadora == NULL) {
        printf("ERRO DE ALOCACAO\n");
        exit(1);
    }

    strcpy(locadora->nome_locadora, nomeLocadora);
    locadora->numero_filmes = 0;
    locadora->lista_filmes = NULL;

    return locadora;
}

void exibirFilmes(LOCADORA* locadora) {
    FILME *inicio = locadora->lista_filmes;
    if (inicio == NULL) {
        printf("VAZIA\n");
        return;
    }

    while (inicio != NULL) {
        printf("NOME: %s\nPRECO: %.2f\nDURACAO: %.2f\n\n",
               getNome(inicio), getValor(inicio), getDuracao(inicio));
        inicio = getProximo(inicio);
    }
}

void carregarFilmesDoArquivo(LOCADORA* locadora, char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo '%s'\n", nomeArquivo);
        return;
    }

    char nome[50];
    float valor, duracao;

    while (fscanf(arquivo, "%49[^,], %f, %f;", nome, &valor, &duracao) == 3) {
        // Cria o novo filme e o adiciona na frente da lista
        FILME* novo = criarFilme(nome, valor, duracao, locadora->lista_filmes);
        locadora->lista_filmes = novo;  // atualiza o início da lista
        locadora->numero_filmes++;
        setId(novo, locadora->numero_filmes);
    }

    fclose(arquivo);

    printf("Filmes carregados com sucesso (%d filmes):\n\n", locadora->numero_filmes);
    exibirFilmes(locadora);
}
