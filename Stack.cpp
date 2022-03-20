#include "Stack.h"
#include <iostream>

template <class T>
Stack<T>::Stack()
{
  stack = std::vector<T>();
}

template <class T>
void Stack<T>::push(T t)
{
  if (t != NULL) stack.push_back(t);
}

template <class T>
T Stack<T>::pop()
{
  if (stack.size() == 0) return NULL;
  T last = stack.back();
  stack.pop_back();
  return last;
}

template <class T>
int Stack<T>::size()
{
  return stack.size();
}

template <class T>
bool Stack<T>::isEmpty()
{
  return stack.size() == 0;
}
