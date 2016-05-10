// 51NOD #1018 排序
// quick sort
// created by yanshengjia
// 2015.11.20


#include <iostream>
#include <algorithm>


using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);   
	
    int N;
    cin>>N;
    int a[50005];
    for(int i=0; i<N; i++)
        cin>>a[i];
    
    sort(a,a+N);
	
    for(int i=0; i<N; i++)
        cout<<a[i]<<endl;
    
    return 0;
}