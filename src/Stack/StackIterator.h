#ifndef USER_COLLECTION_STACKITERATOR_H
#define USER_COLLECTION_STACKITERATOR_H


#include "Iterator.h"
#include "Collection.h"

class StackIterator : public Iterator {
public:
    explicit StackIterator(NODE*,long = 0);

    Iterator& operator++(int)  override;

    Iterator& operator++ () override;

    void next() override;

    ~StackIterator() override;

protected:
    bool last = false;
};


#endif //USER_COLLECTION_STACKITERATOR_H
