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
  bool insert(string name, string phone, string handel, int age,string pfp,string banner);
  bool remove(const string &);
  User *search(const string &) const;
  int size() const;          // return numOfItems
  int maxSize() const;       // return arrSize
  double loadFactor() const; // returns the load factor of the hash table

private:
  AVLTree *arr;
  int arrSize;
  int numOfItems;
  int hashFunc(const string &) const;
  int getPrime(int) const;
  bool isPrime(int) const;
};

#endif // HASHTABLE_H
