#ifndef COLLECTION_VECITERATOR_H
#define COLLECTION_VECITERATOR_H


#include "Iterator.h"
#include "Collection.h"

class VecIterator : public Iterator {
public:
    explicit VecIterator(NODE*,long = 0);

    Iterator& operator++(int) override;

    Iterator& operator++ () override;

    void next() override;

    bool operator!=(const Iterator&) override;

    ~VecIterator() override;

protected:
    bool last = false;
};


#endif //COLLECTION_VECITERATOR_H
