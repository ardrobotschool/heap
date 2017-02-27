#include <iostream>
#pragma once

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
    int count;
    int size;
    void sortUp(int i);
    void sortDown(int i);
};