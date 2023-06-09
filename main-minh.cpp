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

int main() {
    string input, comando;
    int argumentos;
    IMINH minHeap;   // exemplo

    while (getline(cin, input)) {
        stringstream ssInput(input); // Extrai a linha completa e guarda em ssInput

        //string comandoValido = validarComando(input); // Verifica se o comando é valido (diferente de vazio e de #)
        ssInput >> comando;                             // Extrai o nome do comando

        /* Verifica que o comando introduzido é válido*/
        if (comando[0] == '#' || comando.length()==0 ) {// Se o comando introduzido for um comentario (#) ou estiver vazio ignora-se a linha completamente
            continue;                                   // pois é uma linha de comentário
        }
        else if (comando == "insert") {                 // Insere no início da lista um novo nó
            while(ssInput >> argumentos) {              // Extrai os argumentoss do input
                if (minHeap.filtroArgumento()) {          // Verifica se o heap está cheio
                    cout << "Comando " << comando << ": Heap cheio!\n"; // Exibe uma mensagem de erro se o heap estiver cheio
                    break;                              // Auxilio para quebrar o ciclo e impedir repetições
                }
            /* Insere itens no heap pela ordem apresentada */
            minHeap.insere(comando, argumentos);       // Caso existam argumentos, faz os ciclos para executar o comando tantas vezes quanto necessario
            }
        }
        else if (comando == "print_min") {              // Imprime o menor item no heap
            minHeap.imprime_min(comando);
        }
        else if (comando == "print"){                   // Imprime toda a árvore do heap
            minHeap.imprime(comando);
        }
        else if (comando == "dim") {                    // Imprime o número de itens no heap
            minHeap.dimensao(comando);
        }
        else if (comando == "dim_max"){                 // Imprime o número máximo de itens ou capacidade do heap
            minHeap.dimensao_max(comando);
        }
        else if (comando == "clear"){                   // Inicializa o heap com zero elementos
            minHeap.apaga(comando);
        }
        else if (comando == "delete"){                  // Remove o menor item no heap
            minHeap.remove(comando);
        }
        else if (comando == "heapify_up") {             // Converte o vetor definido pelos itens "item..." num min Heap
            while(ssInput >> argumentos) {              // Extrai os argumentoss do input
                if (minHeap.filtroArgumento()) {          // Verifica se o heap está cheio
                    cout << "Comando " << comando << ": Heap cheio!\n"; // Exibe uma mensagem de erro se o heap estiver cheio
                    break;                              // Auxilio para quebrar o ciclo e impedir repetições
                }
                minHeap.heapify_up(comando, argumentos);// Caso existam argumentoss, faz os ciclos para executar o comando tantas vezes quanto necessario
            }
        }
        else if (comando == "redim_max") {              // Redimensiona o número máximo de itens ou capacidade do heap
            ssInput >> argumentos;                      // Extrai os argumentos do input, mas só um
            if (minHeap.filtroArgumento()) {              // Verifica se o heap está cheio
             /* Exibe uma mensagem de erro se o heap estiver cheio*/
                break;                                  // Auxilio para quebrar o ciclo e impedir repetições
            }
            minHeap.redimensao_max(comando, argumentos);// Caso existam argumentoss, faz os ciclos para executar o comando tantas vezes quanto necessario
        }
        else {
            cout << "O comando introduzido nao e valido" << endl; // Devolve uma mensagem de erro
        }
        /* Para limpar a última entrada e não se repetir o comando */
        comando = "";
    }
    /* Para limpar as últimas entradas e não se repetirem os inputs */
    input="";
    return 0;
}
// EOF