#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "AVLTree.h"
#include "User.h"
#include <iostream>
#include <string>
// #pragma once

class HashTable {
public:
  HashTable();    // default constructor
  HashTable(int); // one parameter constructor
  ~HashTable();   // destructor
  bool insert(const User &);
  bool remove(const User &);
  User *search(const User &) const;
  User *search(const string &) const;
  int size() const;          // return numOfItems
  int maxSize() const;       // return arrSize
  double loadFactor() const; // returns the load factor of the hash table
  void displayUsers();

private:
  AVLTree *arr;
  int arrSize;
  int numOfItems;
  int hashFunc(const string &) const;
  int getPrime(int) const;
  bool isPrime(int) const;
};

#endif // HASHTABLE_H
