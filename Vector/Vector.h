#ifndef COLLECTION_VECTOR_H
#define COLLECTION_VECTOR_H

#include "../Interface/Collection.h"


class Vector : Collection{
public:
    Vector();

    void add(int i) override;

    void deleteElement(Iterator) override;

    void deleteAll() override;

    Iterator begin() override;

    Iterator end() override;

    Iterator find(int) override;

    long size() override;

    bool hasNext() override;

private:
    std::unique_ptr<int[]> data;
    unsigned long _size;
};


#endif //COLLECTION_VECTOR_H
