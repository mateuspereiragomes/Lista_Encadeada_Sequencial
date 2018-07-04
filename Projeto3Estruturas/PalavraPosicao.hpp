//
//  PalavraPosicao.hpp
//  Projeto3Estruturas
//
//  Created by mateus gomes on 6/24/17.
//  Copyright © 2017 mateus gomes. All rights reserved.
//

#ifndef PalavraPosicao_hpp
#define PalavraPosicao_hpp


#include <iostream>
#include <iomanip>
#include <string>
#include "PosicaoNoTexto.hpp"

using namespace std;


class PalavraPosicao
{
    
public:
    char* palavra;
    int quantidadePalavras;
    
    Posicao* listaPosicao;
    PalavraPosicao *proximoElementoPalavra;
    
    void setQuantidadePalavras(int quantidadePalavras);
    void adicionaContadorPalavra();
    

    PalavraPosicao();
    PalavraPosicao(char* palavra, int posicao);
    ~PalavraPosicao();
    
    char* getPalavra();
    void setPalavra(char* palavra);
    
    int getQuantidadePalavras();
   
    void setNovaPosicao(int posicao);
    Posicao* getListaPosicao();
    
    PalavraPosicao* getProximoElemento();
    void setProximoElemento(PalavraPosicao* proximoElemento);

};

#endif /* PalavraPosicao_hpp */
