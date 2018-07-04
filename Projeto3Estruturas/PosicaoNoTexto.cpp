//
//  PosicaoNoTexto.cpp
//  Projeto3Estruturas
//
//  Created by mateus gomes on 6/25/17.
//  Copyright © 2017 mateus gomes. All rights reserved.
//

#include "PosicaoNoTexto.hpp"
Posicao::Posicao()
{
    this->proximoElementoPosicao = nullptr;
}
Posicao::Posicao(int posicao)
{
    this->proximoElementoPosicao = nullptr;
    this->posicao = posicao;
}
Posicao::~Posicao()
{
    cout << "Destruindo Posicao" << endl;
    
}
