#include <iostream>
#include "Heap.hpp"

using namespace std;

void populate(Heap &heap, char *list);
void printList(Heap &heap);

int main(){
    /*Heap heap;
    int test[] = {5, 3, 7, 18 , 32, 19, 7, 4, 8, 53, 52, 6, 7, 7, 2};
    for(int i=0; i<sizeof(test)/sizeof(int); i++){
        heap.insert(test[i]);
    }
    heap.print();
    cout << heap.pop();
    while(!heap.isEmpty()){
        cout << ", " << heap.pop();
    }
    cout << "." << endl;*/
    while(true){
        Heap heap;
        char input;
        cout << "Choose an option: \n(1) Enter numbers manually.\n(2) Enter file name.\n(q) Quit." << endl;
        cin >> input;
        if(input == '1'){
            char list[150];
            cout << "Enter the numbers, separated by commas and/or spaces:" << endl;
            cin.ignore();
            cin.getline(list, 150);
            populate(heap, list);
        }
        else if(input == '2'){
            cout << "Enter the file name: ";
            cout << endl;
        }
        else if (input == 'q'){
            break;
        }
        else{
            cout << "Command not recognized." << endl;
        }
        
        cout << "Choose an option: \n(1) Print out numbers in descending order.\n(2) Print out the tree.\n(3) Both (1) and (2)\n(q) Quit." << endl;
        cin >> input;
        if(input == '1'){
            printList(heap);
        }
        else if(input == '2'){
            heap.print();
        }
        else if(input == '3'){
            cout << "Tree:" << endl;
            heap.print();
            cout << "Sorted (in descending order) list:" << endl;
            printList(heap);
        }
        else if (input == 'q'){
            break;
        }
        else{
            cout << "Command not recognized." << endl;
        }
    }
    return 0;
}

void populate(Heap &heap, char *list){
    int index = 0;
    while(list[index]){
        if(isdigit(list[index])){
            int num = list[index] - '0';
            while(isdigit(list[++index])){
                num = 10*num + (list[index] - '0');
            }
            heap.insert(num);
        }
        else{
            index++;
        }
    }
}

void printList(Heap &heap){
    cout << heap.pop();
    while(!heap.isEmpty()){
        cout << ", " << heap.pop();
    }
    cout << "." << endl;
}