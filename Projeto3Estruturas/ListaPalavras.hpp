//
//  ListaPalavras.hpp
//  Projeto3Estruturas
//
//  Created by mateus gomes on 6/24/17.
//  Copyright © 2017 mateus gomes. All rights reserved.
//

#ifndef ListaPalavras_hpp
#define ListaPalavras_hpp

#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <string.h>
#include "PalavraPosicao.hpp"


using namespace std;

class ListaPalavras
{
public:
    
    
    void pesquisaPalavrasParecidas(char* palavra);

    PalavraPosicao* primeiroElemento;
    
    int quantidadePalavras;

    void setNovaPalavraPosicao(PalavraPosicao *novaPalavraPosicao);
    void setPrimeiroElemento(PalavraPosicao* primeiroElemento);
    void adicionaContadorPalavras();
    
    ListaPalavras();
    ~ListaPalavras();
    
    void finalizarLista();
    
    int getQuantidadePalavras();

    PalavraPosicao* getPrimeiroElemento();
    
    void imprimirElementos();
    
    PalavraPosicao* verificaExistencia(char* palavra);
    
    void realizarCadastroNovaPalavra(char *palavra, int posicao);
    };



#endif /* ListaPalavras_hpp */
