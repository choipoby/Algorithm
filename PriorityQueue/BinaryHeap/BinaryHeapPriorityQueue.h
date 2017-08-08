#ifndef BINARY_HEAP_PRIORITY_QUEUE_
#define BINARY_HEAP_PRIORITY_QUEUE_

#include "stdio.h"
#include <vector>

class BinaryHeapPriorityQueue
{
public:
    BinaryHeapPriorityQueue();
    int getMax();
    int getMin();
    void insert(int element);
    void show();
private:
    void swim(int index);
    void sink(int index);
    void swap(int index1, int index2);
    std::vector<int> buffer;
};

BinaryHeapPriorityQueue::BinaryHeapPriorityQueue()
{
    //buffer.resize(1);
    buffer.push_back(-1); // null node at buffer[0]
}

int BinaryHeapPriorityQueue::getMax()
{
    int max = buffer[1];
    swap(1, buffer.size()-1);
    buffer.pop_back();
    sink(1);
    return max;
}

int BinaryHeapPriorityQueue::getMin()
{
    int min = buffer.back();
    buffer.pop_back();
    return min;
}

void BinaryHeapPriorityQueue::insert(int element)
{
    buffer.push_back(element);
    int leafIndex = buffer.size() - 1;
    swim(leafIndex);
}

void BinaryHeapPriorityQueue::swim(int index)
{
    if ( index >= 2 && buffer[index] > buffer[index/2]) {
        swap(index, index/2);
        swim(index/2);
    }
}

void BinaryHeapPriorityQueue::sink(int index)
{
    // return if there is no leaf node to swap
    //printf("index %d, buffer.size() - 1 : %d \n", index, buffer.size() - 1);

    if ( buffer.size()-1 >= 2*index+1 ) {
        if( buffer[2*index + 1] >= buffer[2*index] && buffer[2*index +1] > buffer[index]) {
            swap(2*index + 1, index);
            sink(2*index + 1);
        } else {
            swap(2*index, index);
            sink(2*index);
        }
    } else if ( buffer.size()-1 >= 2*index && buffer[2*index] > buffer[index]) {
        swap(2*index, index);
        sink(2*index);
    }
}

void BinaryHeapPriorityQueue::swap(int index1, int index2)
{
    int temp = buffer[index2];
    buffer[index2] = buffer[index1];
    buffer[index1] = temp;
}

void BinaryHeapPriorityQueue::show()
{

    int size = buffer.size();
    for(int i=1 ; i<size; i++)
    {
        printf("%d,", buffer[i]);
    }
    printf("\n----------------------------\n");
}
#endif
