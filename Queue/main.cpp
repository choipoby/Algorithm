#include "Queue.h"

int main()
{
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);

    printf("%d\n", q.dequeue());
    printf("%d\n", q.dequeue());
    printf("%d\n", q.dequeue());
    printf("%d\n", q.dequeue());
    printf("%d\n", q.dequeue());
    printf("%d\n", q.dequeue());
}
