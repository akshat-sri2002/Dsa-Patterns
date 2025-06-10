// User function template for C++ (gfg)

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // your code here
        map<char,int>mp;
        int st = 0 ;
        int len = 0;
        int ans = -1;
        for(int i =0 ;i<s.size();i++){
            while(mp.size()==k && mp.find(s[i])==mp.end()){
                mp[s[st]]--;
                if(mp[s[st]]==0){
                    mp.erase(s[st]);
                }
                st++;
                len--;
            }
            mp[s[i]]++;
            len++;
            if(mp.size()==k){
                ans = max(len,ans);
            }
        }
        
        return ans;
    }
};