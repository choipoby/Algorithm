#ifndef QUEUE_CIRCULAR_ARRAY_H
#define QUEUE_CIRCULAR_ARRAY_H

#include <memory>
#include <assert.h>
#include "IQueue.h"

template<typename T>
class QueueCircularArray : public IQueue<T>
{
public:
    QueueCircularArray();
    virtual ~QueueCircularArray();
    virtual bool isEmpty() override;
    virtual int size() override;
    virtual void enqueue(T) override;
    virtual T dequeue() override;
    virtual bool hasNext() override;
    virtual T next() override;
private:
    // head and tail are dummy. it is just dummy node
    int head;
    int tail;
    int capacity;
    int mSize;
    T* pool;
    bool isFull();
    int next;
};

template<typename T>
QueueCircularArray<T>::QueueCircularArray()
    : head(-1)
    , tail(-1)
    , capacity(4)
    , mSize(0)
{
    pool = new T[capacity];
}

template<typename T>
QueueCircularArray<T>::~QueueCircularArray()
{
    delete[] pool;
}

template<typename T>
bool QueueCircularArray<T>::isEmpty()
{
    return head == -1;
}

template<typename T>
bool QueueCircularArray<T>::isFull()
{
    if(head > tail) {
        return (head - tail + 1 == capacity);
    } else {
        return tail - 1 == head;
    }
}

template<typename T>
int QueueCircularArray<T>::size()
{
    if (isEmpty())
        return 0;
    if(tail >= head) {
        return (tail - head + 1);
    } else {
        return capacity - (head - tail + 1);
    }
}

template<typename T>
void QueueCircularArray<T>::enqueue(T t)
{
    if (isEmpty()){
        head = tail = 0;
        pool[head] = t;
    } else if (isFull()){
        // enlarge circular array capacity
        // increase the number of pool
        capacity = 2*capacity;
        printf("new capacity %d\n", capacity);
        T* temp = new T[capacity];
        if ( tail > head) {
            for(int i=head; i<=tail; i++) {
                memcpy(&temp[i], &pool[i], sizeof(T));
            }
        } else {
            for(int i=head; i<capacity; i++) {
                memcpy(&temp[i-head], &pool[i], sizeof(T));
            }
            for(int i=0; i<=tail; i++) {
                memcpy(&temp[capacity -head], &pool[i], sizeof(T));
            }
        }
        delete[] pool;
        pool = temp;
    } else {
        ++tail;
        tail %= capacity;
        pool[tail] = t;
    }

    printf("enqueu : head %d, tail %d \n", head, tail);
}

template<typename T>
T QueueCircularArray<T>::dequeue()
{
    // todo : reduce the capacity when not needed all
    T t = pool[head];
    if ( head == tail && head != -1) {
        // returned the last remaining element from an array
        head = tail = -1;
    } else {
        ++head %= capacity;
    }
    printf("dequeue : head %d, tail %d \n", head, tail);
    return t;
}


template<typename T>
bool QueueCircularArray<T>::hasNext()
{

}

template<typename T>
T QueueCircularArray<T>::next()
{


}


#endif
