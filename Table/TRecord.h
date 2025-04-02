#pragma once
#include <iostream>
using namespace std;
template <class TKey, class TVal>
struct TRecord {
	TKey key;
	TVal val;

	TRecord() {};
	TRecord(const TKey k, const TVal v) : key(k), val(v) {}

	bool operator<(TRecord<TKey, TVal> r) { return key < r.key; };
	bool operator==(TRecord<TKey, TVal> r) { return key == r.key; };
};