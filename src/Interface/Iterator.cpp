#include "Iterator.h"


Iterator::Iterator() : current_element(nullptr), index(0) {}

bool operator <= (const Iterator& left, const Iterator& right) {
    return left.getIndex() <= right.getIndex();
}

bool operator < (const Iterator& left,const Iterator& right) {
    return left.getIndex() < right.getIndex();
}

int Iterator::getElement() const {
    return current_element->value;
}

long Iterator::getIndex() const {
    return index;
}

bool Iterator::operator != (const Iterator& right) {
    return right.getElement() != current_element->value ||
           right.getIndex() != index;
}

bool Iterator::hasNext() {
    return current_element->leftNode != nullptr ||
           current_element->rightNode != nullptr;
}

Iterator::~Iterator() {
    delete current_element;
}
