#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
  
#include <stdexcept>
#include <iostream>
using namespace std;
template <typename T>
class DynamicArray {
private:
    T* data;
    size_t size;
    size_t capacity;

public:
    DynamicArray(size_t initialCapacity);
    ~DynamicArray();
    DynamicArray(const DynamicArray<T>& other);
    DynamicArray& operator=(const DynamicArray<T>& other);
    void resize(size_t newSize);
    void expand();
    T& operator[](size_t index);
    size_t getSize() const;
    void insertEnd(const T& value);
    void insertFront(const T& value);
    void removeEnd();
    void removeFront();
    size_t getCapacity(); 
};

#endif
