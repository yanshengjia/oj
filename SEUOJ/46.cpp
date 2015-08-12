//prime number
//SEUOJ

#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

bool primeNumber( int num )
{
    if(num==1)  return false;
    int flag=1;
    int pivot = sqrt(num);
    for(int i=2; i<=pivot; i++)
    {
        if(num%i==0)
        {
            flag=0;
            break;
        }
    }
    if(flag)    return true;
    else return false;
}

int main()
{
    int start, end;
    while(scanf("%d %d", &start, &end)!=EOF)
    {
        int count=0;
        for(int i=start; i<end; i++)
        {
            if(primeNumber(i))
                count++;
        }
        printf("%d\n", count);
        count=0;
    }
    
    return 0;
}