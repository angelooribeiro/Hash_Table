#ifndef HASH_TABLE_H_
#define HASH_TABLE_H_

#include <iostream>
#include <list>

#define SIZE 100

using namespace std;

    struct Dados
    {
        int codigo;
        string concelho;
    };

    struct Estatistica
    {
        int max_colisoes;                          //numero maximo de colisoes
        int num_colisoes;                           //numero de colisoes
        float media_colisoes;                       //media de colisoes, em percentagem
        int num_elementos;                          //elementos inseridos
    };

class hash_table
{
    list <Dados> tabela[SIZE];
    int funcao_hash(int codigo);              //determina o indice no array
    int funcao_hash2(int codigo);               //segunda função de hashing
    int max_colisoes = 0;                          //numero maximo de colisoes
    int num_colisoes = 0;                           //numero de colisoes
    float media_colisoes = 0.00;                       //media de colisoes, em percentagem
    int num_elementos = 0;                          //elementos inseridos

public:
    hash_table();                             //constructor
    void inserir_elemento(int codigo, string concelho);         //para inserir um novo elemento
    string procurar_elemento(int codigo);       //procura de um elemento
    bool remover_elemento(int codigo);        //remove um elemento
    void gere_indices(int indice, char a);    //atualiza as estatisticas da tabela
    Estatistica estatisticas();                //retorna uma estrutura com as estatisticas da tabela
    void imprimir_tabela();                   //função que imprime toda a tabela;
    ~hash_table();                            //destructor
};

#endif
