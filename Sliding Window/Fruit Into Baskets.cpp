class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        //can use simple cnt1 and cnt2 because there can be only 2 types of fruits
        map<int,int>mp;
        int st = 0 ;
        int len = 0;
        int ans = 0;
        for(int i =0 ;i<fruits.size();i++){
            while(mp.size()==2 && mp.find(fruits[i])==mp.end()){
                mp[fruits[st]]--;
                if(mp[fruits[st]]==0){
                    mp.erase(fruits[st]);
                }
                st++;
                len--;
            }
            mp[fruits[i]]++;
            len++;
            if(mp.size()<=2){
                ans = max(len,ans);
            }
        }
        
        return ans;
    }
};