class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> indexcolcount(n,0);
        vector<int> indexrowcount(m,0);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    indexcolcount[j] += 1;
                    indexrowcount[i] += 1;
                }
            }
        }
        int resultserver = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1 && (indexcolcount[j] > 1 || indexrowcount[i] > 1)){
                    resultserver++;
                }
            }
        }
        return resultserver;
    }
};