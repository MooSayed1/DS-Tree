#ifndef USERHASHTABLE_H
#define USERHASHTABLE_H

<<<<<<< HEAD:UserHashTable.h
#include <cstddef>
#include <iostream>
#include <string>
// #include "AVLTree.h"
#include "TemplateAvlTree.h"
#include "DynamicArray.h"
#include "LinkedList.h"
=======
#include "AVLTree.h"
>>>>>>> refs/remotes/origin/main:hashTable.h
#include "User.h"
#pragma once

<<<<<<< HEAD:UserHashTable.h
template <typename KeyType, typename ValueType>
class UserHashTable {
private:
    // Define the structure for a node in the hash table
    //     KeyType key;  // string if we use handel name or int if you want
    //     ValueType value;  // This Will be structer which we will use 
    // size_t size;
    // Node** table;

    DynamicArray<AVLTree<User>>table;
    // Private member functions
    // Node* createNode(KeyType key, ValueType value);
    // size_t hash(KeyType key);

public:
    // Constructor
    UserHashTable(size_t size);

    // Destructor
    ~UserHashTable();

    // Member functions
    int hash_string(string str, int n) {
        long long nn = n;
        long long sum = 0;
        for (int i = 0; i < (int) str.size(); ++i)
            sum = (sum * 26 + str[i] - 'a') % nn;
        return sum % nn;
    }
    void insert(KeyType key, ValueType value);
    bool get(KeyType key, ValueType& value);
    void removeEntry(KeyType key);
};

// Implementation of member functions
// template <typename KeyType, typename ValueType>
// UserHashTable<KeyType, ValueType>::HashTable(size_t size) : size(size) {
//     table = new Node*[size]();
// }
//
// template <typename KeyType, typename ValueType>
// UserHashTable<KeyType, ValueType>::~HashTable() {
//     for (size_t i = 0; i < size; ++i) {
//         Node* current = table[i];
//         while (current != nullptr) {
//             Node* next = current->next;
//             delete current;
//             current = next;
//         }
//     }
//     delete[] table;
// }
//
// template <typename KeyType, typename ValueType>
// typename UserHashTable<KeyType, ValueType>::Node*
// UserHashTable<KeyType, ValueType>::createNode(KeyType key, ValueType value) {
//     Node* newNode = new Node;
//     newNode->key = key;
//     newNode->value = value;
//     newNode->next = nullptr;
//     return newNode;
// }
// template <typename KeyType, typename ValueType>
// size_t UserHashTable<KeyType, ValueType>::hash(KeyType key) {
//     return std::hash<KeyType>{}(key) % size;
// }

// template <typename KeyType, typename ValueType>
// void UserHashTable<KeyType, ValueType>::insert(KeyType key, ValueType value) {
//     size_t index = hash(key);
//     Node* newNode = createNode(key, value);
//     if (newNode == nullptr) {
//         std::cerr << "Failed to insert key-value pair. Memory allocation error." << std::endl;
//         exit(EXIT_FAILURE);
//     }
//
//     newNode->next = table[index];
//     table[index] = newNode;
// }

// template <typename KeyType, typename ValueType>
// bool UserHashTable<KeyType, ValueType>::get(KeyType key, ValueType& value) {
//     size_t index = hash(key);
//     Node* current = table[index];
//
//     while (current != nullptr) {
//         if (current->key == key) {
//             value = current->value;
//             return true;  // Success
//         }
//         current = current->next;
//     }
//
//     return false;  // Key not found
// }

// template <typename KeyType, typename ValueType>
// void UserHashTable<KeyType, ValueType>::removeEntry(KeyType key) {
//     size_t index = hash(key);
//     Node* current = table[index];
//     Node* prev = nullptr;
//
//     while (current != nullptr) {
//         if (current->key == key) {
//             if (prev == nullptr) {
//                 // Remove the first node
//                 table[index] = current->next;
//             } else {
//                 prev->next = current->next;
//             }
//             delete current;
//             return;
//         }
//         prev = current;
//         current = current->next;
//     }
// }

#endif  // UserHashTable_H
=======
class HashTable {
public:
  HashTable();    // default constructor
  HashTable(int); // one parameter constructor
  ~HashTable();   // destructor
  bool insert(const User &);
  bool remove(const User &);
  User *search(const User &) const;
  int size() const;    // return numOfItems
  int maxSize() const; // return arrSize

private:
  AVLTree *arr;
  int arrSize;
  int numOfItems;
  int hashFunc(const string &) const;
  int getPrime(int) const;
  bool isPrime(int) const;
};

#endif // HASHTABLE_H
>>>>>>> refs/remotes/origin/main:hashTable.h
