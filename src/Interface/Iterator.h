#ifndef COLLECTION_ITERATOR_H
#define COLLECTION_ITERATOR_H

#include "Node.h"

class Iterator {
public:
    Iterator();
    virtual int getElement() const;
    virtual bool hasNext();
    virtual Iterator& operator ++ (int) = 0;
    virtual Iterator& operator ++() = 0;
    virtual void next() = 0;
    virtual long getIndex() const;
    virtual bool operator != (const Iterator&);
    virtual ~Iterator();
protected:
    NODE* current_element;
    long index;
};

bool operator <= (const Iterator&,const Iterator&);
bool operator < (const Iterator&,const Iterator&);




#endif //COLLECTION_ITERATOR_H


