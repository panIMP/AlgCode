#ifndef MYTREE_H
#define MYTREE_H

#include <iostream>
#include "hpFun.h"
#include <queue>
#include <iostream>
#include <stack>
#include <math.h>

using namespace std;


template <typename T>
class MyBiTree
{
protected:
    class MyBiTreeNode
    {
    public:
        T mVal = 0;
        MyBiTreeNode* mPtrL = nullptr;
        MyBiTreeNode* mPtrR = nullptr;
        long long mReferCount = 0;

    public:
        MyBiTreeNode(const T& value, MyBiTreeNode* pLeft = nullptr, MyBiTreeNode* pRigth = nullptr) : mVal(value), mPtrL(pLeft), mPtrR(pRigth)
        {
            mReferCount = 1;
        }

        ~MyBiTreeNode()
        {
            if (mPtrL != nullptr)
                mPtrL->delReference();
            if (mPtrR != nullptr)
                mPtrR->delReference();
        }


        MyBiTreeNode(MyBiTreeNode& node)
        {
            mVal = node.mVal;
            mPtrL = node.mPtrL;
            mPtrR = node.mPtrR;
            mPtrL->addReference();
            mPtrR->addReference();
        }

        MyBiTreeNode& operator = (const MyBiTreeNode& rhs)
        {
            if (this == &rhs)
                return *this;

            mVal = rhs.mVal;
            mPtrL = rhs.mPtrL;
            mPtrR = rhs.mPtrR;
            addReference();
            mPtrL->addReference();
            mPtrR->addReference();
        }

        bool operator == (const MyBiTreeNode& rhs) const
        {
            if (mVal == rhs.mVal && mPtrL == rhs.mPtrL && mPtrR == rhs.mPtrR)
                return true;

            return false;
        }

        void addReference()
        {
            ++mReferCount;
        }

        void delReference()
        {
            if (--mReferCount == 0)
            {
                delete this;
            }
        }
    };

public:
    MyBiTree() = default;
    virtual ~MyBiTree()
    {
        if (mPRoot == nullptr)
            return;

        releaseLayerOrder(mPRoot); // or releaseRecursively(mPRoot);
    }

    MyBiTree(MyBiTree& tree)
    {
        mPRoot = tree.mPRoot;
        mNodeNum = tree.mNodeNum;
        mLayerNum = tree.mLayerNum;
    }

    MyBiTree& operator = (const MyBiTree& rhs)
    {
        mPRoot = rhs.mPRoot;
        mNodeNum = rhs.mNodeNum;
        mLayerNum = rhs.mLayerNum;
    }

    bool operator == (const MyBiTree& rhs) const
    {
        if (mPRoot == rhs.mPRoot && mNodeNum == rhs.mNodeNum && mLayerNum == rhs.mLayerNum)
            return true;

        return false;
    }

    // only this conducts deep-copy, all the others are shallow-copy
    bool copyTo(MyBiTree& rhs) const
    {
        if (mPRoot == nullptr)
            return;

        rhs.mNodeNum = mNodeNum;
        rhs.mLayerNum = mLayerNum;
        copyRecursively(mPRoot, rhs.mPRoot);
    }

    virtual bool insert(const T& value) = 0;
    virtual void insertArray(T valueArray[]) = 0;

    // transform it into a mirrored tree
    void mirror()
    {
        if (mPRoot == nullptr || (mPRoot->mPtrL == nullptr && mPRoot->mPtrR == nullptr))
            return;

        mirrorRecursively(mPRoot);
    }

    virtual MyBiTree<T>* getSubLTree() const = 0;
    virtual MyBiTree<T>* getSubRTree() const = 0;

    void getNodeNum() const
    {
        return mNodeNum;
    }

    void getLayerNum() const
    {
        return mLayerNum;
    }

    enum PRINT_TREE_METHOD
    {
        PRE_ORDER = 0x01,
        MID_ORDER,
        POST_ORDER,
        LAYER_ORDER,

        // using recursive function or loop respectively
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

    void printTreeInList(PRINT_TREE_METHOD method) const
    {
        if (mPRoot == nullptr)
             return;

         switch (method) {
         case PRE_ORDER_RECUR:
             printTreePreRecur(mPRoot);
             break;
         case PRE_ORDER_ITER:
             printTreePreIter(mPRoot);
             break;
         case MID_ORDER_RECUR:
             printTreeMidRecur(mPRoot);
             break;
         case MID_ORDER_ITER:
             printTreeMidIter(mPRoot);
             break;
         case POST_ORDER_RECUR:
             printTreePostRecur(mPRoot);
             break;
         case POST_ORDER_ITER:
             printTreePostIter(mPRoot);
             break;
         case LAYER_ORDER_ITER:
             printTreeLayerIter(mPRoot);
             break;
         default:
             break;
         }
    }

//    template <typename X>
//    friend std::ostream& operator << (std::ostream& os, const MyBiTree<X>& rhs);

protected:
    MyBiTreeNode* mPRoot = nullptr;
    long long mNodeNum = 0;
    long long mLayerNum = 0;

    // calculate the node num based on a tree root node
    long long calcNodeNum(MyBiTreeNode* const pRoot) const
    {
        if (pRoot == nullptr)
            return 0;

        int nodeNum = 0;
        stack<MyBiTreeNode*> nodeStack;
        nodeStack.push(pRoot);

        while (!nodeStack.empty())
        {
            MyBiTreeNode* pNode = nodeStack.top();
            nodeStack.pop();

            if (pNode != nullptr)
            {
                nodeNum++;
                nodeStack.push(pNode->mPtrR);
                nodeStack.push(pNode->mPtrL);
            }
        }

        return nodeNum;
    }

private:
    // release the node memory from top to bottom
    void releaseLayerOrder(MyBiTreeNode*& pRoot)
    {
        if (pRoot == nullptr)
            return;

        pRoot->delReference();// trigger the sequently delReference of the its subtree or nodes
    }

    // release the node memory recursively
    void releaseRecursively(MyBiTreeNode*& pNode)
    {
        if (pNode == nullptr)
            return;

        releaseRecursively(pNode->mPtrL);
        releaseRecursively(pNode->mPtrR);

        pNode->delReference();// locate the leaf node and del its reference
    }

    // mirror the sub tree recursively
    void mirrorRecursively(MyBiTreeNode*& pNode)
    {
        if (pNode == nullptr || (pNode->mPtrL == nullptr && pNode->mPtrR == nullptr))
            return;

        MyBiTreeNode* tmp = pNode->mPtrL;
        pNode->setPtrLeft(pNode->mPtrR);
        pNode->setPtrRight(tmp);

        mirrorRecursively(pNode->mPtrL);
        mirrorRecursively(pNode->mPtrR);
    }

    // copy the node recursively
    bool copyRecursively(MyBiTreeNode*& pNodeSrc, MyBiTreeNode*& pNodeDst)
    {
        if (pNodeSrc == nullptr)
            return false;

        pNodeDst = new MyBiTreeNode;
        if (pNodeDst == nullptr)
        {
            DEBUG_PRINT("Memory allocation failed!");
            return false;
        }

        copyRecursively(pNodeSrc->mPtrL, pNodeDst->mPtrL);
        copyRecursively(pNodeSrc->mPtrR, pNodeDst->mPtrR);

        pNodeDst->setValue(pNodeSrc->mVal);

        return true;
    }

    // print tree preorder recursively
    void printTreePreRecur(MyBiTreeNode* pNode) const
    {
        if (pNode == nullptr)
            return;

        cout << pNode->mVal << "\t";

        printTreePreRecur(pNode->mPtrL);
        printTreePreRecur(pNode->mPtrR);
    }

    // print tree preorder iteratively
    void printTreePreIter(MyBiTreeNode* pRoot) const
    {
        if (pRoot == nullptr)
            return;

        stack<MyBiTreeNode*> nodeStack;
        nodeStack.push(pRoot);

        while (!nodeStack.empty())
        {
            MyBiTreeNode* pNode = nodeStack.top();
            nodeStack.pop();

            if (pNode != nullptr)
            {
                cout << pNode->mVal << "\t";
                nodeStack.push(pNode->mPtrR);
                nodeStack.push(pNode->mPtrL);
            }
        }
    }

    // print tree midorder recursively
    void printTreeMidRecur(MyBiTreeNode* pNode) const
    {
        if (pNode == nullptr)
            return;

        printTreeMidRecur(pNode->mPtrL);

        cout << pNode->mVal << "\t";

        printTreeMidRecur(pNode->mPtrR);
    }

    // print tree midorder iteratively
    void printTreeMidIter(MyBiTreeNode* pRoot) const
    {
        if (pRoot == nullptr)
            return;

        stack<MyBiTreeNode*> nodeStack;
        MyBiTreeNode* pNode = pRoot;

        while (!nodeStack.empty() || pNode != nullptr)
        {
            if (pNode != nullptr)
            {
                nodeStack.push(pNode);
                pNode = pNode->mPtrL;
            }
            else
            {
                pNode = nodeStack.top();
                nodeStack.pop();

                cout << pNode->mVal << "\t";

                pNode = pNode->mPtrR;
             }
        }
    }

    // print tree postorder recursively
    void printTreePostRecur(MyBiTreeNode* pNode) const
    {
        if (pNode == nullptr)
            return;

        printTreePostRecur(pNode->mPtrL);
        printTreePostRecur(pNode->mPtrR);

        cout << pNode->mVal << "\t";
    }

    // print tree postorder iteratively
    void printTreePostIter(MyBiTreeNode* pRoot) const
    {
        if (pRoot == nullptr)
            return;

        stack<MyBiTreeNode*> nodeStack;
        MyBiTreeNode* pNode = pRoot;

        while (!nodeStack.empty() || pNode != nullptr)
        {
            if (pNode != nullptr)
            {
                nodeStack.push(pNode);
                pNode = pNode->mPtrL;
            }
            else
            {
                pNode = nodeStack.top();

                if (pNode != nullptr)
                {
                    if (pNode->mPtrR == nullptr)
                    {
                        nodeStack.pop();
                        cout << pNode->mVal << "\t";
                        pNode = nullptr;
                    }
                    else
                    {
                        pNode = pNode->mPtrR;
                    }
                }
            }
        }
    }

    // print tree preorder iteratively
    void printTreeLayerIter(MyBiTreeNode* pRoot) const
    {
        if (pRoot == nullptr)
            return;

        queue<MyBiTreeNode*> nodeQueue;
        nodeQueue.push(pRoot);

        while (!nodeQueue.empty())
        {
            MyBiTreeNode* pNode = nodeQueue.front();
            nodeQueue.pop();

            if (pNode != nullptr)
            {
                cout << pNode->mVal << "\t";
                nodeQueue.push(pNode->mPtrL);
                nodeQueue.push(pNode->mPtrR);
            }
        }
    }
};


template <typename T>
class MyBiSearchTree : public MyBiTree<T>
{
public:
    ~MyBiSearchTree()
    {

    }

    MyBiSearchTree<T>* getSubLTree() const
    {
        MyBiSearchTree<T>* retTree = new MyBiSearchTree;
        retTree->mPRoot = this->mPRoot->mPtrL;
        retTree->mLayerNum = this->mLayerNum - 1;
        retTree->mNodeNum = this->calcNodeNum(this->mPRoot);

        return retTree;
    }

    MyBiSearchTree<T>* getSubRTree() const
    {
        MyBiSearchTree<T>* retTree = new MyBiSearchTree;
        retTree->mPRoot = this->mPRoot->mPtrR;
        retTree->mLayerNum = this->mLayerNum - 1;
        retTree->mNodeNum = this->calcNodeNum(this->mPRoot->mPtrR);

        return retTree;
    }

    bool insert(const T& value) override
    {
        return insertRecursively(value, this->mPRoot);
    }

    bool insertRecursively(const T& value, typename MyBiTree<T>::MyBiTreeNode* pNode)
    {
        if(pNode == nullptr)
        {
            pNode = new typename MyBiTree<T>::MyBiTreeNode(value);
            if (pNode == nullptr)
            {
                DEBUG_PRINT("Memory allocation failed!");
                return false;
            }
            pNode->mVal = value;

            return true;
        }
        else
        {
            if (value < pNode->mVal)
                return this->getSubLTree()->insert(value);
            else if (value > pNode->mVal)
                return this->getSubRTree()->insert(value);
            else
            {
                DEBUG_PRINT("Same elemet is already in the tree!");
                return false;
            }
        }

        return true;
    }


    void insertArray(T valueArray[]) override
    {

    }

private:
};


#endif // MYTREE_H
