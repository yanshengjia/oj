//hihocoder
//第37周 二分查找之 k 小数
//输入长度为 N 的数组找第 k 小的元素并输出，若 k 超出范围输出-1
#include <iostream>
using namespace std;


void Sort(int t[], int low, int high, int k )
{
    int pivot = t[low];
    int i=low, j=high;
    int mid;
    
    while( i<j )
    {
        while(i < j && t[j] > pivot)
        {
            j--;
        }
        
        t[i] = t[j];
        
        while(i < j && t[i] < pivot)
        {
            i++;
        }
        
        t[j] = t[i];
    }
    
    t[i] = pivot;
    mid=i+1;
    
    if (k==mid) cout<<t[mid-1];
    else if(k>mid)  Sort(t,mid,high,k);
    else if(k<mid)  Sort(t,low,mid-1,k);
    
}


int main()
{
    int N,k;
    cin>>N>>k;
    int *a = new int [N];
    
    for(int i=0; i<N; i++)
        cin>>a[i];
    
    if(k<1||k>N)    cout<<"-1";
    else
    {
        Sort(a,0,N-1,k);
    }
    
    return 0;
}