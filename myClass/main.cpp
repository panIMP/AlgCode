#include "myClass/myTree.h"


int main(int argc, char* argv[])
{

    MyBiSearchTree<long long> tree;
    tree.insert(1);
    tree.insert(4);
    tree.insert(5);

    tree.insert(7);
    tree.insert(2);
    tree.insert(6);

    tree.printTreeInList(MyBiSearchTree<long long>::LAYER_ORDER);

    return 0;
}
