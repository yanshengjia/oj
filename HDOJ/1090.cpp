// HDOJ #1090 A+B for Input-Output Practice (II)
// A+B
// created by yanshengjia
// 2016年2月27日

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
    
    int T;
    cin>>T;
    int a, b;
    
    for(int i=0; i<T; i++)
    {
        cin>>a>>b;
        cout<<a+b<<endl;
    }
    
    return 0;
}