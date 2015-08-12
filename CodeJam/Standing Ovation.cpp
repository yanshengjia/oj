//codejam

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    //输入输出重定向
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    int T;  //案例数
    scanf("%d",&T);
    
    int Smax;   //最大害羞水平
    int answer=0;  //答案
    int temp=0;
    
    string s;
    
    for(int i=0; i<T; i++)  //T次循环处理 T 个案例
    {
        scanf("%d",&Smax);  //读取最大害羞水平Smax
        cin>>s;
       
        for(int n=0; n<Smax; n++)
        {
            temp+=s[n]-48; //数组前 n+1个元素之和
            if((s[n]-48)!=0)  continue; //#优化# 如果害羞水平为 n 为的人数不为0，跳过，进行下一项
            if(temp<(n+1))
            {
                answer+=(n+1-temp);
                temp=(n+1);
            }
        }
        
        printf("Case #%d: %d\n", i+1, answer);
        temp=0;
        answer=0;
    }
    
    return 0;
}
