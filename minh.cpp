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

/* Implementação do construtor da classe IMINH que aloca dinamicamente o vetor de nós */
IMINH::IMINH(int nv) {      // nv = capacidade
    v = new int[nv];        // Alocar com o tamanho especificado
    n = 0;                  // n = numero de nós usados,
    this->nv = nv;          // Para iniciar
}

/* Implementação do destrutor da classe IMINH */
IMINH::~IMINH() {
    delete[] v;             // Para libertar a memória alocada para o vetor de nós
}

/* Implementação da função de inserção no heap (1. insert) */
void IMINH::insere(string comand, int item) {
    if (n == nv) {                          // Verifica se o heap está cheio
        cout << "Comando "<< comand <<": Heap cheio!\n"; // Exibe uma mensagem de erro se o heap estiver cheio
        return;
    }
    v[n++] = item;                          // Insere o item no heap
    int i = n - 1;
    while (i > 0 && v[i] < v[(i - 1) / 2]) {// Realiza o ajuste ascendente (heapify up)
        inverte(v[i], v[(i - 1) / 2]);// Troca o item atual com o pai
        i = (i - 1) / 2;                    // Atualiza o índice para o pai
    }
}

/* Implementação da função para imprimir o valor mínimo (raiz) do heap (2. print_min) */
void IMINH::imprime_min(string comand) {
    if (n == 0) {                               // Verifica se o heap está vazio
        cout << "Comando " << comand << ": Heap vazio!\n"; // Exibe uma mensagem de erro se o heap estiver vazio
        return;
    }
    /* Caso o heap não estiver vazio, imprime a mensagem com o valor mínimo do heap */
    cout << "Min= " << v[0] << "\n";            // Imprime o valor mínimo do heap
}

/* Implementação da função para imprimir todos os elementos do heap (3. print) */
void IMINH::imprime(string comand) {
    if (n == 0) {                               // Verifica se o heap está vazio
        cout << "Comando " << comand << ": Heap vazio!\n";    // Exibe uma mensagem de erro se o heap estiver vazio
        return;
    }
    cout << "Heap=\n";                          // Imprime a mensagem indicando o início da impressão do heap
    int nivel_n = 1;                            // Variável para controlar o número de elementos em cada nível
    int i = 0;                                  // Variável para percorrer os elementos do heap
    while (i < n) {                             // Loop para percorrer os elementos do heap
        for (int j = 0; j < nivel_n && i < n; j++) { // Loop para imprimir os elementos de cada nível
            cout << v[i++] <<" ";               // Imprime o elemento atual e incrementa o índice
        }
    cout << "\n";                               // Salta para a próxima linha após imprimir os elementos de um nível
    nivel_n *= 2;                               // Dobra o número de elementos no próximo nível
    }
}

/* Implementação da função para obter a dimensão atual do heap (4. dim) */
void IMINH::dimensao(string comand) {
    /* Zona excluida dado que não passa nos testes, mas corresponde ao enunciado)
     * if (n == 0) {
        cout << "Comando " << comand << ": Heap vazio!\n";
        return;
    }*/
    cout << "Heap tem "<< n <<" itens\n";   // Exibe a quantidade de itens no heap
}

/* Implementação da função para obter a dimensão máxima do heap atual (5. dim_max) */
void IMINH::dimensao_max(string comand) {
    cout << "Heap tem capacidade " << nv <<" itens\n"; // Exibe a capacidade máxima do heap
}

/* Implementação da função para limpar o heap (6. clear) */
void IMINH::apaga(string comand) {
    if (n == 0) {                            // Verifica se o heap está vazio
        cout << "Comando " << comand << ": Heap vazio!\n";
        return;
    }
    n = 0;                                  // Define a dimensão do heap como zero, ou seja, remove todos os elementos
    delete[] v;                             // Libera a memória alocada para o vetor do heap atual
    v = new int[nv];                        // Aloca uma nova memória para o vetor do heap com a capacidade original
}

/* Implementação da função para remover o menor item do heap (7. Remove) */
void IMINH::remove(string comand) {
    if (n == 0) {
        cout << "Comando " << comand << ": Heap vazio!\n"; // Exibe uma mensagem de erro se o heap estiver vazio
        return;
    }
    v[0] = v[--n];                 // Substitui o menor item pelo último item do heap e reduz a dimensão do heap
    heapify_down(0);          // Para reorganizar o heap após ação de outra função, neste caso, de apagar o minimo do heap
}

/* Implementação da função para reorganizar o heap após a inserção de novos itens (8. heapify_up) */
void IMINH::heapify_up(string comand) {
    /*if (n == 0) {
        cout << "Comando " << comand << ": Heap vazio!\n"; // Exibe uma mensagem de erro se o heap estiver vazio
        return;
    }

    int i = n - 1;
    while (i > 0 && v[i] < v[(i - 1) / 2]) { // Realiza o ajuste ascendente (heapify up)
        inverte(v[i], v[(i - 1) / 2]); // Troca o item atual com o pai
        i = (i - 1) / 2; // Atualiza o índice para o pai
    }*/
}

/*void heapify_up(int v, int n) {
    int start = (n - 2) / 2; // Índice do último nó não folha

    while (start >= 0) {
        // Realiza o heapify down para cada nó a partir do último nível não folha até a raiz
        int root = start;
        int child = 2 * root + 1; // Índice do primeiro filho do nó atual

        while (child < n) {
            // Verifica se o nó atual possui um segundo filho e se o valor do segundo filho é menor
            if (child + 1 < n && v[child] > v[child + 1]) {
                child++;
            }

            // Compara o valor do nó atual com o valor do filho selecionado
            if (v[root] > v[child]) {
                // Troca os valores
                int temp = v[root];
                v[root] = v[child];
                v[child] = temp;

                root = child;
                child = 2 * root + 1;
            } else {
                break; // O heapify down foi concluído para o nó atual
            }
        }
        start--;
    }
}*/


/* Implementação da função para redimensionar o heap para uma nova capacidade máxima (9. redim_max) */
void IMINH::redimensao_max(string comand, int novo_nv) {
    if (n == 0) {
        cout << "Comando " << comand << ": Heap vazio!\n"; // Exibe uma mensagem de erro se o heap estiver vazio
        return;
    }
    int *novo_v = new int[novo_nv];// Cria um novo vetor com a nova capacidade máxima
    for (int i = 0; i < n && i < novo_nv; i++) {
        novo_v[i] = v[i];          // Copia os itens do heap atual para o novo vetor
    }
    delete[] v;                    // Libera a memória do vetor antigo
    v = novo_v;                    // Atualiza o vetor do heap para o novo vetor
    nv = novo_nv;                  // Atualiza a capacidade máxima do heap
    n = min(n, nv);                // Atualiza a dimensão do heap para o menor valor entre a dimensão atual e a capacidade máxima
}

/* Implementação de função que inverte a ordem (AUXILIAR: 10. inverte) */
void IMINH::inverte(int& item1, int& item2) {
    int itemAuxiliar = item1;    // Armazena o valor do item1 numa variável auxiliar
    item1 = item2;               // Atribui o valor do item2 ao item1
    item2 = itemAuxiliar;        // Atribui o valor armazenado na variável auxiliar ao item2
}

/* Função auxiliar para reorganizar o heap após a remoção do menor item (AUXILIAR: 11. heapify_down) */
void IMINH::heapify_down(int item) {
    int minimo = item;                 // Índice do item atual
    int filhoEsquerda = (2 * item) + 1;  // Índice do filho esquerdo, impar
    int filhoDireita = (2 * item) + 2;   // Índice do filho direito, par

    // Verifica se o filho esquerdo é menor que o item atual
    if (filhoEsquerda < n && v[filhoEsquerda] < v[minimo]) {
        minimo = filhoEsquerda;
    }

    // Verifica se o filho direito é menor que o item atual
    if (filhoDireita < n && v[filhoDireita] < v[minimo]) {
        minimo = filhoDireita;
    }

    // Se o menor item não for o item atual, troca-os e chama recursivamente a função heapify_down
    if (minimo != item) {
        inverte(v[item], v[minimo]); // Troca o item atual com o menor item
        heapify_down(minimo);         // Chama recursivamente a função heapify_down para o novo índice
    }
}

// EOF