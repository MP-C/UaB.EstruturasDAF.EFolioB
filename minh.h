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
        n,      // num. nós usados
        nv;     // dim max do vetor (capacidade)

    int* heap;
    int size;
    int capacity;
    void heapify_down(int i);
    void swap(int& a, int& b);
public:
    // construtores
    IMINH(int nmax=15);    // cria heap vazio c/ capacidade nmax nós
    ~IMINH();

    // outros atributos e métodos (protótipos) livres
    void insert(int item);
    void print_min() const;
    void print() const;
    int dim() const;
    int dim_max() const;
    void clear();
    void remove();
    void heapify_up(/*std::vector<int> items*/);
    void redim_max(int new_capacity);
};

#endif
// EOF
