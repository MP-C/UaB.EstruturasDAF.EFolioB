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


IMINH::IMINH(int capacity) {
    heap = new int[capacity];
    size = 0;
    this->capacity = capacity;
}

IMINH::~IMINH() {
    delete[] heap;
}

void IMINH::insert(int item) {
    if (size == capacity) {
       cout << "Comando insert: Heap cheio!\n";
        return;
    }
    heap[size++] = item;
    int i = size - 1;
    while (i > 0 && heap[i] < heap[(i - 1) / 2]) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void IMINH::print_min() const {
    if (size == 0) {
       cout << "Comando print_min: Heap vazio!\n";
        return;
    }
    cout << "Min= " << heap[0] << "\n";
}

void IMINH::print() const {
    if (size == 0) {
        cout << "Comando print: Heap vazio!\n";
        return;
    }
    cout << "Heap=\n";
    int level_size = 1;
    int i = 0;
    while (i < size) {
        for (int j = 0; j < level_size && i < size; j++) {
            cout << heap[i++] << " ";
        }
        cout << "\n";
        level_size *= 2;
    }
}

int IMINH::dim() const {
    return size;
}

int IMINH::dim_max() const {
    return capacity;
}

void IMINH::clear() {
    size = 0;
}

void IMINH::remove() { // Corresponde ao commando delete do enunciado
    if (size == 0) {
        cout << "Comando Delete: Heap vazio!\n";
        return;
    }
    heap[0] = heap[--size];
    heapify_down(0);
}

void IMINH::heapify_up(/*vector<int> items*/) {
    clear();
    /*for (int item : items) {
        insert(item);
    }*/
}

void IMINH::redim_max(int new_capacity) {
    int* new_heap = new int[new_capacity];
    for (int i = 0; i < size && i < new_capacity; i++) {
        new_heap[i] = heap[i];
    }
    delete[] heap;
    heap = new_heap;
    capacity = new_capacity;
    size = min(size, capacity);
}

void IMINH::heapify_down(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < size && heap[left] < heap[smallest]) {
        smallest = left;
    }
    if (right < size && heap[right] < heap[smallest]) {
        smallest = right;
    }
    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        heapify_down(smallest);
    }
}

void IMINH::swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
// EOF