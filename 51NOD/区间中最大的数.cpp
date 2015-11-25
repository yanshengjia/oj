// 51NOD #1174 区间中最大的数
// description
// created by yanshengjia
// 2015.11.20

//#define LOCAL

#include <iostream>
using namespace std;

int main()
{
	int N, Q, i, j, max;
	int array[100000];
	
	cin>>N;
	for(int i=0; i<N; i++)	
	{
		cin>>array[i];
	}
	
	cin>>Q;
	for(int m=0; m<Q; m++)
	{
		cin>>i>>j;
		max = array[i];
		for(int k=i+1; k<=j; k++)
		{
			if(array[k] > max)	max = array[k];
		}	
		cout<<max<<endl;
	}
	
    return 0;
}