#ifndef COLLECTION_VECITERATOR_H
#define COLLECTION_VECITERATOR_H


#include "../Interface/Iterator.h"

class VecIterator : Iterator {
public:
    int getElement() override;

    bool isNext(int i) override;

    void operator++() override;

    void next() override;

private:
    int currentElement;
};


#endif //COLLECTION_VECITERATOR_H
