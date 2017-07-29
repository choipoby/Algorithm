#ifndef QUEUE_H
#define QUEUE_H

#include <memory>
#include "IQueue.h"
//#include "QueueLinkedList.h"
#include "QueueCircularArray.h"

template<typename T>
class Queue : public IQueue<T>
{
public:
    Queue();
    virtual ~Queue();
    virtual bool isEmpty() override;
    virtual int size() override;
    virtual void enqueue(T) override;
    virtual T dequeue() override;
private:
    //std::shared_ptr<QueueLinkedList<T> > mImpl;
    std::shared_ptr<QueueCircularArray<T> > mImpl;
};

template<typename T>
Queue<T>::Queue()
{
    //mImpl = std::make_shared<QueueLinkedList<T> >();
    mImpl = std::make_shared<QueueCircularArray<T> >();
}

template<typename T>
Queue<T>::~Queue()
{

}

template<typename T>
bool Queue<T>::isEmpty()
{
    return mImpl->isEmpty();
}

template<typename T>
int Queue<T>::size()
{
    return mImpl->size();
}

template<typename T>
void Queue<T>::enqueue(T t)
{
    return mImpl->enqueue(t);
}

template<typename T>
T Queue<T>::dequeue()
{
    return mImpl->dequeue();
}

#endif
