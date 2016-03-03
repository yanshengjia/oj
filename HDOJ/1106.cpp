// HDOJ #1106 排序
// easy
// created by sjyan
// 2016年2月29日 下午3:16

//#define LOCAL

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <string.h>
#include <sstream>
#include <cmath>

using namespace std;

int main()
{
	#ifdef LOCAL
    freopen("1.txt","r",stdin);
    #endif
    
    std::ios::sync_with_stdio(false);   
    
    string str;
    int length;
    int number = 0;     // 数字的值
    int digit = 1;      // 数字的位数
    int counter = 0;    // 数字的个数
    
    while(cin>>str)
    {
        int a[1005];
        number = 0;
        digit = 1;
        counter = 0;
        memset(a, 0, 1005);
        
        length = str.size();
        
        for(int i=length-1; i>=0; i--)
        {
            if(str[i] == '5')
            {
                if(i == length-1)
                {
                    continue;
                }
                else if(str[i+1] == '5')
                {
                    continue;
                }
                else
                {
                    if(i == 0)  // 读入最左的一个数字
                    {
                        a[counter] = number;
                        counter++;
                        continue;
                    }
                    
                    a[counter] = number;
                    counter++;
                    number = 0;
                    digit = 1;
                }
            }
            else
            {
                number += (str[i]-48)*digit;    // 字符0对应十进制48
                digit*=10;
                
                if(i == 0)  // 读入最左的一个数字
                {
                    a[counter] = number;
                    counter++;
                    continue;
                }
            }
        }
        
        sort(a, a+counter);
        
        for(int i=0; i<counter-1; i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<a[counter-1]<<endl;   
    }

    return 0;
}