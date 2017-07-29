#include "Stack.h"

int main()
{
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    printf("%d\n", s.pop());
    printf("%d\n", s.pop());
    printf("%d\n", s.pop());
    printf("%d\n", s.pop());
    printf("%d\n", s.pop());
    printf("%d\n", s.pop());
}
