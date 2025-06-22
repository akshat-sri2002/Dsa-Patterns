/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
 

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"
 

Constraints:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000
*/

class Solution {
public:
    
    string convert(string s, int numRows) {
        vector<string>ans(numRows);
        int curr = 0;
        int flag = 1;
        if(numRows==1) return s;
        for(int i = 0 ;i<s.size(); i++){
            ans[curr].push_back(s[i]);
            curr+=flag;
            if(curr==numRows-1) flag=-1;
            if(curr==0) flag = 1;
        }

        string finalAns ="";
        for(auto it : ans){
            cout<<it<<endl;
            finalAns+=it;
        }
        return finalAns;
    }

};

/*

P A Y P A L I S H I R  I  N  G
0 1 2 3 4 5 6 7 8 9 10 11 12 13



2n-2->n-1

0 6 12 
1 5 7 11 13
2 4 8 10 
3 9

13/4 = 3 

*/