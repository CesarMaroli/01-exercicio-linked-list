#include <cassert>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include "../include/linked_list.h"

using namespace std;

// ===== TESTES DA FUNÇÃO criaLista =====
void teste_criaLista() {
    cout << "Testando criaLista()..." << endl;

    ListaSimplesmenteEncadeada* lista = criaLista();
    assert(lista != NULL);
    assert(lista->cardinalidade == 0);
    assert(lista->inicio == NULL);

    free(lista);
    cout << "criaLista() passou em todos os testes" << endl;
}

// ===== TESTES DA FUNÇÃO insere (inserção no início) =====
void teste_insere() {
    cout << "Testando insere()..." << endl;

    ListaSimplesmenteEncadeada* lista = criaLista();
    assert(lista != NULL);

    // Insere primeiro elemento
    insere(*lista, 10);
    assert(lista->cardinalidade == 1);
    assert(lista->inicio != NULL);
    assert(lista->inicio->conteudo == 10);
    assert(lista->inicio->proximo == NULL);

    // Insere segundo elemento (deve ficar no início)
    insere(*lista, 20);
    assert(lista->cardinalidade == 2);
    assert(lista->inicio->conteudo == 20);
    assert(lista->inicio->proximo->conteudo == 10);

    // Insere terceiro elemento
    insere(*lista, 30);
    assert(lista->cardinalidade == 3);
    assert(lista->inicio->conteudo == 30);
    assert(lista->inicio->proximo->conteudo == 20);
    assert(lista->inicio->proximo->proximo->conteudo == 10);

    destroiLista(*lista);
    free(lista);
    cout << "insere() passou em todos os testes" << endl;
}

// ===== TESTES DA FUNÇÃO destroiLista =====
void teste_destroiLista() {
    cout << "Testando destroiLista()..." << endl;

    ListaSimplesmenteEncadeada* lista = criaLista();
    assert(lista != NULL);

    // Insere elementos
    insere(*lista, 1);
    insere(*lista, 2);
    insere(*lista, 3);

    // Destrói a lista
    destroiLista(*lista);

    assert(lista->cardinalidade == 0);
    assert(lista->inicio == NULL);

    free(lista);
    cout << "destroiLista() passou em todos os testes" << endl;
}

// ===== TESTES DA FUNÇÃO listaVazia =====
void teste_listaVazia() {
    cout << "Testando listaVazia()..." << endl;

    ListaSimplesmenteEncadeada* lista = criaLista();
    assert(lista != NULL);

    assert(listaVazia(*lista) == true);

    insere(*lista, 10);
    assert(listaVazia(*lista) == false);

    destroiLista(*lista);
    assert(listaVazia(*lista) == true);

    free(lista);
    cout << "listaVazia() passou em todos os testes" << endl;
}

// ===== TESTES DA FUNÇÃO numeroElementos =====
void teste_numeroElementos() {
    cout << "Testando numeroElementos()..." << endl;

    ListaSimplesmenteEncadeada* lista = criaLista();
    assert(lista != NULL);

    assert(numeroElementos(*lista) == 0);

    insere(*lista, 10);
    assert(numeroElementos(*lista) == 1);

    insere(*lista, 20);
    assert(numeroElementos(*lista) == 2);

    removePosicao(*lista, 0);
    assert(numeroElementos(*lista) == 1);

    destroiLista(*lista);
    assert(numeroElementos(*lista) == 0);

    free(lista);
    cout << "numeroElementos() passou em todos os testes" << endl;
}

// ===== TESTES DA FUNÇÃO mostrarLista =====
void teste_mostrarLista() {
    cout << "Testando mostrarLista()..." << endl;

    ListaSimplesmenteEncadeada* lista = criaLista();
    assert(lista != NULL);

    ostringstream captura;
    streambuf* coutAntigo = cout.rdbuf(captura.rdbuf());

    // Teste lista vazia
    mostrarLista(*lista);
    assert(captura.str() == "Lista vazia.\n");

    // Limpa a captura
    captura.str("");
    captura.clear();

    // Como insere coloca no início:
    // insere 10, depois 20, depois 30 => saída: 30 -> 20 -> 10
    insere(*lista, 10);
    insere(*lista, 20);
    insere(*lista, 30);

    mostrarLista(*lista);
    assert(captura.str() == "Lista: 30 -> 20 -> 10\n");

    // Restaura cout
    cout.rdbuf(coutAntigo);

    destroiLista(*lista);
    free(lista);
    cout << "mostrarLista() passou em todos os testes" << endl;
}

// ===== TESTES DA FUNÇÃO inserePosicao =====
void teste_inserePosicao() {
    cout << "Testando inserePosicao()..." << endl;

    ListaSimplesmenteEncadeada* lista = criaLista();
    assert(lista != NULL);

    // Inserção em lista vazia, posição 0
    inserePosicao(*lista, 10, 0);
    assert(lista->cardinalidade == 1);
    assert(lista->inicio->conteudo == 10);
    assert(lista->inicio->proximo == NULL);

    // Inserção no final
    inserePosicao(*lista, 30, 1);
    assert(lista->cardinalidade == 2);
    assert(lista->inicio->conteudo == 10);
    assert(lista->inicio->proximo->conteudo == 30);

    // Inserção no meio
    inserePosicao(*lista, 20, 1);
    assert(lista->cardinalidade == 3);
    assert(lista->inicio->conteudo == 10);
    assert(lista->inicio->proximo->conteudo == 20);
    assert(lista->inicio->proximo->proximo->conteudo == 30);

    // Inserção no início
    inserePosicao(*lista, 5, 0);
    assert(lista->cardinalidade == 4);
    assert(lista->inicio->conteudo == 5);
    assert(lista->inicio->proximo->conteudo == 10);

    // Posição inválida: não deve alterar a lista
    inserePosicao(*lista, 999, -1);
    assert(lista->cardinalidade == 4);
    assert(lista->inicio->conteudo == 5);

    inserePosicao(*lista, 999, 10);
    assert(lista->cardinalidade == 4);

    destroiLista(*lista);
    free(lista);
    cout << "inserePosicao() passou em todos os testes" << endl;
}

// ===== TESTES DA FUNÇÃO removePosicao =====
void teste_removePosicao() {
    cout << "Testando removePosicao()..." << endl;

    ListaSimplesmenteEncadeada* lista = criaLista();
    assert(lista != NULL);

    // Monta lista: 10 -> 20 -> 30 -> 40
    inserePosicao(*lista, 10, 0);
    inserePosicao(*lista, 20, 1);
    inserePosicao(*lista, 30, 2);
    inserePosicao(*lista, 40, 3);

    assert(lista->cardinalidade == 4);

    // Remove do meio (remove 20)
    removePosicao(*lista, 1);
    assert(lista->cardinalidade == 3);
    assert(lista->inicio->conteudo == 10);
    assert(lista->inicio->proximo->conteudo == 30);
    assert(lista->inicio->proximo->proximo->conteudo == 40);

    // Remove do início (remove 10)
    removePosicao(*lista, 0);
    assert(lista->cardinalidade == 2);
    assert(lista->inicio->conteudo == 30);
    assert(lista->inicio->proximo->conteudo == 40);

    // Remove do final (remove 40)
    removePosicao(*lista, 1);
    assert(lista->cardinalidade == 1);
    assert(lista->inicio->conteudo == 30);
    assert(lista->inicio->proximo == NULL);

    // Remove último elemento
    removePosicao(*lista, 0);
    assert(lista->cardinalidade == 0);
    assert(lista->inicio == NULL);

    // Tentativa de remover com lista vazia
    removePosicao(*lista, 0);
    assert(lista->cardinalidade == 0);
    assert(lista->inicio == NULL);

    free(lista);
    cout << "removePosicao() passou em todos os testes" << endl;
}

// ===== TESTES DA FUNÇÃO inverterLista =====
void teste_inverterLista() {
    cout << "Testando inverterLista()..." << endl;

    ListaSimplesmenteEncadeada* lista = criaLista();
    assert(lista != NULL);

    // Inversão de lista vazia
    inverterLista(*lista);
    assert(lista->inicio == NULL);
    assert(lista->cardinalidade == 0);

    // Inversão com 1 elemento
    inserePosicao(*lista, 10, 0);
    inverterLista(*lista);
    assert(lista->cardinalidade == 1);
    assert(lista->inicio->conteudo == 10);
    assert(lista->inicio->proximo == NULL);

    // Monta lista: 10 -> 20 -> 30 -> 40
    inserePosicao(*lista, 20, 1);
    inserePosicao(*lista, 30, 2);
    inserePosicao(*lista, 40, 3);

    // Inverte => 40 -> 30 -> 20 -> 10
    inverterLista(*lista);
    assert(lista->cardinalidade == 4);
    assert(lista->inicio->conteudo == 40);
    assert(lista->inicio->proximo->conteudo == 30);
    assert(lista->inicio->proximo->proximo->conteudo == 20);
    assert(lista->inicio->proximo->proximo->proximo->conteudo == 10);
    assert(lista->inicio->proximo->proximo->proximo->proximo == NULL);

    destroiLista(*lista);
    free(lista);
    cout << "inverterLista() passou em todos os testes" << endl;
}

// ===== FUNÇÃO PRINCIPAL =====
int main() {
    cout << "\n=========================================" << endl;
    cout << "  INICIANDO TESTES DE LINKED LIST" << endl;
    cout << "=========================================" << endl << endl;

    teste_criaLista();
    teste_insere();
    teste_destroiLista();
    teste_listaVazia();
    teste_numeroElementos();
    teste_mostrarLista();
    teste_inserePosicao();
    teste_removePosicao();
    teste_inverterLista();

    cout << "\n=========================================" << endl;
    cout << "  TODOS OS TESTES PASSARAM COM SUCESSO!" << endl;
    cout << "=========================================" << endl << endl;

    return 0;
}