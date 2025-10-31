#include <stdio.h>
#include <stdlib.h>
#include "locadora/locadora.h"

int main() {
    LOCADORA * locadora = criarLocadora("Amizades Locacoes");

    char filme[] = "locadora/filmes.txt";
    carregarFilmesDoArquivo(locadora, filme);
    return 0;
}