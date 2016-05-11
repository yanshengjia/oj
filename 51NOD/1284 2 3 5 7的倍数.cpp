// 51NOD #1284 2 3 5 7的倍数
// 4个集合的容斥原理：|A1∪A2∪A3∪A4|=|A1|+|A2|+|A3|+|A4|-|A1∪A2|-|A1∪A3|-|A1∪A4|-|A2∪A3|-|A2∪A4|-|A3∪A4|+|A1∪A2∪A3|+|A1∪A2∪A4|+|A1∪A3∪A4|+|A2∪A3∪A4|-|A1∪A2∪A3∪A4|
// created by Shengjia Yan
// 2016年5月10日 下午11:54

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

double min(double a, double b) { return a < b ? a : b; }
double max(double a, double b) { return a > b ? a : b; }

struct Point{ double x,y; };

int main()
{
	#ifdef LOCAL
    freopen("1.txt","r",stdin);
    #endif
    
    #ifdef SPEED
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    #endif  
    
    ll n;
    cin>>n;
    
    ll result = n;
    ll a, b, c, d, ab, ac, ad, bc, bd, cd, abc, abd, acd, bcd, abcd;
    
    a = n/2;
    b = n/3;
    c = n/5;
    d = n/7;
    ab = n/6;
    ac = n/10;
    ad = n/14;
    bc = n/15;
    bd = n/21;
    cd = n/35;
    abc = n/30;
    abd = n/42;
    acd = n/70;
    bcd = n/105;
    abcd = n/210;

    result -= a + b + c + d - ab - ac - ad - bc -bd - cd + abc + abd + acd + bcd - abcd;
    
    cout<<result;
    
    return 0;
}