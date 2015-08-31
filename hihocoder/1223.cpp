//hihocoder #1223
//不等式
#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <fstream>
#include <algorithm>
using namespace std;
#define MAXN 55
int n, num[MAXN];
string s, op[MAXN];

int main()
{
    while(cin >> n)
    {
        for(int i = 0;i < n;i++)
        {
            cin >> s >> op[i] >> num[i];
            num[i]<<=1;     //C*2
        }
        
        int max = 1;
        
        for(int x = -1000;x <= 2000;x++)
        {
            int t = 0;
            for(int k = 0;k < n;k++)
            {
                if(op[k] == "=" && x == num[k])               t++;
                else if(op[k] == "<=" && x <= num[k])     t++;
                else if(op[k] == ">=" && x >= num[k])     t++;
                else if(op[k] == "<" && x < num[k])         t++;
                else if(op[k] == ">" && x > num[k])         t++;
            }
            
            if(t>max)   max=t;
        }
        cout << max << endl;
    }
    return 0;
}