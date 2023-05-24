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
string validarComando(string input){
    if(input[0] == '#' || input.empty()){ // Critério para garantir que existe um cmd
        return "Introduzir um comando valido";
    }else{
        return input;// Devolve o input, e continua a executar
    }
}

int main() {
    cout<<"Inicio"<<endl;

    string input, comando, argumento;
    IMINH minHeap;   // exemplo

    while (getline(cin, input)) {

        stringstream ssInput(input); // Extrai a linha completa
        /* Verifica que o comando introduzido é válido*/
        string comandoValido = validarComando(input); // Verifica se o comando é valido

        ssInput >> comando; // Extrai o nome do comando
        while (ssInput >> argumento) { //Extrai os argumentos dos comandos - 2 ou mais argumentos)
            cout <<"argumento: " << argumento<<endl;
            cout <<"commando: " << comando<<endl;
        }
    }
    return 0;
}
// EOF