#include <iostream>
using namespace std;

int partition(int s[], int l, int r) // 返回调整后基准数的位置  
{  
    int i = l, j = r;  
    int x = s[l]; // s[l] 即 s[i] 就是第一个坑  
    while (i < j)  
    {  
        // 从右向左找小于x的数来填 s[i]
        while(i < j && s[j] >= x)   
            j--;
 
        if(i < j)   
        {  
            s[i] = s[j]; // 将 s[j] 填到 s[i] 中，s[j] 就形成了一个新的坑  
            i++;  
        }  
  
        // 从左向右找大于或等于x的数来填 s[j]  
        while(i < j && s[i] < x)  
            i++;
          
        if(i < j)   
        {  
            s[j] = s[i]; // 将 s[i] 填到 s[j] 中，s[i] 就形成了一个新的坑  
            j--;  
        }  
    }
     
    s[i] = x;  //退出时，i等于j。将 x 填到这个坑中
  
    return i;  
}

void quick_sort(int s[], int l, int r)
{
    if (l < r)
    {
        int i = partition(s, l, r); // 先成挖坑填数法调整 s[]  
        quick_sort(s, l, i - 1); // 递归调用   
        quick_sort(s, i + 1, r);  
    }  
}