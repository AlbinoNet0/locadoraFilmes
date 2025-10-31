#ifndef LOCADORA_H
#define LOCADORA_H

typedef struct LOCADORA LOCADORA;

LOCADORA* criarLocadora(char* nomeLocadora);
void novoFilme(LOCADORA* locadora, char* nome, float valor, float tempo);
void carregarFilmesDoArquivo(LOCADORA* locadora, char* nomeArquivo);

#endif