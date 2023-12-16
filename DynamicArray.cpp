#include "DynamicArray.h"
#include <algorithm>

template <typename T>
DynamicArray<T>::DynamicArray(size_t initialCapacity) : size(0), capacity(initialCapacity) {
    data = new T[capacity];
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] data;
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& other) : size(other.size), capacity(other.capacity) {
    data = new T[capacity];
    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        capacity = other.capacity;
        data = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}
template <typename T>
size_t DynamicArray<T>::getCapacity()
{
    return capacity;
}
template <typename T>
void DynamicArray<T>::resize(size_t newSize) {
    if (newSize <= 0) {
        throw std::invalid_argument("Invalid new size");
    }

    T* newData = new T[newSize];
    for (size_t i = 0; i < std::min(size, newSize); ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    size = newSize;
}
template <typename T>
void DynamicArray<T>::expand() {
    capacity*=2;
      
    // if (newSize <= 0) {
    //     throw std::invalid_argument("Invalid new size");
    // }

    T* newData = new T[capacity];
    for (size_t i = 0; i < size; ++i) {
        newData[i] = data[i];
    }
}
template <typename T>
T& DynamicArray<T>::operator[](size_t index) {
    if (index >= capacity) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template <typename T>
size_t DynamicArray<T>::getSize() const {
    return size;
}

template <typename T>
void DynamicArray<T>::insertEnd(const T& value) {
    if (size == capacity) {
        resize(2 * capacity);
    }
    data[size++] = value;
}

template <typename T>
void DynamicArray<T>::insertFront(const T& value) {
    if (size == capacity) {
        resize(2 * capacity);
    }
    for (size_t i = size; i > 0; --i) {
        data[i] = data[i - 1];
    }
    data[0] = value;
    size++;
}

template <typename T>
void DynamicArray<T>::removeEnd() {
    if (size > 0) {
        size--;
    }
}

template <typename T>
void DynamicArray<T>::removeFront() {
    if (size > 0) {
        for (size_t i = 0; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
    }
}

template class DynamicArray<int>;
template class DynamicArray<float>;
template class DynamicArray<double>;
template class DynamicArray<char>;
template class DynamicArray<string>;
