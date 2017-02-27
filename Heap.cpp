#include <iostream>
#include "Heap.hpp"
#include <cmath>

using namespace std;

Heap::Heap(){
    count = 0; //Number of (non-zero) nodes/elements, not the size of the array.
    size = 128; //Size of array.
    nodes = new int[size];
    for(int i = 0; i < size; i++){
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
    nodes[0] = nodes[count-1];
    nodes[count-1] = 0;
    count--;
    sortDown(0);
    return temp;
}

void Heap::insert(int num){
    if(count < size){
        nodes[count] = num;
        sortUp(count); //Preserve heap property
        count++;
    }
    else{
        //Make a bigger array!
        int* newNodes = new int[2*size];
        for(int i = 0; i < size; i++){
            newNodes[i] = nodes[i];
        }
        for(int i = size; i < 2*size; i++){
            newNodes[i] = 0;
        }
        int *temp = nodes;
        nodes = newNodes;
        delete[] temp;
        size *= 2;
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
    //Note: we don't have to worry about going outside the array when checking the values of the children
    //because currently the minimum size is 128 and empty nodes have a value of 0.
    if(nodes[i] < nodes[2*i+1] || nodes[i] < nodes[2*i+2]){
        int maxindex = nodes[2*i+1] > nodes[2*i + 2] ? 2*i+1 : 2*i + 2;
        //swap!
        int temp = nodes[i];
        nodes[i] = nodes[maxindex];
        nodes[maxindex] = temp;
        sortDown(maxindex);
    }
}

void Heap::print(){
    //I made it look pretty, but only if the numbers are 1 or 2 digit.
    int numLevels = ceil(log2(count + 1));
    int index = 0;
    for(int l=1; l <= numLevels; l++){
        //Initial spaces:
        for(int i=0; i < pow(2, numLevels-l)-1; i++){
            cout << ' ';
        }
        //Nodes:
        for(int n=0; n < pow(2, l-1); n++){
            cout << nodes[index++]; // Node
            //Spaces between nodes:
            for(int i=0; i < pow(2, numLevels - l + 1) - 1; i++){
                cout << ' ';
            }
        }
        cout << endl;
    }
}