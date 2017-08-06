// Created by sjyan @2017-06-27

class Solution {
public:    
    /**
     * @param numbers : Give an array numbers of n integer
     * @param target : Give an integer
     * @return : Find all unique triplets in the array which gives the sum of target.
     */
    vector<vector<int> > threeSum(vector<int> &nums, int target) {
        int size = nums.size();
        sort(nums.begin(), nums.end());    // ascending order
        int i, j, k;
        vector<vector<int> > result;
          
        for (i=0; i<size-2; i++) {
            int j=i+1, k=size-1;
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] == target) {
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    temp.push_back(k);
                    // 去重
                    if(find(result.begin(), result.end(), temp) == result.end()) {
                        result.push_back(temp);
                    }
                    j++;
                    k--;
                }
                else if (nums[i] + nums[j] + nums[k] > target) {
                    k--;
                }
                else {
                    j++;
                }
            }
        }
        return result;
    }
};