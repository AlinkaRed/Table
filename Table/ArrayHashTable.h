#pragma once
#include "HashTable.h"
template <class TKey, class TVal>
class ArrayHashTable : public HashTable<TKey, TVal>
{
protected:
	TRecord<TKey, TVal>* pRecs;
	int step, curr;
	TRecord<TKey, TVal> free, deleted;
public:
	ArrayHashTable(int sz = 10);

	bool isFull() const { return DataCount == MaxSize; }

	bool find(TKey key);
	int ins(TKey key, TVal val);
	int ins(TRecord<TKey, TVal> rec);
	int del(TKey key);

	void reset();
	void goNext();
	bool isEnd() { return curr == MaxSize; }

	TKey getCurrKey() { return pRecs[curr].key; };
	TVal getCurrVal() { return pRecs[curr].val; }
	TRecord<TKey, TVal> getCurrRec() { return pRecs[curr]; }
	~ArrayHashTable() { delete pRecs; }

	void setCurrPos(int pos) { return; }
	void setRec(TRecord<TKey, TVal> rec) { return; }
	int getCurrPos() const { return 0; }
	void SelectSort() { return;  }
	void MergeSort(int left, int right) { return; }
	void QSort() { return; }
};

template<class TKey, class TVal>
ArrayHashTable<TKey, TVal>::ArrayHashTable(int sz)
{
	MaxSize = sz;
	for (int i = 2; i * i < MaxSize; i++) {
		if (sz % i != 0)
		{
			step = i;
			break;
		}
	}
	curr = 0;
	free.key = -1;
	deleted.key = -2;
	pRecs = new TRecord<TKey, TVal>[sz];
	for (size_t i = 0; i < sz; i++)
	{
		pRecs[i] = free;
	}
}

template<class TKey, class TVal>
bool ArrayHashTable<TKey, TVal>::find(TKey key)
{
	curr = HashFunc(key);
	int tmp = -1;
	for (size_t i = 0; i < MaxSize; i++)
	{
		eff++;
		if (pRecs[curr] == free) 
			break;
		else if (pRecs[curr] == deleted && tmp == -1) 
			tmp = curr;
		else if (pRecs[curr].key == key) 
			return true;
		curr = (curr + step) % MaxSize;
	}
	if (tmp != -1) 
		curr = tmp;
	return false;
}

template<class TKey, class TVal>
int ArrayHashTable<TKey, TVal>::ins(TKey key, TVal val)
{
	if (find(key)) 
		throw - 1;
	TRecord<TKey, TVal> tmp(key, val);
	pRecs[curr] = tmp;
	DataCount++;
	eff++;
	return 0;
}

template<class TKey, class TVal>
int ArrayHashTable<TKey, TVal>::ins(TRecord<TKey, TVal> rec)
{
	if (find(rec.key)) 
		throw - 1;
	pRecs[curr] = rec;
	DataCount++;
	eff++;
	return 0;
}

template<class TKey, class TVal>
int ArrayHashTable<TKey, TVal>::del(TKey key)
{
	if (!find(key)) 
		throw - 1;
	pRecs[curr] = deleted;
	eff++;
	return 0;
}

template<class TKey, class TVal>
void ArrayHashTable<TKey, TVal>::reset()
{
	curr = -1;
	eff++;
	goNext();
}

template<class TKey, class TVal>
void ArrayHashTable<TKey, TVal>::goNext()
{
	curr++;
	while ((pRecs[curr] == free || pRecs[curr] == deleted) && !isEnd()) {
		curr++;
		eff++;
	}
}

