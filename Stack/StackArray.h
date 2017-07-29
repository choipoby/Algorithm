#include <memory>
#include "IStack.h"

template<class T>
class StackArray : public IStack<T>
{
public:
    StackArray();
    virtual ~StackArray();
    bool isEmpty() override;
    void push(T) override;
    T pop() override;
private:
    T* pool;
    int index;
    int currentSize = 1;
};

template <typename T>
StackArray<T>::StackArray()
    : index(0)
{
    pool = new T[currentSize];
}

template <typename T>
StackArray<T>::~StackArray()
{
    delete[] pool;
}

template <typename T>
bool StackArray<T>::isEmpty()
{
    if (index)
        return true;
    return false;
}

template<typename T>
void StackArray<T>::push(T t)
{
    if (index >= currentSize) {
        // increase the number of pool
        currentSize = 2*index;
        printf("currentSize %d\n", currentSize);
        T* temp = new T[currentSize];
        for(int i=0; i<index; i++) {
            memcpy(&temp[i], &pool[i], sizeof(T));
        }
        delete[] pool;
        pool = temp;
    }
    pool[index++] = t;
    return;
}

template<typename T>
T StackArray<T>::pop()
{
    T t = pool[--index];
    if(index < currentSize/4){
        currentSize = currentSize/2;
            printf("currentSize %d\n", currentSize);
        T* temp = new T[currentSize];
        for(int i=0; i<index; i++) {
            memcpy(&temp[i], &pool[i], sizeof(T));
        }
        delete[] pool;
        pool = temp;
    }
    return t;
}
