// HDOJ #1034 Candy Sharing Game
// easy
// created by sjyan
// 2016年2月28日 下午4:45

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

int a[100000];
int b[100000];

int main()
{
	#ifdef LOCAL
    freopen("1.txt","r",stdin);
    #endif
    
    std::ios::sync_with_stdio(false);   
    
    int T;
    int counter = 0;
    int amount = 0;
    bool flag;
    
    while(cin>>T && T!=0)
    {
        flag = false;
        counter = 0;
        for(int i=0; i<T; i++)
        {
            cin>>a[i];
            b[i] = a[i];
        }
        
        while(!flag)
        {
            flag = true;
            for(int i=0; i<T-1; i++)
            {
                if(a[i+1] != a[i])
                {
                    flag = false;
                }
            }
            
            if(flag)
            {
                amount = a[0];
                cout<<counter<<" "<<amount<<endl;
                break;
            }
            
            // do with a[T-1]
            a[T-1] = b[0]/2 + a[T-1]/2;
            if(a[T-1]%2 == 1)
            {
                a[T-1]++;
            }
            
            // do with a[0]~a[T-2]
            for(int i=0; i<T-1; i++)
            {
                a[i] = b[i+1]/2 + a[i]/2;
                
                if(a[i]%2 == 1)
                {
                    a[i]++;
                }
                
                b[i] = a[i];    // prepare for a new round
            }
            
            b[T-1] = a[T-1];
            counter++;
        }     
    }
    

    return 0;
}