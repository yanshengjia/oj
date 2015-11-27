// 51NOD #1183 编辑距离
// dyanmic programming
// created by yanshengjia
// 2015-11-27

#include <iostream>
#include <string>
using namespace std;

int a[1005][1005];  // a[i][j] = edit(i,j)

int main()
{
    string str1, str2;
    int len1, len2;
    cin>>str1>>str2;
    
    len1 = str1.length();
    len2 = str2.length();
    
    a[0][0] = 0;    // if i==0 && j==0, edit(i,j) = 0
    
    for(int i=1; i<=len1; i++)  // if i>0 && j==0, edit(i,j) = i
        a[i][0]  = i;
    for(int j=1; j<=len2; j++)  // if i==0 && j>0, edit(i,j) = j
        a[0][j]  = j;
    
    if(!len1 || !len2)
    {
        cout<<a[len1][len2]<<endl;   // 有字符串长度为0
        return 0;
    }
    
    // 字符串长度都超过0
    int min;
    for(int i=1; i<=len1; i++)
    {
        for(int j=1; j<=len2; j++)
        {
            int t1 = a[i-1][j] + 1;
            int t2 = a[i][j-1] + 1;
            t1<=t2 ? min = t1 : min = t2;
            int t3 = str1[i-1] == str2[j-1] ? a[i-1][j-1] : a[i-1][j-1] + 1;
            if(t3<min) min = t3;
            
            a[i][j] = min;
        }
    }
   
    cout<<a[len1][len2]<<endl;
    
    return 0;
}