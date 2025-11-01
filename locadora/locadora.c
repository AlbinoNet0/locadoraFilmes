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
        printf("ID: %d\nNOME: %s\nPRECO: %.2f\nDURACAO: %.2f\nSTATUS: %s\n\n",
               getId(inicio), getNome(inicio), getValor(inicio), getDuracao(inicio),
               taAlugado(inicio) ? "ALUGADO" : "DISPONIVEL");
        inicio = getProximo(inicio);
    }
}

void mostraDisponiveis(LOCADORA* locadora) {
    FILME *inicio = locadora->lista_filmes;
    if (inicio == NULL) {
        printf("VAZIA\n");
        return;
    }

    printf("=== FILMES DISPONVEIS ===\n\n");
    while (inicio != NULL) {
        if (!taAlugado(inicio)) {
            printf("ID: %d\nNOME: %s\nPRECO: %.2f\nDURACAO: %.2f\n\n",
                   getId(inicio), getNome(inicio), getValor(inicio), getDuracao(inicio));
        }
        inicio = getProximo(inicio);
    }
}

void mostraAlugados(LOCADORA* locadora) {
    FILME *inicio = locadora->lista_filmes;
    if (inicio == NULL) {
        printf("VAZIA\n");
        return;
    }

    printf("=== FILMES ALUGADOS ===\n\n");
    while (inicio != NULL) {
        if (taAlugado(inicio)) {
            printf("ID: %d\nNOME: %s\nPRECO: %.2f\nDURACAO: %.2f\n\n",
                   getId(inicio), getNome(inicio), getValor(inicio), getDuracao(inicio));
        }
        inicio = getProximo(inicio);
    }
}

FILME* buscaPorId(LOCADORA* locadora, int id) {
    FILME *filme = locadora->lista_filmes;
    while (filme != NULL) {
        if (getId(filme) == id) {
            return filme;
        }
        filme = getProximo(filme);
    }
    return NULL;
}

void alugaPorId(LOCADORA* locadora, int id) {
    FILME* filme = buscaPorId(locadora, id);
    if (filme == NULL) {
        printf("Filme com ID %d nao encontrado.\n", id);
        return;
    }
    
    if (taAlugado(filme)) {
        printf("Filme %s ja esta alugado.\n", getNome(filme));
        return;
    }
    
    alugarFilminho(filme);
    printf("Filme %s alugado com sucesso!\n", getNome(filme));
}

void devolvePorId(LOCADORA* locadora, int id) {
    FILME* filme = buscaPorId(locadora, id);
    if (filme == NULL) {
        printf("Filme com ID %d nao encontrado.\n", id);
        return;
    }
    
    if (!taAlugado(filme)) {
        printf("Filme %s nao esta alugado.\n", getNome(filme));
        return;
    }
    
    devolveFilminho(filme);
    printf("Filme %s devolvido com sucesso!\n", getNome(filme));
}

void carregarFilmesDoArquivo(LOCADORA* locadora, char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        return;
    }

    char nome[50];
    float valor, duracao;

    while (fscanf(arquivo, "%49[^,], %f, %f;", nome, &valor, &duracao) == 3) {
        FILME* novo = criarFilme(nome, valor, duracao, locadora->lista_filmes);
        locadora->lista_filmes = novo;  
        locadora->numero_filmes++;
        setId(novo, locadora->numero_filmes);
    }

    fclose(arquivo);

    printf("Filmes carregados com sucesso (%d filmes):\n\n", locadora->numero_filmes);
    exibirFilmes(locadora);
}
