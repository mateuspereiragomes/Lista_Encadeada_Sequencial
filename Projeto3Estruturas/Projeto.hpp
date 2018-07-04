//
//  Projeto.hpp
//  Projeto3Estruturas
//
//  Created by mateus gomes on 6/26/17.
//  Copyright © 2017 mateus gomes. All rights reserved.
//

#ifndef Projeto_hpp
#define Projeto_hpp

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Projeto
{
private:
    
    string caminhoArquivo;
    
public:
    
    Projeto();
    
    string getCaminhoArquivo();
    void setCaminhoArquivo(string caminhoArquivo);
    
    void escolherOpcaoInicialDesejada();

    
};

#endif /* Projeto_hpp */
