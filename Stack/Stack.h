#ifndef STACK
#define STACK

#include <memory>
#include "IStack.h"
#include "StackLinkedList.h"

template <typename T>
class Stack : public IStack<T>
{
public:
    Stack();
    virtual ~Stack();
    virtual bool isEmpty() override;
    virtual void push(T t) override;
    virtual T pop() override;

private:
    std::shared_ptr<StackLinkedList<T> > pImpl;
};
template <typename T>
Stack<T>::Stack()
{
    pImpl = std::make_shared<StackLinkedList<T> >();
}

template <typename T>
Stack<T>::~Stack()
{
}

template <typename T>
bool Stack<T>::isEmpty()
{
    return pImpl->isEmpty();
}

template<typename T>
void Stack<T>::push(T t)
{
    return pImpl->push(t);
}

template<typename T>
T Stack<T>::pop()
{
    return pImpl->pop();
}


#endif
