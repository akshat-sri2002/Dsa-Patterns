/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int>mp1;
        map<char,int>mp2;
        if(s1.size()>s2.size()) return false;
        for(int i =0 ;i<s1.size();i++){
            mp1[s1[i]]++;
            mp2[s2[i]]++;
        }

        if(mp1==mp2) return true;
        int left = 0;

        for(int right =s1.size();right<s2.size() ;right++){
            mp2[s2[left]]--;
            if(mp2[s2[left]]==0) mp2.erase(s2[left]);
            mp2[s2[right]]++;

            left++;
            if(mp1==mp2) return true; 
        }
        return false;
    }
};