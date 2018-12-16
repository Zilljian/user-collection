#include "Stack.h"
#include "StackIterator.h"

Stack::Stack() : tail(nullptr){}

void Stack::add(int newElement) {
    if (head == nullptr) {
        head = std::make_unique<NODE>(newElement);
        tail.reset(head.get());
    } else {
        std::unique_ptr<NODE> temp = std::make_unique<NODE>(newElement);
        temp->rightNode = tail.release();
        tail.swap(temp);
    }
    _size++;
}

void Stack::deleteElement(const Iterator& item) {
    if (item.getElement() == tail->value) {
        tail.reset(tail->rightNode);
        _size--;
    }
}

void Stack::deleteAll() {
    tail.reset(nullptr);
}

Iterator& Stack::begin() {
    if (_size != 0) {
        return *(new StackIterator(tail.get()));
    }
}

Iterator& Stack::end() {
    if (_size != 0) {
        return *(new StackIterator(head.get(), _size));
    }
}

Iterator& Stack::find(int element) {
    NODE* temp = tail->rightNode;
    for (int i = 0; i < _size; i++) {
        if (temp->value == element) {
            return *(new StackIterator(temp));
        }
        temp = temp->rightNode;
    }
    return *(new StackIterator(tail.get()));
}
