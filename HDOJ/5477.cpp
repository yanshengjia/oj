//HDOJ #5477
//A Sweet Journey
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <cmath>
#include <stdio.h>
using namespace std;


int main()
{
    int T;
    scanf("%d",&T);

    int n,A,B,L;
    

    for(int i=0; i<T; i++)
    {
    	scanf("%d %d %d %d",&n, &A, &B, &L);

        int min=100000000;
    	int temp=0;
    	int li, ri;
    	int begin=0;

    	for(int j=0; j<n; j++)
    	{
    		scanf("%d %d", &li, &ri);
    		temp += ((li-begin)*B - (ri-li)*A);
    		begin=ri;

    		if(min>temp)  min=temp;
    	}

        if(min>0)   temp=0;
        else temp=(-1)*min;

    	printf("Case #%d: %d\n", i+1, temp);

    }

    return 0;
}