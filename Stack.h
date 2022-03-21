/**
 * @file Stack.h
 * @author Boran Seckin (seckinb@mcmaster.ca)
 */

#ifndef STACK_H_
#define STACK_H_

#include "TNode.h"
#include <vector>

template <class T>
class Stack
{
  private:
    std::vector<T> stack;
  
  public:
    Stack();

    void push(T);
    T pop();
    int size();
    bool isEmpty();
};

#endif /* STACK_H_ */
