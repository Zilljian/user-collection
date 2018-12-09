#ifndef COLLECTION_COLLECTION_H
#define COLLECTION_COLLECTION_H

#include <array>
#include <memory>
#include "Iterator.h"


class Collection{
public:
    virtual void add(int) = 0;
    virtual void deleteElement(Iterator) = 0;
    virtual void deleteAll() = 0;
    virtual Iterator begin() = 0;
    virtual Iterator end() = 0;
    virtual Iterator find(int) = 0;
    virtual long size() = 0;
    virtual bool hasNext() = 0;
};


#endif //COLLECTION_COLLECTION_H
