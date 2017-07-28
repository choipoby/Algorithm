#include <memory>
#include <assert.h>
#include "IStack.h"

template<typename T>
class StackLinkedList : public IStack<T>
{
public:
    class Node {
    public:
        virtual ~Node(){
            printf("destroyng node\n");
        }
        T item;
        std::shared_ptr<Node> prev;
        std::shared_ptr<Node> next;
    };
    virtual ~StackLinkedList();
    bool isEmpty() override;
    void push(T) override;
    T pop() override;
private:
    std::shared_ptr<Node> last;
};

template <typename T>
StackLinkedList<T>::~StackLinkedList()
{

}

template <typename T>
bool StackLinkedList<T>::isEmpty()
{
    if (!last)
        return true;
    return false;
}

template<typename T>
void StackLinkedList<T>::push(T t)
{
    std::shared_ptr<Node> node = std::make_shared<Node>();
    node->item = t;
    if (last) {
        node->prev = last;
        last->next = node;
    }
    last = node;
}

template<typename T>
T StackLinkedList<T>::pop()
{
    assert(last);
    T t = last->item;
    if(last->prev) {
        last->prev->next.reset();
        last = last->prev;
    }
    return t;
}
