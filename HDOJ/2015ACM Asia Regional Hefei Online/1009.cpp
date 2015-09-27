//HDOJ 


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
#include <stack>

using namespace std;

int main()
{
    #ifdef LOCAL
    freopen("1.txt","r",stdin);
    #endif

    int T;
    scanf("%d",&T);
    int N, M;
    int a[35][35];  //maze

    stack<pair(int,int)> array[35][35];

    int answer;

    for(int i=0; i<T; i++)
    {
        scanf("%d %d", &N, &M);

        for(int n=0; n<N; n++)
        {
            for(int m=0; m<M; m++)
            {
                scanf("%d", &a[n][m]);
            }
        }

        int k = N+M-1;

        array[0][0].push()

        for(int m=0; m<M; m++)
        {
            for(int n=0; n<N; n++)
            {
                

            }
        }

        

        printf("Case #%d: %d\n", i+1, answer);

    }

    return 0;
}