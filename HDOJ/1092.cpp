// HDOJ #1092 A+B for Input-Output Practice (IV)
// A+B
// created by sjyan
// 2016年2月27日 下午9:00

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

int main()
{
	#ifdef LOCAL
    freopen("1.txt","r",stdin);
    #endif
    
    std::ios::sync_with_stdio(false);   
    
    int T;
    string s;
    stringstream ss;
    int sum;
    
    while(getline(cin, s))
    {
        sum = 0;
        ss.clear();
        ss<<s;
        ss>>T;
        
        if(T == 0)
        {
            break;
        }
        else
        {
            for(int i=0; i<T; i++)
            {
                ss>>a[i];
                sum += a[i];
            }
            
            cout<<sum<<endl;
        }
    }
    
    return 0;
}