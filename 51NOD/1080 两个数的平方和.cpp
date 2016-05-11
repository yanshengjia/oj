// 51NOD #1080 两个数的平方和
// description
// created by Shengjia Yan
// 2016年5月11日 下午1:00

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
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

//#define LOCAL
//#define SPEED
#define ll long long int

double min(double a, double b) { return a < b ? a : b; }
double max(double a, double b) { return a > b ? a : b; }

struct Point{ double x,y; };

bool isSquareNumber(int n)
{
    int t = sqrt(n);
    if(t*t == n)    return true;
    else return false;
}


int main()
{
	#ifdef LOCAL
    freopen("1.txt","r",stdin);
    #endif
    
    #ifdef SPEED
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    #endif  

    int N;
    cin>>N;
    bool flag = false;

    for(int i=0; i*i<=N; i++)
    {
        int e = N-i*i;
        int j = sqrt(e);
        
        if(i > j)   break;
        
        if(isSquareNumber(e))
        {
            flag = true;
            cout<<i<<" "<<j<<endl;
        }
    }

    if(!flag)   cout<<"No Solution"<<endl;

    return 0;
}