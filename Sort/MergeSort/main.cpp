#include <vector>
#include "MergeSort.h"

int main()
{
    std::vector<int> example = {5,4,6,3,9,1, 22};
    MergeSort<int> ms;
    ms.sort(example);

    std::vector<int>::iterator itr = example.begin();
    for(; itr!=example.end(); itr++) {
        printf("%d\n", *itr);
    }
}
