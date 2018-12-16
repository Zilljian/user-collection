#include "StackIterator.h"
#include <stdexcept>


StackIterator::StackIterator(NODE* instance, long index){
    current_element = instance;
    this->index = index;
}

Iterator& StackIterator::operator++(int i) {
    StackIterator &temp = *this;
    ++*this;
    return temp;
}

Iterator& StackIterator::operator++() {
    if (hasNext()) {
        current_element = current_element->rightNode;
        index++;
    } else if (!last) {
        last = true;
        index++;
    }
    return *this;
}

void StackIterator::next() {
    if (hasNext()) {
        current_element = current_element->rightNode;
        index++;
    } else if (!last) {
        last = true;
        index++;
    }
}

StackIterator::~StackIterator() {
    delete current_element;
}

