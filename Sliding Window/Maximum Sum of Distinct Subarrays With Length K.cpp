class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long curr=0;
        long long ans =0;
        int st=0;
        unordered_set<int>s;
        for(int i =0 ;i<nums.size();i++){
            while(i-st==k || s.find(nums[i])!=s.end()){
                s.erase(nums[st]);
                curr-=nums[st++];
            }
            curr+=nums[i];
            s.insert(nums[i]);

            if (i - st + 1 == k) {
                ans = max(ans, curr);
            }
        }
        return ans;
    }
};