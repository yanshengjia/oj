// SEUOJ #144 亮瞎眼的素数
// description
// created by Shengjia Yan
// 2016年5月14日 上午10:10

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

// 配置
#define LOCAL 0     // 输入输出重定向
#define SPEED 1     // cin关缓冲区同步

#define ll long long int
#define f0 0
#define f1 1

double min(double a, double b) { return a < b ? a : b; }
double max(double a, double b) { return a > b ? a : b; }

struct Point{ double x,y; };

bool isSquareNumber(int n)
{
    int t = sqrt(n);
    if(t*t == n)    return true;
    else return false;
}

int a[40000];
int b[40000];
int c[40000];

bool isPrimeNumber(int n)
{
    if(n <= 1)    return false;
    else if(n == 2)    return true;
    else    // n >= 3
    {
        for(int i=2; i*i<=n; i++)
        {
            if(n%i == 0)    return false;
        }
        return true;
    }
}


int charm(int n)
{
    int length;
    
    if(n == 0)  return 1;
    else if(n == 1) return 1;
    else // n >= 2
    {
        
    }
    
    
    
    
    
}





int main()
{
	#if LOCAL
    freopen("1.txt","r",stdin);
    #endif
    
    #if SPEED
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    #endif  

    // Coding The World!
    int T;
    cin>>T;
    
    for(int i=0; i<T; i++)
    {
        memset(a, -1, sizeof(a));   // 重置数组
        
        int n;
        cin>>n;
        cout<<charm(n)<<endl;
        
    }
    return 0;
}