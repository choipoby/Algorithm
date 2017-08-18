#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <vector>

template<typename T>
class MergeSort
{
public:
    static void sort(std::vector<T>& data);

public:
    MergeSort(const std::shared_ptr<Comparator>& cc);
    virtual ~MergeSort(){}
    void static sort(std::vector<T>& data, int from, int to);
    void static merge(std::vector<T>& data);
};

template<typename T>
void MergeSort<T>::sort(std::vector<T>& input)
{
    std::vector<T> output;
    output.resize(input.size());
    sort(input, 0, input.size() - 1, output);
    input = output;
}

template<typename T>
void MergeSort<T>::sort(
    std::vector<T>& in,
    int from,
    int to,
    std::vector<T>& out)
{
    if(from == to)
        return;
    int mid = from + (to - from)/2;
    sort(in, from, mid, out);
    sort(in, mid+1, to, out);
    merge(in, from, mid, to);
}

template<typename T>
void MergeSort<T>::merge(
    std::vector<T>& in,
    int from,
    int mid,
    int to,
    std::vector<T>& out)
{
    int i = from;
    int j = mid + 1;
    int k = from;

    while(k<=to){
        if (in[i] > in[j]){
            out[k++] = in[j++];
        } else {
            out[k++] = in[i++];
        }
    }
}

#endif
