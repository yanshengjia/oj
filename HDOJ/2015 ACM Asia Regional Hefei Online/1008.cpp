//HDOJ #1008


#define LOCAL

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <cmath>
#include <stdio.h>

using namespace std;

int BitCount(int n)
{
    int c =0 ;
    for (c =0; n; ++c)
    {
        n &= (n -1) ; // 清除最低位的1
    }
    return c ;
}

int main()
{
    #ifdef LOCAL
    freopen("1.txt","r",stdin);
    #endif

    int T;
    scanf("%d",&T);

    int D, S1, S2;
    int answer;

    for(int i=0; i<T; i++)
    {
        scanf("%d %d %d", &D, &S1, &S2);



        

        printf("Case #%d: %d\n", i+1, answer);

    }

    return 0;
}