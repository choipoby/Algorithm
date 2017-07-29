#ifndef QUEUE_LINKED_LIST_H
#define QUEUE_LINKED_LIST_H

#include <memory>
#include <assert.h>
#include "IQueue.h"

template<typename T>
class QueueLinkedList : public IQueue<T>
{
public:
    class Node{
    public:
        T item;
        std::shared_ptr<Node> prev;
        std::shared_ptr<Node> next;
    };
    QueueLinkedList();
    virtual ~QueueLinkedList();
    virtual bool isEmpty() override;
    virtual int size() override;
    virtual void enqueue(T) override;
    virtual T dequeue() override;
private:
    // head and tail are dummy. it is just dummy node
    std::shared_ptr<Node> head;
    std::shared_ptr<Node> tail;
    int mSize;
};

template<typename T>
QueueLinkedList<T>::QueueLinkedList() : mSize(0)
{
    head = std::make_shared<Node>();
    tail = std::make_shared<Node>();
    head->next = tail;
    head->prev = std::shared_ptr<Node>();
    tail->next = std::shared_ptr<Node>();
    tail->prev = head;
}

template<typename T>
QueueLinkedList<T>::~QueueLinkedList()
{
    head.reset();
    tail.reset();
}

template<typename T>
bool QueueLinkedList<T>::isEmpty()
{
    return head->next == tail;
}

template<typename T>
int QueueLinkedList<T>::size()
{
    return mSize;
}

template<typename T>
void QueueLinkedList<T>::enqueue(T t)
{
    // add a new element at head
    std::shared_ptr<Node> node = std::make_shared<Node>();
    node->item = t;
    node->prev = head;
    node->next = head->next;
    head->next->prev = node;
    head->next = node;
    ++mSize;
}

template<typename T>
T QueueLinkedList<T>::dequeue()
{
    assert(tail->prev != head);
    std::shared_ptr<Node> node = tail->prev;
    node->prev->next = tail;
    tail->prev = node->prev;
    --mSize;
    return node->item;
}

#endif
