class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int row =grid.size();
        int col = grid[0].size();

        int n=row*col;
        k = k%n;

        if(k==0) return grid;
        auto reserve =  [&](int i, int j){
            while(i<j){
                swap(grid[i/col][i%col],grid[j/col][j%col]);
                i++;
                j--;
            }
        };

        reserve(0,n-1);
        reserve(0,k-1);
        reserve(k,n-1);
        return grid;
    }
};