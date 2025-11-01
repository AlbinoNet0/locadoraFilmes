#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "filme.h"

typedef struct FILME {
    int id;
    char nome[50];
    float valor;
    float duracao;
    int alugado;  
    struct FILME* proximo;
} FILME;

FILME* criarFilme(char* nome, float valor, float duracao, FILME* proximo) {
    FILME* filme = (FILME*)malloc(sizeof(FILME));
    if (filme == NULL) {
        printf("ERRO DE ALOCACAO\n");
        exit(1);
    }

    strcpy(filme->nome, nome);
    filme->valor = valor;
    filme->duracao = duracao;
    filme->alugado = 0;  
    filme->proximo = proximo;

    return filme;
}

void setId(FILME* filme, int id) {
    filme->id = id;
}

int getId(FILME* filme) {
    return filme->id;
}

void setEndereco(FILME* meuFilme, FILME* lista) {
    meuFilme->proximo = lista;
}

FILME* getProximo(FILME* filme) {
    return filme->proximo;
}

char* getNome(FILME* filme) {
    return filme->nome;
}

float getValor(FILME* filme) {
    return filme->valor;
}

float getDuracao(FILME* filme) {
    return filme->duracao;
}

int taAlugado(FILME* filme) {
    return filme->alugado;
}

void alugarFilminho(FILME* filme) {
    filme->alugado = 1;
}

void devolveFilminho(FILME* filme) {
    filme->alugado = 0;
}
