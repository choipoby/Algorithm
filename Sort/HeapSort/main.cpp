#include <stdio.h>

#include <vector>
#include "heapSort.h"

int main()
{
    std::vector<int> example = {-1,5,4,6,3,9,1,22,44,7,45,2,0,4,6,7,8};
    HeapSort hs;
    hs.sort(example);
    std::vector<int>::iterator itr = example.begin();
    for(++itr; itr!=example.end(); itr++) {
        printf("%d\n", *itr);
    }

}
