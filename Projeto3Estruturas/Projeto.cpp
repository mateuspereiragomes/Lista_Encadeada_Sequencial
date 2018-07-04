//
//  Projeto.cpp
//  Projeto3Estruturas
//
//  Created by mateus gomes on 6/26/17.
//  Copyright © 2017 mateus gomes. All rights reserved.
//

#include "Projeto.hpp"


Projeto::Projeto()
{
    cout << ".:Bem Vindo ao Projeto 3 de Estruturas:." << endl << endl;
    
    cout << "Processamento de Cadeia de Caracteres " << endl << endl;
}

string Projeto::getCaminhoArquivo()
{
    return caminhoArquivo;
}
void Projeto::setCaminhoArquivo(string caminhoArquivo)
{
    this->caminhoArquivo = caminhoArquivo;
}

void Projeto::escolherOpcaoInicialDesejada()
{
    cout << endl << endl << "Digite a Opção desejada" << endl << endl;
    
    cout << "1 - Ler um arquivo de Texto " << endl;
    cout << "2 - Imprimir o arquivo carregado " << endl;
    cout << "3 - Imprimir o arquivo invertido " << endl;
    cout << "4 - Procurar uma palavra " << endl;
    cout << "5 - Sair do Programa " << endl;
}
