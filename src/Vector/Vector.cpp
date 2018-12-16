#include "Vector.h"

Vector::Vector() : head(nullptr), tail(nullptr){}

void Vector::add(int newElement) {
    if (head == nullptr) {
        head = new NODE(newElement);
        tail = head;
    } else {
        tail->rightNode = new NODE(newElement);
        tail = tail->rightNode;
    }
    _size++;
}

void Vector::deleteElement(const Iterator& item) {
    if (item.getElement() == head->value) {
        head = head->rightNode;
        _size--;
    } else {
        NODE *temp = head->rightNode;
        for (int i = 0; i < _size; i++) {
            if (item.getElement() == temp->rightNode->value) {
                temp = temp->rightNode->rightNode;
                _size--;
            }
            temp = temp->rightNode;
        }
    }
}

void Vector::deleteAll() {
    for (int i = 0; i < _size; i++) {
        NODE* temp = head->rightNode;
        delete head;
        head = temp;
    }
}

Iterator& Vector::begin() {
    if (_size != 0) {
        return *(new VecIterator(head));
    }
}

Iterator& Vector::end() {
    if (_size != 0) {
        return *(new VecIterator(tail, _size));
    }
}

Iterator& Vector::find(int element) {
    NODE* temp = head;
    for (int i = 0; i < _size; i++) {
        if (temp->value == element) {
            return *(new VecIterator(temp));
        }
        temp = temp->rightNode;
    }
    return *(new VecIterator(head));
}
