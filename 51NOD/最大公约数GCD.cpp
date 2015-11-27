// 51NOD #1011 最大公约数GCD
// 辗转相除法
// created by yanshengjia
// 2015-11-27


#include <iostream>
using namespace std;

int main()
{
    int gcd = 0;
    int a, b;
    cin>>a>>b;
    
    // 使a为a,b中不小的那个
    if(a<b) 
    {
        int t = b;
        b = a;
        a = t; 
    }
	
    int r = 1;  // r = a%b
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
    
    cout<<gcd<<endl;
    
    return 0;
}