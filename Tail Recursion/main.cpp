// Example.cpp : Defines the entry point for the console application.
//
 
#include <iostream> 
#include <time.h>

using namespace std; 
typedef  unsigned long long ULONG64;
 

ULONG64 fib_tail_x64(ULONG64 n, ULONG64 res, ULONG64 next) {
	if (n == 0) {
		return res;
	}
	return fib_tail_x64(n - 1, next, res + next);
}

int fib_tail(unsigned int n,unsigned int res,unsigned int next) {
	if (n == 0) {
		return res;
	}
	return fib_tail(n - 1, next, res + next);
}

int main(int argc, char* argv[])
{
	clock_t t;
	t = clock();
	auto fibrec = fib_tail(40,0,1);
	t = clock() - t;
	cout << "Clock cycles Fibonacci Recursive x86: " << (float)t << " Time: " << ((float)t)/CLOCKS_PER_SEC << endl;
	cout << "Result: " << fibrec << endl;

	t = clock();

	auto fibrec64 = fib_tail_x64(40,0,1);
	t = clock() - t;
	cout << "Clock cycles Fibonacci Recursive x64: " << (float)t << " Time: " << ((float)t)/CLOCKS_PER_SEC << endl;
	cout << "Result: " << fibrec64 << endl;

	int p ;
	cin >> p;
}
