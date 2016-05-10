// 51NOD #1015 水仙花数
// description
// created by yanshengjia
// 2015-11-25


#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int M;   // M:输入数字
    bool flag = true;  // 还未找到水仙花数
    cin>>M;
	
    while(flag)
    {
        if( M/10>=1 && M/10<=9 )
        {
            // 2位数
            int a = (M/10)%10;  // 个位
            int b = M%10;       // 十位
            if( M == pow(a,2) + pow(b,2) )
            {
                cout<<M<<endl;
                flag = false;
            }
        }
        else if( M/100>=1 && M/100<=9 )
        {
            // 3位数
            int a = (M/100)%10; // 百位
            int b = (M/10)%10;  // 个位
            int c = M%10;       // 十位
            if( M == pow(a,3) + pow(b,3) + pow(c,3))
            {
                cout<<M<<endl;
                flag = false;
            }
        }
        else 
        {
            // 4位数 M==1000
            int a = M/1000;     // 千位
            int b = (M/100)%10; // 百位
            int c = (M/10)%10;  // 个位
            int d = M%10;       // 十位
            if(M == pow(a,4) + pow(b,4) + pow(c,4) + pow(d,4))
            {
                cout<<M<<endl;
                flag = false;
            }
        }
        M++;
    }
    
    return 0;
}
