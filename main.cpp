#include <iostream>
#include <cstdlib>
#include "linked_list.h"

using namespace std;

int main() {
    cout << "Exercicio de Linked List" << endl;
    cout << "------------------------\n" << endl;

    ListaSimplesmenteEncadeada* lista = criaLista();

    if (lista == NULL) {
        cout << "Erro ao criar a lista." << endl;
        return 1;
    }

    cout << "Lista vazia? " << (listaVazia(*lista) ? "Sim" : "Nao") << endl;
    mostrarLista(*lista);
    cout << "Numero de elementos: " << numeroElementos(*lista) << endl;

    cout << "\nInserindo elementos no inicio..." << endl;
    insere(*lista, 10);
    insere(*lista, 20);
    insere(*lista, 30);
    mostrarLista(*lista);
    cout << "Numero de elementos: " << numeroElementos(*lista) << endl;

    cout << "\nInserindo 99 na posicao 1..." << endl;
    inserePosicao(*lista, 99, 1);
    mostrarLista(*lista);
    cout << "Numero de elementos: " << numeroElementos(*lista) << endl;

    cout << "\nRemovendo elemento da posicao 2..." << endl;
    removePosicao(*lista, 2);
    mostrarLista(*lista);
    cout << "Numero de elementos: " << numeroElementos(*lista) << endl;

    cout << "\nInvertendo a lista..." << endl;
    inverterLista(*lista);
    mostrarLista(*lista);
    cout << "Numero de elementos: " << numeroElementos(*lista) << endl;

    cout << "\nDestruindo a lista..." << endl;
    destroiLista(*lista);
    mostrarLista(*lista);
    cout << "Lista vazia? " << (listaVazia(*lista) ? "Sim" : "Nao") << endl;
    cout << "Numero de elementos: " << numeroElementos(*lista) << endl;

    free(lista);

    return 0;
}