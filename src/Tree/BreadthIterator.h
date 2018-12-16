#ifndef USER_COLLECTION_BREADTHITERATOR_H
#define USER_COLLECTION_BREADTHITERATOR_H


#include "Iterator.h"
#include "Node.h"
#include <queue>

class BreadthIterator : public Iterator {
public:
    explicit BreadthIterator(NODE*,long = 0);

    BreadthIterator() = default;

    Iterator& operator++(int) override;

    Iterator& operator++() override;

    void next() override;

    bool hasNext();

protected:
    bool last = false;
    std::queue<NODE*> lineQueue;
};


#endif //USER_COLLECTION_BREADTHITERATOR_H
