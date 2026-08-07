class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0, maxl=0;
        unordered_map<char, int> lastseen;
        for(int right=0;right<s.size();right++){
            if(lastseen.count(s[right]) && lastseen[s[right]]  >= left){
                left = lastseen[s[right]]+1;
            }
             lastseen[s[right]] = right;
             maxl = max(maxl, right-left+1); 
        }
        return maxl;
         
    }
};