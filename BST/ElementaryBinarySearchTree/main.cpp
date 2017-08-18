#include "ElementaryBinarySearchTree.h"

int main()
{
    ElementaryBinarySearchTree ebst;
    ebst.insert('s', 2);
    ebst.insert('t', 3);
    ebst.insert('u', 4);
    ebst.insert('d', 1);
    ebst.insert('y', 5);

    ebst.show();
}
