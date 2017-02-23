#include <iostream>
#include "Heap.hpp"

Heap::Heap(){
    size = 0; //Number of (non-zero) nodes, not the size of the array.
    nodes = new int[128];
    for(int i = 0; i < 128; i++){
        nodes[i] = 0;
    }
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
    if(size < sizeof(nodes)/sizeof(int)){
        nodes[size] = num;
        sortUp(size++);
    }
    else{
        //Make a bigger array!
        int* newNodes = new int[2*sizeof(nodes)/sizeof(int)];
        for(int i = 0; i < sizeof(nodes)/sizeof(int); i++){
            newNodes[i] = nodes[i];
        }
        for(int i = sizeof(nodes)/sizeof(int); i < sizeof(newNodes)/sizeof(int); i++){
            newNodes[i] = 0;
        }
        insert(num);
    }
}

void Heap::sortUp(int i){
    if(i<=0){
        return;
    }
    int parent = i%2 == 1 ? (i-1)/2 : (i-2)/2;
    if(nodes[i] > nodes[parent]){
        //Swap and keep swapping if necessary!
        int temp = nodes[parent];
        nodes[parent] = nodes[i];
        nodes[i] = temp;
        sortUp(parent);
    }
}

void Heap::sortDown(int i){
    
}