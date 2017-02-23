#include <iostream>

class Heap{
  public:
    Heap();
    ~Heap();
    int peek();
    int pop();
    void insert(int num);
    bool isEmpty();
  private:
    int *nodes;
    int size;  
};