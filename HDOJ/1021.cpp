//HDOJ

#include <iostream>
using namespace std;

int main()
{
	int x;
	int Fibonacci(int);
	while (cin >> x)
	{
		if (Fibonacci(x) % 3 == 0)  cout << "yes" << endl;
		else cout << "no" << endl;
	}


	system("pause");
	return 0;
}

int Fibonacci(int n)
{
	if (n == 0)  return 7;
	if (n == 1) return 11;
	else return Fibonacci(n - 1) + Fibonacci(n - 2);
}