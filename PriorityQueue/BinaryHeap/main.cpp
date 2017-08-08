#include <stdio.h>

#include <vector>
#include "BinaryHeapPriorityQueue.h"

int main()
{
    std::vector<int> example = {5,4,6,3,9,1,22};

    BinaryHeapPriorityQueue bh;

    for(std::vector<int>::iterator it = example.begin(); it!=example.end(); it++)
    {
        printf("insert %d\n", *it);
        bh.insert(*it);
        bh.show();
    }

    for(std::vector<int>::iterator it = example.begin(); it!=example.end(); it++)
    {
        printf("getMax %d\n", bh.getMax());
        bh.show();
    }
}
