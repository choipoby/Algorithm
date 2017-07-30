#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <vector>

template<typename T>
class MergeSort
{
public:
    static void sort(std::vector<T>& data);

public:
    virtual ~MergeSort(){}
    void static sort(std::vector<T>& data, int from, int to, std::vector<T>& result);
    void static merge(std::vector<T>& data, int from, int mid, int to, std::vector<T>& result);
};

template<typename T>
void MergeSort<T>::sort(std::vector<T>& input)
{
    std::vector<T> output = input;
    sort(input, 0, output.size() - 1, output);
}

template<typename T>
void MergeSort<T>::sort(
    std::vector<T>& in,
    int from,
    int to,
    std::vector<T>& out)
{
    printf("sort %d - %d\n", from, to);
    if(from == to)
        return;
    int mid = from + (to - from)/2;
    sort(in, from, mid, out);
    sort(in, mid+1, to, out);
    merge(in, from, mid, to, out);
}

template<typename T>
void MergeSort<T>::merge(
    std::vector<T>& in,
    int from,
    int mid,
    int to,
    std::vector<T>& out)
{
    printf("merge from:%d, mid:%d, to:%d\n", from, mid, to);
    int i = from;
    int j = mid + 1;
    int k = from;

    while(k<=to){
        if (i > mid) {
            out[k] = in[j++];
        } else if(j>to){
            out[k] = in[i++];
        } else if (in[i] > in[j]){
            out[k] = in[j++];
        } else {
            out[k] = in[i++];
        }
        k++;
    }

    for(i=from; i<=to; i++){
        in[i] = out[i];
    }
}

#endif
