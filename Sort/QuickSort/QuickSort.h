#ifndef QUICKSORT_H__
#define QUICKSORT_H__

#include <vector>

class QuickSort
{
public:
    ~QuickSort(){}
    void static sort(std::vector<int>& input);
private:
    void static sort(std::vector<int>& input, int start, int end);
};

void QuickSort::sort(std::vector<int>& input)
{
    // call API that can be recursive form
    sort(input, 0, input.size() - 1);
}

void QuickSort::sort(std::vector<int>& input, int start, int end)
{
    if (start == end) return;

    int anchor = input[start];
    int i = start+1;
    int j = end;

    while(true){
        while(true){
            if(input[i] < anchor)
                i++;
            else
                break;
        }

        while(true) {
            if(input[j] > anchor) {
                j--;
            } else {
                break;
            }
        }

        if(i>j){
            input[start] = input[j];
            input[j] = anchor;
            break;
        }

        int temp = input[i];
        input[i] = input[j];
        input[j] = temp;
    }

    sort(input, start, j-1);
    sort(input, i, end);

}


#endif
