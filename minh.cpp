/*
** file: minh.cpp
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

#include "minh.h"
using namespace std;

//Implementação do construtor da classe IMINH que aloca dinamicamente o vetor de nós
IMINH::IMINH(int nv) {                      // nv = capacidade
    v = new int[nv];                        // Alocar com o tamanho especificado
    n = 0;                                  // n = numero de nós usados,
    this->nv = nv;                          // Para iniciar
}

//Implementação do destrutor da classe IMINH
IMINH::~IMINH() {
    delete[] v; // Para libertar a memória alocada para o vetor de nós
}


//Implementação da função de inserção no heap
void IMINH::insert(int item) {
    if (n == nv) {                       // Verifica se o heap está cheio
        cout << "Comando insert: Heap cheio!\n"; // Exibe uma mensagem de erro se o heap estiver cheio
        return;
    }
    v[n++] = item;                          // Insere o item no heap
    int i = n - 1;
    while (i > 0 && v[i] < v[(i - 1) / 2]) { // Realiza o ajuste ascendente (heapify up)
        //swap(v[i], v[(i - 1) / 2]);         // Troca o item atual com o pai
        i = (i - 1) / 2;                    // Atualiza o índice para o pai
    }
}

// Implementação da função para imprimir o valor mínimo (raiz) do heap.
void IMINH::print_min() const {
    if (n == 0) {                           // Verifica se o heap está vazio
        cout << "Comando print_min: Heap vazio!\n"; // Exibe uma mensagem de erro se o heap estiver vazio
        return;
    }
    // Caso o heap não estiver vazio, imprime a mensagem com o valor mínimo do heap
    cout << "Min= " << v[0] << "\n";        // Imprime o valor mínimo do heap
}


// Implementação da função para imprimir todos os elementos do heap
void IMINH::print() const {
    if (n == 0) { // Verifica se o heap está vazio
        cout << "Comando print: Heap vazio!\n"; // Exibe uma mensagem de erro se o heap estiver vazio
        return;
    }
    cout << "Heap=\n";
    int nivel_n = 1;
    int i = 0;
    while (i < n) {
        for (int j = 0; j < nivel_n && i < n; j++) {
            cout << v[i++] << " ";
        }
        cout << "\n";
        nivel_n *= 2;
    }
}

// Implementação da função para obter a dimensão atual do heap.
int IMINH::dim() const {
    cout << "Heap tem "<< n <<" itens\n" << endl;   // Exibe a quantidade de itens no heap
}

// Implementação da função para obter a dimensão máxima do heap.
int IMINH::dim_max() const {
    int capacidade = nv - n;            // Calcula a capacidade máxima do heap
    cout << "Heap tem capacidade "<< capacidade <<" itens\n" << endl; // Exibe a capacidade máxima do heap
}

// Implementação da função para limpar o heap.
void IMINH::clear() {
    if (n == 0) {
        cout << "Comando clear: Heap vazio!" << endl;
        return;
    }
    n = 0; // Define a dimensão do heap como zero, ou seja, remove todos os elementos
}

// Implementação da função para remover o menor item do heap.
void IMINH::remove() {
    if (n == 0) {
        cout << "Comando delete: Heap vazio!\n"; // Exibe uma mensagem de erro se o heap estiver vazio
        return;
    }
    v[0] = v[--n];                      // Substitui o menor item pelo último item do heap e reduz a dimensão do heap
    //heapify_down(0);                  // TODO Implementar a função heapify_down para manter a propriedade do heap
}

// Implementação da função para reorganizar o heap após a inserção de novos itens.
void IMINH::heapify_up(/*vector<int> int items*/) { // TODO VETORES?!?!?
    clear(); // Limpa o heap
    /*for (int item : items) {
        insert(item);                   // Insere cada item no heap
    }*/
}

// Implementação da função para redimensionar o heap para uma nova capacidade máxima.
void IMINH::redim_max(int novo_nv) {
    if (n == 0) {
        cout << "Comando redim_max: Heap vazio!\n"; // Exibe uma mensagem de erro se o heap estiver vazio
        return;
    }
    int *novo_v = new int[novo_nv];     // Cria um novo vetor com a nova capacidade máxima
    for (int i = 0; i < n && i < novo_nv; i++) {
        novo_v[i] = v[i];               // Copia os itens do heap atual para o novo vetor
    }
    delete[] v;                         // Libera a memória do vetor antigo
    v = novo_v;                         // Atualiza o vetor do heap para o novo vetor
    nv = novo_nv;                       // Atualiza a capacidade máxima do heap
    n = min(n, nv);                     // Atualiza a dimensão do heap para o menor valor entre a dimensão atual e a capacidade máxima
}



// EOF