class Solution {
public:
    int maxArea(vector<int>& height) {
        int low = 0 ;
        int n = height.size();
        int high = n - 1;
        int ans=0;
        while(low<=high){
            ans = max(ans,min(height[low],height[high])*(high - low));
            if(height[low]<height[high]) low++;
            else high --;
        }
        return ans;
    }
};