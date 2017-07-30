// Author: Shengjia Yan
// Date: 2017年7月1日
// Email: sjyan@seu.edu.cn
// Time Complexity: O(logn)
// Space Complexity: O(1)


class Solution {
public:
    /**
     * @param A an integer array sorted in ascending order
     * @param target an integer
     * @return an integer
     */
    int findPosition(vector<int>& A, int target) {
        // Write your code here
        int size = A.size();
        int mid = size / 2;
        int index = mid;
        bool flag = false;
        
        if (size == 0)  return -1;
        
        if (A[mid] == target) {
            flag = true;
            return index;
        }
        else if (A[mid] > target) {
            // <-
            index--;
            while (index >= 0) {
                if (A[index] == target) {
                    flag = true;
                    return index;
                }
                index--;
            } 
        }
        else {
            // ->
            index++;
            while (index < size) {
                if (A[index] == target) {
                    flag = true;
                    return index;
                }
                index++;
            } 
        }
        
        if (!flag)  return -1;
    }
};