//
//  ProcessamentoTexto.hpp
//  Projeto3Estruturas
//
//  Created by mateus gomes on 6/24/17.
//  Copyright © 2017 mateus gomes. All rights reserved.
//

#ifndef ProcessamentoTexto_hpp
#define ProcessamentoTexto_hpp

#include <iostream>
#include <iomanip>
#include <string>
#include "ListaPalavras.hpp"
#include "PalavraPosicao.hpp"


using namespace std;

class ProcessamentoTexto
{
private:
    string texto;   
    ListaPalavras *arquivoInvertido;
public:
    
    ProcessamentoTexto(ListaPalavras *arquivoInvertido);
    ProcessamentoTexto(string caminho);
    ~ProcessamentoTexto();
    
    void lerArquivoTexto(string caminho);
    
    void imprimirTexto();
    
    void imprimirArquivoInvertido();
   
    string getTexto();
   
    void gerarArquivoInvertido();
    
    void procurarPalavra(char* palavra);
    
    void apagarElementosLista();
    void criarNovoArquivoInvertido();
};


#endif /* ProcessamentoTexto_hpp */
