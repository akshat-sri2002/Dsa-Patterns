/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 

Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/

//using set to eliminate duplicate elements
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>s;
        int i = 0 , j = nums.size()-1;
        for(int k = 0 ;k<nums.size()-2;k++){
            i = k+1;
            j = nums.size()-1;
            while(i<j){
                if(nums[i]+nums[j]==-nums[k]){
                    s.insert({nums[k],nums[i],nums[j]});
                    i++,j--;
                }else if (nums[i]+nums[j]>-nums[k]){
                    j--;
                }else{
                    i++;
                }
            }
        }
        vector<vector<int>>ans(s.begin(),s.end());
        return ans ;
    }
};

// -4 -4 -1 -1 0 1 2 8

// wihout using set 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i = 0 ;i<n-2;i++){
            if(i==0||(i>0 && nums[i]!=nums[i-1])){
                int low = i+1;
                int high = n-1;
                int k =0-nums[i];
                while(low < high){
                    if(nums[low]+nums[high]<k){
                       low++;
                    }else if(nums[low]+nums[high]>k){
                        high--;
                    }else{
                        ans.push_back({nums[i],nums[low],nums[high]});
                        while(low<high && (nums[low]==nums[low+1])) low++;
                        while(low<high && (nums[high]==nums[high-1])) high--;
                        low++;
                        high--;
                    }
                }
            }
        }
        return ans;
    }
};