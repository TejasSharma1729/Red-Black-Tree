#include <iostream>
#include "dict.h"
#include <chrono>
#include <cassert>
#include <map>
using namespace std;

const long LENGTH = 9999901;
const long MULT = 4937;
const long REM = 9999971;
const long FACT = 100000;
const long SUB = 500000000000;

int main() {
	auto begin = chrono::high_resolution_clock::now();
	dict<long, bool> A;
	long l = 0;
	for (long i = 0; i < LENGTH; i++) {
		A.insert(((i*MULT % REM)*FACT - SUB), false);
		assert(A.size() == ++l);
	}
	long v = LONG_MIN;
	for (auto itr = A.begin(); !itr.isNull(); itr++) {
		assert(itr.key() > v);
		v = itr.key();
	}
	for (long i = 0; i < LENGTH; i++) {
		A.remove(((i*MULT % LENGTH)*MULT % REM)*FACT - SUB);
		assert(A.size() == --l);
	}
	assert(A.empty());
	assert(l == 0);
	auto end = chrono::high_resolution_clock::now();
	long time = chrono::duration_cast<chrono::nanoseconds>(end - begin).count();
	cout.precision(10);
	cout << "Time taken for my dictionary: " << (double)time/1000000000.00 << "\n";

	begin = chrono::high_resolution_clock::now();
	map<long, bool> B;
	unsigned long L = 0;
	for (int i = 0; i < LENGTH; i++) {
		B.insert({((i*MULT % REM)*FACT - SUB), false});
		assert(B.size() == ++L);
	}
	v = LONG_MIN;
	for (auto itr = B.begin(); itr != B.end(); itr++) {
		assert(itr->first > v);
		v = itr->first;
	}
	for (long i = 0; i < LENGTH; i++) {
		B.erase(((i*MULT % LENGTH)*MULT % REM)*FACT - SUB);
		assert(B.size() == --L);
	}
	assert(B.empty());
	assert(L == 0);
	end = chrono::high_resolution_clock::now();
	time = chrono::duration_cast<chrono::nanoseconds>(end - begin).count();
	cout << "Time taken for STL map: " << (double)time/1000000000.00 << "\n";
}
