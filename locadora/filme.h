#ifndef FILME_H
#define FILME_H

typedef struct FILME FILME;

FILME* criarFilme(char* nome, float valor, float duracao, FILME*novo);
void setEndereco(FILME* meuFilme, FILME* lista);

FILME* getProximo(FILME* filme);
void setId(FILME* filme, int id);
int getId(FILME* filme);
char* getNome(FILME* filme);
float getValor(FILME* filme);
float getDuracao(FILME* filme);
int taAlugado(FILME* filme);
void alugarFilminho(FILME* filme);
void devolveFilminho(FILME* filme);

#endif