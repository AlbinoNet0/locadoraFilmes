#include <stdio.h>
#include <stdlib.h>
#include "locadora/locadora.h"

int main() {
    LOCADORA * locadora = criarLocadora("Locadora Eros +18 movies");

    char filme[] = "locadora/filmes.txt";
    carregarFilmesDoArquivo(locadora, filme);
    mostraDisponiveis(locadora);
    alugaPorId(locadora, 2);
    mostraAlugados(locadora);
    devolvePorId(locadora, 2);
    
    return 0;
}