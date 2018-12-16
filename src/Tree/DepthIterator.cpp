#include "DepthIterator.h"


DepthIterator::DepthIterator(NODE* instance, long index) : lineStack(){
    current_element = instance;
    this->index = index;
    if (instance->leftNode != nullptr) {
        lineStack.push(instance);
        while (1) {
            if (current_element->leftNode != nullptr) {
                lineStack.push(current_element->leftNode);
                current_element = current_element->leftNode;
            } else {
                lineStack.pop();
                if (current_element->rightNode != nullptr) lineStack.push(current_element->rightNode);
                break;
            }
        }
    }
}

Iterator& DepthIterator::operator++(int i) {
    DepthIterator &temp = *this;
    ++*this;
    return temp;
}

Iterator& DepthIterator::operator++() {
    if (hasNext()) {
        if (current_element->rightNode == nullptr) {
            NODE* temp = current_element;
            current_element = lineStack.top();
            lineStack.pop();
            while (1) {
                lineStack.push(current_element);
                if (current_element->leftNode != nullptr && temp->value != current_element->leftNode->value) {
                    lineStack.push(current_element->leftNode);
                    current_element = current_element->leftNode;
                } else {
                    lineStack.pop();
                    break;
                }
            }
        } else {
            current_element = current_element->rightNode;
            if (current_element->leftNode != nullptr) {
                lineStack.push(current_element);
                while (1) {
                    if (current_element->leftNode != nullptr) {
                        lineStack.push(current_element->leftNode);
                        current_element = current_element->leftNode;
                    } else {
                        lineStack.pop();
                        if (current_element->rightNode != nullptr) lineStack.push(current_element->rightNode);
                        break;
                    }
                }
            }
        }
        index++;
    } else if (!last) {
        last = true;
        index++;
    }
    return *this;
}

void DepthIterator::next() {
    if (hasNext()) {
        current_element = lineStack.top();
        lineStack.pop();
        if (current_element->leftNode != nullptr) lineStack.push(current_element->leftNode);
        if (current_element->rightNode != nullptr) lineStack.push(current_element->rightNode);
        index++;
    } else if (!last) {
        last = true;
        index++;
    }
}

bool DepthIterator::hasNext() {
    return !lineStack.empty() || current_element->leftNode != nullptr || current_element->rightNode != nullptr;
}
