#ifndef REDBLACK_BST_H
#define REDBLACK_BST_H

class RedBlackBST{
public:
    enum {
        BLACK = 0,
        RED = 1
    };

    class Node {
        Node* left;
        Node* right;
        int item;
        int color;
    };



private:
    bool isRed(Node node);
    void rotateLeft(Node* node);
    void rotateRight(Node* node);
};


bool RedBlackBST::isRed(Node* node)
{
    if(node == NULL)
        return false;
    return node->color == RED;
}

void RedBlackBST::rotateLeft(Node* alpha)
{
    // after this, what *node has is original node's right child
    Node* beta = alpha->right;

    // rotate nodes
    Node* temp = beta->left;
    beta->left = alpha;
    alpha->right = temp;

    // rotate color
    beta->color = alpha->color;
    alpha->colr = RED;

    // now switch the pointer
    alpha = beta;
}

void RedBlackBST::rotateRight(Node* alpah)
{
    Node* beta = alpha->left;
    Node* temp = beta->right;
    beta->right = alpha;
    alpha->left = temp;

    alpha->color = RED;
    beta->color = alpha;

    alpha = beta;
}

void RedBlackBST::flipColor(Node* alpah)
{
    if (alpha->left && alpha->right && isRed(alpha->left) && isRead(alpha->right)){
        alpha->color = RED;
        alpha->left = BLACK;
        alpha->right = BLACK;
    }
}

void RedBlackBST::insert(Node* node, int item)
{


}
#endif
