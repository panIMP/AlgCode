#include <iostream>
#include <iomanip>
#include <limits>

#include <stack>


using namespace std;

typedef int elementT;

#define NULLNODE ((elementT)'#')

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
    PRE_ORDER = 0x01,
    MID_ORDER,
    POST_ORDER,
    LAYER_ORDER,

    //using recursive function or loop respectively
    RECURSIVELY = 0x10,
    ITERATIVELY = 0x20,

    // combined choice
    PRE_ORDER_RECUR = PRE_ORDER | RECURSIVELY,
    MID_ORDER_RECUR = MID_ORDER | RECURSIVELY,
    POST_ORDER_RECUR = POST_ORDER | RECURSIVELY,
    LAYER_ORDER_RECUR = LAYER_ORDER | RECURSIVELY,

    PRE_ORDER_ITER = PRE_ORDER | ITERATIVELY,
    MID_ORDER_ITER = MID_ORDER | ITERATIVELY,
    POST_ORDER_ITER = POST_ORDER | ITERATIVELY,
    LAYER_ORDER_ITER = LAYER_ORDER | ITERATIVELY,
};


// Tree class
class BinaryTree
{
    // prior declaration
    class BinaryTreeNode;

public:
    // construct a tree root, then complete by continuely insert element
    explicit BinaryTree(BINARY_TREE_TYPE type = SEARCH_TREE) : mType(type) {}

    // construct a tree straight through the input array
    BinaryTree(const elementT value[], int len, BINARY_TREE_TYPE type = RANDOM_TREE);

    ~BinaryTree();

    BINARY_TREE_TYPE getTreeType() const {return mType;}

    // construct a tree through sequentially input stream until all the leaves are input
    void input();

    // remove a node
    void remove(const elementT& value);

    // release the memory of a tree including all its tree nodes with two methods respectively
    void releaseMemIteratively();
    void releaseMemRecursively();

    // print the tree through different iteration method
    void printTree(BINARY_TREE_ITERATION_METHOD type = PRE_ORDER_RECUR) const;

    // mirror itself
    void mirror();

private:
    // insert a node
    void insert(BinaryTreeNode*& pNode, const elementT*& value, int& len) const;

    // print tree preorder recursively
    void printTreePreRecur(BinaryTreeNode* pNode) const;

    // put input-element in the tree
    void inputRecursively(BinaryTreeNode*& pNode);

private:
    // Tree node class
    class BinaryTreeNode
    {
    public:
        ~BinaryTreeNode()
        {
            delete(mLeft);
            mLeft = nullptr;
            delete(mRight);
            mRight = nullptr;
        }

        elementT mValue = NULLNODE;
        BinaryTreeNode* mLeft = nullptr;
        BinaryTreeNode* mRight = nullptr;
    };

    BinaryTreeNode* mPRoot = nullptr;
    BINARY_TREE_TYPE mType;
};


// construct a tree straight through the input array
BinaryTree::BinaryTree(const elementT value[], int len, BINARY_TREE_TYPE type)
{
    this->mType = type;

    switch (type) {
    case RANDOM_TREE:
    {
        insert(this->mPRoot, value, len);
    }
        break;
    default:
        break;
    }
}


// insert the element array
void BinaryTree::insert(BinaryTreeNode*& pNode, const elementT*& value, int& len) const
{
    if (len <= 0)
        return;

    if (value[0] == NULLNODE)
    {
        pNode = nullptr;
        return;
    }

    pNode = new BinaryTreeNode();
    pNode->mValue = value[0];

    insert(pNode->mLeft, ++value, --len);
    insert(pNode->mRight, ++value, --len);
}


// construct a tree through sequentially input stream until all the leaves are input
void BinaryTree::input()
{
    inputRecursively(this->mPRoot);
}


// put input-element in the tree
void BinaryTree::inputRecursively(BinaryTreeNode*& pNode)
{
    elementT value = 0;
    cin >> value;

    if (value == NULLNODE || cin.fail())
    {
        pNode = nullptr;
        cin.clear();
        cin.ignore();
        return;
    }

    pNode = new BinaryTreeNode();
    pNode->mValue = value;

    inputRecursively(pNode->mLeft);
    inputRecursively(pNode->mRight);
}

// print the tree through different iteration method
void BinaryTree::printTree(BINARY_TREE_ITERATION_METHOD type) const
{
    switch (type) {
    case PRE_ORDER_RECUR:
        printTreePreRecur(this->mPRoot);
        break;
    default:
        break;
    }
}


// print tree preorder recursively
void BinaryTree::printTreePreRecur(BinaryTreeNode* pNode) const
{
    if (pNode == nullptr)
        return;

    cout << pNode->mValue << "\t";

    printTreePreRecur(pNode->mLeft);
    printTreePreRecur(pNode->mRight);
}



int main(int argc, char* argv[])
{
    //elementT value[] = {10, 3, '#', '#', 4, '#', 5, 6, '#', 9, 1, 7, 8};

    //BinaryTree* tree = new BinaryTree(value, sizeof(value) / sizeof(elementT));

    BinaryTree* tree = new BinaryTree(RANDOM_TREE);
    tree->input();

    tree->printTree();

    return 0;
}












































