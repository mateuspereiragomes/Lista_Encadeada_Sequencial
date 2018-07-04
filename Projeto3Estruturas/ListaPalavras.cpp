//
//  ListaPalavras.cpp
//  Projeto3Estruturas
//
//  Created by mateus gomes on 6/24/17.
//  Copyright © 2017 mateus gomes. All rights reserved.
//

#include "ListaPalavras.hpp"


void ListaPalavras::realizarCadastroNovaPalavra(char *palavra, int posicao)
{
    PalavraPosicao *resultado = verificaExistencia(palavra);

    PalavraPosicao *novaPalavra = new PalavraPosicao(palavra, posicao);
    
    if(resultado == NULL)
    {
        
        if(primeiroElemento == NULL)
        {
            setPrimeiroElemento(novaPalavra);
            
            return;
        }
        
        PalavraPosicao* aux = primeiroElemento;
        
        while(aux->proximoElementoPalavra != NULL)
        {
            aux = aux->proximoElementoPalavra;
        }
        
        aux->setProximoElemento(novaPalavra);
        
        return;
    }
    
    resultado->setNovaPosicao(posicao);
    
    return;
}
ListaPalavras::ListaPalavras()
{
    primeiroElemento = nullptr;
    this->quantidadePalavras = 0;
}

ListaPalavras::~ListaPalavras()
{
    cout << "Destruindo ListaPalavras" << endl;
    finalizarLista();
}

int ListaPalavras::getQuantidadePalavras()
{
    return quantidadePalavras;
}

void ListaPalavras::adicionaContadorPalavras()
{
    quantidadePalavras++;
}

PalavraPosicao* ListaPalavras::getPrimeiroElemento()
{
    return primeiroElemento;
}
void ListaPalavras::setPrimeiroElemento(PalavraPosicao* primeiroElemento)
{
    this->primeiroElemento = primeiroElemento;
}

void ListaPalavras::imprimirElementos()
{
    int i = 0;
    
    PalavraPosicao *aux = primeiroElemento;
    
    while(aux != NULL)
    {
        cout << aux->getPalavra() << endl <<  "   Qtd: " << aux->getQuantidadePalavras() <<  " P: " ;
        
        
        Posicao *auxPosicao = aux->getListaPosicao();
        
        while(auxPosicao != NULL)
        {
            cout << auxPosicao->posicao << " ";
            
            auxPosicao = auxPosicao->proximoElementoPosicao;
        }
        
        aux = aux->proximoElementoPalavra;
        
        cout << endl << endl;
        i++;
    }
    
    cout << "Quantidade na lista: " << i << endl;
}
 void ListaPalavras::setNovaPalavraPosicao(PalavraPosicao *novaPalavraPosicao)
{

    if(primeiroElemento == NULL)
    {
        setPrimeiroElemento(novaPalavraPosicao);
        
        return;
    }
    
    PalavraPosicao* aux = primeiroElemento;
        
    while(aux->proximoElementoPalavra != NULL)
    {
        aux = aux->proximoElementoPalavra;
    }
    
    aux->setProximoElemento(novaPalavraPosicao);
    
}

PalavraPosicao* ListaPalavras::verificaExistencia(char* palavra)
{
    if(primeiroElemento != NULL)
    {
        PalavraPosicao *aux = primeiroElemento;
        
        while(aux->proximoElementoPalavra != NULL)
        {
            aux = aux->proximoElementoPalavra;
            
            char* lista = aux->getPalavra(), *novaPalavra = palavra;
            
            //EDITAR ESTA PARTE PARA QUE POSSA ENCONTRAR PALAVRAS
//            int i, j, cont = 0;
//            
//            string naLista = aux->getPalavra(), palavraSera = palavra;
//            
//            bool igual = true;
//            
//            for(i = 0; i < naLista.length(); i++)
//            {
//                
//                for(j = 0; j < palavraSera.length(); j++)
//                {
//                    
//                    if(lista[i] == novaPalavra[j])
//                    {
//                        
//                        cout << lista[i] << "  " << novaPalavra[j] << endl;
//                       
//                        cont++;
//                    }
//                    else
//                    {
//                        igual = false;
//                    }
//                }
//                
//            }
//            
//            if(cont >= 3)
//            {
//                cout << "Parecida: " << aux->getPalavra() <<  " P: " <<  endl;
//            }
//            
//            if(igual == true)
//            {
//                cout << " true" << endl;
//                return aux;
//            }
        
            //Final da parte editada
            bool resultado = strcmp(lista, novaPalavra);
            
            if(!resultado)
            {
                return aux;
            }
        }
    }
    
    return NULL;
}

void ListaPalavras::pesquisaPalavrasParecidas(char* palavra)
{
    
    cout << " PARECIDAS: "<< endl << endl;
    
    if(primeiroElemento != NULL)
    {
        PalavraPosicao *aux = primeiroElemento;
        
        while(aux->proximoElementoPalavra != NULL)
        {
            aux = aux->proximoElementoPalavra;
            
            string naLista = aux->getPalavra(), palavraSera = palavra;
        
            int i,cont = 0;
            
            bool igual = true;
            
            
            for(i = 0; i < palavraSera.length()  ; i++)
            {
                
                if(naLista[i] == palavraSera[i])
                {
                    igual = true;
                    
                    cont++;
                }
                else
                {
                    igual = false;
                    
                    break;
                }
                
            }
            
            if(cont >= 3 && igual == false)
            {
                cout << "  "  << aux->getPalavra() <<  " P: " <<  endl;
            }
          
        }
    }

    
    
    
    
    
    string naLista = "Mate", palavraSera = "Mateus";
    
   
}

void ListaPalavras::finalizarLista()
{
    PalavraPosicao *aux = primeiroElemento, *aux2;
    
    Posicao *auxP, *auxP2;
    
    while (aux != NULL)
    {
        aux2 = aux->proximoElementoPalavra;
        
        auxP = aux->listaPosicao;
        
        while (auxP != nullptr)
        {
            auxP2 = auxP->proximoElementoPosicao;
            
            delete auxP;
            
            auxP = auxP2;
            
        }
    
        delete aux;
        
        aux = aux2;
        
    }
    primeiroElemento = nullptr;
}
