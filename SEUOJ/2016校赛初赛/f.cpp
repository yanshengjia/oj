// SEUOJ #num name
// description
// created by Shengjia Yan
// 2016年5月22日 下午1:25

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <stack>
#include <deque>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <algorithm>

using namespace std;

#define ll long long int
#define ull unsigned long long int

#define FOR(i,n) for(int i=0; i<n; i++)
#define FOR1(i,n) for(int i=1; i<=n; i++)

#define fix(x) cout<<setiosflags(ios::fixed)<<setprecision(x)

const double pi = 3.1415926535898;
const double esp = 1e-8;
const double mod = 1e9 + 7;

double min(double a, double b) { return a < b ? a : b; }
double max(double a, double b) { return a > b ? a : b; }

struct Point{ double x,y; };

// 判断平方数
bool isSquareNumber(int n)
{
    int t = sqrt(n);
    if(t*t == n)    return true;
    else return false;
}

// 判断素数
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

int main()
{
    // Coding The World!
    int T;
    scanf("%d",&T);

    for(int i=0; i<T; i++)
    {
        int N;
        scanf("%d",&N); // N 张纸牌
        bool flag = true;
        int counter = 0;
        int a[N+5];
        
        for(int j=0; j<N; j++)  scanf("%d",&a[j]);
        
        while(flag)
        {
            flag = false;
            
            for(int k=0; k<N-1; k++)
            {
                if(a[k]<a[k+1]) 
                {
                    flag = true;
                    break;
                    counter++;
                }
            }
            
            if(N == 1 || flag == false)   break;
            
            for(int j=0; j<N-1; j++)
            {
                if(a[j]<a[j+1])
                {
                    for(int p=j; p<N-1; p++)  a[p]=a[p+1];
                    N--;
                }
            }
        }
        
        printf("%d\n",counter);
        for(int l=0; l<N-1; l++)  printf("%d ",a[l]);
        printf("%d\n",a[N-1]);
    }
    
    return 0;
}