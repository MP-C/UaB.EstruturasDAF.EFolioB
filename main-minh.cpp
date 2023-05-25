/*
** file: main-minh.cpp
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
// em main-minh.cpp
//   A entrada/saída de dados
//   As instâncias da classe da estrutura de dados
//   A implementação dos comandos através dos métodos da classe
//   Código auxiliar
//   Não utilize variáveis globais

#include <iostream>
#include <sstream>
#include <string>
#include "minh.h"
using namespace std;

/* Se o comando introduzido for um comentario (#) ou estiver vazio ignora-se a linha */
string validarComando(string input){  // Verifica se o comando é valido
    if(input[0] == '#' || input.empty()){ // Critério para garantir que existe um cmd
        return "Introduza um comando valido";
    }else{
        return input;// Devolve o input, e continua a executar
    }
}

int main() {
    string input, comando;
    int argumentos;
    IMINH minHeap;   // exemplo

    while (getline(cin, input)) {
        stringstream ssInput(input); // Extrai a linha completa e guarda em ssInput
        /* Verifica que o comando introduzido é válido*/
        string comandoValido = validarComando(input); // Verifica se o comando é valido (diferente de vazio e de #)
        ssInput >> comando; // Extrai o nome do comando

        if (comando == "insert") {// Insere no início da lista um novo nó
            while(ssInput >> argumentos) { // Extrai os argumentoss do Input
                // Insere itens no heap pela ordem apresentada
                minHeap.insert(argumentos); // Caso existam argumentos, faz os ciclos para executar o comando tantas vezes quanto necessario
            }
        }
        else if (comando == "print_min") { //Imprime o menor item no heap
            minHeap.print_min();
        }
        else if (comando == "print"){// Imprime toda a árvore do heap
            minHeap.print();
        }
        else if (comando == "dim") {// Imprime o número de itens no heap
            minHeap.dim();
        }
        else if (comando == "dim_max"){// Imprime o número máximo de itens ou capacidade do heap
            minHeap.dim_max();
        }
        else if (comando == "clear"){// Inicializa o heap com zero elementos
            minHeap.clear();
        }
        else if (comando == "delete"){// Remove o menor item no heap
            minHeap.remove();
        }
        else if (comando == "heapify_up") {// Converte o vetor definido pelos itens "item ..." num min Heap
            while(ssInput >> argumentos) {// Extrai os argumentoss do Input
                minHeap.heapify_up(/*argumentos*/); // Caso existam argumentoss, faz os ciclos para executar o comando tantas vezes quanto necessario
            }
        }
        else if (comando == "redim_max") {// Redimensiona o número máximo de itens ou capacidade do heap
            ssInput >> argumentos;// Extrai os argumentos do Input, mas só um
                minHeap.redim_max(argumentos);// Caso existam argumentoss, faz os ciclos para executar o comando tantas vezes quanto necessario
        }
        else {
            cout << "O comando introduzido nao e valido" <<endl; // Devolve uma mensagem de erro

        }
    }
    return 0;
}
// EOF