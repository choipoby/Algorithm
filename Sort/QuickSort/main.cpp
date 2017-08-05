#include <stdio.h>

#include <vector>
#include "QuickSort.h"

int main()
{
    std::vector<int> example = {5,4,6,3,9,1,22};

    QuickSort qs;
    qs.sort(example);

    std::vector<int>::iterator itr = example.begin();
    for(; itr!=example.end(); itr++) {
        printf("%d\n", *itr);
    }

}
