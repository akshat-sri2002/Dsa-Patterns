class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int stIdx=0;
        int len = 0;
        int mxLen=0;
        set<int>st;
        for(int i =0 ;i<s.size();i++){
            while(st.find(s[i])!=st.end() && len>0){
                st.erase(s[stIdx++]);
                len--;
            }
            st.insert(s[i]);
            len++;
            mxLen=max(len,mxLen);
        }
        return mxLen;
    }
};