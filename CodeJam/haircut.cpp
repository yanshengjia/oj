//codejam

#include <iostream>
using namespace std;
#include <stdio.h>

int gcd(int a, int b)
{
    if (b == 0)return a;
    else return gcd(b, a%b);
}

int lcm(int m, int n)
{
    return (m*n) / gcd(m, n);
}

void findMin(int sign[],int B,int &value,int &number)
{
    value = 1000000;
    number = 0;
    for(int i=B-1;i>=0;i--)
        if(value >= sign[i])
        {
            value = sign[i];
            number = i;
        }
}

int compute(int m[],int B,int N)
{
    int *sign = new int[B];
    int temp = m[0];
    for(int i=1;i<B;i++)
    {
        temp = lcm(temp,m[i]);
    }
    int t = 0;
    for(int i=0;i<B;i++)
        t += temp/m[i];
    int count = B + (N/temp)*t;
    
    int min = 1;  //编号最小的理发师
    for(int i=0;i<B;i++)
    {
        sign[i] = m[i];
    }
    int value=0;
    int number=0;
    while(count<N)
    {
        findMin(sign,B,value,number);
        for(int i=0;i<B;i++)
            sign[i] -= value;
        for(int i=0;i<B;i++)
        {
            if(sign[i] == 0)
            {
                sign[i] = m[i];
                count++;
                if(count == N)
                    min = i;
            }
        }
    }
    
    return min+1;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    int T;
    cin>>T;
    int B,N;
    int m[100001];
    for(int i=1;i<=T;i++)
    {
        cin>>B>>N;
        for(int j=0;j<B;j++)
            cin>>m[j];
        cout<<"Case #"<<i<<": "<<compute(m,B,N)<<endl;
    }
    return 0;
}