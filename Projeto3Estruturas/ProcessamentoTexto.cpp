//
//  ProcessamentoTexto.cpp
//  Projeto3Estruturas
//
//  Created by mateus gomes on 6/24/17.
//  Copyright © 2017 mateus gomes. All rights reserved.
//

#include "ProcessamentoTexto.hpp"


ProcessamentoTexto::ProcessamentoTexto(ListaPalavras *arquivoInvertido)
{
    this->arquivoInvertido = arquivoInvertido;
}
ProcessamentoTexto::ProcessamentoTexto(string caminho)
{
    lerArquivoTexto(caminho);
    gerarArquivoInvertido();
    imprimirTexto();
    imprimirArquivoInvertido();
}
ProcessamentoTexto::~ProcessamentoTexto()
{
    cout << "Destruindo Processamento Texto" << endl;
    
    apagarElementosLista();
    
    delete arquivoInvertido;
}
void ProcessamentoTexto::criarNovoArquivoInvertido()
{
    arquivoInvertido = new ListaPalavras();
}

void ProcessamentoTexto::lerArquivoTexto(string caminho)
{
    FILE *arquivo;
    
    arquivo = fopen(caminho.c_str(), "rt");
    
    char * resultado, linha[10000];
    
    while(!feof(arquivo))
    {
        resultado = fgets(linha, 10000, arquivo);
    
        if(resultado)
        {
            texto.append(linha);
        }
    }
}

void ProcessamentoTexto::imprimirTexto()
{
    cout << (texto) << endl;
}
void ProcessamentoTexto::imprimirArquivoInvertido()
{
    arquivoInvertido->imprimirElementos();
}
string ProcessamentoTexto::getTexto()
{
    return texto;
}

void ProcessamentoTexto::gerarArquivoInvertido()
{
    int i, k, posicaoVazia, contador =0;
    
    string vazio = " ", ponto = ".", virgula = ",", interrogacao = "?", exclamacao = "!", menos = "-", doispontos = ":", pontovirgula = ";";
    
    char tmp[100];
    
    for (i = 0; i < (texto).length();i++)
    {
        
        if((texto)[i] == vazio[0] || (texto)[i] == ponto[0] || (texto)[i] == virgula[0] || (texto)[i] == interrogacao[0] || (texto)[i] == exclamacao[0] || (texto)[i] == menos[0]|| (texto)[i] == doispontos[0]|| (texto)[i] == pontovirgula[0] )
        {
            if (contador > 0)
            {
                char * palavraFinal = (char*)malloc(sizeof(char)*contador + 1);
                
                for (k = 0; k <contador; k++)
                {
                    palavraFinal[k] = tolower(tmp[k]);
                }
                palavraFinal[k] = '\0';
                
                arquivoInvertido->realizarCadastroNovaPalavra(palavraFinal, i - contador);
            }
            
            posicaoVazia = i;
            contador = 0;
            
        }
        else if((texto)[i] != vazio[0])
        {
            
            tmp[contador] = ((texto)[i]);
            contador++;
            
        }
    }
    
}

void ProcessamentoTexto::procurarPalavra(char* palavra)
{
    PalavraPosicao *palavraPesquisada;
    
    palavraPesquisada = arquivoInvertido->verificaExistencia(palavra);
    
    if(palavraPesquisada != nullptr)
    {
        cout << "Palavra Encontrada: " << endl << endl;
        
        cout << palavraPesquisada->getPalavra() << endl;
        
        cout << "  qtd: " << palavraPesquisada->getQuantidadePalavras() << endl << endl;
        
        Posicao *auxPosicao = palavraPesquisada->getListaPosicao();
        
        while(auxPosicao != NULL)
        {
            cout << "  P: " << auxPosicao->posicao << " - ...";
            
            int i;
            
            for (i = auxPosicao->posicao; i >= 0 && i < auxPosicao->posicao + 20  && i < texto.length() ; i++)
            {
                cout << texto[i];
            }
            cout << "..." << endl;
            auxPosicao = auxPosicao->proximoElementoPosicao;
        }
        cout << endl << endl;
        
        return;
    }
    
    cout << "Palavra - " << palavra << " - Não Encontrada " <<  endl << endl;
    
    
    

}
void ProcessamentoTexto::apagarElementosLista()
{
    arquivoInvertido->finalizarLista();
    
    delete arquivoInvertido;
    
    texto.erase();
    arquivoInvertido = nullptr;
}
