#ifndef COLLECTION_VECTOR_H
#define COLLECTION_VECTOR_H

#include "Collection.h"
#include "VecIterator.h"
#include <stdexcept>


class Vector : public Collection{
public:
    Vector();

    void add(int) override;

    void deleteElement(const Iterator&) override;

    void deleteAll() override;

    Iterator& begin() override;

    Iterator& end() override;

    Iterator& find(int) override;

private:
    NODE* head;
    NODE* tail;
    //unsigned long _size;
};


#endif //COLLECTION_VECTOR_H


