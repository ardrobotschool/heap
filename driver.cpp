#include <iostream>
#include "Heap.hpp"

using namespace std;

int main(){
    Heap heap;
    int test[] = {5, 3, 7, 18 , 32, 19, 7, 4, 8, 53, 52, 6, 7, 7, 2};
    for(int i=0; i<sizeof(test)/sizeof(int); i++){
        heap.insert(test[i]);
    }
    heap.print();
    cout << heap.pop();
    while(!heap.isEmpty()){
        cout << ", " << heap.pop();
    }
    cout << "." << endl;
    return 0;
}