#ifndef USER_COLLECTION_STACK_H
#define USER_COLLECTION_STACK_H


#include "Collection.h"
#include <memory>

class Stack : public Collection {
public:
    Stack();

    void add(int) override;

    void deleteElement(const Iterator&) override;

    void deleteAll() override;

    Iterator &begin() override;

    Iterator &end() override;

    Iterator &find(int) override;

private:
    std::unique_ptr<NODE> tail;
    std::unique_ptr<NODE> head;
    //unsigned long _size;
};


#endif //USER_COLLECTION_STACK_H
