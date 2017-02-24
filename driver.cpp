#include <iostream>
#include "Heap.hpp"

using namespace std;

int main(){
    Heap heap;
    heap.insert(3);
    heap.insert(4);
    cout << heap.peek() << endl;
    return 0;
}