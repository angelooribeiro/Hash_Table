#include "hash_table.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>

//list<dados>xtabela;

void imprimir_menu()
{
    cout << "1.Inserir Elemento" << endl;
    cout << "2.Procurar Elemento" << endl;
    cout << "3.Remover Elemento" << endl;
    cout << "4.Consultar estatiticas " << endl;
    cout << "5.Imprimir Tabela " << endl;
    cout << "6.Sair" << endl;
}

int main()
{
    hash_table ht;
    Estatistica est;
    int codigo;
    string concelho;

    int op = 0;

    ht.inserir_elemento(4800, "Guimaraes");

    ht.inserir_elemento(4700, "Braga");

    ht.inserir_elemento(7875, "Sobral da Adiça");

    do
    {
        system("cls");
        imprimir_menu();
        cin >> op;
        switch(op)
        {
            case 1:
                system("cls");
                cout << "Inserir Elemento" << endl;
                cout << "insira um codigo:" << endl;
                cin >> codigo;
                if( codigo < 1000 || codigo > 9999)
                    break;
                cout << "insira o concelho:" << endl;
                cin >> concelho;
                ht.inserir_elemento(codigo, concelho);
                cout << "elemento inserido" << endl;
                getchar();
                getchar();
                break;

            case 2:
                system("cls");
                cout << "Procurar Elemento" << endl;
                cout << "Insira um codigo" << endl;
                cin >> codigo;
                concelho = ht.procurar_elemento(codigo);
                if( !concelho.empty() )
                    cout << codigo << ' ' << concelho << endl;
                else
                    cout << "Elemento Nao Encontrado" << endl;
                getchar();
                getchar();
                break;

            case 3:
                system("cls");
                cout << "Remover Elemento" << endl;
                cout << "Insira o codigo do elemento a remover" << endl;
                cin >> codigo;
                if( ht.remover_elemento(codigo) )
                    cout << "Elemento Removido Com Sucesso" << endl;
                else
                    cout << "Elemento Nao Removido" << endl;
                getchar();
                getchar();
                break;

            case 4:
                system("cls");
                est = ht.estatisticas();
                cout << "max colisoes " << est.max_colisoes << endl;
                cout << "media colisoes " << est.media_colisoes << endl;
                cout << "num colisoes " << est.num_colisoes << endl;
                cout << "num elementos " << est.num_elementos << endl;
                getchar();
                getchar();
                break;

            case 5:
                system("cls");
                ht.imprimir_tabela();
                getchar();
                getchar();
                break;

            default:
                break;
        }
    }   while(op != 6);

    return 0;
}
