//
//  main.cpp
//  Projeto3Estruturas
//
//  Created by mateus gomes on 6/23/17.
//  Copyright © 2017 mateus gomes. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <string>
#include "ProcessamentoTexto.hpp"
#include "Projeto.hpp"




using namespace std;

//Processamento de Cadeia de Caracteres

//Funcoes

//Ler um arquivo de texto
//Apresentar o arquivo invertido

//Procurar uma Palavra
    //o numero de ocorrencia da palavra
    //sua posicao N no arquivo
    //algumas palavras incluindo a palavra procurada  -- pedaco da frase

//Procurar as próximas ocorrências

    //sua posicao n no arquivo
    //algumas palavras incluindo a palavra procurada -- pedaco da frase

//Sair do sistema



//TODO

//OK Deletar a lista quando carregar um novo arquivo ou quando sair do programa
//OK deletar tambem as sublistas de posicoes




//arrumar o método de inclusao na lista para que se possa apenas incluir palavras sem acentos - fazer um metodo que retire acentos
//fazer pesquisar palavras no meio

int main(int argc, const char * argv[])
{
    
    ListaPalavras *arquivoInvertido = new ListaPalavras();
   
    ProcessamentoTexto *processadorTexto = new ProcessamentoTexto(arquivoInvertido);

    Projeto *projeto = new Projeto();
    
    int funcaoInicialEscolhida = -1;
    
    while(funcaoInicialEscolhida != 0)
    {
    
        do{
        
           projeto->escolherOpcaoInicialDesejada();
           
           cin >> funcaoInicialEscolhida;
           
        }while(funcaoInicialEscolhida < 0 || funcaoInicialEscolhida  > 6 );


        cout << endl << "Funcao " << funcaoInicialEscolhida << " escolhida: " << endl << endl;


        if(funcaoInicialEscolhida == 1)
        {
            processadorTexto->apagarElementosLista();
            processadorTexto->criarNovoArquivoInvertido();
            
            cout << "LEITURA DE ARQUIVO" << endl << endl;
            cout << "Local Atual: " << endl << endl;
            cout << "/Users/mateusgomes/Downloads/" << endl << endl;
            cout << "Digite o arquivo para a leitura: " << endl;
            
            char arquivo[256];
            
            string caminho = "/Users/mateusgomes/Downloads/";
            
            std::cin.ignore(256, '\n');
            
            std::cin.getline(arquivo, 256);
         
            caminho.append(arquivo);
            
            projeto->setCaminhoArquivo(caminho);
            
            processadorTexto->lerArquivoTexto(caminho);
            
            processadorTexto->gerarArquivoInvertido();
            
            
        }
        else if(funcaoInicialEscolhida == 2)
        {
            cout << "IMPRESSAO ARQUIVO CARREGADO" << endl << endl;
            processadorTexto->imprimirTexto();
            
        }
        else if(funcaoInicialEscolhida == 3)
        {
            cout << "IMPRESSAO ARQUIVO INVERTIDO" << endl << endl;
            processadorTexto->imprimirArquivoInvertido();
        }
        else if(funcaoInicialEscolhida == 4)
        {
            cout << "PESQUISAR PALAVRA" << endl << endl;
            
            char palavra[256];
            
            cin.ignore(256, '\n');
            
            cin.getline(palavra, 256);
            
            processadorTexto->procurarPalavra(palavra);
            
        }
        else if(funcaoInicialEscolhida == 5)
        {
            cout << "SAIR DO PROGRAMA" << endl << endl;
            processadorTexto->apagarElementosLista();
            break;
        }
    }
    return 0;
}
