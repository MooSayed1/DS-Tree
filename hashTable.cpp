#include "hashTable.h"
#include <string>

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
  for (size_t i = 0; i < s.size(); i++) {
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

bool HashTable::insert(string name, string phone, string handel, int age,string pfp,string banner)
// inserts string s if it doesn't exist in the hash table and
// returns 1 if insertion successful, 0 otherwise
{
  int hash = hashFunc(handel);
  User key(name, phone, handel, age,pfp,banner);
  bool successOrFail = arr[hash].insert(key);
  numOfItems++;
  return successOrFail;
}

bool HashTable::remove(const string &handel)
// removes string s if s exist in the hash table and returns
// 1 if removal successful, 0 otherwise
{
  int hash = hashFunc(handel);
  bool successOrFail = arr[hash].remove(handel);
  numOfItems--;
  return successOrFail;
}
User *HashTable::search(const string &s) const
// returns user if s exist in the hash table, null otherwise
{
  int hash = hashFunc(s);
  cout << hash << endl;
  arr[hash].search(s);
  return &(arr[hash].search(s)->key);
}

int HashTable::size() const // returns numOfItems
{
  return numOfItems;
}

int HashTable::maxSize() const // returns arrSize
{
  return arrSize;
}
