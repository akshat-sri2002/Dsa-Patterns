class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans;
        deque<int>dq;
        for(int i = 0 ;i< n;i++){
            // removing the element i.e not of use
            // because the index has paased the window
            if(!dq.empty() && dq.front()==i-k) dq.pop_front();

            //removing any smaller element because it 
            //will be never in answer.
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            //pushing the current element.
            dq.push_back(i);
            // if window size is hit push the largest element
            //(i.e. front ele) in the answer.
            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};