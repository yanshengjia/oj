// 51NOD #1003 阶乘中0的个数
// N!中5的个数就是阶乘中0的个数，N/5 + N/25 + N/125... = result
// created by yanshengjia
// 2015-11-25

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int N;
    cin>>N;
    
    bool flag = true;   
    int i = 1;   // 5的指数
    int count=0;
    
    while(flag)
    {
        int t = pow(5, i);
        if(N/t >= 1)    count += N/t;
        else flag = false;
        i++;
    }
    
    cout<<count<<endl;
    
    return 0;
}