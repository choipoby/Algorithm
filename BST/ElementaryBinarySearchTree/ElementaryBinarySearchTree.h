#ifndef ELEMENTARY_BINARY_SEARCH_TREE
#define ELEMENTARY_BINARY_SEARCH_TREE

#include <vector>

class ElementaryBinarySearchTree{
public:
    ElementaryBinarySearchTree();
    void insert(char key, int value);
    void remove(char key);
    int search(char key);
    void show();
private:
    int getInsertIndex(char key, int startIndex, int endIndex);
    std::vector<char> mKeyHolder;
    std::vector<int> mValHolder;
};

ElementaryBinarySearchTree::ElementaryBinarySearchTree()
{
    mKeyHolder.reserve(100);
}


void ElementaryBinarySearchTree::insert(char key, int val)
{
    // first get the index for a key
    int index = getInsertIndex(key, 0, mKeyHolder.size() - 1);
    std::vector<char>::const_iterator newKeyPos = mKeyHolder.begin() + index;
    std::vector<int>::const_iterator newValPos = mValHolder.begin() + index;
    mKeyHolder.insert(newKeyPos, 1, key);
    mValHolder.insert(newValPos, 1, val);
}

void ElementaryBinarySearchTree::remove(char key)
{

}

int ElementaryBinarySearchTree::getInsertIndex(char key, int startIndex, int endIndex)
{
    // recursion exit condition
    if(startIndex > endIndex) {
        return startIndex;
    }

    int midIndex = startIndex + (endIndex - startIndex)/2;
    // search the key, starting from the N/2
    if (key < mKeyHolder[midIndex]) {
        // find from right half
        return getInsertIndex(key, startIndex, midIndex - 1);
    } else if (key > mKeyHolder[midIndex]) {
        // find from left half
        return getInsertIndex(key, midIndex + 1, endIndex);
    } else {
        return midIndex;
    }
}

void ElementaryBinarySearchTree::show()
{
    std::vector<char>::iterator citr = mKeyHolder.begin();
    for(;citr!=mKeyHolder.end();citr++){
        printf("%c ", *citr);
    }
    printf("\n");

    std::vector<int>::iterator itr = mValHolder.begin();
    for(;itr!=mValHolder.end();itr++){
        printf("%d ", *itr);
    }
    printf("\n");

}
#endif
