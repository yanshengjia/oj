//HDOJ #1008
//Elevator

//#define LOCAL

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

int main()
{
	#ifdef LOCAL
    freopen("1.txt","r",stdin);
    #endif
    
    int T;
    int a[105];
    while(scanf("%d",&T)&&T)
    {
    	int sum=0;
    	for(int i=0; i<T; i++)
    	{
    		scanf("%d",&a[i]);
    		if(i==0)
    		{
    			sum+=6*(a[0]-0);
    		}
    		else
    		{
    			if(a[i]>a[i-1])
    			{
    				sum+=6*(a[i]-a[i-1]);
    			}
    			else if(a[i]<a[i-1])
    			{
    				sum+=4*(a[i-1]-a[i]);
    			}
    		}
    	}

    	sum+=T*5;

    	printf("%d\n",sum);
    }

    return 0;
}