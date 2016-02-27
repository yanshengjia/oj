// HDOJ #1040 As Easy As A+B
// sort
// created by yanshengjia
// 2016-2-27

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

int a[1005];


int main()
{
	#ifdef LOCAL
    freopen("1.txt","r",stdin);
    #endif
    
    std::ios::sync_with_stdio(false);   
    
    int T, N;
    cin>>T;
    
    for(int i=0; i<T; i++)
    {
        cin>>N;
        for(int j=0; j<N; j++)
        {
            cin>>a[j];
        }
        
        sort(a, a+N);
        
        for(int j=0; j<N-1; j++)
        {
            cout<<a[j]<<" ";
        }
        cout<<a[N-1]<<endl;
    }
    
    
    return 0;
}