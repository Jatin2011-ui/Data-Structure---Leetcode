class Solution {
public:
    string smallestSubsequence(string s) {
        string st = "";
        vector<int> seen(26,0), freq(26,0);
        for(int i = 0; i < s.size(); i++ ) {
             freq[s[i] - 'a']++;
        }
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']--;
            if (seen[s[i]-'a']){
                continue;
            }

            while (!st.empty() && st.back() > s[i]&&freq[st.back() - 'a'] != 0){
                seen[st.back()-'a'] =0;
                st.pop_back();

            } 
            seen[s[i]-'a'] =1 ;
            st.push_back(s[i]);
        }
        return st;

    }
};