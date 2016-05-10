// 51NOD #1264 线段相交
// description
// created by Shengjia Yan
// 2016年5月10日 下午2:56

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

//#define LOCAL
//#define SPEED
#define ll long long int

const double eps=1e-10;

struct point { double x, y; };

double min(double a, double b) { return a < b ? a : b; }
double max(double a, double b) { return a > b ? a : b; }

bool inter(point a, point b, point c, point d){
    if ( min(a.x, b.x) > max(c.x, d.x) ||
          min(a.y, b.y) > max(c.y, d.y) ||
          min(c.x, d.x) > max(a.x, b.x) ||
          min(c.y, d.y) > max(a.y, b.y) ) return 0;

     double h, i, j, k;
     h=(b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
     i=(b.x-a.x)*(d.y-a.y)-(b.y-a.y)*(d.x-a.x);
     j=(d.x-c.x)*(a.y-c.y)-(d.y-c.y)*(a.x-c.x);
     k=(d.x-c.x)*(b.y-c.y)-(d.y-c.y)*(b.x-c.x);
     return h * i <= eps && j * k <= eps;
}

int main()
{
	#ifdef LOCAL
    freopen("1.txt","r",stdin);
    #endif
    
    #ifdef SPEED
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    #endif  

    int T;
    cin>>T;
    
    double x1, x2, x3, x4, y1, y2, y3, y4;
    
    point A1, A2, B1, B2;

    for(int i=0; i<T; i++)
    {
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        
        A1.x = x1;
        A1.y = y1;
        A2.x = x2;
        A2.y = y2;
        B1.x = x3;
        B1.y = y3;
        B2.x = x4;
        B2.y = y4;

        if(inter(A1, A2, B1, B2)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    
    return 0;
}