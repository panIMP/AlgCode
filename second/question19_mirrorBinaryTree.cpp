#include <stack>

using namespace std;

typedef int elementT;


// Tree type enumeration
enum BINARY_TREE_TYPE
{
    RANDOM_TREE = 0, // all nodes are randomly inserted into the tree
    SEARCH_TREE,     // binary search/sorted tree
    MAX_HEAP,        // maximum heap
    MIN_HEAP,        // minimum heap
};


// Tree iteration method
enum BINARY_TREE_ITERATION_METHOD
{
    PRE_ORDER = 0,
    MID_ORDER,
    POST_ORDER,
    LAYER_ORDER,
};


// Tree node class
class BinaryTreeNode
{
public:
    explicit BinaryTreeNode(elementT& value, BinaryTreeNode* left = nullptr, BinaryTreeNode* right = nullptr)
        : mValue(value), mLeft(left), mRight(right) {}

    elementT getElement() {return mValue;}
    void setElement(elementT& newValue) {mValue = newValue;}

    BinaryTreeNode* getLeft() {return mLeft;}
    void setLeft(BinaryTreeNode*& newLeft) {mLeft = newLeft;}

    BinaryTreeNode* getRight() {return mRight;}
    void setRight(BinaryTreeNode*& newRight) {mRight = newRight;}

private:
    elementT mValue;
    BinaryTreeNode* mLeft;
    BinaryTreeNode* mRight;
};


// Tree class
class BinaryTree
{
public:
    explicit BinaryTree(BinaryTreeNode* pRoot = nullptr, BINARY_TREE_TYPE type = RANDOM_TREE);

    // release the memory of a tree including all its tree nodes
    void releaseMem();

    // insert a new node into the tree
    void insertNewNode(elementT& value);

    BinaryTreeNode* getPRoot();
    void setPRoot(BinaryTreeNode* newPRoot);

    BINARY_TREE_TYPE getTreeType();

    void printTree(BINARY_TREE_ITERATION_METHOD method = PRE_ORDER);

    // mirror itself
    void mirror();

private:
    BinaryTreeNode* mPRoot;
    BINARY_TREE_TYPE mTypeInfo;
};





int main(int argc, char* argv[])
{
    return 0;
}












































