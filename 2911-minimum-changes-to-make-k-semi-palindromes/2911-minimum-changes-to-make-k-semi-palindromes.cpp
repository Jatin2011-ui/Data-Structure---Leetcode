class Solution {
public:
    int  n;
    string str;
    vector<vector<int>> costmemo;
    vector<vector<int>> memo;
    int getcost(int i, int j){
        int len = j - i + 1;
        if(costmemo[i][j] != -1 ){
            return costmemo[i][j];
        }
        int mincost = INT_MAX;
        for(int d=1;d<len;d++){
            if(len % d != 0)
                continue;
            
            int cost = 0;
            for(int group = 0; group < d; group++){
                int l = i + group;
                int r = l + (len/d - 1) * d;

                while(l<r){
                    if(str[l] != str[r])
                        cost++;
                    l += d;
                    r -= d;
                }
            }
            mincost = min(mincost, cost);
        }
        return costmemo[i][j] = mincost;
    }
    int solve(int start, int k){
        if(k==0){
            if(start == n)
                return 0;
            return INT_MAX;
        }
        //early return 
        if(start + 2*k > n){
            return INT_MAX;
        }
        if(memo[start][k]  != -1){
            return memo[start][k];
        }
        int result = INT_MAX;
        for(int end = start+1; end < n; end++){
            //start....end --> 1 piece
            int remainingcost = solve(end+1, k-1);

            if(remainingcost == INT_MAX){
                continue;
            }
            result  = min(result, getcost(start, end) + remainingcost);
        }
        return memo[start][k] =  result;
    }
    int minimumChanges(string s, int k) {
        n = s.length();
        str = s;
        costmemo.assign(n+1, vector<int>(n+1, -1));
        memo.assign(n+1, vector<int>(k+1, -1));
        return solve(0,k);
    }
};