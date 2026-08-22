class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l=0, ans=0;
        unordered_map<char,int> freq;

        for(int i=0;i<s.size();i++){
            freq[s[i]]++;
            while(freq[s[i]] > 2){
                freq[s[l]]--;
                l++;
            }
             ans = max(ans,i-l+1);
        }
        return ans;
    }
};