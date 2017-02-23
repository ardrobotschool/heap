#include <iostream>

class Heap{
  public:
    Heap();
    ~Heap();
    int peek();
    int pop();
    void insert();
    bool isEmpty();
  private:
    int *nodes = NULL;
};