// 51NOD #1106 质数检测
// description
// created by yanshengjia
// 2015-11-28


#include <iostream>
using namespace std;

int main()
{
	int N;
	cin>>N;
	int num;

	for(int i=0; i<N; i++)
	{
		bool flag = true;
		cin>>num;
		
		if(num == 1)	// 1不是质数
		{
			cout<<"No"<<endl;
			continue;
		}
		
		for(int j=2; j*j<=num; j++)
		{
			if(num%j == 0)	
			{
				flag = false;
				cout<<"No"<<endl;
				break;
			}
		}
		
		if(flag)	cout<<"Yes"<<endl;
	}
	
    return 0;
}