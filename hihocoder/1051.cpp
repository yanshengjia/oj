//hihocoder 1051
//补提交卡
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<sstream>
using namespace std;

int main()
{
    int T, N, M;
    cin>>T;
    
    for(int i=0; i<T; i++)
    {
        int max = 1;
        cin>>N>>M;
        
        int *a = new int[N+2];
        a[0] = 1;
        a[N+1] = 100;
        for(int j=1; j<=N; j++)
            cin>>a[j];
        
        if(N==0)
        {
            max = 100;
        }
        else if(M==0)
        {
            for(int k=0; k<N+2; k++)
            {
                if(k+M+1>=N+2)   break;
                
                int t;
                if(k==0 || k+M+1==N+1)    t = a[k+M+1]-a[k];
                else    t = a[k+M+1]-a[k]-2;
                
                if(t>max)   max = t;
            }

        }
        else if(M>=N)
        {
            max = 100;

        }
        else    //N!=0 && M!=0 && M<N
        {
            for(int k=0; k<N+2; k++)
            {
                if(k+M+1>=N+2)   break;
                
                int t;
                if(k==0 || k+M+1==N+1)    t = a[k+M+1]-a[k];
                else    t = a[k+M+1]-a[k]-1;

                if(t>max)   max = t;
            }

        }
        cout<<max<<endl;
    }
    
    return 0;
}