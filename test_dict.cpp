#include <iostream>
#include "dict.h"
#include <chrono>
#include <cassert>
#include <thread>
#include <map>
using namespace std;

#define LENGTH 9999901L
#define MULT 4937L
#define REM 9999971L
#define FACT 100000L
#define SUB 500000000000L

void f1(void) {
	auto begin = chrono::high_resolution_clock::now();
	dict<long, bool> A;
	size_t l = 0;
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
}

void f2(void) {
	auto begin = chrono::high_resolution_clock::now();
	map<long, bool> B;
	size_t L = 0;
	for (long i = 0; i < LENGTH; i++) {
		B.insert({((i*MULT % REM)*FACT - SUB), false});
		assert(B.size() == ++L);
	}
	long v = LONG_MIN;
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
	auto end = chrono::high_resolution_clock::now();
	long time = chrono::duration_cast<chrono::nanoseconds>(end - begin).count();
	cout.precision(10);
	cout << "Time taken for STL map: " << (double)time/1000000000.00 << "\n";
}

int main(void) {
    thread T1(f1);
    thread T2(f2);
    T1.join();
    T2.join();
    return 0;
}
