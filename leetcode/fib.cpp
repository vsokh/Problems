#include <iostream>
using namespace std;

unsigned long long rfib(unsigned long long n)
{
	if (n<=1) return 1;
	return rfib(n-2)+rfib(n-1);
}

unsigned long long fib(unsigned long long n)
{
	if (n<=1) return 1;
	unsigned long long a,b,c;
	a = 0, b = 1, c = 0;
	for (unsigned long long i=0;i<n;++i) {
		c = a+b; a = b; b = c;
	}
	return c;
}

int main(int argc, char **argv)
{
	cout << fib(atoi(argv[1])) << endl;
	return 0;
}
