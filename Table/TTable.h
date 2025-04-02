#pragma once
#include "TRecord.h"
#include <iostream>
using namespace std;
template <class TKey, class TVal>
class TTable {
protected:
	int DataCount;
	int eff;
public:
	TTable() :DataCount(0), eff(0) {}
	virtual ~TTable() {}
	int getDataCount() { return DataCount; }
	int getEff() { return eff; }
	bool isEmpty() const { return DataCount == 0; }
	virtual void QSort() = 0;
	virtual	bool isFull() const = 0;
	virtual bool find(TKey key) = 0;
	virtual int ins(TKey key, TVal val) = 0;
	virtual int ins(TRecord<TKey, TVal> rec) = 0;
	virtual int del(TKey key) = 0;
	virtual void reset() = 0;
	virtual void goNext() = 0;
	virtual bool isEnd() = 0;
	virtual TKey getCurrKey() = 0;
	virtual TVal getCurrVal() = 0;
	virtual TRecord<TKey, TVal> getCurrRec() = 0;
	virtual void setCurrPos(int pos) = 0;
	virtual void setRec(TRecord<TKey, TVal> rec) = 0;
	virtual int getCurrPos() const = 0;
	virtual void SelectSort() = 0;
	virtual void MergeSort(int left, int right) = 0;
	friend ostream& operator<<(ostream& out, const TTable<TKey, TVal>& t);
};
template <class TKey, class TVal>
ostream& operator<<(ostream& out, TTable<TKey, TVal>& t) {
	for (t.reset(); !t.isEnd(); t.goNext()) {
		out << t.getCurrKey() << " " << t.getCurrVal() << endl;
	}
	return out;
}