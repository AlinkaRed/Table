#include "TScanTable.h"
#include "TTable.h"
#include "TSortTable.h"
#include "ArrayHashTable.h"
void main() {
	TTable<int, int>* s1;
	s1 = new TScanTable<int, int>;
	TTable<int, int>* s2;
	s2 = new TSortTable<int, int>;
	for (int i = 3; i >= 0; i--) {
		int r = s1->ins(i, i * i);
	}
	for (int i = 4; i >= 0; i--) {
		int r = s2->ins(i, i * i);
	}
	cout << "TScanTable: " << endl;
	for (s1->reset(); !s1->isEnd(); s1->goNext()) {
		int s = s1->getCurrKey();
		int a = s1->getCurrVal();
		cout << s << ' ' << a << endl;
	}
	cout << "TSortTable: " << endl;
	for (s2->reset(); !s2->isEnd(); s2->goNext()) {
		int s = s2->getCurrKey();
		int a = s2->getCurrVal();
		cout << s << ' ' << a << endl;
	}
	int r = s1->del(3);
	r = s2->del(2);
	cout << "TScanTable: " << endl;
	for (s1->reset(); !s1->isEnd(); s1->goNext()) {
		int s = s1->getCurrKey();
		int a = s1->getCurrVal();
		cout << s << ' ' << a << endl;
	}
	cout << "TSortTable: " << endl;
	for (s2->reset(); !s2->isEnd(); s2->goNext()) {
		int s = s2->getCurrKey();
		int a = s2->getCurrVal();
		cout << s << ' ' << a << endl;
	}
	TTable<int, int>* h;
	h = new ArrayHashTable<int, int>(100);
	for (int i = 0; i < 10; i++)
	{
		h->ins(i * 10, i);
	}
	cout << "ArrayHashTable: " << endl;
	for (h->reset(); !h->isEnd(); h->goNext()) {
		int s = h->getCurrKey();
		int a = h->getCurrVal();
		cout << s << ' ' << a << endl;
	}
	for (int i = 0; i < 5; i++)
	{
		h->del(i * 10);
	}
	cout << "ArrayHashTable: " << endl;
	for (h->reset(); !h->isEnd(); h->goNext()) {
		int s = h->getCurrKey();
		int a = h->getCurrVal();
		cout << s << ' ' << a << endl;
	}
	/*TTable<int, int>* s3;
	s3 = new TSortTable<int, int>;
	s3->ins({ 3, 500 });
	s3->ins({ 4, 300 });
	s3->ins({ 1, 400 });
	s3->ins({ 5, 100 });
	s3->MergeSort(0, 3);
	cout << "TSortTable: " << endl;
	cout << s3 << endl;*/
	TTable<int, int>* h1;
	h1 = new ArrayHashTable<int, int>(1);
	TRecord<int, int> rec = { 1, 100 };
	h1->ins(rec);
	h1->find(1);
	cout << h1->getEff();
}