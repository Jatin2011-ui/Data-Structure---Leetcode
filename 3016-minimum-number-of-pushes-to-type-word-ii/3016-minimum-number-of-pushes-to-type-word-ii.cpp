class Solution {
public:
    int minimumPushes(string word) {
        vector<int> mp(26,0);
        for(char &ch:word)
            mp[ch - 'a']++; //mentioned in qn , all letters are distinct 
        
        sort(begin(mp),end(mp),greater<int>()); //decending order sorting 

        int ans = 0;
        
        for(int i=0;i<26;i++){
            ans += mp[i] * ((i/8) + 1 );
        }
        return ans;
        
    }
};