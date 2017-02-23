#include <iostream>
#include "Heap.hpp"

Heap::Heap(){
    size = 128;
    nodes = new int[size];
    memset(nodes, 0, size);
}

Heap::~Heap(){
    delete[] nodes;
}

bool Heap::isEmpty(){
    return nodes[0] == 0;
}

int Heap::peek(){
    return nodes[0];
}

int Heap::pop(){
    int temp = nodes[0];
    //Remove the root and preserve the heap property!
    return temp;
}

void Heap::insert(int num){
    //Insert!
}