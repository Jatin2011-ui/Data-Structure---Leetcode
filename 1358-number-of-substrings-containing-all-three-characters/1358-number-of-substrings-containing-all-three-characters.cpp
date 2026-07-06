class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(), i = 0, j = 0, ans = 0;
        
        // map for storing the frequency of characters
        unordered_map<char, int> mp;

        // sliding window approach
        for (j = 0; j < n; j++) {
            // add the current character to the map
            mp[s[j]]++;

            // move i to maintain the window condition (containing all three characters)
            while (mp.size() == 3) {
                // calculate the number of valid substrings starting from i to j
                ans += n - j;

                // remove the character at i from the map
                mp[s[i]]--;
                if (mp[s[i]] == 0) {
                    mp.erase(s[i]);
                }
                i++;
            }
        }
        return ans;
    }
};
