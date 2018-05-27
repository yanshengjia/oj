// Author: Shengjia Yan
// Date: 2018-04-20 Friday
// Email: i@yanshengjia.com
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
using namespace std;

int partition(int a[], int low, int high) {
    int i = low, j = high, index = a[i];
    
    while (i < j) {
        while (a[j] < index && i < j) {
            j--;
        }
        
        if (i < j) {
            a[i] = a[j];
            i++;
        }
        
        while (a[i] >= index && i < j) {
            i++;
        }
        
        if (i < j) {
            a[j] = a[i];
            j--;
        }
    }
    a[i] = index;
    
    return i;
}

void greatestK(int a[], int low, int high, int k) {
    int index, n;
    
    if (low < high) {
        index = partition(a, low, high);
        n = index - low + 1;
        
        if (n == k)
            return ;
        else if (n < k) {
            greatestK(a, index+1, high, k-n);
            return ;
        }
        else {
            greatestK(a, low, index, k);
            return ;
        }
    }
}


int main(){
    int k = 5;
    int a[] = {3, 4, 7, 1, 2, 5, 6};
    greatestK(a, 0, 6, k);
    for (int i=0; i<k; i++) {
        cout << a[i] << ' ';
    }
    
    return 0;
}