class Solution {
public:
    int countOverlaps(vector<vector<int>>& A, vector<vector<int>>& B, int rowoff, int coloff){
        int n = A.size();
        int count = 0;
        for(int row = 0; row<n; row++){
            for(int col = 0; col<n;col++){
                if(row+rowoff < 0 || row+rowoff >= n || col+coloff < 0 || col+coloff >= n)
                    continue;
                count += A[row][col]*B[row+rowoff][col+coloff];
            }
        }
        return count;
    }
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
        int maxOverlap = 0;
        for(int rowoff = -n+1; rowoff<n;rowoff++){
            for(int coloff = -n+1; coloff<n;coloff++){
                maxOverlap = max(maxOverlap, countOverlaps(A,B, rowoff, coloff));
            }
        }
        return maxOverlap;
    }
};