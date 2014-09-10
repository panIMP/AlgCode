#include "myClass/myTree.h"
#include <iostream>
#include <myClass/MyRCString.h>

using namespace std;



int main(int argc, char* argv[])
{

    MyRCString a("joke");
    MyRCString b = a;
    MyRCString c = a;
    MyRCString d = MyRCString(a);
    MyRCString* e = new MyRCString();

    cout << a[0] << endl;
    cout << b[1] << endl;

    cout << c[2] << d[3] << endl;


//    MyBiSearchTree<long long> tree;
//    tree.insert(1);
//    tree.insert(4);
//    tree.insert(5);

//    tree.insert(7);
//    tree.insert(2);
//    tree.insert(6);

//    tree.printTreeInList(MyBiSearchTree<long long>::LAYER_ORDER);

    return 0;
}
