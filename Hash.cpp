#include "Hash.h"
#include <algorithm>
#include <iterator>


template<class T>
int HashTable<T>::myHash(const T& x) {//Finds the correct bucket wonly applicable when hash is int
	int c(x);
	return (c % theLists.size());
}

template<class T>
bool HashTable<T>::contains(const T& x) const {
	auto& whichList = theLists[myHash(x)];//selects the correct list using the correct bucket sub
	return std::find(std::begin(whichList), end(whichList), x) != end(whichList);//searches for the exact value then returns a boolean value true if not end()
}

template <class T>
bool HashTable<T>::insert(const T& x) {
	int index = myHash(x);
	theLists[index].push_back(x);
	++currSize;
	return true;
}

template<class T>
void HashTable<T>::clear() {
	for (int& x : theLists) {
		x.clear();
	}
}

template<class T>
bool HashTable<T>::remove(const T& x) {
	auto& whichList = theLists[myHash(x)];
	auto it = find(begin(whichList), end(whichList), x);
	if (it == end(find))
		return false;
	whichList.erase(it);
	--currSize;
	return true;
}