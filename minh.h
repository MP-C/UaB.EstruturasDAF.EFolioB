/*
** file: minh.h
**
** min Heap por comandos
** (binary tree on array)
** UC: 21046 - EDAF @ UAb
** e-fólio B 2022-23
**
** Aluno: Mário Carvalho - 2000563
*/

// Defina:
// em minh.h as classes da estrutura de dados
// em minh.cpp a implementação dos métodos das classes da estrutura de dados

#ifndef _MINH_H
#define _MINH_H

#include <iostream>
#include <sstream>

using namespace std;

// definir int min heap em array
class IMINH {
private:
    // atributos obrigatórios
    int *v,     // vetor com nós
        n,      // numero nós usados
        nv;     // dimensão maxima do vetor = capacidade

public:
    // construtores
    IMINH(int nmaximo =15);    //  Construtor da classe IMINH que cria heap vazio c/ capacidade maxima de 15 nós
    ~IMINH(); //Destrutor da classe IMINH que libera a memória alocada para o vetor de nós

    // outros atributos e métodos (protótipos) livres
    void insert(int item);  // 1. Insere um item no heap. Caso o heap esteja cheio, exibe uma mensagem de erro.
    void print_min() const; // 2. Imprime o valor mínimo (raiz) do heap. Caso o heap esteja vazio, exibe uma mensagem de erro
    void print() const;     // 3. Imprime todos os nós do heap
    int dim() const;        // 4. Retorna mensagem com o número de nós atualmente presentes no heap
    int dim_max() const;    // 5. Retorna mensagem com a capacidade máxima do heap (número máximo de nós que ele pode armazenar)
    void clear();           // 6. Remove todos os nós do heap
    void remove();          // 7. Remove o nó mínimo (raiz) do heap
    //TODO VETORES?!?!?!
    void heapify_up(/*vector<int> int items*/); // 8. Reorganiza o heap após uma inserção para garantir que a propriedade do heap seja mantida
    void redim_max(int new_capacity); // 9. Redimensiona a capacidade máxima do heap para um novo valor especificado
    // TODO ?!?!?
    //void heapify_down(int i);
    //void swap(int& a, int& b);

};
#endif
// EOF
