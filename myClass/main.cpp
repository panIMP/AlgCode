#include "myClass/MyTree.h"
#include <iostream>
#include <myClass/MyRCString.h>
#include <string>
#include <myClass/MyString.h>
#include <myClass/MyList.h>

using namespace std;



int main(int argc, char* argv[])
{
    MySigList<int> list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);

    cout << ((list.findKthToTail(2))->mValue) << endl;

    return 0;
}
