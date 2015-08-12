//How many prime numbers?
//SEUOJ

#include <stdio.h>

bool primeNumber(int num)
{
    if(num<=1)  return false;
    else
    {
        for(int i=2; i*i<=num; i++)
        {
            if( num%i==0 )
            {
                return false;
            }
        }
        return true;
    }
}

int main()
{
    int N;
    scanf("%d",&N);
    int counter=1;
    if(N==1)    counter=0;
    else if(N==2)   counter=1;
    else
    {
    for(int i=3; i<=N; i++)
    {
        if( i%2==0 )    continue;
        if( primeNumber(i) )
            counter++;
    }
    }
    printf("%d", counter );
    return 0;
}