#include "VecIterator.h"
#include <stdexcept>

VecIterator::VecIterator(NODE* instance, long index) {
    current_element = instance;
    this->index = index;
}

Iterator& VecIterator::operator++(int i) {
    VecIterator &temp = *this;
    ++*this;
    return temp;
}

Iterator& VecIterator::operator++() {
    if (hasNext()) {
        current_element = current_element->rightNode;
        index++;
    } else if (!last) {
        last = true;
        index++;
    }
    return *this;
}

void VecIterator::next() {
    if (hasNext()) {
        current_element = current_element->rightNode;
        index++;
    } else if (!last) {
        last = true;
        index++;
    }
}

bool VecIterator::operator!=(const Iterator& right) {
    return right.getElement() != current_element->value ||
           right.getIndex() != index;
}

VecIterator::~VecIterator() {
    delete current_element;
}
