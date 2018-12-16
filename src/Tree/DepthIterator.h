#ifndef USER_COLLECTION_DEPTHITERATOR_H
#define USER_COLLECTION_DEPTHITERATOR_H

#include "Iterator.h"
#include "Node.h"
#include <stack>

class DepthIterator : public Iterator {
public:
    explicit DepthIterator(NODE*,long = 0);

    DepthIterator() = default;

    Iterator &operator++(int i) override;

    Iterator &operator++() override;

    void next() override;

    bool hasNext() override;

protected:
    bool last = false;
    std::stack<NODE*> lineStack;
};


#endif //USER_COLLECTION_DEPTHITERATOR_H
