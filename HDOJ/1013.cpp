// HDOJ #1013 Digital Roots
// 考虑超大数的处理
// created by sjyan
// 2016年3月4日 下午2:31

//#define LOCAL

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <string.h>
#include <sstream>
#include <cmath>

using namespace std;

int digitCalculator(int number)
{
	int digit=0;

	while(number != 0)
	{
		number/=10;
		digit++;
	}

	return digit;
}

int main()
{
	#ifdef LOCAL
    freopen("1.txt","r",stdin);
    #endif
    
    std::ios::sync_with_stdio(false);

    string str;

    while(cin>>str)
    {
    	long long int number = 0;
    	long long int sum = 0;
    	
    	int length = str.size();

    	if(length == 1)
    	{
    		number = atoi(str.c_str());
    		if(number == 0)
    		{
    			break;
    		}
    		else
    		{
    			sum += number;
    			cout<<number<<endl;
    			continue;
    		}
    	}
    	else
    	{
    		for(int i=0; i<length; i++)
    		{
    			number += (str[i]-48);
    		}

    		long long int digit = digitCalculator(number);

    		if(digit == 1)
	    	{
	    		sum += number;
	    		cout<<sum<<endl;
	    	}
	    	else
	    	{
	    		do
	    		{
	    			sum = 0;
	    			for(int i=0; i<digit; i++)
	    			{
	    				sum += (number%10);
	    				number /= 10;
	    			}

	    			number = sum;
	    			digit = digitCalculator(number);

	    		}while(digit != 1);

	    		cout<<sum<<endl;
	    	}
	    }
    }

    return 0;
}
