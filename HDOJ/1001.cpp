//
//


#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <cmath>
#include <stdio.h>

using namespace std;

int sum(int x)
{
	long long int a = x;
	int answer = (int)((1+a)*a/2);
	return answer;
}



int main()
{
    int a;

    while(scanf("%d", &a)!=EOF)
    {
    	printf("%d\n\n", sum(a));
    }
    
    return 0;
}