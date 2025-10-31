#ifndef FILME_H
#define FILME_H

typedef struct FILME FILME;

FILME* criarFilme(char* nome, float valor, float duracao, FILME*novo);
void setEndereco(FILME* meuFilme, FILME* lista);

FILME* getProximo(FILME* filme);
void setId(FILME* filme, int id);
char* getNome(FILME* filme);
float getValor(FILME* filme);
float getDuracao(FILME* filme);

#endif