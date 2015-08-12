//HDOJ

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double e = 0;

	double factorial(int);

	cout << "n e" << endl;
	cout << "- -----------" << endl;

	for (int m = 0; m <= 9; m++)
	{
		for (int j = 0; j <= m; j++)
		{
			e += 1 / factorial(j);
		}
		if (m == 8)		cout << setprecision(9) << m << " " << e <<"0"<< endl;
		else cout << setprecision(10) << m << " " << e << endl;
		e = 0;
	}

	system("pause");
	return 0;
}

double factorial(int x)
{
	if (x == 0 || x == 1)  return 1;
	else return x*factorial(x - 1);
}