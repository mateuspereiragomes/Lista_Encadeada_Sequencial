//
//  PosicaoNoTexto.hpp
//  Projeto3Estruturas
//
//  Created by mateus gomes on 6/25/17.
//  Copyright © 2017 mateus gomes. All rights reserved.
//

#ifndef PosicaoNoTexto_hpp
#define PosicaoNoTexto_hpp

#include <iostream>
#include <iomanip>
#include <string>

#include <stddef.h>
using namespace std;

class Posicao
{
public:
    int posicao;
    Posicao *proximoElementoPosicao;
    
    Posicao();
   
    Posicao(int posicao);


    ~Posicao();
};

#endif /* PosicaoNoTexto_hpp */
