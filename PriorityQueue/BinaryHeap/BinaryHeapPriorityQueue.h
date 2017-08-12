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
    int arraySize = buffer.size() - 1;
    if (arraySize < index*2) {
        return;
    }

    int comparingIndex = 0;
    if ( (arraySize >= index*2 + 1) && (buffer[2*index + 1] > buffer[2*index]) ){
        comparingIndex = 2*index+1;
    } else {
        comparingIndex = 2*index;
    }

    if (buffer[comparingIndex] > buffer[index]){
        swap(comparingIndex, index);
        sink(comparingIndex);
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
}
#endif
