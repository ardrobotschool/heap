#include <iostream>

class Heap{
  public:
    Heap();
    ~Heap();
    int peek();
    int pop();
    void insert();
  private:
    int *nodes = NULL;
};