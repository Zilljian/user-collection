#ifndef COLLECTION_ITERATOR_H
#define COLLECTION_ITERATOR_H


class Iterator{
public:
    virtual int getElement() = 0;
    virtual bool isNext(int) = 0;
    virtual void operator ++ () = 0;
    virtual void next() = 0;
};


#endif //COLLECTION_ITERATOR_H
