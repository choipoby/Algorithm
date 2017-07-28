#ifndef ISTACK
#define ISTACK

template <typename T>
class IStack
{
public:
    virtual ~IStack(){};
    virtual bool isEmpty() = 0;
    virtual void push(T) = 0;
    virtual T pop() = 0;
};
#endif
