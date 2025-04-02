#pragma once
#include "TScanTable.h"
template<class TKey, class TVal>
class TSortTable : public TScanTable<TKey, TVal> {
public:
	TRecord<TKey, TVal>* pBuf;

	void QSortRec(int l, int r);
	TSortTable(int sz = 10) : TScanTable<TKey, TVal>(sz) {}
	TSortTable(const TScanTable<TKey, TVal>& t) : TScanTable<TKey, TVal>(t) { QSort(); }
	virtual bool find(TKey key);
	virtual int ins(TKey k, TVal v); 
	virtual int ins(TRecord<TKey, TVal> rec);
	virtual int del(TKey key);
	void SelectSort();
	void QSort() { QSortRec(0, DataCount - 1); };
	void Merge(int left, int mid, int right);
	void MergeSort(int left, int right);
};

template<class TKey, class TVal>
void TSortTable<TKey, TVal>::Merge(int left, int mid, int right) {
	int i = left, j = mid + 1;
	int k = left;
	while (i <= mid && j <= right)
	{
		if (pRecs[i].key <= pRecs[j].key)
		{
			pBuf[k] = pRecs[i];
			i++;
		}
		else {
			pBuf[k] = pRecs[j];
			j++;
		}
		k++;
		eff++;
	}
	if (i <= mid) {
		while (i <= mid) {
			pBuf[k] = pRecs[i];
			i++;
			k++;
			eff++;
		}
	}
	else {
		while (j <= right) {
			pBuf[k] = pRecs[j];
			j++;
			k++;
			eff++;
		}
	}
	for (i = left; i <= right; i++) {
		pRecs[i] = pBuf[i];
		eff++;
	}
}

template<class TKey, class TVal>
void TSortTable<TKey, TVal>::MergeSort(int left, int right) {
	if (left < right) {
		int mid = (right + left) / 2;
		MergeSort(left, mid);
		MergeSort(mid + 1, right);
		Merge(left, mid, right);
	}
}

template<class TKey, class TVal>
void TSortTable<TKey, TVal>::QSortRec(int l, int r)
{
	int m = (l + r) / 2;
	TKey mkey = pRecs[m].key;
	int i = l, j = r;
	while (i < j) {
		while (pRecs[i].key < mkey)
			i++;
		while (pRecs[j].key > mkey)
			j--;
		if (i <= j) {
			std::swap(pRecs[i], pRecs[j]);
			i++; 
			j--;
		}
		eff++;
	}
	if (j > l)
		QSortRec(l, j);
	if (i < r)
		QSortRec(i, r);
}

template<class TKey, class TVal>
bool TSortTable<TKey, TVal>::find(TKey key)
{
	int l = 0, r = DataCount - 1;
		while (l <= r) {
			eff++;
			int m = (l + r) / 2;
			if (key == pRecs[m].key) {
				CurrPos = m;
				return true;
			}
			else if (key > pRecs[m].key) {
				l = m + 1;
			}
			else { r = m - 1; }
			eff++;
		}
		CurrPos = l;
		return false;
}

template<class TKey, class TVal>
int TSortTable<TKey, TVal>::ins(TKey k, TVal v)
{
	if (isFull())
		throw - 1;
	if (find(k)) 
		throw - 1;
	for (size_t i = DataCount; i > CurrPos; i--) {
		pRecs[i] = pRecs[i - 1];
		eff++;
	}
	pRecs[CurrPos].key = k; 
	pRecs[CurrPos].val = v;
	DataCount++;
	eff++;
	return 0;
}

template<class TKey, class TVal>
int TSortTable<TKey, TVal>::ins(TRecord<TKey, TVal> rec)
{
	if (isFull())
		throw - 1;
	bool res = find(rec.key);
	if (res)
		throw - 1;
	for (int i = DataCount; i > CurrPos; i--) {
		pRecs[i] = pRecs[i - 1];
		eff++;
	}
	pRecs[CurrPos] = rec;
	DataCount++;
	eff++;
	return 0;
}

template<class TKey, class TVal>
int TSortTable<TKey, TVal>::del(TKey key)
{
	bool res = find(key);
	if (res == false)
		throw - 1;
	for (int i = CurrPos; i < DataCount - 1; i++) {
		pRecs[i] = pRecs[i + 1];
		eff++;
	}
	DataCount--;
	return 0;
}

template<class TKey, class TVal>
void TSortTable<TKey, TVal>::SelectSort()
{
	int i, j, mini, tmp;
	for (i = 0; i < DataCount; i++)
	{
		int min = pRecs[i].key, mini = i;
		for (j = i; j < DataCount; j++) {
			if (min > pRecs[j].key) {
				mini = j;
				min = pRecs[j].key;
			}
			eff++;
		}
		tmp = pRecs[mini].key;
		pRecs[mini].key = pRecs[i].key;
		pRecs[i].key = tmp;
	}
}
