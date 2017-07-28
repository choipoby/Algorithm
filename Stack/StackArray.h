#include <memory>
#include "IStack.h"

template<class T>
class StackArray : public IStack<T>
{
public:
    class Node {
        T item;
        std::shared_ptr<Node> prev;
        std::shared_ptr<Node> next;
    };
    virtual ~StackArray();
    bool isEmpty() override;
    void push(T) override;
    T pop() override;
private:
    std::shared_ptr<Node> last;
};

template <typename T>
StackArray<T>::~StackArray()
{

}

template <typename T>
bool StackArray<T>::isEmpty()
{
    return false;
}

template<typename T>
void StackArray<T>::push(T t)
{
    // TBI
    return;
}

template<typename T>
T StackArray<T>::pop()
{
    // TBI
    T t;
    return t;
}
