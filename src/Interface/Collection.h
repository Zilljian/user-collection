#ifndef COLLECTION_COLLECTION_H
#define COLLECTION_COLLECTION_H


#include "Iterator.h"
#include "Node.h"

class Collection {
public:
    Collection();
    virtual void add(int) = 0;
    virtual void deleteElement(const Iterator&) = 0;
    virtual void deleteAll() = 0;
    virtual Iterator& begin() = 0;
    virtual Iterator& end() = 0;
    virtual Iterator& find(int) = 0;
    virtual long size();

protected:
    long _size;
};


#endif //COLLECTION_COLLECTION_H
