// HDOJ #1089 A+B for Input-Output Practice (I)
// description
// created by sjyan
// 2016年2月27日 下午8:32

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
    
    std::ios::sync_with_stdio(false);   
    
    int a,b;
    
    while(cin>>a>>b)
    {
        cout<<a+b<<endl;
    }
    
    
    return 0;
}