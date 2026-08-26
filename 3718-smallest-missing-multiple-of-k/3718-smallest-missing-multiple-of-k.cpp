class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s;
        for(int n:nums){
            if(n%k == 0)
                s.insert(n);
        }
        int ans = k;
        while(s.count(ans)){
            ans = ans+k;
        }
        return ans;
    }
};