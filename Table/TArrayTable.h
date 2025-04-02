#pragma once
#include "TTable.h"
template <class TKey, class TVal>
class TArrayTable : public TTable<TKey, TVal> {
protected:
	int MaxSize;
	int CurrPos;
	TRecord<TKey, TVal>* pRecs;
public:
	TArrayTable(int sz = 10);
	TArrayTable(const TArrayTable<TKey, TVal>& t);
	TArrayTable& operator=(const TArrayTable<TKey, TVal>& t)
	{
		if (this != &t)
		{
			delete[] pRecs;
			MaxSize = t.MaxSize;
			CurrPos = t.CurrPos;
			DataCount = t.DataCount;
			pRecs = new TRecord[MaxSize];
			for (int i = 0; i < DataCount; ++i) {
				pRecs[i] = t.pRecs[i];
			}
		}
		return *this;
	}
	~TArrayTable() { delete[] pRecs; }
	TKey getCurrKey() { 
		if (CurrPos < 0 || CurrPos >= MaxSize)
			throw - 1;
		return pRecs[CurrPos].key; 
	}
	TVal getCurrVal() { 
		if (CurrPos < 0 || CurrPos >= MaxSize)
			throw - 1;
		return pRecs[CurrPos].val; 
	}
	TRecord<TKey, TVal> getCurrRec() { 
		if (CurrPos < 0 || CurrPos >= MaxSize)
			throw - 1;
		return pRecs[CurrPos]; 
	}
	virtual void setRec(TRecord<TKey, TVal> rec) {
		if (CurrPos < 0 || CurrPos >= MaxSize)
			throw - 1;
		pRecs[CurrPos] = rec;
		DataCount++;
	}
	virtual int getCurrPos() const { return CurrPos; };
	virtual void setCurrPos(int pos) { CurrPos = pos; };
	int getMaxSize() const { return MaxSize; }
	bool isFull() const { return DataCount == MaxSize; }
	bool isEmpty() { return MaxSize == 0; }
	void reset() { CurrPos = 0; };
	void goNext() { 
		if (!isEnd())
			CurrPos++; 
	};
	bool isEnd() { return CurrPos == DataCount; }
};

template<class TKey, class TVal>
TArrayTable<TKey, TVal>::TArrayTable(int sz) : TTable<TKey, TVal>()
{
	MaxSize = sz;
	pRecs = new TRecord<TKey, TVal>[MaxSize];
	CurrPos = -1;
}

template<class TKey, class TVal>
TArrayTable<TKey, TVal>::TArrayTable(const TArrayTable<TKey, TVal>& t)
{
	MaxSize = t.MaxSize;
	CurrPos = t.CurrPos;
	DataCount = t.DataCount;
	eff = t.eff;
	pRecs = new TRecord<TKey, TVal>[MaxSize];
	for (int i = 0; i < MaxSize; i++)
	{
		pRecs[i] = t.pRecs[i];
	}
}