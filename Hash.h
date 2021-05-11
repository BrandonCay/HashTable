#pragma once
#include <vector>
#include <list>

template<class T>
class HashTable {
	std::vector<std::list<T>> theLists;
	int currSize;
public:
	int myHash(const T&);
	bool contains(const T& ) const;
	void makeEmpty();
	bool insert(const T&);
	void clear();
	bool remove(const T&);
};