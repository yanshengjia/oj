// 51NOD #1012 最小公倍数LCM
// 辗转相除法
// created by yanshengjia
// 2015-11-27


#include <iostream>
using namespace std;

int main()
{
    long long int gcd = 0;
    long long int lcm = 0;
    long long int a, b, c, d;
    cin>>a>>b;
    
    // c,d保存a,b的值
    c = a;  
    d = b;
    
    // 使a为a,b中不小的那个
    if(a<b) 
    {
        long long int t = b;
        b = a;
        a = t; 
    }
	
    long long int r = 1;  // r = a%b
    while(r)
    {
        r = a%b;
        if(r == 0) 
        {
            gcd = b;
        } 
        else
        {
            a = b;
            b = r;
        }
    }
    
    lcm = c*d/gcd;
    
    cout<<lcm<<endl;
    
    return 0;
}