#include "linked_list.h"
#include <iostream>
#include <cstdlib>

using namespace std;

ListaSimplesmenteEncadeada* criaLista() {
    ListaSimplesmenteEncadeada* lista =
        (ListaSimplesmenteEncadeada*) malloc(sizeof(ListaSimplesmenteEncadeada));

    if (lista == NULL) {
        cerr << "Erro na alocacao de memoria da lista." << endl;
        return NULL;
    }

    lista->cardinalidade = 0;
    lista->inicio = NULL;
    return lista;
}

void destroiLista(ListaSimplesmenteEncadeada &lista) {
    Node* temp;

    while (lista.inicio != NULL) {
        temp = lista.inicio;
        lista.inicio = lista.inicio->proximo;
        free(temp);
    }

    lista.cardinalidade = 0;
}

void insere(ListaSimplesmenteEncadeada &lista, int conteudo) {
    Node* novoNode = (Node*) malloc(sizeof(Node));

    if (novoNode == NULL) {
        cerr << "Erro na alocacao de memoria do node." << endl;
        return;
    }

    novoNode->conteudo = conteudo;
    novoNode->proximo = lista.inicio;

    lista.inicio = novoNode;
    lista.cardinalidade++;
}

void mostrarLista(const ListaSimplesmenteEncadeada &lista) {
    if (lista.inicio == NULL) {
        cout << "Lista vazia." << endl;
        return;
    }

    Node* atual = lista.inicio;

    cout << "Lista: ";
    while (atual != NULL) {
        cout << atual->conteudo;

        if (atual->proximo != NULL) {
            cout << " -> ";
        }

        atual = atual->proximo;
    }

    cout << endl;
}

bool listaVazia(const ListaSimplesmenteEncadeada &lista) {
    return (lista.inicio == NULL);
}

int numeroElementos(const ListaSimplesmenteEncadeada &lista) {
    return lista.cardinalidade;
}

void inserePosicao(ListaSimplesmenteEncadeada &lista, int conteudo, int posicao) {
    if (posicao < 0 || posicao > lista.cardinalidade) {
        cout << "Posicao invalida para insercao." << endl;
        return;
    }

    Node* novoNode = (Node*) malloc(sizeof(Node));

    if (novoNode == NULL) {
        cerr << "Erro na alocacao de memoria do node." << endl;
        return;
    }

    novoNode->conteudo = conteudo;

    if (posicao == 0) {
        novoNode->proximo = lista.inicio;
        lista.inicio = novoNode;
        lista.cardinalidade++;
        return;
    }

    Node* atual = lista.inicio;

    for (int i = 0; i < posicao - 1; i++) {
        atual = atual->proximo;
    }

    novoNode->proximo = atual->proximo;
    atual->proximo = novoNode;
    lista.cardinalidade++;
}

void removePosicao(ListaSimplesmenteEncadeada &lista, int posicao) {
    if (lista.inicio == NULL) {
        cout << "Nao e possivel remover: lista vazia." << endl;
        return;
    }

    if (posicao < 0 || posicao >= lista.cardinalidade) {
        cout << "Posicao invalida para remocao." << endl;
        return;
    }

    Node* removido;

    if (posicao == 0) {
        removido = lista.inicio;
        lista.inicio = lista.inicio->proximo;
        free(removido);
        lista.cardinalidade--;
        return;
    }

    Node* atual = lista.inicio;

    for (int i = 0; i < posicao - 1; i++) {
        atual = atual->proximo;
    }

    removido = atual->proximo;
    atual->proximo = removido->proximo;
    free(removido);
    lista.cardinalidade--;
}

void inverterLista(ListaSimplesmenteEncadeada &lista) {
    Node* anterior = NULL;
    Node* atual = lista.inicio;
    Node* proximo = NULL;

    while (atual != NULL) {
        proximo = atual->proximo;
        atual->proximo = anterior;
        anterior = atual;
        atual = proximo;
    }

    lista.inicio = anterior;
}