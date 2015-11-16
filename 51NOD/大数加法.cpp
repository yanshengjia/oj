// 51NOD #1005 big integer
// use the stack as a data sturcture
// created by yanshengjia
// 2015.11.3

#define LOCAL

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

string str1;
string str2;


int main()
{
	#ifdef LOCAL
    freopen("1.txt","r",stdin);
    #endif
  
	scanf("%s",str1);
	scanf("%s",str2);
	
	int length1 = str1.length();
	int length2 = str2.length();
	
	for(int i=0; i<length1; i++)
	{
		s1.push(str1[i]-48);	// the top of stack s1 is the lowerest digit of str1
	}
	
	for(int i=0; i<length2; i++)
	{
		s2.push(str1[i]-48);	// the top of stack s2 is the lowerest digit of str2
	}
	
	int t = 0;
	
	while(!s1.empty() && !s2.empty())
	
	
	
	
	
    return 0;
}