#ifndef IQUEUE_H
#define IQUEUE_H

#include <memory>

template<typename T>
class IQueue
{
public:
    virtual ~IQueue(){};
    virtual bool isEmpty() = 0;
    virtual int size() = 0;
    virtual void enqueue(T) = 0;
    virtual T dequeue() = 0;
};

#endif
