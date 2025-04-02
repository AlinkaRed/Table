#pragma once
#include "TArrayTable.h"
template <class TKey, class TVal>
class TScanTable : public TArrayTable<TKey, TVal> {
public:
	TScanTable(int sz = 10) : TArrayTable<TKey, TVal>(sz) {}
	void SelectSort() { return; }
	void QSort() { return; }
	void MergeSort(int left, int right) { return; }
	virtual bool find(TKey key) {
		int i;
		for (i = 0; i < DataCount; i++)
		{
			eff++;
			if (pRecs[i].key == key) {
				CurrPos = i;
				return true;
			}
		}
		CurrPos = DataCount;
		return false;
	}

	virtual int ins(TKey k, TVal v) {
		if (isFull())
			throw - 1;
		TRecord<TKey, TVal> r(k, v);
		pRecs[DataCount] = r;
		DataCount++;
		eff++;
		return 0;
	}

	virtual int ins(TRecord<TKey, TVal> rec) {
		if (isFull())
			throw - 1;
		if (find(rec.key))
			throw - 1;
		pRecs[DataCount] = rec;
		DataCount++;
		eff++;
		return 0;
	}

	virtual int del(TKey key) {
		if (!find(key))
			throw - 1;
		pRecs[CurrPos] = pRecs[DataCount - 1];
		DataCount--;
		eff++;
		return 0;
	}
};