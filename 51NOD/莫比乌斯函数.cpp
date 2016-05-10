// 51NOD #1240 莫比乌斯函数
// description
// created by Shengjia Yan
// 2016年5月9日 下午7:40

//#define LOCAL
//#define SPEED

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

bool isPrimeNumber(int n)
{
    if(n <= 1)  return false;
    else if(n == 2) return true;
    else
    {
        for(int i=2; i*i<n; i++)
        {
            if(n%i == 0)    return false;
        }
        return true;
    }
}

// 莫比乌斯函数
int miu(int n)
{
    int counter = 0;
    
    // 将 n 表示为 k 个质因子的乘积
    for(int i=2; i<=n; i++)
    {
        if(n%i == 0)    // i 是 n 的因子
        {
            counter++;
            
            int flag = 0;  // 平方因子旗帜
                        
            while(n%i == 0)
            {
                flag++;
                n /= i;
                if(flag >= 2)   return 0;
            }
            
            if(isPrimeNumber(n))
            {
            counter++;
            break;
            }
        } 
    }
    
    return counter%2==0 ? 1 : -1;
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

    int n;
    cin>>n;

    cout<<miu(n);

    return 0;
}