#include <iostream>
#include <iomanip>
#include <limits>
#include <fstream>
#include <string>
#include <stdio.h>
#include "myClass/hpFun.h"

#include <stack>
#include <queue>

#include <stdexcept>

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
    explicit BinaryTree(BINARY_TREE_TYPE type = RANDOM_TREE);

    // construct a tree straight through the input array
    BinaryTree(const elementT value[], int len, BINARY_TREE_TYPE type = RANDOM_TREE);

    ~BinaryTree();

    // shallow copy, share the same node data memory with father tree
    BinaryTree(const BinaryTree& bTree);
    BinaryTree& operator=(const BinaryTree& biTree);

    // construct a tree through sequentially input stream until all the leaves are input
    void input();

    // insert one element into the search tree or max heap or min heap
    void insertOneElement(const elementT& value);

    // shallow copy, share the same node data memory with father tree
    BinaryTree getSubLeftTree();
    BinaryTree getSubRightTree();

    BINARY_TREE_TYPE getTreeType() const {return mType;}

    // mirror itself
    void mirror();

    // print the tree through different iteration method
    void printTree(BINARY_TREE_ITERATION_METHOD type = PRE_ORDER_RECUR) const;

private:
    // insert input element into the tree
    void inputRecursively(BinaryTreeNode*& pNode);

    // insert a node
    void insertArrayOfElements(BinaryTreeNode*& pNode, const elementT*& value, int& len);

    // insert an element into search tree
    BinaryTreeNode* insertOneElementIntoSearchTree(const elementT& value, BinaryTreeNode*& pNode);

    // release the node memory recursively
    void releaseRecursively(BinaryTreeNode *&pNode);

    // release the node memory from top to bottom
    void releaseLayerOrder(BinaryTreeNode*& pNode);

    // mirror the tree recursively
    void mirrorRecursively(BinaryTreeNode* pNode);

    // print tree preorder recursively
    void printTreePreRecur(BinaryTreeNode* pNode) const;

    // print tree preorder iteratively
    void printTreePreIter(BinaryTreeNode* pRoot) const;

    // print tree preorder iteratively
    void printTreePreIter2(BinaryTreeNode* pRoot) const;

    // print tree midorder recursively
    void printTreeMidRecur(BinaryTreeNode* pNode) const;

    // print tree midorder iteratively
    void printTreeMidIter(BinaryTreeNode* pRoot) const;

    // print tree postorder recursively
    void printTreePostRecur(BinaryTreeNode* pNode) const;

    // print tree postorder iteratively
    void printTreePostIter(BinaryTreeNode* pRoot) const;

    // print tree layerorder recursively
    void printTreeLayerRecur(BinaryTreeNode* pNode) const;

    // print tree preorder iteratively
    void printTreeLayerIter(BinaryTreeNode* pRoot) const;

    // Tree node class
    class BinaryTreeNode
    {
    public:
        explicit BinaryTreeNode()
        {
            ++rcCount;
        }

        BinaryTreeNode(const BinaryTreeNode& biTreeNode)
        {
            this->mLeft = biTreeNode.mLeft;
            this->mRight = biTreeNode.mRight;
            this->mValue = biTreeNode.mValue;

            ++rcCount;
        }

        BinaryTreeNode& operator =(const BinaryTreeNode& biTreeNode)
        {
            if (this == &biTreeNode)
                return *this;

            this->mLeft = biTreeNode.mLeft;
            this->mRight = biTreeNode.mRight;
            this->mValue = biTreeNode.mValue;

            ++rcCount;
        }

        ~BinaryTreeNode()
        {
            if (mLeft != nullptr)
                mLeft->deleteReference();

            if (mRight != nullptr)
                mRight->deleteReference();
        }

        void addReference()
        {
            ++rcCount;
        }

        void deleteReference()
        {
            if (--rcCount == 0)
            {
                delete this;
            }
        }

        elementT mValue = NULLNODE;
        BinaryTreeNode* mLeft = nullptr;
        BinaryTreeNode* mRight = nullptr;

    private:
        // reference count
        int rcCount = 0;
    };

    BinaryTreeNode* mPRoot = nullptr;
    BINARY_TREE_TYPE mType;
};


// construct a tree root, then complete by continuely insert element
BinaryTree::BinaryTree(BINARY_TREE_TYPE type)
{
    this->mType = type;
    this->mPRoot = nullptr;
}


// construct a tree through sequentially input stream until all the leaves are input
void BinaryTree::input()
{
    switch (this->mType) {
    case RANDOM_TREE:
        // insert element from input(std, file, etc)
        inputRecursively(this->mPRoot);
        break;
    default:
        break;
    }
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
    if (pNode == nullptr)
    {
        DEBUG_PRINT("memory allocation failed");
        exit(-1);
    }
    pNode->mValue = value;

    inputRecursively(pNode->mLeft);
    inputRecursively(pNode->mRight);
}


// construct a tree straight through the input array
BinaryTree::BinaryTree(const elementT value[], int len, BINARY_TREE_TYPE type)
{
    if (value == nullptr || len <= 0)
        return;

    this->mType = type;
    this->mPRoot = nullptr;

    switch (type){
    case RANDOM_TREE:
        // insert the element in the value array
        insertArrayOfElements(this->mPRoot, value, len);
        break;
    default:
        break;
    }
}


// insert the element array
void BinaryTree::insertArrayOfElements(BinaryTreeNode*& pNode, const elementT*& value, int& len)
{
    if (len <= 0 || value == nullptr)
        return;

    if (value[0] == NULLNODE)
    {
        pNode = nullptr;
        return;
    }

    pNode = new BinaryTreeNode();
    if (pNode == nullptr)
    {
        DEBUG_PRINT("memory allocation failed");
        exit(-1);
    }
    pNode->mValue = value[0];

    insertArrayOfElements(pNode->mLeft, ++value, --len);
    insertArrayOfElements(pNode->mRight, ++value, --len);
}


// insert one element into the search tree or max heap or min heap
void BinaryTree::insertOneElement(const elementT &value)
{
    switch (this->mType) {
    case RANDOM_TREE:
        DEBUG_PRINT("not a valid tree type to call this method");
        exit(-1);
    case SEARCH_TREE:
        insertOneElementIntoSearchTree(value, this->mPRoot);
        break;
    default:
        break;
    }

}


// insert an element into search tree
BinaryTree::BinaryTreeNode* BinaryTree::insertOneElementIntoSearchTree(const elementT& value, BinaryTreeNode*& pNode)
{
    if (pNode == nullptr)
    {
        pNode = new BinaryTreeNode();
        if (pNode == nullptr)
        {
            DEBUG_PRINT("memory allocation failed");
            return nullptr;
        }
        else
        {
            pNode->mValue = value;
            pNode->mLeft = nullptr;
            pNode->mRight = nullptr;
        }
    }

    if (value > pNode->mValue)
        insertOneElementIntoSearchTree(value, pNode->mRight);
    else if (value < pNode->mValue)
        insertOneElementIntoSearchTree(value, pNode->mLeft);

    return pNode;
}


BinaryTree::~BinaryTree()
{
    releaseRecursively(this->mPRoot);
    //releaseLayerOrder(this->mPRoot);//recommended
}


// release the node memory recursively
void BinaryTree::releaseRecursively(BinaryTreeNode*& pNode)
{
    if (pNode == nullptr)
        return;

    if (pNode->mLeft != nullptr)
        releaseRecursively(pNode->mLeft);

    if (pNode->mRight != nullptr)
        releaseRecursively(pNode->mRight);

    pNode->deleteReference();
}


// release the node memory from top to bottom
void BinaryTree::releaseLayerOrder(BinaryTreeNode*& pNode)
{
    if (pNode == nullptr)
        return;

    pNode->deleteReference();
}


// shallow copy, share the same node data memory with father tree
BinaryTree::BinaryTree(const BinaryTree& bTree)
{
    this->mPRoot = bTree.mPRoot;
    this->mPRoot->addReference();
    this->mType = bTree.mType;
}


BinaryTree& BinaryTree::operator=(const BinaryTree& biTree)
{
    if (this == &biTree)
        return *this;

    this->mPRoot = biTree.mPRoot;
    this->mPRoot->addReference();
    this->mType = biTree.mType;

    return *this;
}


BinaryTree BinaryTree::getSubLeftTree()
{
    BinaryTree subLeftTree(this->mType);

    subLeftTree.mPRoot = this->mPRoot->mLeft;
    subLeftTree.mPRoot->addReference();

    return subLeftTree;
}


BinaryTree BinaryTree::getSubRightTree()
{
    BinaryTree subRightTree(this->mType);

    subRightTree.mPRoot = this->mPRoot->mRight;
    subRightTree.mPRoot->addReference();

    return subRightTree;
}


// mirror itself
void BinaryTree::mirror()
{
    if (this->mPRoot == nullptr || (this->mPRoot->mLeft == nullptr && this->mPRoot->mRight == nullptr))
        return;

    mirrorRecursively(this->mPRoot);
}


// mirror itself recursively
void BinaryTree::mirrorRecursively(BinaryTreeNode *pNode)
{
    if (pNode == nullptr || (pNode->mRight == nullptr && pNode->mLeft == nullptr))
        return;

    BinaryTreeNode* pTmpNode = pNode->mLeft;
    pNode->mLeft = pNode->mRight;
    pNode->mRight = pTmpNode;

    mirrorRecursively(pNode->mLeft);
    mirrorRecursively(pNode->mRight);
}


// print the tree through different iteration method
void BinaryTree::printTree(BINARY_TREE_ITERATION_METHOD type) const
{
    if (this->mPRoot == nullptr)
        return;

    switch (type) {
    case PRE_ORDER_RECUR:
        printTreePreRecur(this->mPRoot);
        break;
    case PRE_ORDER_ITER:
        printTreePreIter(this->mPRoot);
        break;
    case MID_ORDER_RECUR:
        printTreeMidRecur(this->mPRoot);
        break;
    case MID_ORDER_ITER:
        printTreeMidIter(this->mPRoot);
        break;
    case POST_ORDER_RECUR:
        printTreePostRecur(this->mPRoot);
        break;
    case POST_ORDER_ITER:
        printTreePostIter(this->mPRoot);
        break;
    case LAYER_ORDER_RECUR:
        printTreeLayerRecur(this->mPRoot);
        break;
    case LAYER_ORDER_ITER:
        printTreeLayerIter(this->mPRoot);
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


// print tree preorder iteratively
void BinaryTree::printTreePreIter(BinaryTreeNode* pRoot) const
{
    if (pRoot == nullptr)
        return;

    stack<BinaryTreeNode*> nodeStack;
    nodeStack.push(pRoot);

    while(!nodeStack.empty())
    {
        BinaryTreeNode* tmpNode = nodeStack.top();
        nodeStack.pop();
        cout << tmpNode->mValue << "\t";

        if (tmpNode->mRight)
            nodeStack.push(tmpNode->mRight);

        if (tmpNode->mLeft)
            nodeStack.push(tmpNode->mLeft);
    }
}


// print tree preorder iteratively
void BinaryTree::printTreePreIter2(BinaryTreeNode* pRoot) const
{
    if (pRoot == nullptr)
        return;

    stack<BinaryTreeNode*> nodeStack;
    BinaryTreeNode* pTmpNode = pRoot;

    while(pTmpNode != nullptr || !nodeStack.empty())
    {
        if (pTmpNode != nullptr)
        {
            cout << pTmpNode->mValue << "\t";

            nodeStack.push(pTmpNode);

            pTmpNode = pTmpNode->mLeft;
        }
        else
        {
            pTmpNode = nodeStack.top();
            nodeStack.pop();

            pTmpNode = pTmpNode->mRight;
        }
    }
}


// print tree midorder recursively
void BinaryTree::printTreeMidRecur(BinaryTreeNode* pNode) const
{
    if (pNode == nullptr)
        return;

    printTreeMidRecur(pNode->mLeft);
    cout << pNode->mValue << "\t";
    printTreeMidRecur(pNode->mRight);
}


// print tree midorder iteratively
void BinaryTree::printTreeMidIter(BinaryTreeNode* pRoot) const
{
    if (pRoot == nullptr)
        return;

    stack<BinaryTreeNode*> nodeStack;
    BinaryTreeNode* pTmpNode = pRoot;

    while (pTmpNode != nullptr || !nodeStack.empty())
    {
        if (pTmpNode != nullptr)
        {
            nodeStack.push(pTmpNode);

            pTmpNode = pTmpNode->mLeft;
        }
        else
        {
            pTmpNode = nodeStack.top();
            nodeStack.pop();

            cout << pTmpNode->mValue << "\t";

            pTmpNode = pTmpNode->mRight;
        }
    }
}


// print tree postorder recursively
void BinaryTree::printTreePostRecur(BinaryTreeNode* pNode) const
{
    if (pNode == nullptr)
        return;

    printTreePostRecur(pNode->mLeft);
    printTreePostRecur(pNode->mRight);

    cout << pNode->mValue << "\t";
}


// print tree postorder iteratively -- this implemention is ugly!!!
void BinaryTree::printTreePostIter(BinaryTreeNode* pRoot) const
{
    stack<BinaryTreeNode*> nodeStack;
    BinaryTreeNode* pTmpNode = pRoot;

    while (pTmpNode != nullptr || !nodeStack.empty())
    {
        if (pTmpNode != nullptr)
        {
            nodeStack.push(pTmpNode);
            nodeStack.push(pTmpNode->mRight);

            pTmpNode = pTmpNode->mLeft;
        }
        else
        {
            pTmpNode = nodeStack.top();
            nodeStack.pop();

            if (pTmpNode == nullptr)
            {
                pTmpNode = nodeStack.top();
                nodeStack.pop();

                if (pTmpNode != nullptr)
                {
                    cout << pTmpNode->mValue << "\t";
                }

                if (nodeStack.empty())
                    return;

                pTmpNode = nodeStack.top();
                nodeStack.pop();
            }

            nodeStack.push(nullptr);
        }
    }
}


// print tree layerorder recursively -- not completed yet!
void BinaryTree::printTreeLayerRecur(BinaryTreeNode* pNode) const
{

}


// print tree preorder iteratively
void BinaryTree::printTreeLayerIter(BinaryTreeNode* pRoot) const
{
    if (pRoot == nullptr)
        return;

    queue<BinaryTreeNode*> nodeQueue;
    nodeQueue.push(pRoot);

    while (!nodeQueue.empty())
    {
        BinaryTreeNode* pTmpNode = nodeQueue.front();
        nodeQueue.pop();
        cout << pTmpNode->mValue << "\t";

        if (pTmpNode->mLeft)
            nodeQueue.push(pTmpNode->mLeft);

        if (pTmpNode->mRight)
            nodeQueue.push(pTmpNode->mRight);
    }
}



//int main(int argc, char* argv[])
//{
//    elementT value[] = {5, 3, 4, 10, 6, 9, 1, 7, 8};
//    BinaryTree tree(SEARCH_TREE);
//    for (int i = 0; i < (sizeof(value) / sizeof(elementT)); ++i)
//        tree.insertOneElement(value[i]);

//    BinaryTree tree2;
//    tree2 = tree;

//    tree.printTree(MID_ORDER_RECUR);

//    cout << endl;

//    tree2.getSubRightTree().printTree(PRE_ORDER_RECUR);

//    cout << endl;

//    return 0;
//}












































