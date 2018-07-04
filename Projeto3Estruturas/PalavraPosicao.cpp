//
//  PalavraP.cpp
//  Projeto3Estruturas
//
//  Created by mateus gomes on 6/24/17.
//  Copyright © 2017 mateus gomes. All rights reserved.
//

#include "PalavraPosicao.hpp"


PalavraPosicao::PalavraPosicao()
{
    
}
PalavraPosicao::PalavraPosicao(char* palavra, int posicao)
{
    quantidadePalavras = 0;
    listaPosicao = nullptr;
    proximoElementoPalavra = nullptr;
    this->palavra = palavra;
    this->setNovaPosicao(posicao);
}
PalavraPosicao::~PalavraPosicao()
{
    cout << "Destruindo PalavraPosicao " <<   endl;
    
}
char* PalavraPosicao::getPalavra()
{
    return this->palavra;
}

void PalavraPosicao::setPalavra(char* palavra)
{
    this->palavra = palavra;
}

int PalavraPosicao::getQuantidadePalavras()
{
    return quantidadePalavras;
}

void PalavraPosicao::setQuantidadePalavras(int quantidadePalavras)
{
    this->quantidadePalavras = quantidadePalavras;
}

void PalavraPosicao::adicionaContadorPalavra()
{
    quantidadePalavras++;
}
void PalavraPosicao::setNovaPosicao(int posicao)
{
    Posicao *novaPosicao = new Posicao(posicao);
    
    if (listaPosicao == nullptr)
    {
        listaPosicao = novaPosicao;
    }
    else
    {
        Posicao * teste = listaPosicao;
        
        while (teste->proximoElementoPosicao != nullptr)
        {
            
            teste = teste->proximoElementoPosicao;
            
        }
        
        teste->proximoElementoPosicao = novaPosicao;
    }

    adicionaContadorPalavra();
}

Posicao* PalavraPosicao::getListaPosicao()
{
    return listaPosicao;
}

PalavraPosicao* PalavraPosicao::getProximoElemento()
{
    return proximoElementoPalavra;
}

void PalavraPosicao::setProximoElemento(PalavraPosicao* proximoElementoPalavra)
{
    this->proximoElementoPalavra = proximoElementoPalavra;
}
