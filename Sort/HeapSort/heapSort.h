#ifndef HEAP_SORT_H
#define HEAP_SORT_H

class HeapSort {
public:
    void sort(std::vector<int>& input);

private:
    void sort(std::vector<int>& array, int arraySize);
    void sink(std::vector<int>& array, int index, int arraySize);
    void swap(std::vector<int>& array, int from, int to);
};

void HeapSort::sort(std::vector<int>& input)
{
    // construct the max heap first out of example
    int inputSize = input.size() -1; // abstraction away the first element in the input
    for(int i=inputSize/2; i>=1; i--) {
        sink(input, i, inputSize);
    }
    // sort the input
    sort(input, input.size()-1);
}

void HeapSort::sort(std::vector<int>& array, int arraySize)
{
    if(arraySize < 2)
        return;

    // need to pop last one and replace it with the biggest one at root node
    // after this, biggest one is at the last index, so now shrink index size with arraySize - 1
    // so that last one with biggest number is not touched from
    swap(array, 1, arraySize);
    sink(array, 1, arraySize-1);
    sort(array, arraySize-1);
}

void HeapSort::sink(std::vector<int>& array, int index, int arraySize)
{
    if (arraySize < index*2) {
        return;
    }

    int comparingIndex = 0;
    if ( (arraySize >= index*2 + 1) && (array[2*index + 1] > array[2*index]) ){
        // compare which one is bigger between array[index*2] and array[index*2+1]
        comparingIndex = 2*index+1;
    } else {
        comparingIndex = 2*index;
    }

    if (array[comparingIndex] > array[index]){
        swap(array, comparingIndex, index);
        sink(array, comparingIndex, arraySize);
    }
}

void HeapSort::swap(std::vector<int>& array, int a, int b)
{
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

#endif
