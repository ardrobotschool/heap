#include <iostream>
#include "Heap.hpp"

Heap::Heap(){
    size = 0; //Number of (non-zero) nodes, not the size of the array.
    nodes = new int[128];
    memset(nodes, 0, sizeof(nodes));
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
    if(size < sizeof(nodes)){
        nodes[size] = num;
        sortUp(size++);
    }
    else{
        //Make a bigger array!
    }
}

void Heap::sortUp(int i){
    
}

void Heap::sortDown(int i){
    
}