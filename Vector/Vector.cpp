#include "Vector.h"

Vector::Vector() : data(), _size(0){
    data = std::make_unique<int[]>(0);
}

void Vector::add(int newElement) {
    std::unique_ptr<int[]> temp = std::make_unique<int[]>(_size);
    temp = std::move(data);
    data.swap(temp);
    data[_size - 1] = newElement;
    _size ++;
}

void Vector::deleteElement(Iterator item) {

}

void Vector::deleteAll() {
    data = nullptr;
    _size = 0;
}

Iterator Vector::begin() {
    if (_size) return Iterator();
}

Iterator Vector::end() {
    return Iterator();
}

Iterator Vector::find(int i) {
    return Iterator();
}

long Vector::size() {
    return 0;
}

bool Vector::hasNext() {
    return false;
}
