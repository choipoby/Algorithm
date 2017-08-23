#include <stdio.h>
#include <set>

#define null 0

class Node
{
public:
    Node(int v)
    : val(v)
    , prev(null)
    , next(null)
    {}
    int val;
    Node* prev;
    Node* next;
};

class LinkedList
{
public:
    LinkedList() : head(null) {}
    // Last in First out
    void add(Node* node);
    void remove();
    Node* removeNode(Node *n);
    void removeDuplicate();
    void printAll();
private:
    Node* head;
};

void LinkedList::add(Node* node)
{
    if (head == null) {
        head = node;
        head->next = null;
        return;
    }
    head->prev = node;
    node->next = head;
    head = node;

    return;
}

void LinkedList::remove()
{
    if(head==null)
        return;

    if(head->next == null){
        delete head;
        head = null;
        return;
    }

    Node* newHead = head->next;
    newHead->prev = null;
    delete head;
    head = newHead;
}

Node* LinkedList::removeNode(Node *n)
{
    Node* nextNode = null;
    printf("remove Node %p\n", n);
    if(n->next){
        n->next->prev = n->prev;
    }
    if(n->prev){
        n->prev->next = n->next;
    }

    if(n == head)
        head = null;

    nextNode = n->next;
    delete n;
    return nextNode;
}

void LinkedList::removeDuplicate()
{
    std::set<int> s;
    Node* currentNode = head;
    while(currentNode != null) {
        if(s.find(currentNode->val) != s.end()){
            // remove current node
            currentNode = removeNode(currentNode);
        } else {
            s.insert(currentNode->val);
            currentNode = currentNode->next;
        }
    }
}

void LinkedList::printAll()
{
    Node* currentNode = head;
    while(currentNode != null) {
        printf("%d\n", currentNode->val);
        currentNode = currentNode->next;
    }
}

int main()
{
    // remove duplicate
    LinkedList list;
    for(int i=0; i<10; i++) {
        list.add(new Node(i));
    }

    for(int i=0; i<14; i++) {
        list.remove();
    }

    for(int i=0; i<100; i++) {
        list.add(new Node(i%10));
    }

    list.removeDuplicate();

    list.printAll();

}
