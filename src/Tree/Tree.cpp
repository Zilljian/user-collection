#include "Tree.h"

Tree::Tree() : head(nullptr), tail(nullptr), depth(), breadth(), tempQueue(), deleteStack() {}

void Tree::add(int newElement) {
    if (head == nullptr) {
        head = new NODE(newElement);
        deleteStack.push(head);
        tail = head;
    } else {
        if (newElement >= head->value) {
            if (head->rightNode != nullptr) {
                _insertNew(head->rightNode, newElement);
            } else {
                head->rightNode = new NODE(newElement);
                deleteStack.push(head->rightNode);
            }
        } else {
            if (head->leftNode != nullptr) {
                _insertNew(head->leftNode, newElement);
            } else {
                head->leftNode = new NODE(newElement);
                deleteStack.push(head->leftNode);
            }
        }
    }
    _size++;
}

void Tree::_insertNew(NODE* node, int newElement) {
    if (newElement > node->value) {
        if (node->rightNode != nullptr) {
            _insertNew(node->rightNode, newElement);
        } else {
            node->rightNode = new NODE(newElement);
            tail = node->rightNode;
        }
    } else {
        if (node->leftNode != nullptr) {
            _insertNew(node->leftNode, newElement);
        } else {
            node->leftNode = new NODE(newElement);
            tail = node->leftNode;
        }
    }
};

void Tree::deleteElement(const Iterator& item) {
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

void Tree::deleteAll() {
    for (int i = 0; i < _size; i++) {
        NODE* temp = head->rightNode;
        delete head;
        head = temp;
    }
}

Iterator& Tree::begin() {
    if (_size != 0) {
        return *(new BreadthIterator(head));
    }
}

DepthIterator& Tree::depthBegin() {
    if (_size != 0) {
        return *(new DepthIterator(head));
    }
}

Iterator& Tree::end() {
    if (_size != 0) {
        NODE* temp = head;
        while(1) {
            if (temp->rightNode == nullptr) {
                break;
            }
            temp = temp->rightNode;
        }
        return *(new BreadthIterator(temp, _size));
    }
}

DepthIterator& Tree::depthEnd() {
    if (_size != 0) {
        NODE* temp = head;
        while(1) {
            if (temp->rightNode == nullptr) {
                break;
            }
            temp = temp->rightNode;
        }
        return *(new DepthIterator(temp, _size));
    }
}

Iterator& Tree::find(int i) {
    tempQueue.push(head);
    long count = 0;

    while (!tempQueue.empty()) {
        NODE* temp = tempQueue.front();
        tempQueue.pop();
        if(temp->value == i) return *(new BreadthIterator(temp, count));
        if (temp->leftNode != nullptr) tempQueue.push(temp->leftNode);
        if (temp->rightNode != nullptr) tempQueue.push(temp->rightNode);
        count++;
    } return *(new BreadthIterator(head));
}

Tree::~Tree() {
    while (!deleteStack.empty()) {
        delete deleteStack.top();
        deleteStack.pop();
    }
}
