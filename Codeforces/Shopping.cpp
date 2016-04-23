// codeforces 
// Educational Codeforces Round 12 
// #B Shopping
// created by Shengjia Yan
// 2016年4月23日 上午10:18

//#define LOCAL

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
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
    std::ios::sync_with_stdio(false);
    
    int n, m, k;
    cin>>n>>m>>k;
    int a[105];    
    int t = 0;  // the total time
    
    for(int i=0; i<k; i++)
    {
        cin>>a[i];
    }
    
    for(int j=0; j<n; j++)
    {
        for(int p=0; p<m; p++)
        {
            int target, position;
            cin>>target;
            
            for(int q=0; q<k; q++)
            {
                if(a[q] == target)
                {
                    position = q+1;
                    t += position;
                    
                    for(int c=q-1; c>=0; c--)
                    {
                        a[c+1] = a[c];
                    }
                    a[0] = target;
                    break;
                }
            } 
        }
    }
    cout<<t<<endl;
    return 0;
}