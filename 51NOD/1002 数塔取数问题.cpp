// 51NOD #1002 数塔取数问题
// dynamic programming
// created by Shengjia Yan
// 2016年5月11日 下午3:45

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

    // Coding The World!
    int N;
    cin>>N;
    
    int a[N+10][N+10];
    int t;
    
    cin>>a[0][0];   // 读取塔顶
    
    for(int i=1; i<N; i++)
    {
        for(int j=0; j<=i; j++)
        {
            cin>>t;
            if(j==0)    a[i][j] = a[i-1][j] + t;
            else if(j==i)   a[i][j] = a[i-1][j-1] + t;
            else
            {
                int left = a[i-1][j-1] + t;
                int right = a[i-1][j] +t;
                a[i][j] = max(left, right);
            } 
        }
    }
    
    int bottom[N];
    
    for(int i=0; i<N; i++)
    {
        bottom[i] = a[N-1][i];
    }
    
    sort(bottom, bottom+N);
    cout<<bottom[N-1];
    
    
    return 0;
}