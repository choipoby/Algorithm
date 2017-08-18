#ifndef ITERABLE_H
#define ITERABLE_H

template<typename T>
class IIterable
{
public:
    virtual ~Iterable(){};
    virtual bool hasNext() = 0;
    virtual T next() = 0;
};

#endif
