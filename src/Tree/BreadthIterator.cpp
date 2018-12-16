#include "BreadthIterator.h"


BreadthIterator::BreadthIterator(NODE* instance, long index) : lineQueue() {
    current_element = instance;
    this->index = index;
    if (instance->leftNode != nullptr) lineQueue.push(instance->leftNode);
    if (instance->rightNode != nullptr) lineQueue.push(instance->rightNode);
}

Iterator& BreadthIterator::operator++(int i) {
    BreadthIterator &temp = *this;
    ++*this;
    return temp;
}

Iterator& BreadthIterator::operator++() {
    if (hasNext()) {
        current_element = lineQueue.front();
        lineQueue.pop();
        if (current_element->leftNode != nullptr) lineQueue.push(current_element->leftNode);
        if (current_element->rightNode != nullptr) lineQueue.push(current_element->rightNode);
        index++;
    } else if (!last) {
        last = true;
        index++;
    }
    return *this;
}

void BreadthIterator::next() {
    if (hasNext()) {
        current_element = lineQueue.front();
        lineQueue.pop();
        if (!current_element->leftNode) lineQueue.push(current_element->leftNode);
        if (!current_element->rightNode) lineQueue.push(current_element->rightNode);
        index++;
    } else if (!last) {
        last = true;
        index++;
    }
}

bool BreadthIterator::hasNext() {
    return !lineQueue.empty();
}
