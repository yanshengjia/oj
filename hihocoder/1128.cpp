//hihocoder

#include <iostream>
using namespace std;


int main()
{
    int N,K;
    cin>>N>>K;
    int *a = new int[N];
    for(int i=0; i<N; i++)
        cin>>a[i];
    
    for(int i=0; i<N; i++)
    cout<<a[i]<<" ";
    
    int flag=0;
    int num=0;
    for(int i=0; i<N; i++)
    {
        if(a[i]==K)
        {
            num=i;  //将 K 的下标给 num
            flag=1;
            break;
        }
    }
    
    if(flag==0) cout<<-1;
    else
    {
        int counter=0;
        int pivot = a[num];
        for(int i=0; i<N; i++)
        {
            if(a[i]<pivot)  counter++;
        }
        cout<<counter+1;
    }

    return 0;
}


