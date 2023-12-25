#include "hashTable.h"

HashTable::HashTable() // default constructor
{
  arrSize = 101;
  arr = new AVLTree[arrSize];
  numOfItems = 0;
}

HashTable::HashTable(int n)
// creates a hash table to store n items where the size of the array
// is the smallest prime number >= 2*n
{
  arrSize = getPrime(n);
  arr = new AVLTree[arrSize];
  numOfItems = 0;
}
HashTable::~HashTable() // destructor
{
  delete[] arr;
}

int HashTable::hashFunc(const string &s) const
// hash function (utilizes horner's method to prevent
// overflow on large strings)
{
  int hashVal = 0, asc;
  for (int i = 0; i < s.size(); i++) {
    asc = s[i] > 96 ? s[i] - 96 : s[i] - 64;
    hashVal = (hashVal * 32 + asc) % arrSize;
  }
  return hashVal;
}

int HashTable::getPrime(int n) const // return the smallest prime number >= 2*n
{
  int i = 2 * n;
  while (!isPrime(i))
    i++;
  return i;
}

bool HashTable::isPrime(int n) const
// check whether n is prime, helper function for getPrime()
{
  bool isPrime = true;
  for (int count = 2; count < n && isPrime; count++)
    if (n % count == 0)
      isPrime = false;
  return isPrime;
}

bool HashTable::insert(const User &s)
// inserts string s if it doesn't exist in the hash table and
// returns 1 if insertion successful, 0 otherwise
{
  int hash = hashFunc(s.getHandel());
  bool successOrFail = arr[hash].insert(arr[hash].GetRoot(), s);
  numOfItems++;
  return successOrFail;
}

bool HashTable::remove(const User &s)
// removes string s if s exist in the hash table and returns
// 1 if removal successful, 0 otherwise
{
  int hash = hashFunc(s.getHandel());
  bool successOrFail = arr[hash].remove(arr[hash].GetRoot(), s);
  numOfItems--;
  return successOrFail;
}

User* HashTable::search(const User &s) const
// returns user if s exist in the hash table, null otherwise
{
  int hash = hashFunc(s.getHandel());
  arr[hash].search(arr[hash].GetRoot(), s);
  return &(arr[hash].search(arr[hash].GetRoot(), s)->data);
}

User *HashTable::search(const string&s) const
// returns user if s exist in the hash table, null otherwise
{
  int hash = hashFunc(s);
  arr[hash].search(arr[hash].GetRoot(), s);
  return &(arr[hash].search(arr[hash].GetRoot(), s)->data);
}

int HashTable::size() const // returns numOfItems
{
  return numOfItems;
}

int HashTable::maxSize() const // returns arrSize
{
  return arrSize;
}
