#ifndef USER_COLLECTION_TREE_H
#define USER_COLLECTION_TREE_H


#include "Collection.h"
#include "BreadthIterator.h"
#include "DepthIterator.h"

class Tree : public Collection {
public:
    Tree();

    void add(int) override;

    void deleteElement(const Iterator&) override;

    void deleteAll() override;

    Iterator& begin() override;

    DepthIterator& depthBegin();

    Iterator& end() override;

    Iterator& find(int) override;

    DepthIterator& depthEnd();

    ~Tree();

private:
    void _insertNew(NODE*,int);
    NODE* head;
    NODE* tail;
    DepthIterator depth;
    BreadthIterator breadth;
    std::queue<NODE*> tempQueue;
    std::stack<NODE*> deleteStack;

};


#endif //USER_COLLECTION_TREE_H
