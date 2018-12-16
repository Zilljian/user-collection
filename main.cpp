#include <iostream>
#include <vector>
#include "Vector.h"
#include "VecIterator.h"
#include "Stack.h"
#include "DepthIterator.h"
#include "Tree.h"

int main() {
    Vector one = Vector();
    one.add(2);
    one.add(5);
    one.add(3);
    std::cout << "Vector:" << std::endl;
    std::cout << "Size: " << one.size() << std::endl;
    Iterator& iter = one.begin();
    Iterator& iter2 = one.end();

    for (;iter < one.end(); iter++) {
        std::cout << iter.getElement() << std::endl;
    }

    Stack two = Stack();
    two.add(3);
    two.add(5);
    two.add(6);
    two.add(8);

    std::cout << "Stack:" << std::endl;
    std::cout << "Size: " << two.size() << std::endl;

    Iterator& iter3 = two.begin();
    Iterator& iter4 = two.end();

    for (;iter3 < iter4; iter3++) {
        std::cout << iter3.getElement() << std::endl;
    }

    Tree three = Tree();

    three.add(6);
    three.add(5);
    three.add(6);
    three.add(3);
    three.add(10);
    three.add(7);
    three.add(12);

    std::cout << "Tree:" << std::endl;
    std::cout << "Size: " << three.size() << std::endl;

    Iterator& iter5 = three.depthBegin();
    Iterator& iter6 = three.depthEnd();

    for (;iter5 < iter6; iter5++) {
        std::cout << iter5.getElement() << std::endl;
    }

    Iterator& iter7 = three.begin();
    iter5 = three.end();

    for (;iter7 < iter5; iter7++) {
        std::cout << iter7.getElement() << std::endl;
    }
}